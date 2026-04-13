from fastapi import APIRouter, Request
from fastapi.responses import RedirectResponse, JSONResponse
import requests, secrets, os
from dotenv import load_dotenv
load_dotenv()

githubRouter = APIRouter()

CLIENT_ID     = os.getenv("GITHUB_CLIENT_ID")
CLIENT_SECRET = os.getenv("GITHUB_CLIENT_SECRET")
REDIRECT_URI  = "http://localhost:5000/callback/github"

authorize_url = "https://github.com/login/oauth/authorize"
token_url     = "https://github.com/login/oauth/access_token"
user_api      = "https://api.github.com/user"

@githubRouter.get("/login/github")
def login (request: Request):
  state = secrets.token_urlsafe(16)
  request.session["oauth_state"] = state

  params = f"?client_id={CLIENT_ID}&redirect_uri={REDIRECT_URI}&scope=read:user%20user:email&state={state}"
  return RedirectResponse(authorize_url + params)

@githubRouter.get("/callback/github")
def callback (request: Request, code: str, state: str):
  if state != request.session.get("oauth_state"):
    return JSONResponse({"error": "Estado inválido"}, status_code=403)
  
  token_response = requests.post(token_url, data= {
    "code": code,
    "client_id": CLIENT_ID,
    "client_secret": CLIENT_SECRET,
    "redirect_uri": REDIRECT_URI,
  }, headers={"Accept": "application/json"})
  access_token = token_response.json().get("access_token")

  user_data = requests.get(
    user_api,
    headers={
      "Authorization": f"Bearer {access_token}",
      "Accept": "application/json"
      },
  ).json()

  if not user_data.get("email"):
    emails_response = requests.get(
      "https://api.github.com/user/emails",
      headers={
          "Authorization": f"Bearer {access_token}",
          "Accept": "application/json"
      }
    ).json()
    primary_email = next (
      (e["email"] for e in emails_response if e["primary"] and e["verified"]),
      None
    )
    user_data["email"] = primary_email

  request.session["user"] = user_data
  request.session["access_token"] = access_token

  return RedirectResponse("http://localhost:3000?logged=true")
