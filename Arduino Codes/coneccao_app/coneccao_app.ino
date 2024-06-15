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

// Funções
