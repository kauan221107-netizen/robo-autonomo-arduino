#include <Arduino.h>

// ====== SENSOR ===================================
#define TRIG_PIN 8
#define ECHO_PIN 9

// ====== MOTORES (L298N) ===========================
// Motor A
#define ENA 6
#define IN1 7
#define IN2 5

// Motor B
#define ENB 3
#define IN3 4
#define IN4 2

// ====== VARIÁVEIS =================================
long duracao;
int distancia;

const int limiteDistancia = 26; // distância mínima antes de ativar o recuo

bool eventoDisparado = false; // trava de recuo permanente

// ====== PROTÓTIPOS =================================
void frente();
void tras();
void parar();
int medirDistancia();

// ===================================================
void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

  // Leitura inicial descartada para evitar leitura "0"
  medirDistancia();
  delay(50);
}

// ===================================================
void loop() {

  distancia = medirDistancia();

  // Ignora leituras inválidas (sensor às vezes dá 0 ao iniciar)
  if (distancia == 0) {
    return;
  }

  // Se já recuou uma vez → recua para sempre
  if (eventoDisparado) {
    tras();
    return;
  }

  // Se está longe → segue pra frente
  if (distancia > limiteDistancia) {
    frente();
  }
  // Se chegou perto → ativa recuo permanente
  else {
    eventoDisparado = true;
    tras();
  }
}

// =============================================
// FUNÇÃO DO SENSOR
// =============================================
int medirDistancia() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duracao = pulseIn(ECHO_PIN, HIGH, 20000); // timeout 20ms evita travamento

  if (duracao == 0) return 0;

  distancia = duracao * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  return distancia;
}

// =============================================
// MOVIMENTOS
// =============================================
void frente() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
