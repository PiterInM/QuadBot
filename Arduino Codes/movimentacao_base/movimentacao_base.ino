// Biblioteca Servo Esp32
#include <ESP32_Servo.h>

// Definir os pinos
Servo servo[4][2];
const int servo_pin[4][2] = { {25, 33},  //fe
                              {19, 21},  //fd
                              {18,  5},  //td
                              {26, 27},};//te

                            //Quadril\Coxa
#define tg 5  //delay giro
#define ta 5  //delay andar

int k;

void padrao();
void frente();
void tras();
void virar_esquerda();
void virar_direita();
void morte();
void respawn();

void setup() {
  // Configurações Servos
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      servo[i][j].attach(servo_pin[i][j]);
      delay(100);
    }
  }
    padrao();
}

void loop() {

    frente();
    padrao();
    
}




void padrao () {
    //Perna Esquerda da Frente
    servo[0][0].write(45);
    servo[0][1].write(0);
    //Perna Direita da Frente
    servo[1][0].write(135);
    servo[1][1].write(180);
    //Perna Direita Traseira
    servo[2][0].write(45);
    servo[2][1].write(0);
    //Perna Esquerda Traseira
    servo[3][0].write(135);
    servo[3][1].write(180);
    delay(100);
}

void morte (){
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

void frente(){
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(ta);
    }

    // Frente primeiro par
    for (k = 0; k <= 40; k++){
      servo[0][0].write(45 - k);
      servo[2][0].write(45 + k);
      delay(ta);
    }

    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(ta);
    }
    
    // Sobe segundo par
    for (k = 180; k >= 155; k--){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(tg);
    }
    
    // Reseta primeiro par
    for (k = 0; k <= 40; k++){
      servo[0][0].write(5 + k);
      servo[2][0].write(85 - k);
      delay(ta);
    }

    // Frente segundo par
    for (k = 0; k <= 40; k++){
      servo[1][0].write(135 + k);
      servo[3][0].write(135 - k);
      delay(ta);
    }
    
    // Desce segundo par
    for (k = 155; k <= 180; k++){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(tg);
    }
    
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(ta);
    }
    
    // Reseta segundo par
    for (k = 0; k <= 40; k++){
      servo[1][0].write(175 - k);
      servo[3][0].write(95 + k);
      delay(ta);
    }
    
    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(ta);
    }
}

void tras(){

  
}

void virar_esquerda (){

    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(tg);
    }
    
    // Rotação horario primeiro par
    for (k = 45; k >= 25; k--){
      servo[0][0].write(k);
      servo[2][0].write(k);
      delay(tg);
    }

    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(tg);
    }

    // Sobe segundo par
    for (k = 180; k >= 155; k--){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(tg);
    }

    // Rotação antihorario primeiro par
    for (k = 25; k <= 45; k++){
      servo[0][0].write(k);
      servo[2][0].write(k);
      delay(tg);
    }
    
    // Desce segundo par
    for (k = 155; k <= 180; k++){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(tg);
    }
}
void virar_direita (){

    // Sobe segundo par
    for (k = 180; k >= 155; k--){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(tg);
    }

    // Rotação antihorario segundo par
    for (k = 135; k <= 155; k++){
      servo[1][0].write(k);
      servo[3][0].write(k);
      delay(tg);
    }

    // Desce segundo par
    for (k = 155; k <= 180; k++){
      servo[1][1].write(k);
      servo[3][1].write(k);
      delay(tg);
    }
  
    // Sobe primeiro par
    for (k = 0; k <= 25; k++){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(tg);
    }

    // Rotação horario segundo par
    for (k = 155; k >= 135; k--){
      servo[1][0].write(k);
      servo[3][0].write(k);
      delay(tg);
    }
    
    // Desce primeiro par
    for (k = 25; k >= 0; k--){
      servo[0][1].write(k);
      servo[2][1].write(k);
      delay(tg);
    }
}



      /*//Perna Esquerda da Frente
      servo[0][0].write(20);
      servo[0][1].write(105);
      delay(100);

      //Perna Direita da Frente
      servo[1][0].write(160);
      servo[1][1].write(75);
      delay(100);

      //Perna Direita Traseira
      servo[2][0].write(20);
      servo[2][1].write(105);
      delay(100);

      //Perna Esquerda Traseira
      servo[3][0].write(160);
      servo[3][1].write(75);
      delay(100);*/
