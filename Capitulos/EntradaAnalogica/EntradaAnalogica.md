# Entrada Analógica
Arduino tiene la capacidad de recibir información desde componentes externos y emplear esa información en conjunto con el código para realizar distintas funciones. Esto lo hace a través de los puertos Analógicos, los cuales se diferencian por estar enumerador acompañados de una letra 'A', en el caso de Arduino UNO los puertos analógicos se encuentran en la esquina inferior:
<div id="ArduinoA">
  <ul align="center">
    <img alt="JPG" height = "200" src="https://i.ibb.co/zssHH8Z/ard.jpg">
    </ul>
</div>
Estos puertos analógicos se emplean para recibir información de distintos componentes, tales como potenciómetros, foto-resistencias, joysticks, LEDs infrarrojos y una enorme variedad de sensores.

Es importante destacar que esta lectura de datos se procesa dentro de la placa Arduino con valores entre 0 y 1023.

Para leer datos desde los pines analógicos se usa la función `analogRead();`, esta función usa un único parámetro, el cual es el pin del cual realizará la lectura, veámoslo con un pequeño ejemplo:
## Ejemplo
En este ejemplo se realizaron las conexiones con un Potenciómetro, pero se puede emplear cualquier otro componente de los ya mencionados. Las conexiones son las siguientes, note que el cable naranja es el utilizado para la lectura analógica:
<div id="ArduinoA">
  <ul align="center">
    <img alt="JPG" height = "200" src="https://i.ibb.co/L59npSk/ptc.jpg">
    </ul>
</div>

El código que se subió a la placa Arduino es el siguiente:
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
Según se vaya moviendo la perilla del potenciómetro el valor de la entrada analógica debería variar, este cambio puede percibirse desde el monitor serial.