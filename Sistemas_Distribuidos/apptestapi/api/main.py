from fastapi import FastAPI, Depends
from fastapi.middleware.cors import CORSMiddleware
from sqlalchemy.orm import Session
from database import SessionLocal, engine
import models
import os
from dotenv import load_dotenv

load_dotenv()

models.Base.metadata.create_all(bind=engine)

app = FastAPI()

origins = os.getenv("CORS_ORIGINS", "").split(",")

app.add_middleware(
  CORSMiddleware,
  allow_origins=origins,
  allow_credentials=True,
  allow_methods=["*"],
  allow_headers=["*"],
)

def get_db():
  db = SessionLocal()
  try:
    yield db
  finally:
    db.close()

@app.post("/users/")
def create_user(name: str, email: str, db: Session = Depends(get_db)):
  user = models.User(name=name, email=email)
  db.add(user)
  db.commit()
  db.refresh(user)
  return user

@app.get("/users/")
def get_user(db: Session = Depends(get_db)):
  return db.query(models.User).all()