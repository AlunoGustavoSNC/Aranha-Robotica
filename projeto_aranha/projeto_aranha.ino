/*
  SIGLAS:

  C = motores de cima;
  B = motores de baixo;
*/

#include <VarSpeedServo.h>

//DEFINICÕES

#define C1 0
#define B1 1

#define C2 2
#define B2 3

#define C3 4
#define B3 5

#define C4 6
#define B4 7

//MOTORES

VarSpeedServo servoC1;
VarSpeedServo servoC2;
VarSpeedServo servoC3;
VarSpeedServo servoC4;

VarSpeedServo servoB1;
VarSpeedServo servoB2;
VarSpeedServo servoB3;
VarSpeedServo servoB4;
  

//VARIÁVEIS

int velocidade = 250;
int varDelay = 120;

int varCima = 170;
int varBaixo = 180;

int varPosition = 90;

void setup() {

  //PINOS DOS CERVOS

  servoB1.attach(B1);
  servoB2.attach(B2);
  servoB3.attach(B3);
  servoB4.attach(B4);

  servoB1.write(180);
  servoB2.write(180);
  servoB3.write(180);
  servoB4.write(180);

  servoC1.attach(C1);
  servoC2.attach(C2);
  servoC3.attach(C3);
  servoC4.attach(C4);

  servoC1.write(0);
  servoC2.write(0);
  servoC3.write(0);
  servoC4.write(0);

  delay(300);

  servoC1.write(180);
  servoC2.write(180);
  servoC3.write(180);
  servoC4.write(180);

  delay(700);

  servoC1.write(90);
  servoC2.write(90);
  servoC3.write(90);
  servoC4.write(90);

  delay(300);

  B1cima();
  B2cima();
  B3cima();
  B4cima();
}

//SERVO C1

void C1frente(){
  //QUANTO MENOR, MAIS PARA FRENTE VAI
  servoC1.slowmove(varPosition - 30, velocidade);
  delay(varDelay);
}

void C1atras(){
  //QUANTO MAIOR, MAIS PARA TRÁS VAI
  servoC1.slowmove(varPosition + 40, velocidade);
  delay(varDelay);
}

//SERVO C2

void C2frente(){
  //QUANTO MAIOR, MAIS PARA FRENTE
  servoC2.slowmove(varPosition + 30, velocidade);
  delay(varDelay);
}

void C2atras(){
  //QUANTO MENOR, MAIS PARA TRÁS
  servoC2.slowmove(varPosition - 30, velocidade);
  delay(varDelay);
}

//SERVO C3

void C3frente(){
  // QUANTO MENOR, MAIS PARA FRENTE
  servoC3.slowmove(varPosition - 40, velocidade);
  delay(varDelay);
}

void C3atras(){
  // QUANTO MAIOR, MAIS PARA TRÁS  
  servoC3.slowmove(varPosition + 20, velocidade);
  delay(varDelay);
}

//SERVO C4

void C4frente(){
  // QUANTO MAIOR, MAIS PARA FRENTE
  servoC4.slowmove(varPosition + 40, velocidade);
  delay(varDelay);
}

void C4atras(){
  // QUANTO MENOR, MAIS PARA TRÁS
  servoC4.slowmove(varPosition - 30, velocidade);
  delay(varDelay);
}

//SERVO B1{

void B1cima(){
  servoB1.slowmove(varCima, velocidade);
  delay(varDelay);
}

void B1baixo(){
  servoB1.slowmove(varBaixo, velocidade);
  delay(varDelay);
}

//SERVO B2{

void B2cima(){
  servoB2.slowmove(varCima, velocidade);
  delay(varDelay);
}

void B2baixo(){
  servoB2.slowmove(varBaixo, velocidade);
  delay(varDelay);
}

//SERVO B3{

void B3cima(){
  servoB3.slowmove(varCima, velocidade);
  delay(varDelay);
}

void B3baixo(){
  servoB3.slowmove(varBaixo, velocidade);
  delay(varDelay);
}

//SERVO B4{

void B4cima(){
  servoB4.slowmove(varCima, velocidade);
  delay(varDelay);
}

void B4baixo(){
  servoB4.slowmove(varBaixo, velocidade);
  delay(varDelay);
}

void loop() {

  B1baixo();
  C1atras();
  B1cima();

  B3baixo();
  C3atras();
  B3cima();

  B2baixo();
  C2atras();
  B2cima();

  B4baixo();
  C4atras();
  B4cima();

  B1cima();
  C1frente();
  B1baixo();

  B3cima();
  C3frente();
  B3baixo();

  B2cima();
  C2frente();
  B2baixo();

  B4cima();
  C4frente();
  B4baixo();

  /*C1atras();
  C1frente();
  C3frente();    
  C3atras();

  C2atras();
  C2frente();
  C4frente();    
  C4atras();*/

  /*C1atras();
  C4atras();
  C1frente();
  C4frente();

  C2atras();
  C3atras();
  C2frente();
  C3frente();*/
}