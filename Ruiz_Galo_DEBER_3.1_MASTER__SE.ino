/*
 * DEBER 3.1: MODULOS DE COMUNICACION I2C
   Nombre: Galo Ruiz
 * /////////////MASTER/////////////
 */
#include <Wire.h>      //Inicia la libreria
char dato;
void setup() {
  Wire.begin();          //Inicia el hardware  
  Serial.begin(9600);
}

void loop() {
 
    
if(Serial.available()>0){  //verifica que existe datos
    dato=Serial.read();      //Almacena el dato en la variable  
    Wire.beginTransmission(3); //Empieza la comunicacion I2C
    Wire.write(dato);          //Envio dato
    Wire.endTransmission();   //termina la transmision I2C
  } 

}
