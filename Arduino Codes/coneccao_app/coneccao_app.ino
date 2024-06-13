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

void setup() {
  // Iniciar Serial
  Serial.begin(115200);

  // Configurações WiFi
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("QuadBot","12345678");
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

        // 
        if (currentLine.endsWith("GET /")) ;
        
        // 
        else if (currentLine.endsWith("GET /")) ;

        // 
        else if (currentLine.endsWith("GET /")) ;
        
        // 
        else if (currentLine.endsWith("GET /")) ;
        
        // 
        else if (currentLine.endsWith("GET /")) ;
      }
    }
  }
}
