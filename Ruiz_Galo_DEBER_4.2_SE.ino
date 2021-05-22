/*
 * DEBER 4.2
 * DESCRIPCION: Realizar la modificación correspondiente en el código 16 que se utilizó en clase, para que al iniciar el sistema solicite el número de veces a jugar 
 * y se comience a ejecutar de forma normal desde el inicio. 
 * Nombre:Galo Ruiz
 */


const int leds[6]={13,12,11,10,9,8};
int on=0;     //int0
int cont;     //int1
int i;        //variable de conteo
int j=0;      //variable de conteo

void setup() {
  for(i=0;i<6;i++){           //configuracion de los leds
    pinMode(leds[i],OUTPUT);  
  }
  i=0;
  Serial.begin(9600);         //activacion de la comunicacion serial
  attachInterrupt(0,activacion,LOW); //interrupt 0 habilitada
  attachInterrupt(1,contador,LOW);
}

void loop() {
  if(on==2){
    for(;i<cont;i++){
      for(j=0;j<6;j++){
        digitalWrite(leds[j],HIGH);
        delay(200);
        digitalWrite(leds[j],LOW);
        delay(200);
      }
    }
  }
}

void activacion(){
  switch(on){
    case 0:
    Serial.println("Ingrese el numero de veces a jugar");
    
    on++;
    break;
    case 1:
    on++;
    break;
    case 2:
    on++;
    cont=0;
    on=0;
    i=0;
    
    
  }
 
}

void contador(){
  if(on==1){
    cont++;
    Serial.println(String("Juega ")+String(cont)+String(" veces"));
    
  }
}
