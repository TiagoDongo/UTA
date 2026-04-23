from sqlalchemy import Column, String, Integer, create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

SQLaLCHEMY_DATABASE_URL = "sqlite:///./project.db"

engine = create_engine(
  SQLaLCHEMY_DATABASE_URL, connect_args={"check_same_thread": False}
)

SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
Base = declarative_base()

class DBUser(Base):
  __tablename__="users"
  id = Column(Integer, primary_key=True, index=True)
  name = Column(String)
  email = Column(String, unique=True)

async def init_db():
  Base.metadata.create_all(bind=engine)