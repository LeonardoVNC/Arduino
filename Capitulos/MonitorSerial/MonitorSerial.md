 # Monitor Serial
El monitor serial es un puerto de comunicación entre el usuario y la placa Arduino, permite enviar y recibir información durante la ejecución del programa.

## Inicialización
Para usar el monitor serial es necesario inicializar el puerto serial. Este se inicializa con el siguiente comando dentro del bloque `setup`:

```
void setup(){
    Serial.begin(9600);
}
```
Este comando inicializa el puerto serial en 9600 bauds, es decir, la velocidad de comunicación estandar para Arduino. Es importante destacar que Arduino puede soportar otras velocidades, pero 9600 es el estándar y la velocidad que suele usarse.
## Salida de datos
Arduino puede imprimir la información que le pidamos a traves del monitor serial, esto a través de los comandos `Serial.print();` y `Serial.println();`, los cuales son bastante similares al resto de comandos de impresion de otros lenguajes de programación, es decir, basta con introducir texto entre comillas dentro de los parentesis para imprimir el mensaje deseado, además, podemos colocar variables dentro de los parentesis para que se imprima su valor y se puede usar `\n` para hacer un salto de línea:
```
int n = 0;
void setup(){
    Serial.begin(9600);
    Serial.println("\nHola");
}
void loop() {
    Serial.print("Contador: ");
    Serial.println(n);
    n++;
}
```
## Entrada de datos
Es posible enviar datos desde el monitor serial hasta la placa Arduino. Para esto se usa el comando `Serial.read();` el cual suele estar acompañado de una variable char para guardar la entrada y poder procesarla sin perder su valor luego de su primer uso, a continuación un ejemplo de su uso:
```
char input;
void setup() {
  Serial.begin(9600);
}
void loop() {
  input = Serial.read();
  Serial.print("La entrada es: ");
  Serial.println(input);
  delay(1000);
}
```
`Serial.read();` leera los datos caractér por caractér, sobre-escribiendo al valor anterior con cada llamada al método que se ejecute. 

En caso de no existir un dato a leer en el Monitor Serial, el char se sobre-escribira con "�". Es decir, por defecto `Serial.read();` no esperará a que introduzcamos un dato para seguir con el flujo del programa, se debe tener cuidado con esto. Para evitar este problema se puede hacer uso de la función `Serial.available();`, la cual devuelve un valor int que indica cuantos caractéres tiene a continuación el monitor serial, por lo que podemos usar un if para confirmar la entrada de datos y asi no sobreescribir la variable de no ser necesario:
```
char input;
void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();
    Serial.print("La entrada es: ");
    Serial.println(input);
    delay(1000);
  }
}

```
De modo que si hay 1 o más caractéres disponibles para leer se sobreescribirá la información alojada en la variable input, caso contrario, se ignorará el bloque de código.


Con esto termina este capítulo. Al igual que con el capítulo anterior, se ha añadido un pequeño programa que muestra un poco de los conceptos presentados en este documento.

Las conexiones empleadas para el [Programa](pruebaMonitorSerial.ino) son las mismas del anterior capítulo, es decir, las siguientes:
<div id="monitorSerial">
  <ul align="center">
    <img alt="JPG" src="https://i.postimg.cc/FFbNxFvQ/Primer-Programa.png">
    </ul>
</div>
