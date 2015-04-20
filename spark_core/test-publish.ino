#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(SPARK)
#include "application.h"
#endif

const int buttonPin = D2;
const int ledPin = D7;
const int commPin = D4;
int buttonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(commPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, LOW);
  digitalWrite(commPin, HIGH);
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        digitalWrite(ledPin, HIGH);
        digitalWrite(commPin, LOW);
        Spark.publish("button_status","closed");
      }
    }
  }
  lastButtonState = reading;
}
