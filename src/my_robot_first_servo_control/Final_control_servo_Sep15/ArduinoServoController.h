#ifndef ARDUINO_SERVO_CONTROLLER_H
#define ARDUINO_SERVO_CONTROLLER_H

#include <Adafruit_PWMServoDriver.h>

class ArduinoServoController {
public:
  uint16_t currentPositions[6];
  uint16_t speeds[6];
  ArduinoServoController(uint8_t numberOfServos, uint16_t servomin, uint16_t servomax);
  void begin();
  void moveServo(uint16_t newPositions[], uint16_t speeds[]);

  uint16_t getCurrentPosition(uint8_t servo) const;
  
private:
  Adafruit_PWMServoDriver myServo;
  uint8_t numberOfServos;
  uint16_t servomin;
  uint16_t servomax;
  
};

#endif
