const int buttonPin = D2;
const int ledPin = D7;
int buttonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, LOW);
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        digitalWrite(ledPin, HIGH);
        Spark.publish("button_status","closed");
      }
    }
  }
  lastButtonState = reading;
}
