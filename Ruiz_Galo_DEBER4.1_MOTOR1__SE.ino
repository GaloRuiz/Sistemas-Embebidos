/*
 * DEBER 4.1: CAD y PWM
 * Nombre: Galo Ruiz
 * Programacion del motor 1 va encender mediante un boton, obtener los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor.
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,5,4,3,2);  //Seleccion de pines para la LCD
int conversor;                      //variable para adquirir datos del conversor entre 0-1023
float voltaje;                      //variable de conversion de conversor a voltaje
int dutty;                          //variable para el uso de pwm  

const int sw1=6;

void setup() {
  lcd.begin(16,2); 
  pinMode(sw1,INPUT);
}

void loop() {
  if(digitalRead(sw1)==LOW){
   conversor=analogRead(16);         //lectura del canal A0-0-14
  voltaje=(conversor*5.0)/1023.0;   //conversor de voltaje
  dutty=conversor/4;                //cambio la escala para el dutty cicle
  analogWrite(10,dutty);            //envio de valor al pin 11
  lcd.setCursor(0,0);
  lcd.print("CAD:");
  lcd.setCursor(5,0);
  lcd.print(conversor);
  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PWM:");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(300);
  lcd.clear();

  

}

}
