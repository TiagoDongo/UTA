// ========================================
//  APP DE REFLEXOS: REAÇÃO RÁPIDA
//  Arduino UNO — Sem bibliotecas externas
// ========================================

// Definição dos pinos
const int KY040_CLK = 2;  // Encoder CLK
const int KY040_DT  = 3;  // Encoder DT
const int KY010_PIN = 5;  // Interrupção Ótica
const int KY032_PIN = 6;  // Obstáculo IR
const int KY021_PIN = 7;  // Reed Magnético Digital
const int KY035_PIN = A0; // Sensor Magnético Analógico

// Variáveis Globais de Controlo
int totalAcertos    = 0;
int totalErros      = 0;
int comandoSorteado = 0;
unsigned long tempoInicio    = 0;
unsigned long ultimoDebounce = 0;        // FIX: debounce do encoder
int baseHall = 512;                      // FIX: valor base calibrado do KY-035
const unsigned long TEMPO_LIMITE = 3000; // 3 segundos
bool jogoAtivo = true;

int ultimoEstadoCLK;

// ----------------------------------------

void setup() {
  Serial.begin(9600);

  pinMode(KY040_CLK, INPUT_PULLUP);
  pinMode(KY040_DT,  INPUT_PULLUP);
  pinMode(KY010_PIN, INPUT_PULLUP);
  pinMode(KY032_PIN, INPUT_PULLUP);
  pinMode(KY021_PIN, INPUT_PULLUP);

  ultimoEstadoCLK = digitalRead(KY040_CLK);

  // FIX: calibra o KY-035 em repouso antes do jogo começar
  baseHall = analogRead(KY035_PIN);
  Serial.print("KY-035 calibrado em repouso: ");
  Serial.println(baseHall);

  randomSeed(analogRead(A1));

  iniciarJogo();
}

// ----------------------------------------

void loop() {
  if (!jogoAtivo) return;

  bool acertou = false;

  // 1. Verifica se o tempo limite expirou
  if (millis() - tempoInicio > TEMPO_LIMITE) {
    totalErros++;
    Serial.println("TEMPO ESGOTADO! Demasiado lento...");
    Serial.print("Erros: ");
    Serial.print(totalErros);
    Serial.println("/3");

    if (totalErros >= 3) {
      finalizarJogo();
    } else {
      delay(2000);
      sortearComando();
    }
    return;
  }

  // 2. Verifica o sensor correspondente ao comando atual
  switch (comandoSorteado) {

    case 1: {  // FIX: bloco { } para permitir declaração de variável local
      int estadoCLK = digitalRead(KY040_CLK);
      // FIX: debounce de 50ms para evitar falsos gatilhos do encoder
      if (estadoCLK != ultimoEstadoCLK && millis() - ultimoDebounce > 50) {
        ultimoDebounce = millis();
        acertou = true;
      }
      ultimoEstadoCLK = estadoCLK;
      break;
    }

    case 2:
      if (digitalRead(KY010_PIN) == LOW) acertou = true;
      break;

    case 3:
      if (digitalRead(KY032_PIN) == LOW) acertou = true;
      break;

    case 4:
      if (digitalRead(KY021_PIN) == LOW) acertou = true;
      break;

    case 5: {  // FIX: bloco { } para permitir declaração de variável local
      int valorHall = analogRead(KY035_PIN);
      // FIX: threshold relativo ao valor calibrado em vez de valor fixo
      if (abs(valorHall - baseHall) > 100) acertou = true;
      break;
    }
  }

  // 3. Se o utilizador reagir corretamente dentro do tempo
  if (acertou) {
    unsigned long tempoReacao = millis() - tempoInicio;
    totalAcertos++;

    Serial.print("CORRETO! Tempo: ");
    Serial.print(tempoReacao);
    Serial.print(" ms | Pontos: ");
    Serial.println(totalAcertos);

    ultimoEstadoCLK = digitalRead(KY040_CLK);
    ultimoDebounce  = millis(); // FIX: reseta debounce após acerto

    delay(2000);
    sortearComando();
  }
}

// ----------------------------------------

void iniciarJogo() {
  totalAcertos = 0;
  totalErros   = 0;
  jogoAtivo    = true;

  Serial.println("========================================");
  Serial.println(" APP DE REFLEXOS: REACAO RAPIDA ");
  Serial.println("========================================");
  Serial.println("Regras: Responda em menos de 3 segundos.");
  Serial.println("O jogo termina ao acumular 3 erros.");
  Serial.println("Prepare-se...\n");
  delay(2000);
  sortearComando();
}

void sortearComando() {
  comandoSorteado = random(1, 6);

  Serial.println("----------------------------------------");
  Serial.print("FACA ISTO: ");

  switch (comandoSorteado) {
    case 1: Serial.println("GIRE O ENCODER! (KY-040)");             break;
    case 2: Serial.println("Corte a luz da ranhura (KY-010)");      break;
    case 3: Serial.println("Aproxime a mao do sensor IR (KY-032)"); break;
    case 4: Serial.println("Encoste o iman no Reed Switch (KY-021)"); break;
    case 5: Serial.println("Aproxime o iman do Sensor Hall (KY-035)"); break;
  }

  tempoInicio = millis();
}

void finalizarJogo() {
  jogoAtivo = false;
  Serial.println("\n========================================");
  Serial.println("GAME OVER");
  Serial.println("Atingiu o limite de 3 falhas.");
  Serial.print("PONTUACAO FINAL: ");
  Serial.print(totalAcertos);
  Serial.println(" pontos!");
  Serial.println("========================================");
  Serial.println("Para jogar novamente, reinicie o Arduino.");
}