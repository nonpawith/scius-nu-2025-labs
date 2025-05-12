#define LED_ON_BOARD 2

void setup() {
  pinMode(LED_ON_BOARD, OUTPUT);
}

void loop() {
  digitalWrite(LED_ON_BOARD, HIGH);
  delay(1000);
  digitalWrite(LED_ON_BOARD, LOW);
  delay(1000);
}
