from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, declarative_base

#SQLite database
DATABASE_URL = "sqlite:///./test.db"

#Para uma base de dados SQLite (cria o ficheiro )
engine = create_engine(
  DATABASE_URL,
  connect_args={"check_same_thread": False}
)

# Para base de dados cliente-servidor
# engine = create_engine("postgresql://utilizador:palava-passe")
SessionLocal = sessionmaker (
  autocommit = False,
  autoflush= False,
  bind=engine
)

Base = declarative_base()