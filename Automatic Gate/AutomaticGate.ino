
#include <Servo.h>  

// Pin definitions
const int trigPin = 35;     //ESP32 pin connection GPIO 35
const int echoPin = 34;    //ESP32 pin connection GPIO 34
const int servoPin = 13;  //ESP32 pin connection GPIO 13
const int ledPin = 12;     //ESP32 pin connection GPIO 12

// Gate parameters
const int openAngle = 90;  // Angle when gate is open
const int closeAngle = 0;  // Angle when gate is closed
const int detectionDistance = 10; // Distance in cm to trigger gate opening

// System variables
Servo gateServo;
bool gateOpen = false;
unsigned long lastDetectionTime = 0;
const unsigned long autoCloseDelay = 2000; // 2 seconds auto-close delay

// Function prototypes (forward declarations)
long measureDistance();
void openGate();
void closeGate();

void setup() {
  // Initialize serial monitor
  Serial.begin(74880);
  
  // Initialize pins
  pinMode(trigPin, OUTPUT);//configure this pin as an output pin
  pinMode(echoPin, INPUT);//configure this pin as an input pin
  pinMode(ledPin, OUTPUT);//configure this pin as an output pin
  
  // Attach servo
  gateServo.attach(servoPin);
  closeGate(); // Start with gate closed
  
  Serial.println("Automatic Gate System Initialized");
}

void loop() {
  // Measure distance from ultrasonic sensor
  long distance = measureDistance();
  
  // Check if object is within detection range
  if (distance > 0 && distance < detectionDistance) {
    //printing these statements in the serial monitor during runtime
    Serial.print("Object detected at ");
    Serial.print(distance);
    Serial.println(" cm");
    
    if (!gateOpen) {
      openGate();
    }
    lastDetectionTime = millis(); // Reset auto-close timer
  }
  
  // Auto-close gate if no detection for specified time
  if (gateOpen && (millis() - lastDetectionTime > autoCloseDelay)) {
    closeGate();
  }
  
  // Small delay to prevent excessive readings
  delay(100);
}

long measureDistance() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm (speed of sound is 343 m/s or 0.0343 cm/µs)
  // Distance = duration * speed / 2 (round trip)
  long distance = duration * 0.0343 / 2;
  
  return distance;//a way to send the "value" of distance back 
}

void openGate() {
  Serial.println("Opening gate...");
  gateServo.write(openAngle);
  digitalWrite(ledPin, HIGH); // Turn LED green
  gateOpen = true;
}

void closeGate() {
  Serial.println("Closing gate...");
  gateServo.write(closeAngle);
  digitalWrite(ledPin, LOW); // Turn LED off
  gateOpen = false;
}
