/*
 * DEBER 5.2: Codigo 23
 * Nombre: Galo Ruiz
 * Descripción: Se modifico en la parte del void tiempo() 
 * borrando la accion sleep_mode()  y en void loop() se utilizo condicional while cuando solo se cumple 
 * esa condicion da ventaja para las acciones del switch debido que al utilizar otras condicionales va aparecer un ciclo con el mensaje "Despierto" 
 * el while va evitar eso y el sleep_mode() para ambas acciones del boton y permite cambiar el mensaje al encender y apagar el switch
 * 
 */


#include<avr/power.h>    
#include<avr/sleep.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include<EEPROM.h>
int dato;

void(* resetFunc) (void) = 0; 
//void on(void);
void setup() {
   dato=EEPROM.read(0);
   Serial.begin(9600);
   Serial.println("SETUP");
   if(dato==0){
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0,1);
    wdt_enable(WDTO_8S);
    }
    else{
    sleep_disable();
     EEPROM.write(0,0);
      MsTimer2::set(10000,tiempo); // configura timer 2 a un segundo
       MsTimer2::start();
    }
   attachInterrupt(0,encender,LOW);
}
void loop() {
while(dato==0){   //Condicional while cuando esta apagado el switch
  Serial.println("DORMIDO"); //Mensaje
  delay(20);          //Retardo del mensaje
  sleep_mode();  
}
 while (dato==1){ //Condicional while cuando esta encendido el switch
  Serial.println("DESPIERTO"); //Mensaje
  delay(1000);                 //Retardo del mensaje
  sleep_mode(); 
  }
}
void tiempo(){

  Serial.println("DORMIDO"); //Mensaje que aparece cuando esta apagado el switch en el momento de simular  
  delay(2000);                 //Retardo del mensaje
 }
 
 void encender (){
    resetFunc();  
 }
 
