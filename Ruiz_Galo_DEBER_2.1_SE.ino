/*
 *DEBER 2.1: Puertos como salida
 *Nombre: Galo Ruiz
 *
 */

 //variable que representan los leds
const int led1 =7;    // led1
const int led2 = 8;  //led2 
const int led3 = 9;  // led3
const int led4 = 10; // led4
  


void setup() {

  pinMode(led1,OUTPUT); //declara el pin 7 como salida
  pinMode(led2,OUTPUT); //declara el pin 8 como salida
  pinMode(led3,OUTPUT); //declara el pin 9 como salida
  pinMode(led4,OUTPUT); //declara el pin 10 como salida
}

void loop() {
  digitalWrite(led1,HIGH); //Envia 5V al pin 7
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led1,LOW);  //Envía 0V al pin 7
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led2,HIGH); //Envia 5V al pin 8
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led2,LOW);  //Envía 0V al pin 8
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led3,HIGH); //Envia 5V al pin 9
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led3,LOW);  //Envía 0V al pin 9
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led4,HIGH); //Envia 5V al pin 10
  delay(500);              //Se detiene el microcontrolador por medio segundo
  digitalWrite(led4,LOW);  //Envía 0V al pin 10
  delay(500);              //Se detiene el microcontrolador por medio segundo
  
  
}
