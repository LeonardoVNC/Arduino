# Introducción
Para dar inicio al curso y poder empezar a trabajar en Arduino, es necesario dar una pequeña introducción, tanto a la Organización del Código como a los códigos más básicos dentro de Arduino. 
## Organización
Arduino puede separarse básicamente en 3 "zonas" de código, no es necesario seguir al pie de la letra como se usan estas zonas, pero es lo recomendado por convención. Estas 3 zonas se dividen según su función de la siguiente manera:
### Declaración 
Esta zona es la primera dentro del código, es decir, empieza en la línea 1. Su función principal es la declaración de variables y la importación de librerias. Estos son conceptos que se llevarán más adelante dentro del curso.
### Setup
Esta zona se identifica por la función ya definida dentro del molde por defecto dentro de cualquier sketch de Arduino, el cual es el siguiente:
```
void setup() {
  // put your setup code here, to run once:

}
```
Tal y como se indica en el texto comentado dentro de la función, este bloque de código se ejecutará una sola vez. Su función principal es establecer la configuración principal del programa, suele ser usado para definir las entradas y salidas de Arduino (seleccionando los pines como INPUT o como OUTPUT), usar las funciones de configuración inicial de cualquier librería externa o simplemente dar una bienvenida al programa.
### Loop
Esta zona se identifica por la función ya definida dentro del molde por defecto dentro de cualquier sketch de Arduino:
```
void loop() {
  // put your main code here, to run repeatedly:

}
```
Al igual que con la función `void setup()`, el sketch por defecto de Arduino incluirá un texto comentado que indica el uso de esta función, el cual dice que el código de esa función se ejecutará repetidamente. Esta función es, en la gran mayoría de ocaciones, el cuerpo principal del programa Arduino, pues suele usarse para colocar el código principal, el cual se ejecutará siempre que el Arduino reciba la alimentación necesaria.
## Introducción al Código
Arduino está hecho en base a C, es por esto que tienen una estructura similar y se comparten ciertas funciones, un ejemplo de similitudes entre Arduino y C se encuentra en la declaración de variables.
### Variables
Las variables son "Casillas de Memoria" en donde se guardarán los valores que necesitemos, estas hallan su utilidad cuando debemos acceder a valores que varian a lo largo del transcurso del programa, o cuando debemos usar cierto valor repetidas veces y no se quiere escribir el valor específico cada vez que se lo utiliza (Además que ayuda a cambiar todas las repeticiones de ese valor con solo cambiar la asignación de la variable).

Para declarar una variable en Arduino debemos seguir una sencilla serie de pasos. En primer lugar, nos ubicaremos en la zona de [Declaración](#declaración) para mantener el orden dentro de nuestro programa. A continuación definimos el tipo de dato que emplearemos. Para terminar, elegimos un nombre para nuestra variable. Dentro de esta línea es opcional asignarle un valor a la variable. Un ejemplo se muestra a continuación:
```
int variable = 15;
```
Cabe recalcar que la declaración de constantes es igual a la declaración de variables, con la única diferencia de que se añade `const` al inicio de la línea:
```
const int constante = 16;
```
### Funciones básicas
Arduino posee algunas funciones que son básicas para cualquier programa que desee realizarse, obviamente no todos los programas las emplean, pero suelen ser bastante utilizadas, algunas de estas funciones son:
* **pinMode**

  Es una función que suele usarse en el [Setup](#setup). Su utilidad en el programa radica en definir las entradas y salidas de la placa Arduino. Para esto sigue la siguiente estructura:
  ```
  pinMode(pin, modo);
  ```
  Donde: 
  - *pin* se refiere al pin de la placa Arduino (los cuales se enumeran de 0 a 13 para los pines digitales y desde A0 a A5 para los pines analógicos, ambos en el caso de Arduino UNO).
  - *modo* se refiere al modo que tomará el pin, pudiendo ser una Entrada (INPUT) o una Salida (OUTPUT).
* **delay**
  
  Tiene la función de detener el flujo de código por cierta cantidad de milisegundos. Sigue la siguiente estructura:
  ```
  delay(millis);
  ```
  Donde:
  - *millis* se refiere a la cantidad de milisegundos que se detendrá el programa.
* **Serial.begin**

  Esta es una función que inicializa el puerto serial y sirve para comenzar con todas las funciones que tiene la clase Serial. El puerto serial se verá en profundidad más adelante en el curso. 
* **Serial.println y Serial.print**

  Estas son funciones que dependen del puerto serial, por lo que deben ejecutarse despues de un `Serial.begin`, su uso es imprimir información en el monitor serial, el cual también se verá a detalle más adelante en el curso.
* **digitalWrite**

  Es una función que establece un pin de salida como 1 ó 0, es decir, si envía voltaje o no. Sigue la siguiente estructura: 
  ```
  digitalWrite(pin, modo);
  ```
  Donde:
  - *pin* se refiere a uno de los pines de la placa Arduino.
  - *modo* se refiere al modo que tomará la salida, siendo HIGH para un 1 o LOW para un 0.

Con esto termina la introducción a Arduino. Además se ha añadido un pequeño programa que muestra un poco de los conceptos que se han establecido hasta el momento.

Las conexiones empleadas para el [Programa](primerSketch) son las siguientes:
<div id="PrimerPrograma">
  <ul align="center">
    <img alt="JPG" src="https://i.ibb.co/zrLpbhm/Primer-Programa.jpg">
    </ul>
</div>