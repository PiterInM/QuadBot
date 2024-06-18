// Configuração Controle Laser
#define laserPin 23
#define freqLedC 1000 
#define laserChannel 1 
#define resolution 8

void setup() {
  // Setup Laser
  ledcSetup(laserChannel, freqLedC, resolution);
  ledcAttachPin(laserPin, laserChannel);
}

void loop() {
  ledcWrite(laserChannel, 10);
  delay(800);
  ledcWrite(laserChannel, 255);
  delay(800);
}
