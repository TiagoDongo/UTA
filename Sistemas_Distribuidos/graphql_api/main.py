import strawberry
from fastapi import FastAPI
from contextlib import asynccontextmanager
from fastapi.middleware.cors import CORSMiddleware
from strawberry.fastapi import GraphQLRouter
from database import SessionLocal, DBUser, init_db
import os
from dotenv import load_dotenv

load_dotenv()

@strawberry.type
class User:
  id: int
  name: str
  email: str

@strawberry.type
class Query:
  @strawberry.field
  def all_users(self) -> list[User]:
    db = SessionLocal()
    users = db.query(DBUser).all()
    db.close()
    return [User(id=u.id, name=u.name, email=u.email) for u in users]

@strawberry.type
class Mutation:
  @strawberry.mutation
  def add_user(self, name: str, email: str) -> User:
    db = SessionLocal()
    new_user = DBUser(name=name, email=email)
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    db.close()
    return User(id=new_user.id, name=new_user.name, email=new_user.email)


schema = strawberry.Schema(query=Query, mutation=Mutation)
graphql_app = GraphQLRouter(schema)

@asynccontextmanager
async def lifespan(app: FastAPI):
  await init_db()
  print("Database initialized")

  yield

  print("Server shutting down ....")

app = FastAPI(title="Strawberry SQLite API", lifespan=lifespan)

origins = os.getenv("ORIGIN_CORS", "").split(",")

app.add_middleware(
  CORSMiddleware,
  allow_origins=origins,
  allow_credentials=True,
  allow_methods=["*"],
  allow_headers=["*"],
)

app.include_router(graphql_app, prefix="/graphql")

if __name__ == "__main__":
  import uvicorn
  uvicorn.run("main:app", host="127.0.0.1", port=1024, reload=True)

