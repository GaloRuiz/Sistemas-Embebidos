/*
 * Deber 4.3
 * Descripcion: Realizar la modificación correspondiente en el código 18 que se utilizó en clase, trabajando con una LCD 20x4, en donde en la primera fila se observe un mensaje de bienvenida,  
en la segunda línea se visualice su nombre y apellido, en la tercera línea se observe:
"Horas : minutos : segundos"; y en la última fila se visualice los valores asignados a las variables del timer2, centradas.  
 * Nombre: Galo Ruiz
 */


#include <MsTimer2.h>  //libreria Timer
#include <LiquidCrystal.h> //libreria LCD
LiquidCrystal lcd(13,12,11,10,9,8); //objeto para la libreria LCD

int ss=0;   //variable de segundos
int mm=0;    //variable de minutos
int hh=0;      //variable de horas


void setup() {
lcd.begin(20,4); //inicia la lcd
MsTimer2::set(1000,reloj); //configura el timer 2 a 1 segundo
MsTimer2::start();
}

void loop() {
  

}
void reloj(){
  if(ss<60){
    ss++;
  }
  else{
    ss=0;
    if(mm<60){  //Condicion de minutos
      mm++;     //Incrementa la variable
    }else{
    mm=0;
    if(hh<24){    //Condicion de horas
      hh++;       //Incrementa la variable
    }else{
      hh=0;
    }
  }
}
lcd.clear(); //Borrar el anterior mensaje
lcd.setCursor(0,0); //ubicacion lcd
lcd.print(String(" Bienvenidos a todos "));//Mensaje de Bienvenida

lcd.setCursor(4,1); //ubicacion lcd
lcd.print(String(" Galo ")+String(" Ruiz ")); //Nombre y Apellido

lcd.setCursor(6,2); //ubicacion lcd
lcd.print(String(hh)+String(" : ")+String(mm)+String(" : ")+String(ss)); //Reloj digital

lcd.setCursor(4,3); //ubicacion lcd
lcd.print(String(" hh ")+String(" mm ")+String(" ss ")); //Variables del reloj

}
