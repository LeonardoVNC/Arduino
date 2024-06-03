char entrada;        //Definimos una variable char para la lectura del monitor serial
int entradaInt;      //Definimos una variable int para almacenar el valor numerico de la entrada
const int led = 2;   //Definimos una constante led y le asignamos el valor 2
const int ms = 500;  //Definimos una constante ms y le asignamos el valor 500

void setup() {
  Serial.begin(9600);                       //Inicializamos el monitor serial en 9600 bauds
  pinMode(led, OUTPUT);                     //Se establece el pin led como una salida
  Serial.println("\nInicio del programa");  //Se indica que el programa ya inició y recibe entradas
}

void loop() {
  if (Serial.available() > 0) {              //Si el monitor serial tiene por lo menos un caractér para leer...
    entrada = Serial.read();                 //Se almacena el caractér en la variable char entrada
    if (entrada >= '1' && entrada <= '9') {  //Si esta entrada es un número entre el 1 y el 9...
      entradaInt = String(entrada).toInt();  //Se castea de char a int
      for (int i = 0; i < entradaInt; i++) {
        digitalWrite(led, HIGH);  //Se prenderá y apagará el led definido
        delay(ms);                //en interválos de ms milisegundos+
        digitalWrite(led, LOW);
        delay(ms);
      }
    }
  }
}

