#define LIGHT_PIN 20

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);
  digitalWrite(LIGHT_PIN, LOW);
  Serial.begin(115200);
  Serial.setTimeout(10);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == '1') {
      digitalWrite(LIGHT_PIN, HIGH);
    } else if (cmd == '0') {
      digitalWrite(LIGHT_PIN, LOW);
    }
  }
}

