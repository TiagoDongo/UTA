# API GraphQL

![Python](https://img.shields.io/badge/Python-FFD43B?style=for-the-badge&logo=python&logoColor=blue)
![FastAPI](https://img.shields.io/badge/fastapi-109989?style=for-the-badge&logo=FASTAPI&logoColor=white)
![strawberry](https://img.shields.io/badge/Strawberry-purple?style=for-the-badge)
![sqlalchemy](https://img.shields.io/badge/SQLALCHEMY-%23D71F00?style=for-the-badge&logo=sqlalchemy&logoColor=white)
![SQLite](https://img.shields.io/badge/Sqlite-003B57?style=for-the-badge&logo=sqlite&logoColor=white)
![graphql](https://img.shields.io/badge/GraphQl-E10098?style=for-the-badge&logo=graphql&logoColor=white)

Uma API GraphQL simples construída com FastAPI e Strawberry, usando SQLAlchemy para interações com o banco de dados e SQLite como backend. Este projeto demonstra operações básicas CRUD para gerenciar usuários via consultas e mutações GraphQL.

## Funcionalidades

- **Esquema GraphQL**: Suporta consulta de todos os usuários e adição de novos usuários via mutações.
- **Integração com Banco de Dados**: Usa SQLAlchemy ORM com SQLite para armazenamento persistente.
- **Suporte a CORS**: Habilitado para solicitações de origem cruzada.
- **Configuração de Ambiente**: Carrega configurações de um arquivo `.env` usando `python-dotenv`.
- **Gerenciamento de Vida Útil Assíncrono**: Inicializa o banco de dados na inicialização.

## Instalação

1. **Clone o Repositório** (se ainda não foi feito):

   ```bash
   git clone https://github.com/TiagoDongo/UTA.git
   cd UTA/Sistemas_Distribuidos/graphql_api
   ```

2. **Instale as Dependências**:
   - Certifique-se de ter Python 3.8+ instalado.
   - Instale os pacotes necessários usando o `requirements.txt`:
     ```bash
     pip install -r requirements.txt
     ```

3. **Configure o Ambiente**:
   - Crie um arquivo `.env` com o CORS_ORIGINS:
      ```
      ORIGIN_CORS=http://localhost:8000,http://127.0.0.1:8000
      ```

4. **Execute a Aplicação**:
   ```bash
   uvicorn main:app --reload
   ```
   A API estará disponível em `http://127.0.0.1:8000/graphql` para o GraphQL Playground.


### Endpoints da API

- **Endpoint GraphQL**: `POST /graphql` – Lida com consultas e mutações GraphQL.
- **GraphQL Playground**: Visite `http://127.0.0.1:8000/graphql` em um navegador para testes interativos.


## Estrutura do Projeto

- `main.py`: Define a aplicação FastAPI, esquema GraphQL (usando Strawberry) e rotas.
- `database.py`: Lida com a configuração do banco de dados com SQLAlchemy, incluindo o modelo `DBUser`.

## Contribuição

1. Faça um fork do repositório.
2. Crie uma branch de funcionalidade.
3. Faça suas alterações e teste thoroughly.
4. Envie um pull request.

## Contato

Para dúvidas ou problemas, abra uma issue no repositório.
