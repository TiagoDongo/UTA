from fastapi import APIRouter, Request
from fastapi.responses import RedirectResponse, JSONResponse
import requests, secrets, os
from dotenv import load_dotenv
load_dotenv()

router = APIRouter()

CLIENT_ID = os.getenv("GOOGLE_CLIENT_ID")
CLIENT_SECRET = os.getenv("GOOGLE_CLIENT_SECRET")
REDIRECT_URI = os.getenv("REDIRECT_URI")

authorize_url = "https://accounts.google.com/o/oauth2/v2/auth"
token_url = "https://oauth2.googleapis.com/token"
user_api = "https://www.googleapis.com/oauth2/v2/userinfo"

@router.get("/login")
def login (request: Request):
  state = secrets.token_urlsafe(16)
  request.session["oauth_state"] = state

  params = f"?client_id={CLIENT_ID}&redirect_uri={REDIRECT_URI}&response_type=code&scope=openid%20email%20profile&state={state}"
  return RedirectResponse(authorize_url + params)

@router.get("/callback")
def callback (request: Request, code: str, state: str):
  if state != request.session.get("oauth_state"):
    return JSONResponse({"error": "Estado inválido"}, status_code=403)
  
  token_response = requests.post(token_url, data= {
    "code": code,
    "client_id": CLIENT_ID,
    "client_secret": CLIENT_SECRET,
    "redirect_uri": REDIRECT_URI,
    "grant_type": "authorization_code"
  })
  access_token = token_response.json().get("access_token")

  user_data = requests.get(
    user_api,
    headers={"Authorization": f"Bearer {access_token}"}
  ).json()

  request.session["user"] = user_data
  request.session["access_token"] = access_token

  return RedirectResponse("http://localhost:3000?logged=true")

@router.get("/me")
def me (request: Request):
  user = request.session.get("user")
  if not user:
    return JSONResponse({"error": "Não autenticado"}, status_code=401)
  return JSONResponse(user)

@router.get("/logout")
def logout(request: Request):
  request.session.clear()
  return JSONResponse({"message": "Sessão terminada"})