/*
   DEBER 5.4: FUNCIONES RTOS
   NOMBRE: Galo Ruiz
*/

#include <Arduino_FreeRTOS.h> // librería de RTOS

//definir los pines de los leds del semaforo
#define rojo 11
#define amarillo 10
#define verde 9

//objeto del gestor tareas
typedef int TaskProfiler;

//definir las tareas
TaskProfiler rojoLEDProfiler;
TaskProfiler amariLEDProfiler;
TaskProfiler verdeLEDProfiler;

TaskHandle_t red_Handle, yellow_Handle, green_Handle; // manejar la prioridad

//contadores para el semaforo
int contRojo = 0;
int contAmarillo = 0;
int contVerde = 0;

void setup() {
  Serial.begin(9600);

  xTaskCreate(redLedControllerTask, "Red LED Task", 100, NULL, 1, &red_Handle); //rutina,nombre,memoria,NULL,prioridad,Manejo de prioridad
  xTaskCreate(yellowLedControllerTask, "Yellow LED Task", 100, NULL, 1, &yellow_Handle); //rutina,nombre,memoria,NULL,prioridad,NULL
  xTaskCreate(greenLedControllerTask, "Green LED Task", 100, NULL, 1, &green_Handle);
}


void redLedControllerTask(void *pvParameters) { //primera tarea
  pinMode(rojo, OUTPUT);    //pin rojo va ser salida
  while (1) {               //cilcio while
    contRojo++;                //contador 
    Serial.println(contRojo);
    if ((contRojo > 0) && (contRojo <= 10)) { //si contadorR esta entre 0 - 10 seg ejecuta:
      digitalWrite(rojo, HIGH);         //enciende led rojo
      digitalWrite(verde, LOW);         //apaga led verde
      vTaskSuspend(yellow_Handle);      //suspende la tarea yellow
      vTaskSuspend(green_Handle);       //suspende la tarea green
    }
    else if ((contRojo > 11) && (contRojo <= 12)) {     //si contadorRojo esta entre 11 - 12 seg ejecuta:
      vTaskResume(yellow_Handle);                 //reanuda tarea yellow
      //vTaskSuspend(green_Handle);
    }
    else if ((contRojo > 13) && (contRojo <= 22)) {     //si contadorRojo esta entre 13 - 22 seg ejecuta:
      vTaskResume(green_Handle);                  //reanuda tarea green
      vTaskSuspend(yellow_Handle);                //suspende tarea yellow
    }
    else if ((contRojo > 23) && (contRojo <= 24)) {     //si contadorRojo esta entre 23 - 24 seg ejecuta:
      vTaskResume(yellow_Handle);                 //reanuda tarea yellow
      //vTaskSuspend(green_Handle);
    }
    else if (contRojo == 25) {                       //si contadorR es igual a 25 seg ejecuta:
      contRojo = 0;                                  //contadorR es igual a cero
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);        //deley en 1s
  }
}


void yellowLedControllerTask(void *pvParameters) { //segunda tarea
  pinMode(amarillo, OUTPUT);               //establecer el pin amarillo ver ser salida
  while (1) {                           //ciclo while
    
    contAmarillo++;                            //contador 
    Serial.println(contAmarillo);
    digitalWrite(amarillo, digitalRead(amarillo) ^ 1);    //enciende el led amarillo
    digitalWrite(rojo, LOW);                        //apaga led rojo
    digitalWrite(verde, LOW);                       //apaga led verde

    vTaskDelay(200 / portTICK_PERIOD_MS);           //tiempo de retardo
  }
}


void greenLedControllerTask(void *pvParameters) { //tercera tarea
  pinMode(verde, OUTPUT);                     //pin del led rojo de salida
  while (1) {                                 //ciclo while
    contVerde++;                                  //contador
    Serial.println(contVerde);
    digitalWrite(verde, HIGH);                //enciende led verde
    digitalWrite(rojo, LOW);                  //apaga led rojo
    digitalWrite(amarillo, LOW);                 //apaga led amarillo

    vTaskDelay(1000 / portTICK_PERIOD_MS);    //velocidad de retardo
  }
}


void loop() {
  
}
