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
### Variables
### Funciones básicas