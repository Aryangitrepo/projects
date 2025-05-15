int ledPin = 9;  // PWM pin
int value = -1;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    value = Serial.read();

    if (value >= 0) {
      Serial.println(value);          // Debug: print the received value
      analogWrite(ledPin, value);     // Set LED brightness
      value = -1;                     // Reset value
    }
  }
}