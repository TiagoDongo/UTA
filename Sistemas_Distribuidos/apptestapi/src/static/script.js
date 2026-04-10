const getUsersButton = document.getElementById('btn')
const container = document.getElementById('all-usersId')

getUsersButton.addEventListener('click', async () => {
  try {
    const response = await fetch("http://127.0.0.1:3000/users/")
    const data = await response.json()

    data.forEach((user, index) => {
      const div = document.createElement('div')
      div.className = "users"
      div.id = `user-${user.id}-Id`

      div.innerHTML += `
        <h3 class="product-price">${user.name}</h3>
        <h1 class="product-title">${user.email}</h1>
      `

      container.append(div)
    });
  }catch (error) {
    console.log(error)
  }
})