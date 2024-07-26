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
Arduino puede imprimir la información que le pidamos a traves del monitor serial, esto a través de comandos como `Serial.print();` o `Serial.println();`, los cuales son bastante similares al resto de comandos de impresion de otros lenguajes de programación, es decir, basta con introducir texto entre comillas dentro de los parentesis para imprimir el mensaje deseado.

Además, podemos colocar variables dentro de los parentesis para que se imprima su valor, también se puede usar `\n` para hacer un salto de línea:
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
También es posible hacer concatenaciones, pero para esto se debe operar únicamente con Strings. En caso de concatenar con otro tipo de dato saltaría un error de compilación o podrían existir problemas durante la ejecución del programa, para esto, podemos Castear un tipo de dato a un String y asi implementarlo correctamente dentro del `print`. Ejecute el siguiente código y observe la diferencia de la salida de estos 2 casos:
```
int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  i++;
  Serial.println("Salida con casteo: " + String(i));
  Serial.println("Salida sin casteo: " + i);
  delay(800);
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
De modo que si hay 1 o más caractéres disponibles para leer, se sobreescribirá la información alojada en la variable input, caso contrario, se ignorará el bloque de código.

### Trabajando con Strings
En caso de que las operaciones de entrada de datos únicamente con char resulten algo limitantes, es posible trabajar con Strings, lo cual será algo más complicado en el código, pero resultará en una mayor variedad de operaciones y más flexibilidad a la hora de decidir como actuará nuestro programa en función de la entrada.

Para leer correctamente los datos enviados por el usuario vamos a leer caractér a caractér la información y apilarla poco a poco en un variable String hasta que se detecte un salto de línea. Esto lo hacemos de la siguiente manera:
```
String input = "";
char c;

void setup() {
  Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0) {
    c = Serial.read();
    if (c == '\n' || c == '\r') {
      //TODO Implementar casos para tratar el String
      input = "";
    } else {
      input += c;
    }
  }
}
```
Es importante destacar que una vez se detecte un salto de línea se tomará el String como terminado y se procederá a analizar a que caso corresponde la entrada al compararse con las entradas planteadas. En el caso de este programa las entradas aun no se han implementado.

Las variables de tipo String tienen métodos que podemos usar a nuestro favor. Los más importantes son:
* **equals()**

  Es una función que compara 2 Strings, en caso de que los Strings sean idénticos devolverá true, si no son iguales (contando minúsculas, mayúsculas y espacios) devuelve false. Sigue la siguiente estructura:
  ```
  StringA.equals(StringB);
  ```

  Su importancia en este capítulo radica en que es de vital importancia para comparar el input del usuario con las entradas que se planteen en el programa.
* **toLowerCase()**

  Es un método que transforma todos los caractéres del String en minúsculas. Es importante destacar que su tipo de retorno es void, es decir, no podemos guardar el String en minúscula en otra variable. 
  
  Toma su importancia en este capítulo si se quiere que la entrada del usuario no distinga mayúsculas o minúsculas y pueda compararse sin problema con las entradas planteadas.
* **replace()**

  Este método reemplaza componentes del String por otros, es decir, si dentro de nuestro String existe una secuencia de caractéres identica a la que planteemos, este método la reemplazará por otra secuencia. Tiene la siguiente estructura:

  ```
  String.replace(CadenaAReemplazar, CadenaSustituta);
  ```
  De modo que la CadenaSustituta tomará el lugar de la CadenaAReemplazar.

  Es especialmente útil en este capítulo para eliminar los espacios vaciós de nuestros Strings, dado que hay veces que se puede escapar un espacio al inicio o al final de la entrada del usuario, y este caractér ya evita que `equals()` los clasifique como identicos, por lo que eliminar estos caracteres sobrantes al inicio o al final ayuda a evitar problemas.

Con esto termina este capítulo. Al igual que con el capítulo anterior, se ha añadido un pequeño programa que muestra un poco de los conceptos presentados en este documento.

Las conexiones empleadas para el [Programa](pruebaMonitorSerial.ino) son las mismas del anterior capítulo, es decir, las siguientes:
<div id="monitorSerial">
  <ul align="center">
    <img alt="JPG" src="https://i.postimg.cc/FFbNxFvQ/Primer-Programa.png">
    </ul>
</div>
