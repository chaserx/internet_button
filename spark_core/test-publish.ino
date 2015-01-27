const int buttonPin = D2;
const int ledPin = D7;
int buttonState = 0;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, LOW);
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW)
    {
        digitalWrite(ledPin, HIGH);
        Spark.publish("button_status","closed");
    }
}
