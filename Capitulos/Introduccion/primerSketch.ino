const int led = 2;          //Definimos la constante led y le asignamos el valor 2
const int ms = 500;         //Definimos la constante ms y le asignamos el valor 500

void setup() {
  pinMode(led, OUTPUT);     //Definimos el pin de la variable led como una Salida
}

void loop() {
  digitalWrite(led,HIGH);   //El pin de la variable led envía voltaje
  delay(ms);                //El programa se detiene ms milisegundos
  digitalWrite(led,LOW);    //El pin de la variable led deja de enviar voltaje
  delay(ms);                //El programa se detiene ms milisegundos
} 
