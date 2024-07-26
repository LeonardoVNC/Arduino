String input = "";
char c;
int led = 2;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.println("\nInicio del Programa");
}

void loop() {
  if (Serial.available() > 0) {
    c = Serial.read();
    if (c == '\n' || c == '\r') {
      input.toLowerCase();
      input.replace(" ","");
      if (input.equals("encender")) {
        digitalWrite(led, HIGH);
      } else if (input.equals("apagar")) {
        digitalWrite(led, LOW);
      } else {
        int intput = input.toInt();
        if (intput != 0) {
          for (int i = 0; i < intput; i++) {
            digitalWrite(led, HIGH);
            delay(500);
            digitalWrite(led, LOW);
            delay(500);
          }
        }
      }
      input = "";
    } else {
      input += c;
    }
  }
}
