# Login com Google OAuth 2.0

![FastAPI](https://img.shields.io/badge/fastapi-109989?style=for-the-badge&logo=FASTAPI&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-323330?style=for-the-badge&logo=javascript&logoColor=F7DF1E)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![Google](https://img.shields.io/badge/Google_Cloud-4285F4?style=for-the-badge&logo=google-cloud&logoColor=white)
![OAuth](https://img.shields.io/badge/OAuth_2.0-EB5424?style=for-the-badge&logo=auth0&logoColor=white)
![Uvicorn](https://img.shields.io/badge/Uvicorn-499848?style=for-the-badge&logo=gunicorn&logoColor=white)


Implementação de autenticação com Google OAuth 2.0 seguindo o **Authorization Code Flow**, desenvolvida com FastAPI no backend e JavaScript puro no frontend.

---
> **Notas:** 
> - `Python 3.8+` é necessário para rodar este projeto.
> - `Estrutura do projeto`:
>   - `api/` - Backend FastAPI
>   - `src/` - Frontend JavaScript

---


## Configuração

1. Cria um projeto no [Google Cloud Console](https://console.cloud.google.com) e obtém as credenciais OAuth 2.0.

2. Cria o ficheiro `api/.env` com as seguintes variáveis:
```env
  GOOGLE_CLIENT_ID=teu_client_id
  GOOGLE_CLIENT_SECRET=teu_client_secret
  REDIRECT_URI=http://localhost:5000/callback           
  CORS_ORIGINS=http://localhost:3000,http://127.0.0.1:3000
```

## Instalação de Dependências

```python
pip install fastapi uvicorn requests dotenv itsdangerous
```

## Execução

1. Inicia o backend numa terminal dentro da pasta `api`:
```bash
    uvicorn main:app --reload --port 5000
```

2. Inicia o frontend noutro terminal dentro da pasta `src`:
```bash
    uvicorn main:app --reload --port 3000
```

3. Abre o browser em `http://localhost:3000`

---

## Rotas da API

| Método | Rota        | Descrição                          |
|--------|-------------|------------------------------------|
| GET    | `/login`    | Redireciona para o Google          |
| GET    | `/callback` | Recebe o code e cria a sessão      |
| GET    | `/me`       | Devolve os dados do utilizador     |
| GET    | `/logout`   | Termina a sessão                   |