#ifndef WIFISERVERHANDLER_H
#define WIFISERVERHANDLER_H

#include <WiFiS3.h>
#include "ArduinoServoController.h"
#include "Arduino_LED_Matrix.h"  // Include the matrix library

class WiFiServerHandler {
public:
    WiFiServerHandler(uint16_t port);
    void begin();
    void handleClient(ArduinoServoController& servoController, uint16_t servomin);

private:
    WiFiServer server;
    ArduinoLEDMatrix matrix;  // Declare the matrix object

    // Utility function to extract an array of integers from a comma-separated string
    void extractArrayFromString(const String& data, uint16_t* array, uint8_t size);
};

#endif
