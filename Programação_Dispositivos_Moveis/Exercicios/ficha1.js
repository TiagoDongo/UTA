//Considere um array de objetos representando alunos, onde cada aluno possui um nome e um array de notas; desenvolva um programa que calcule a média das notas de cada aluno, classifique-o como “Excelente” (média >= 16), “Aprovado” (média >= 10) ou “Reprovado” (média < 10), e apresente os resultados no console utilizando métodos de arrays como map e reduce, bem como estruturas de decisão.
const alunos = [
  { nome: "Tiago", notas: [15, 18, 17] },
  { nome: "Ana", notas: [12, 10, 14] },
  { nome: "Carlos", notas: [8, 9, 7] },
];

const resultados = alunos.map((aluno) => {
  const soma = aluno.notas.reduce((total, nota) => total + nota, 0);
  const media = soma / aluno.notas.length;
  let classification;

  if (media >= 16) {
    classification = "Excelente";
  } else if (media >= 10) {
    classification = "Aprovado";
  } else {
    classification = "Reprovado";
  }

  return {
    nome: aluno.nome,
    media: media.toFixed(2),
    classification,
  };
});

resultados.forEach((aluno) => {
  console.log(
    `${aluno.nome} - Media: ${aluno.media} - Classificação: ${aluno.classification}`,
  );
});

/*
Dado um array de números, construa um programa que remova todos os valores negativos, multiplique os restantes por 2, filtre apenas os números pares resultantes e, por fim, calcule a soma total desses valores utilizando métodos de arrays apropriados.
 */
const arrNum = [10, -5, 20, 30, -8, 40, 50];
const newArray = arrNum
  .filter((num) => num > 0)
  .map((n) => n * 2)
  .filter((n) => n % 2 === 0)
  .reduce((total, n) => total + n, 0);

console.log(newArray);

// Implemente um sistema simples de autenticação onde existe um objeto utilizador com propriedades username e password, sendo necessário criar uma função que simule a introdução de credenciais, verifique a sua validade através de estruturas condicionais e apresente no console uma mensagem indicando se o login é válido ou inválido.
const user = {
  username: "Tiago",
  password: "1234",
};

function auth(username, password) {
  if (username === user.username && password === user.password) {
    console.log(`User  ${user.username} is authenticated`);
  } else {
    console.log(`Error: username or password is incorrect`);
  }
}

auth("Tiago", "1234");

//Desenvolva uma função que receba um número inteiro como argumento e utilize um ciclo de repetição para apresentar todos os números desde 0 até esse valor, indicando separadamente quais são pares e quais são ímpares com base no operador módulo.
const redution = (num) => {
  for (let index = 0; index <= num; index++) {
    if (index % 2 === 0) {
      console.log(index + " é par");
    } else {
      console.log(index + " é impar");
    }
  }
};

redution(10);

//5-Considere um array de objetos representando produtos, onde cada produto possui nome, preço e stock; implemente um programa que liste apenas os produtos disponíveis, calcule o valor total do stock existente e identifique os produtos que estão esgotados utilizando métodos como filter, map e reduce.
const products = [
  { name: "sapato", price: 3000, stock: 20 },
  { name: "calça", price: 1200, stock: 0 },
  { name: "meia", price: 300, stock: 12 },
  { name: "camisa", price: 1500, stock: 26 },
];

const showProductsAvailables = () => {
  const avProducts = products.filter((product) => product.stock > 0);
  console.log("Produtos Disponiveis:");
  avProducts.forEach((p) => console.log(p.name));

  const totalStockValue = avProducts.reduce((total, product) => {
    return total + product.price * product.stock;
  }, 0);
  console.log("Valor total do stock disponível:", totalStockValue, "CVE");

  const soldOutProducts = products
    .filter((product) => product.stock === 0)
    .map((p) => p.name);
  console.log("Produtos esgotados:", soldOutProducts.join(", "));
};

showProductsAvailables();

//6-Crie uma função arrow que receba um objeto representando uma pessoa com propriedades nome e idade e retorne uma string formatada contendo essas informações.
const User = {
  nome: String,
  idade: Number,
};

const people = (user = User) => {
  return console.log(`Nome: ${user.nome} - Idade: ${user.idade}`);
};

people({ nome: "tiago", idade: "21" });

/*
7-Dado um array de notas, desenvolva um programa que utilize um ciclo de repetição para
contar quantos alunos foram aprovados e quantos foram reprovados, considerando que a
nota mínima de aprovação é 10.
*/
const notas = [
  { aluno: "Tiago", listasnotas: [10, 12, 19, 20, 16] },
  { aluno: "Henrique", listasnotas: [8, 5, 9, 10, 0] },
  { aluno: "Dongo", listasnotas: [15, 20, 19, 20, 16] },
];
function verifyAproves(notes = notas) {
  let approved = 0;
  let reproved = 0;

  notes.forEach((student) => {
    const sum = student.listasnotas.reduce((total, nota) => total + nota, 0);
    const average = sum / student.listasnotas.length;

    if (average >= 10) {
      approved++;
    } else {
      reproved++;
    }
  });

  console.log(`Aprovados: ${approved}, Reprovados: ${reproved}`);
}

verifyAproves(notas)

/*
8-Implemente uma função que receba um nome completo como argumento e retorne o
nome em letras maiúsculas, o número total de caracteres e a primeira letra do nome.
 */
const strName = (completeName) => {
  const upperName = completeName.toUpperCase();
  const totalChars = completeName.length;
  const firstLetter = completeName.slice(0, 1);

  return {
    nomeMaiusculo: upperName,
    totalCaracteres: totalChars,
    primeiraLetra: firstLetter,
  };
};

console.log(strName("Tiago Henrique da Graça Dongo"))

/*
9-Crie um objeto que represente uma conta bancária com um saldo inicial e métodos para
depositar e levantar dinheiro, garantindo que não é possível realizar levantamentos que
resultem em saldo negativo, e mostrando o saldo atualizado após cada operação.
 */

const account = {
  numeroConta: "1234567890",
  titular: {
    nome: "Tiago",
    nif: "123456789",
    telefone: "+238 1234567",
    email: "tiago@example.com"
  },
  moeda: "CVE",
  saldo: 15000.00,
  ativa: true,
  dataCriacao: new Date("2024-01-15"),

  depositar(valor) {
    if (!this.ativa){
      console.log("conta inativa");
      return
    }
    if (valor <= 0){
      console.log("Valor invalido para deposito");
      return
    }
    this.saldo += valor
    console.log(`Depósito de ${valor} efetuado. Saldo: ${this.saldo}`);
  },

  levantar(valor) {
    if (!this.ativa){
      console.log("conta inativa");
      return
    }
    if (valor <= 0){
      console.log("Valor invalido para deposito");
      return
    }
    if (valor > this.saldo){
      console.log("Saldo insuficiente");
      return
    }
    this.saldo -= valor
    console.log(`Levantamento de ${valor} efetuado. Saldo: ${this.saldo}`);
  },

  mostrarSaldo() {
    console.log(`Saldo atual: ${this.saldo}`);
  }
}

account.depositar(1000)
account.mostrarSaldo()
account.levantar(5000)