//working code for buildinq co detector
const int AOUTpin = A0;   // CO sensor analog output to A0
const int DOUTpin = 8;    // CO sensor digital output to D8
const int ledPin = 13;    // LED to pin D13
const int buzzerPin = 7;  // Buzzer connected to pin D7

int limit;
int value;

void setup() {
  Serial.begin(115200);          // Set baud rate for Serial Monitor
  pinMode(DOUTpin, INPUT);       // CO sensor digital pin
  pinMode(ledPin, OUTPUT);       // LED output
  pinMode(buzzerPin, OUTPUT);    // Buzzer output
}

void loop() {
  value = analogRead(AOUTpin);   // Read analog value from CO sensor
  limit = digitalRead(DOUTpin);  // Read digital alert level

  Serial.print("CO value: ");
  Serial.println(value);
  Serial.print("Limit: ");
  Serial.println(limit);

  if (limit == HIGH) {
    digitalWrite(ledPin, HIGH);   // Turn on LED
    tone(buzzerPin, 1000);        // Turn on buzzer (1 kHz)
    delay(200);                   // Beep duration
    noTone(buzzerPin);            // Turn off buzzer
    delay(200);                   // Pause before next beep
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED
    noTone(buzzerPin);            // Ensure buzzer is off
    delay(200);                   // Still add a small delay
  }
}
