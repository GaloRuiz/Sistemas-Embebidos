/*
 * DEBER 5.1
 * NOMBRE: Galo Ruiz
 */
 
#include <EEPROM.h>
#include <Keypad.h> 
#include <LiquidCrystal.h>


LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte FIL = 4;     // define numero de filas
const byte COL = 4;    // define numero de columnas
char keys[FIL][COL] = {    // define la distribucion de teclas
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FIL] = {13,12,11,10};   
byte pinesColumnas[COL] = {9,8,7,6}; 

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FIL, COL);  

const int sw1 = 4;
char c1;
int bb;
int co = 0;
String pal;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Datos:");
   
}

void loop() {
  c1 = teclado.getKey();
  if(c1){
    if(c1 != '#' && co < 15){
      co++;
      pal +=c1;
      bb = int(c1);
      Serial.println(c1);
      EEPROM.write((co-1),c1);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(String("Caracter: ")+String(co));
      lcd.setCursor(0,1);
      lcd.print(c1);
     
    }
    else{
      Serial.println("Resultado:");
      Serial.println(pal);
      co = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Resultado:");
      pal = " ";
      for(int k=0; k<15; k++){
        lcd.setCursor(k+k,1);
        lcd.print(EEPROM.read(k));         
      }
    }
  }

}
