#include "WiFiServerHandler.h"
#include "ArduinoServoController.h"

// Define min and max PWM for servos
#define SERVOMIN 200 //160
#define SERVOMAX 640
#define NUM_SERVOS 6

// Create servo controller
ArduinoServoController servoController(NUM_SERVOS, SERVOMIN, SERVOMAX);

// Create WiFi server handler
WiFiServerHandler wifiServerHandler(80);

void setup() {
  Serial.begin(9600);
  
  // Initialize servo controller
  servoController.begin();
  
  servoController.moveServo(servoController.currentPositions, servoController.speeds);

  // Start WiFi server
  wifiServerHandler.begin();
}

void loop() {
  // Handle client requests and control servos
  wifiServerHandler.handleClient(servoController, SERVOMIN);
}
