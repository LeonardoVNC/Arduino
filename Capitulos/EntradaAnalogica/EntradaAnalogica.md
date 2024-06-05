# Entrada Analógica
Arduino tiene la capacidad de recibir información desde componentes externos y emplear esa información en conjunto con el código para realizar distintas funciones. Esto lo hace a través de los puertos Analógicos, los cuales se diferencian por estar enumerados acompañados de una letra 'A', en el caso de Arduino UNO los puertos analógicos se encuentran en la esquina inferior:
<div id="ArduinoA">
  <ul align="center">
    <img alt="JPG" height = "200" src="https://i.ibb.co/zssHH8Z/ard.jpg">
    </ul>
</div>
Estos puertos analógicos se emplean para recibir información de distintos componentes, tales como potenciómetros, foto-resistencias, joysticks, LEDs infrarrojos y una enorme variedad de sensores.

Es importante destacar que esta lectura de datos se procesa dentro de la placa Arduino con valores entre 0 y 1023.

Para leer datos desde los pines analógicos se usa la función `analogRead();`

* **analogRead()**

  Esta función lee la señal que llega al pin designado al momento de hacerse la llamada del método, devuelve un valor int entre 0 y 1023, se usa del siguiente modo:
  ```
  analogRead(pinAnalogico);
  ```
  Donde: 
  - *pin* se refiere al pin de la placa Arduino desde A0 a A5 para los pines analógicos en el caso de Arduino UNO.

## Ejemplos
A continuación se mostraran ejemplos de conexión a la placa Arduino mientras se muestra el valor de la entrada analógica a través del monitor serial. El código que se subió a la placa Arduino es el siguiente:
```
int entrada;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  entrada = analogRead(A0);
  Serial.print("La entrada analógica es: ");
  Serial.println(entrada);
}
```
### Potenciómetro
En este ejemplo se realizaron las conexiones con un Potenciómetro. Las conexiones son las siguientes, note que el cable naranja es el utilizado para la lectura analógica:
<div id="PTC">
  <ul align="center">
    <img alt="JPG" height = "300" src="https://i.ibb.co/L59npSk/ptc.jpg">
    </ul>
</div>

Según se vaya moviendo la perilla del potenciómetro el valor de la entrada analógica debería variar.
### Foto-resistencia
Como su nombre lo indica, una foto-resistencia o LDR es una resistencia que cambia su valor en función de la cantidad de luz que ingrese por la parte superior. Las conexiones que se usan son las siguientes:
<div id="LDR">
  <ul align="center">
    <img alt="JPG" height = "300" src="https://i.ibb.co/TWC6NDh/ldr.jpg">
    </ul>
</div>

Según cambie la iluminación en el ambiente que sensa el LDR el valor de la entrada analógica variará.