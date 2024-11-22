#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
#include <Servo.h>

// Criando elemento LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Definindo o buzzer
#define buzzer 8

//Definindo Pino do DHT
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
//Criando variaveis do DHT
float temperatura = 0;
float umidade = 0;

//Definindo o LDR
int ldr_Pino = A1;
int ldr = 0;

//Criando elemento do Servo
Servo meuServo;
int servo_Pino = 9;  // Pino do Servo Motor
bool abrirServo = false;
int servoPos = 0;

//Criando o elemento do botao
int botao_Pino = 2;

//Definindo os LED`S
int led_Vermelho = 5;
int led_Amarelo = 6;
int led_Azul = 7;


void setup() {
  //Iniciando Serial
  Serial.begin(9600);
  //Iniciando o DHT
  dht.begin();
  //Associando o pino do servo
  meuServo.attach(servo_Pino);
  //Definindo o tipo de pino
  pinMode(led_Vermelho, OUTPUT);
  pinMode(led_Amarelo, OUTPUT);
  pinMode(led_Azul, OUTPUT);
  pinMode(servo_Pino, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botao_Pino, INPUT_PULLUP);
  //Definindo o tamanho e iniciando o LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(1000);
}

void loop() {

  // Lendo a temperatura e umidade do DHT
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  // Lendo a luminocidade do LDR
  ldr = analogRead(ldr_Pino);

  // Variável de status
  String status = "";

  // Lógica de controle dos LEDs e status
  if (ldr > 800 || temperatura > 28) {
    // Nível excessivo de energia (muita luz artificial ou temperatura muito alta)
    tone(buzzer, 1500, 2000);
    digitalWrite(led_Vermelho, HIGH);
    digitalWrite(led_Amarelo, LOW);
    digitalWrite(led_Azul, LOW);
    status = "Contaminacao Ambiental";
    abrirServo = true;
  }
  else if (ldr > 600 || (temperatura > 22 && temperatura <= 28)) {
    // Nível médio de sustentabilidade (uso moderado de energia)
    digitalWrite(led_Vermelho, LOW);
    digitalWrite(led_Amarelo, HIGH);
    digitalWrite(led_Azul, LOW);
    status = "Nivel Medio de Sustentabilidade";
    abrirServo = false;
  }
  else {
    // Nível sustentáveis (luz natural, temperatura ideal)
    digitalWrite(led_Vermelho, LOW);
    digitalWrite(led_Amarelo, LOW);
    digitalWrite(led_Azul, HIGH);
    status = "Nivel Bom de Sustentabilidade";
    abrirServo = false;
  }
  // Lendo o precionamento do botao
  if (digitalRead(botao_Pino) == LOW) {
    abrirServo = true;
  }
  // Condição para abrir o servo
  if (abrirServo) {
    meuServo.write(180);
  }
  else {
    meuServo.write(0);
  }
  // Exibindo os dados no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperatura) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Umidade: " + String(umidade) + "%");
  // Criar o elemento JSON
  StaticJsonDocument<200> json;
  json["Temperatura"] = temperatura;
  json["Umidade"] = umidade;
  json["Status"] = status;  // Status atualizado conforme o LED
  // Enviando o JSON pela serial
  serializeJson(json, Serial);
  Serial.println();
  //Delay de 1s
  delay(2000);
}
