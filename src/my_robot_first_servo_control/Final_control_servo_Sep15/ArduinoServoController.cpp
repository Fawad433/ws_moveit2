#include "ArduinoServoController.h"

ArduinoServoController::ArduinoServoController(uint8_t numberOfServos, uint16_t servomin, uint16_t servomax)
  : numberOfServos(numberOfServos), servomin(servomin), servomax(servomax) {
    // curl "http://10.0.0.150/?angle0=60&speed0=30&angle1=30&speed1=30&angle2=0&speed2=30&angle3=0&speed3=30&angle4=90&speed4=30&angle5=70&speed5=30"
    
    currentPositions[0] = 420;
    currentPositions[1] = 200;
    currentPositions[2] = 200;
    currentPositions[3] = 200;
    currentPositions[4] = 200;
    currentPositions[5] = 400;
    speeds[0] = 10;
    speeds[1] = 10;
    speeds[2] = 10;
    speeds[3] = 10;
    speeds[4] = 10;
    speeds[5] = 10;
    speeds[6] = 10;
}

void ArduinoServoController::begin() {
  myServo = Adafruit_PWMServoDriver();
  myServo.begin();
  myServo.setPWMFreq(60);
  delay(10);
}

void ArduinoServoController::moveServo(uint16_t newPositions[], uint16_t speeds[]) {
  for (uint8_t i = 0; i < numberOfServos; ++i) {
    uint16_t newPosition = newPositions[i];
    uint16_t speed = speeds[i];

    if (newPosition > servomax) newPosition = servomax;
    if (newPosition < servomin) newPosition = servomin;

    uint16_t stepDelay = speed;
    uint16_t stepSize = 1;
    Serial.println(stepDelay);

    if (currentPositions[i] < newPosition) {
      for (uint16_t pos = currentPositions[i]; pos <= newPosition; pos += stepSize) {
        myServo.setPWM(i, 0, pos);
        delay(stepDelay);
      }
    } else {
      for (uint16_t pos = currentPositions[i]; pos >= newPosition; pos -= stepSize) {
        myServo.setPWM(i, 0, pos);
        delay(stepDelay);
      }
    }

    currentPositions[i] = newPosition;
  }
}

uint16_t ArduinoServoController::getCurrentPosition(uint8_t servo) const {
  if (servo < numberOfServos) {
    return currentPositions[servo];
  }
  return servomin;
}
