char input = 'g'; // Character used to turn the LED on and off. We use 'g' for Godzilla
int state = 1; // LED is off by default
const int led = 9;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(9, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == 'g' && state == LOW) {
      state = HIGH;
    } else if (input == 'g' && state == HIGH) {
      state = LOW;
    }
  }
  digitalWrite(led, state);
  delay(500);
}
