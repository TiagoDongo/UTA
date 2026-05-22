from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from fastapi import Request

app = FastAPI(title="WebSocket")

# Static files (JS, CSS)
app.mount("/static", StaticFiles(directory="static"), name="static")

# Templates (HTML)
templates = Jinja2Templates(directory="templates")


@app.get("/", response_class=HTMLResponse)
async def home(request: Request):
    return templates.TemplateResponse(
    name="index.html",
    request=request,
    context={}
)

clients = []

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()

    username = await websocket.receive_text()

    client = {"ws": websocket, "username": username}
    clients.append(client)

    for c in clients:
        await c["ws"].send_text(f"🔵 {username} joined the chat")

    try:
        while True:
            message = await websocket.receive_text()
            for c in clients:
                await c["ws"].send_text(f"{username}: {message}")

    except WebSocketDisconnect:
        clients.remove(client)
        for c in clients:
            await c["ws"].send_text(f"🔴 {username} left the chat")
