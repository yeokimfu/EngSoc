const int ledPin = 2; // GPIO2 is commonly used for the built-in LED on ESP32 boards

void setup() {
  // Initialize serial communication for debugging purposes.
  // This allows you to see messages printed to the Serial Monitor.
  Serial.begin(115200);
  Serial.println("ESP32 LED Blink Example");

  // Set the LED pin as an OUTPUT.
  // This configures the pin to send electrical signals (voltage).
  pinMode(ledPin, OUTPUT);
  Serial.print("LED Pin (GPIO): ");
  Serial.println(ledPin);
}

void loop() {
  // Turn the LED ON (HIGH voltage).
  // This applies voltage to the specified pin, lighting up the LED.
  digitalWrite(ledPin, HIGH);
  Serial.println("LED ON");

  // Wait for 1000 milliseconds (1 second).
  // The program pauses here for the specified duration.
  delay(1000);

  // Turn the LED OFF (LOW voltage).
  // This removes voltage from the specified pin, turning off the LED.
  digitalWrite(ledPin, LOW);
  Serial.println("LED OFF");

  // Wait for 1000 milliseconds (1 second).
  delay(1000);
}
