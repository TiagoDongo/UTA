const container = document.getElementById("container")
const googleLogin = document.getElementById("google-login")

window.onload = async () => {
  const params = new URLSearchParams(window.location.search)
  console.log("[onload] params:", params.toString())

  if(params.get("logged") === "true") {
    console.log("[onload] logged=true, a carregar utilizador...")
    await loadUsers()
  }
}

async function loadUsers() {
  console.log("[loadUsers] a fazer fetch para /me...")

  const response = await fetch("http://localhost:5000/me", {credentials: "include"})
  console.log("[loadUsers] status da resposta:", response.status)

  const user = await response.json()
  console.log("[loadUsers] dados recebidos:", user)

  if (user.error) {
    console.error("[loadUsers] erro:", user.error)
    return
  }

  container.innerHTML = `
    <div style="display:flex; flex-direction:column; align-items:center; justify-content:center; height:480px; gap:15px;">
      <img src="${user.picture}" style="border-radius:50%; width:90px;">
      <h2>${user.name}</h2>
      <p>${user.email}</p>
      <button onclick="logout()" 
        style="background:#512da8; color:white; padding:10px 30px; border:none; border-radius:8px; cursor:pointer;"
      >
        Logout
      </button>
    </div>
  `
}

async function logout() {
  console.log("[logout] a terminar sessão...")
  await fetch("http://localhost:5000/logout", {credentials: "include"})
  window.location.href = "http://localhost:3000"
}

googleLogin.addEventListener('click', (event) => {
  event.preventDefault()
  console.log("[login] a redirecionar para o Google...")
  window.location.href = "http://localhost:5000/login"
})