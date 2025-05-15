// Pin definitions
const int sensorPin = 2;    // IR sensor connected to digital pin 2
const int ledPin = 12;      // LED connected to digital pin 13
const int lepin=11;

void setup() {
  pinMode(sensorPin, INPUT);   // Set sensor pin as input
  pinMode(ledPin, OUTPUT);     // Set LED pin as output
}

void loop() {
  int sensorValue = digitalRead(sensorPin);  // Read IR sensor

  if (sensorValue == HIGH) {  // Fire detected (LOW signal)
    digitalWrite(lepin,HIGH);
    digitalWrite(ledPin, HIGH);  // LED ON
    delay(500);
    digitalWrite(ledPin, LOW);   // LED OFF
    digitalWrite(lepin,LOW);
    delay(500);
  } else {
    digitalWrite(lepin,LOW);
    digitalWrite(ledPin, LOW);   // Keep LED OFF if no fire
  }
}