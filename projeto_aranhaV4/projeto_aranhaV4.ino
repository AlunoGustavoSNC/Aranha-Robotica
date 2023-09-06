/*
  SIGLAS:

  C = motores de cima;
  B = motores de baixo;
*/

#include <VarSpeedServo.h>

//DEFINICÕES

#define C1 4
#define B1 5

#define C2 6
#define B2 7

#define C3 8
#define B3 9

#define C4 10
#define B4 11

#define sentado 101

//MOTORES

VarSpeedServo servoC1;
VarSpeedServo servoC2;
VarSpeedServo servoC3;
VarSpeedServo servoC4;

VarSpeedServo servoB1;
VarSpeedServo servoB2;
VarSpeedServo servoB3;
VarSpeedServo servoB4;

//VARIAVEIS

int velocidade = 250;
int varDelay = 120;

int varCima = 90;
int varBaixo = 110;

int varPosition = 90;
int varDelayPadrao = 500;

int movimentoAtual = 0;

void setup() {

  //PINOS DOS CERVOS

  servoB1.attach(B1);
  servoB2.attach(B2);
  servoB3.attach(B3);
  servoB4.attach(B4);

  servoC1.attach(C1);
  servoC2.attach(C2);
  servoC3.attach(C3);
  servoC4.attach(C4);

  //SERIAL

  Serial.begin(9600);

  //FUNCOES

  padrao();

  //testeMotoresC();
  //testeMotoresB();

  //acenar();
  //sentar();
  //palmas();
  //levantar();

}

void padrao(){

  servoB1.write(varBaixo);
  servoB2.write(varBaixo);
  servoB3.write(varBaixo);
  servoB4.write(varBaixo);

  delay(varDelayPadrao);

  servoC1.write(varPosition);
  servoC2.write(varPosition);
  servoC3.write(varPosition);
  servoC4.write(varPosition);

  delay(varDelayPadrao);

  movimentoAtual = 0;
}

void testeMotoresC(){

  servoC1.write(180);
  servoC2.write(180);
  servoC3.write(180);
  servoC4.write(180);

  delay(varDelayPadrao);

  servoC1.write(0);
  servoC2.write(0);
  servoC3.write(0);
  servoC4.write(0);

  delay(varDelayPadrao);

  padrao();
}

void testeMotoresB(){

  delay(varDelayPadrao);

  servoB1.write(180);
  servoB2.write(180);
  servoB3.write(180);
  servoB4.write(180);

  delay(varDelayPadrao);

  servoB1.write(0);
  servoB2.write(0);
  servoB3.write(0);
  servoB4.write(0);

  delay(varDelayPadrao);

  padrao();
}

void acenar(){
  padrao();

  servoC2.write(varPosition + 20);
  servoC3.write(varPosition - 20);

  delay(varDelayPadrao);

  servoB2.write(150);
  servoB3.write(150);

  delay(varDelayPadrao);

  for(int i = 0; i < 4; i++){
    servoB1.write(varPosition);
    servoC1.slowmove(varPosition + 30, 200);
    delay(300);
    servoC1.slowmove(varPosition - 30, 200);
    delay(300);
  }

  padrao();

}

void sentar(){
  if(movimentoAtual != sentado){
  servoC4.write(varPosition + 90);
  servoC3.write(varPosition - 90);

  delay(varDelayPadrao - 100);

  servoB1.write(varPosition + 90);
  servoB2.write(varPosition + 90);

  delay(varDelayPadrao - 100);

  servoB1.write(varPosition);
  servoB2.write(varPosition);

  movimentoAtual = sentado;
  }
}

void palmas(){
  sentar();

  for(int i = 0; i < 4; i++){
    servoC1.slowmove( varPosition - 90, 200);
    servoC2.slowmove( varPosition + 90, 200);
    delay(300);
    servoC1.slowmove( varPosition - 60, 200);
    servoC2.slowmove( varPosition + 60, 200);
    delay(300);    
  }

  servoC1.write(varPosition);
  servoC2.write(varPosition);
}

void levantar(){
  servoC4.slowmove(varPosition, 150);
  delay(300);
  servoC3.slowmove(varPosition, 150);

  padrao();
}

void andarC1(){
  servoB1.slowmove(varBaixo - 30, 155);
  servoC1.slowmove(varPosition -60, 155);
  delay(500);
  servoC2.slowmove(varPosition -40, 100);
  servoC3.slowmove(varPosition +40, 100);
  servoC4.slowmove(varPosition -40, 100);
  delay(300);
  padrao();
} 

void loop() {

  //BLUETOOTH

  while(Serial.available()){
    char botao = Serial.read();
    Serial.print("Serial lido: ");
    Serial.println(botao);

    //FUNÇÕES

    switch (botao){
        case 'A' :
        padrao();
        break;

        case 'B' :
        sentar();
        break;

        case 'C' :
        palmas();
        break;

        case 'D' :
        levantar();
        break;

        case 'E' :
        acenar();
        break;

        case 'F' :
        testeMotoresC();
        testeMotoresB();
        break;

        case 'G' :
        andarC1();
        break;

        default :
        padrao();
    }
  }

}