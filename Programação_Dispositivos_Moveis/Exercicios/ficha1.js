//Considere um array de objetos representando alunos, onde cada aluno possui um nome e um array de notas; desenvolva um programa que calcule a média das notas de cada aluno, classifique-o como “Excelente” (média >= 16), “Aprovado” (média >= 10) ou “Reprovado” (média < 10), e apresente os resultados no console utilizando métodos de arrays como map e reduce, bem como estruturas de decisão.
const alunos = [
  { nome: "Tiago", notas: [15, 18, 17] },
  { nome: "Ana", notas: [12, 10, 14] },
  { nome: "Carlos", notas: [8, 9, 7] }
];

const resultados = alunos.map(aluno => {
  const soma = aluno.notas.reduce((total, nota) => total + nota, 0)
  const media = soma / aluno.notas.length
  let classification

  if(media >= 16) {
    classification = "Excelente"
  } else if(media >= 10) {
    classification = "Aprovado"
  } else {
    classification = "Reprovado"
  }

  return {
    nome: aluno.nome,
    media: media.toFixed(2),
    classification
  }
})

resultados.forEach(aluno => {
  console.log(
    `${aluno.nome} - Media: ${aluno.media} - Classificação: ${aluno.classification}`
  );
})

/*
Dado um array de números, construa um programa que remova todos os valores negativos, multiplique os restantes por 2, filtre apenas os números pares resultantes e, por fim, calcule a soma total desses valores utilizando métodos de arrays apropriados.
 */
const arrNum = [10, -5, 20, 30, -8, 40, 50]
const newArray = arrNum
  .filter(num => num > 0)
  .map(n => n * 2)
  .filter(n => n % 2 === 0)
  .reduce((total, n) => total + n, 0)

console.log(newArray);

// Implemente um sistema simples de autenticação onde existe um objeto utilizador com propriedades username e password, sendo necessário criar uma função que simule a introdução de credenciais, verifique a sua validade através de estruturas condicionais e apresente no console uma mensagem indicando se o login é válido ou inválido.
const user = {
  username: 'Tiago',
  password: '1234'
}

function auth (username, password) {
  if(username === user.username && password === user.password){
    console.log(`User  ${user.username} is authenticated`);
  }else{
    console.log(`Error: username or password is incorrect`);
  }    
}

auth('Tiago', '1234')

//Desenvolva uma função que receba um número inteiro como argumento e utilize um ciclo de repetição para apresentar todos os números desde 0 até esse valor, indicando separadamente quais são pares e quais são ímpares com base no operador módulo.
const redution = (num) => {
  for (let index = 0; index <= num; index++) {
    if (index % 2 === 0){   
      console.log(index + ' é par');
    }else {
      console.log(index + ' é impar');
    }
  }
}

redution(10)

//5-Considere um array de objetos representando produtos, onde cada produto possui nome, preço e stock; implemente um programa que liste apenas os produtos disponíveis, calcule o valor total do stock existente e identifique os produtos que estão esgotados utilizando métodos como filter, map e reduce.
const products = [
  {name: 'sapato', price: 3000 , stock: 20},
  {name: 'calça', price: 1200 , stock: 0},
  {name: 'meia', price: 300 , stock: 12},
  {name: 'camisa', price: 1500 , stock: 26},
]

const showProductsAvailables = () => {
  const avProducts =  products.filter(product => product.stock > 0)
  console.log('Produtos Disponiveis:')
  avProducts.forEach(p => console.log(p.name))

  const totalStockValue = avProducts.reduce((total, product) => {
    return total + (product.price * product.stock)
  }, 0)
  console.log("Valor total do stock disponível:", totalStockValue, "CVE");

  const soldOutProducts = products.filter(product => product.stock === 0).map(p => p.name);
  console.log("Produtos esgotados:", soldOutProducts.join(", "));
}

showProductsAvailables();

//6-Crie uma função arrow que receba um objeto representando uma pessoa com propriedades nome e idade e retorne uma string formatada contendo essas informações.
const User = {
  nome: String,
  idade: Number
}

const people = (user=User) => {
  return console.log(`Nome: ${user.nome} - Idade: ${user.idade}`);
}

people({nome: 'tiago', idade: '21'})
