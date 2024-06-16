// Bibliotecas WiFi Esp32
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiManager.h>
#include <WiFiAP.h>

// Info rede Esp32
IPAddress ip(192,168,8,222);
IPAddress gateway(192,168,8,100);
IPAddress subnet(255,255,255,0);
WiFiServer server(80);

// Biblioteca Servo Esp32
#include <ESP32_Servo.h>

// Definir os pinos
Servo servo[4][3];
const int servo_pin[4][3] = { {11, 12}, 
                              { 2,  4}, 
                              {14, 15},
                              { 8,  9}};

// Definições para Movimentos
#define dg 5  //delay giro
#define da 5  //delay andar

int acao, k;

// Protótipos
void padrao();
void frente();
void tras();
void virar_esquerda();
void virar_direita();
void desativar();
void respawn();

// Setup
void setup() {
  // Iniciar Serial
  Serial.begin(115200);

  // Configurações WiFi
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("QuadBot","12345678"); // Rede AP para Conectar WiFi
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("Server started");

  // Configurações Servos
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].attach(servo_pin[i][j]);
      delay(100);
    }
  }

  // Inicial
  padrao();
  delay(500);
  desativar();
}

void loop() {
  // Leiitura WiFi
  WiFiClient client = server.available();
  if (client){
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') break;
        else if (c != '\r') currentLine += c;

        // Parar
        if (currentLine.endsWith("GET /parar")) acao = 0;
        
        // Andar Frente
        else if (currentLine.endsWith("GET /frente")) acao = 1;

        // Andar Trás
        else if (currentLine.endsWith("GET /tras")) acao = 2;
        
        // Girar Direita
        else if (currentLine.endsWith("GET /direita")) acao = 3;
        
        // Girar Esquerda
        else if (currentLine.endsWith("GET /esquerda")) acao = 4;
      }
    }
  }

  if (acao == 0) padrao();
  else if (acao == 1) frente();
  else if (acao == 2) tras();
  else if (acao == 3) virar_direita();
  else if (acao == 4) virar_esquerda();
  
}

/////////////////////////////////////////////////////

// Funções
void padrao () {
    //Perna Esquerda da Frente
    servo[0][0].write(45);
    servo[0][1].write(0);
    //Perna Direida da Frente
    servo[1][0].write(135);
    servo[1][1].write(180);
    //Perna Direida Traseira
    servo[2][0].write(45);
    servo[2][1].write(0);
    //Perna Esquerda Traseira
    servo[3][0].write(135);
    servo[3][1].write(180);
    delay(100);
}

/////////////////////////////////////////////////////

void desativar (){
    servo[0][0].write(45);
    servo[1][0].write(135);
    servo[2][0].write(45);
    servo[3][0].write(135);

    for (k = 0; k <= 90; k++){
      servo[0][1].write(k);
      servo[1][1].write(180 - k);
      servo[2][1].write(k);
      servo[3][1].write(180 - k);
      delay(10);
    }
}

/////////////////////////////////////////////////////

void respawn (){
    servo[0][0].write(45);
    servo[1][0].write(135);
    servo[2][0].write(45);
    servo[3][0].write(135);

    for (k = 90; k >= 0; k--){
      servo[0][1].write(k);
      servo[1][1].write(180 - k);
      servo[2][1].write(k);
      servo[3][1].write(180 - k);
      delay(10);
    }
}

/////////////////////////////////////////////////////

void frente(){
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(da);
    }

    // Frente primeiro par
    for (k = 0; k <= 40; k++){
      servo[0][0].write(45 - k);
      servo[2][0].write(45 + k);
      delay(da);
    }

    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(da);
    }
    
    // Sobe segundo par
    for (k = 180; k >= 155; k--){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(dg);
    }
    
    // Reseda primeiro par
    for (k = 0; k <= 40; k++){
      servo[0][0].write(5 + k);
      servo[2][0].write(85 - k);
      delay(da);
    }

    // Frente segundo par
    for (k = 0; k <= 40; k++){
      servo[1][0].write(135 + k);
      servo[3][0].write(135 - k);
      delay(da);
    }
    
    // Desce segundo par
    for (k = 155; k <= 180; k++){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(dg);
    }
    
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(da);
    }
    
    // Reseda segundo par
    for (k = 0; k <= 40; k++){
      servo[1][0].write(175 - k);
      servo[3][0].write(95 + k);
      delay(da);
    }
    
    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(da);
    }
}

/////////////////////////////////////////////////////

void tras(){

  
}

/////////////////////////////////////////////////////

void virar_esquerda (){
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(dg);
    }
    
    // Rodação horario primeiro par
    for (k = 45; k >= 25; k--){
      servo[0][0].write(k);
      servo[2][0].write(k);
      delay(dg);
    }

    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(dg);
    }

    // Sobe segundo par
    for (k = 180; k >= 155; k--){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(dg);
    }

    // Rodação antihorario primeiro par
    for (k = 25; k <= 45; k++){
      servo[0][0].write(k);
      servo[2][0].write(k);
      delay(dg);
    }
    
    // Desce segundo par
    for (k = 155; k <= 180; k++){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(dg);
    }
}

/////////////////////////////////////////////////////

void virar_direita (){
    // Sobe segundo par
    for (k = 180; k >= 155; k--){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(dg);
    }

    // Rodação antihorario segundo par
    for (k = 135; k <= 155; k++){
      servo[1][0].write(k);
      servo[3][0].write(k);
      delay(dg);
    }

    // Desce segundo par
    for (k = 155; k <= 180; k++){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(dg);
    }
  
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(dg);
    }

    // Rodação horario segundo par
    for (k = 155; k >= 135; k--){
      servo[1][0].write(k);
      servo[3][0].write(k);
      delay(dg);
    }
    
    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(dg);
    }
}
