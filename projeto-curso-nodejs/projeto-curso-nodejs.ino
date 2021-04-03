
const int ANALOG_PIN = A0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);
  
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.begin(115200);
}

void loop() {
 digitalWrite(LED_BUILTIN, LOW);

 int valor = analogRead(ANALOG_PIN);

 Serial.println(valor);

 digitalWrite(LED_BUILTIN, HIGH);

 delay(100);
}
