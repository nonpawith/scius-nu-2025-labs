#define buzzer 23

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(4);
  digitalWrite(buzzer, LOW);
  delay(100);
}
