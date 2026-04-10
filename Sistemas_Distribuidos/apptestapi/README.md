# AppTestAPI

![Python](https://img.shields.io/badge/Python-3.8+-blue)
![FastAPI](https://img.shields.io/badge/FastAPI-0.100+-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

## Descrição do Mini-Projeto

Este é um mini-projeto de exemplo para Sistemas Distribuídos, composto por duas partes principais:
- **API Backend**: Uma API REST construída com FastAPI e SQLAlchemy para gerenciar usuários (criar e listar). Usa SQLite como banco de dados e inclui CORS para integração com frontend.
- **Frontend Web**: Uma aplicação web simples em HTML/CSS/JS que consome a API para exibir usuários.

O projeto demonstra conceitos básicos de APIs REST, integração frontend-backend e configuração de servidores locais.

## Estrutura do Projeto

```
apptestapi/
├── api/          # Código da API (backend)
├── src/          # Código do frontend web
├── requirements.txt  # Dependências Python
└── README.md     # Este arquivo
```

## Comandos para Executar o Projeto

## Configuração

### Arquivo .env
O arquivo `api/.env` contém variáveis de ambiente para configuração:
- `CORS_ORIGINS`: Lista de origens permitidas para CORS (separadas por vírgula). Exemplo: `http://localhost:8000,http://127.0.0.1:8000`.

Certifique-se de que o arquivo `.env` existe na pasta `api/` antes de executar a API.

### Executar Separadamente
- **API**: `uvicorn api.main:app --reload --host 127.0.0.1 --port 3000`
- **Frontend**: `uvicorn src.main:app --reload`

### Executar Ambos ao Mesmo Tempo
Use o script `run.py` para iniciar ambos os servidores em paralelo:
- `python run.py`

Isso executará a API na porta 3000 e o frontend na porta 8000.