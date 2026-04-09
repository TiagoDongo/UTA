// Dados de exemplo usados na interface
const alunos = [
  { nome: "Tiago", notas: [15, 18, 17] },
  { nome: "Ana", notas: [12, 10, 14] },
  { nome: "Carlos", notas: [8, 9, 7] },
];

const arrNum = [10, -5, 20, 30, -8, 40, 50];

const user = {
  username: "Tiago",
  password: "1234",
};

const products = [
  { name: "sapato", price: 3000, stock: 20 },
  { name: "calça", price: 1200, stock: 0 },
  { name: "meia", price: 300, stock: 12 },
  { name: "camisa", price: 1500, stock: 26 },
];

const notas = [
  { aluno: "Tiago", listasnotas: [10, 12, 19, 20, 16] },
  { aluno: "Henrique", listasnotas: [8, 5, 9, 10, 0] },
  { aluno: "Dongo", listasnotas: [15, 20, 19, 20, 16] },
];

function calculateStudentResults(alunosList) {
  return alunosList.map((aluno) => {
    const soma = aluno.notas.reduce((total, nota) => total + nota, 0);
    const media = soma / aluno.notas.length;
    const classification =
      media >= 16 ? "Excelente" : media >= 10 ? "Aprovado" : "Reprovado";

    return {
      nome: aluno.nome,
      media: media.toFixed(2),
      classification,
    };
  });
}

function getPositiveEvenSum(numbers) {
  return numbers
    .filter((num) => num > 0)
    .map((num) => num * 2)
    .filter((num) => num % 2 === 0)
    .reduce((total, num) => total + num, 0);
}

function authenticateUser(username, password) {
  if (username === user.username && password === user.password) {
    return { success: true, message: `Bem-vindo, ${username}!` };
  }
  return { success: false, message: "Username ou password incorreto." };
}

function getParityList(maxNumber) {
  const result = [];
  for (let i = 0; i <= maxNumber; i += 1) {
    result.push(`${i} é ${i % 2 === 0 ? "par" : "ímpar"}`);
  }
  return result;
}

function getProductSummary(productList) {
  const availableProducts = productList.filter((product) => product.stock > 0);
  const availableNames = availableProducts.map((product) => product.name);
  const totalStockValue = availableProducts.reduce(
    (total, product) => total + product.price * product.stock,
    0,
  );
  const soldOutNames = productList
    .filter((product) => product.stock === 0)
    .map((product) => product.name);

  return {
    availableNames,
    totalStockValue,
    soldOutNames,
  };
}

function formatPerson(userData) {
  return `Nome: ${userData.nome} - Idade: ${userData.idade}`;
}

function verifyAproves(notesList) {
  let approved = 0;
  let reproved = 0;

  notesList.forEach((student) => {
    const sum = student.listasnotas.reduce((total, nota) => total + nota, 0);
    const average = sum / student.listasnotas.length;
    if (average >= 10) approved += 1;
    else reproved += 1;
  });

  return { approved, reproved };
}

function formatCompleteName(completeName) {
  const upperName = completeName.toUpperCase();
  const totalChars = completeName.length;
  const firstLetter = completeName.slice(0, 1);

  return {
    nomeMaiusculo: upperName,
    totalCaracteres: totalChars,
    primeiraLetra: firstLetter,
  };
}

class BankAccount {
  constructor(titular, numAccount, saldo = 0, ativa = true) {
    this.titular = titular;
    this.numAccount = numAccount;
    this.saldo = saldo;
    this.ativa = ativa;
    this.dataCriacao = new Date();
  }

  depositar(valor) {
    if (!this.ativa) return { success: false, message: "Conta inativa." };
    if (valor <= 0)
      return { success: false, message: "Valor inválido para depósito." };
    this.saldo += valor;
    return { success: true, message: `Depósito de ${valor} efetuado.` };
  }

  levantar(valor) {
    if (!this.ativa) return { success: false, message: "Conta inativa." };
    if (valor <= 0)
      return { success: false, message: "Valor inválido para levantamento." };
    if (valor > this.saldo)
      return { success: false, message: "Saldo insuficiente." };
    this.saldo -= valor;
    return { success: true, message: `Levantamento de ${valor} efetuado.` };
  }

  mostrarSaldo() {
    return this.saldo;
  }
}

const contaBancaria = new BankAccount(
  {
    nome: "Tiago",
    nif: "123456789",
    telefone: "+238 1234567",
    email: "tiago@example.com",
  },
  "1234567890",
  15000,
);

function setText(id, text) {
  const element = document.getElementById(id);
  if (element) element.innerHTML = text;
}

function initUI() {
  // Adicionar aluno à lista
  document.getElementById("btn-add-student").addEventListener("click", () => {
    const name = document.getElementById("student-name").value.trim();
    const notesInput = document.getElementById("student-notes").value.trim();
    if (name && notesInput) {
      const notes = notesInput.split(",").map((n) => Number(n.trim()));
      alunos.push({ nome: name, notas: notes });
      document.getElementById("student-name").value = "";
      document.getElementById("student-notes").value = "";
      alert(`Aluno ${name} adicionado!`);
    } else {
      alert("Por favor, preencha todos os campos.");
    }
  });

  // Definir novo array
  document.getElementById("btn-set-array").addEventListener("click", () => {
    const input = document.getElementById("array-input").value.trim();
    if (input) {
      const numbers = input.split(",").map((n) => Number(n.trim()));
      arrNum.length = 0;
      arrNum.push(...numbers);
      alert("Array atualizado!");
    }
  });

  // Adicionar produto
  document.getElementById("btn-add-product").addEventListener("click", () => {
    const name = document.getElementById("product-name").value.trim();
    const price = Number(document.getElementById("product-price").value);
    const stock = Number(document.getElementById("product-stock").value);
    if (name && price > 0 && stock >= 0) {
      products.push({ name, price, stock });
      document.getElementById("product-name").value = "";
      document.getElementById("product-price").value = "";
      document.getElementById("product-stock").value = "";
      alert(`Produto ${name} adicionado!`);
    } else {
      alert("Por favor, preencha todos os campos corretamente.");
    }
  });

  // Adicionar aluno aos grades
  document.getElementById("btn-add-grade").addEventListener("click", () => {
    const name = document.getElementById("grades-name").value.trim();
    const notesInput = document.getElementById("grades-notes").value.trim();
    if (name && notesInput) {
      const listasnotas = notesInput.split(",").map((n) => Number(n.trim()));
      notas.push({ aluno: name, listasnotas });
      document.getElementById("grades-name").value = "";
      document.getElementById("grades-notes").value = "";
      alert(`Aluno ${name} adicionado!`);
    } else {
      alert("Por favor, preencha todos os campos.");
    }
  });

  document.getElementById("btn-students").addEventListener("click", () => {
    const result = calculateStudentResults(alunos);
    const html = result
      .map(
        (item) =>
          `<div>${item.nome} - ${item.media} - <strong>${item.classification}</strong></div>`,
      )
      .join("");
    setText("students-result", html);
  });

  document.getElementById("btn-array").addEventListener("click", () => {
    const sum = getPositiveEvenSum(arrNum);
    setText("array-result", `<div>Soma final: <strong>${sum}</strong></div>`);
  });

  document.getElementById("auth-form").addEventListener("submit", (event) => {
    event.preventDefault();
    const username = document.getElementById("auth-username").value;
    const password = document.getElementById("auth-password").value;
    const result = authenticateUser(username, password);
    setText("auth-result", `<div>${result.message}</div>`);
  });

  document.getElementById("parity-form").addEventListener("submit", (event) => {
    event.preventDefault();
    const maxNumber = Number(document.getElementById("parity-number").value);
    const items = getParityList(maxNumber);
    setText("parity-result", `<div>${items.join("<br>")}</div>`);
  });

  document.getElementById("btn-products").addEventListener("click", () => {
    const summary = getProductSummary(products);
    setText(
      "products-result",
      `<div>Produtos disponíveis: <strong>${summary.availableNames.join(", ")}</strong></div>
       <div>Valor total do stock: <strong>${summary.totalStockValue} CVE</strong></div>
       <div>Produtos esgotados: <strong>${summary.soldOutNames.join(", ") || "Nenhum"}</strong></div>`,
    );
  });

  document.getElementById("person-form").addEventListener("submit", (event) => {
    event.preventDefault();
    const name = document.getElementById("person-name").value;
    const age = document.getElementById("person-age").value;
    setText(
      "person-result",
      `<div>${formatPerson({ nome: name, idade: age })}</div>`,
    );
  });

  document.getElementById("btn-grades").addEventListener("click", () => {
    const summary = verifyAproves(notas);
    setText(
      "grades-result",
      `<div>Aprovados: <strong>${summary.approved}</strong></div><div>Reprovados: <strong>${summary.reproved}</strong></div>`,
    );
  });

  document.getElementById("name-form").addEventListener("submit", (event) => {
    event.preventDefault();
    const name = document.getElementById("full-name").value;
    const formatted = formatCompleteName(name);
    setText(
      "name-result",
      `<div>Maiúsculas: <strong>${formatted.nomeMaiusculo}</strong></div>
       <div>Caracteres: <strong>${formatted.totalCaracteres}</strong></div>
       <div>Primeira letra: <strong>${formatted.primeiraLetra}</strong></div>`,
    );
  });

  function refreshBankSummary(message = "") {
    const summary = `Titular: <strong>${contaBancaria.titular.nome}</strong><br>
      Conta: <strong>${contaBancaria.numAccount}</strong><br>
      Saldo: <strong>${contaBancaria.mostrarSaldo()} CVE</strong><br>
      Estado: <strong>${contaBancaria.ativa ? "Ativa" : "Inativa"}</strong>`;
    setText("bank-summary", summary);
    setText("bank-result", message ? `<div>${message}</div>` : "");
  }

  document.getElementById("btn-deposit").addEventListener("click", () => {
    const amount = Number(document.getElementById("bank-amount").value);
    const result = contaBancaria.depositar(amount);
    refreshBankSummary(result.message);
  });

  document.getElementById("btn-withdraw").addEventListener("click", () => {
    const amount = Number(document.getElementById("bank-amount").value);
    const result = contaBancaria.levantar(amount);
    refreshBankSummary(result.message);
  });

  refreshBankSummary();
}

window.addEventListener("DOMContentLoaded", initUI);
