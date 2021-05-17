/*
 * DEBER 3.1: MODULOS DE COMUNICACION I2C
 * Nombre: Galo Ruiz
 * /////////////ESCLAVO3/////////////
 * Para que encienda los leds que estan conectados al esclavo3,ingrese la letra 'C' caso contrario no van encenderse
 */


#include <Wire.h>
char dato;
 const int led1=8;
 const int led2=9;
 const int led3=10;
 
void setup() {
 Wire.begin(3);           //id del esclavo
 Wire.onReceive(receiveEvent);  //Registra una funcion de callback al recibir un dato
 Serial.begin(9600);
 pinMode(led1,OUTPUT); //pin8 como salida
 pinMode(led2,OUTPUT); //pin9 como salida
 pinMode(led3,OUTPUT); //pin10 como salida
 
  

}

void loop() {
  
  }

 void receiveEvent(int bytes){
while(Wire.available()){    // Detecta si hay un dato pendiente para ser leido
    dato=Wire.read();       //Recibe un byte
    while(dato=='C'){       //Permite encender los leds que estan conectados al esclavo 1,va cumplir cuando se ingresa la letra 'C'
  digitalWrite(led3,HIGH);  //Enciende el led3
      delay(40000);
      digitalWrite(led2,HIGH); //Enciende el led2
      delay(40000);
      digitalWrite(led1,HIGH); //Enciende el led1
      delay(40000);
      digitalWrite(led3,LOW);  //Apaga el led3
      digitalWrite(led2,LOW);  //Apaga el led2
      digitalWrite(led1,LOW);  //Apaga el led1
      delay(40000);

  }
  }
  
  }
 
  
  
 
  



   
 
