/*
 * Reto 3
 * Nombre: Galo Ruiz
 * 
 */


#define boton 2
boolean b = false;

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
}

void loop() {
  if (digitalRead(boton) == LOW && b == false) {
    Serial.println("HIGH");
    b = true;
  }
  else if (digitalRead(boton) == HIGH && b == true){
    Serial.println("LOW");
    b = false;
  }
  delay(5);

}
