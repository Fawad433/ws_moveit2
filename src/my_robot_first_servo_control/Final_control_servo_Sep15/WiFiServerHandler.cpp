#include "WiFiServerHandler.h"
#include "ArduinoServoController.h"
#include "Arduino_LED_Matrix.h"
#include "arduino_secrets.h"

// Constructor for WiFiServerHandler
WiFiServerHandler::WiFiServerHandler(uint16_t port) : server(port), matrix() {
    // Initialization in the constructor
}

// Initialize WiFi and server
void WiFiServerHandler::begin() {
    Serial.println("Beginning WiFi connection...");
    WiFi.begin(SECRET_SSID, SECRET_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
  
    server.begin();
    Serial.println("Server started");

    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
  
    matrix.begin();  // Initialize the matrix
    Serial.println("Matrix initialized");
}

// Handle incoming client requests
void WiFiServerHandler::handleClient(ArduinoServoController& servoController, uint16_t servomin) {
    WiFiClient client = server.available();

    if (client) {
        Serial.println("New client connected");
        while (client.connected()) {
            if (client.available()) {
                String request = client.readStringUntil('\r');
                Serial.println("Received request:");
                Serial.println(request);
                client.flush();

                // Initialize arrays for angles and speeds
                uint16_t angles[6] = {0};
                uint16_t speeds[6] = {0};

                // Parse the request
                for (int i = 0; i < 6; i++) {
                    String angleParam = "angle" + String(i) + "=";
                    String speedParam = "speed" + String(i) + "=";

                    int angleIndex = request.indexOf(angleParam);
                    int speedIndex = request.indexOf(speedParam);

                    if (angleIndex != -1 && speedIndex != -1) {
                        angleIndex += angleParam.length();
                        speedIndex += speedParam.length();

                        int angleEndIndex = request.indexOf('&', angleIndex);
                        int speedEndIndex = request.indexOf('&', speedIndex);

                        if (angleEndIndex == -1) angleEndIndex = request.length();
                        if (speedEndIndex == -1) speedEndIndex = request.length();

                        angles[i] = request.substring(angleIndex, angleEndIndex).toInt();
                        int receivedData = angles[i] * 2.72;
                        angles[i] = receivedData + servomin;
                        speeds[i] = request.substring(speedIndex, speedEndIndex).toInt();
                    }
                }

                // Print received angles and speeds
                Serial.print("Received angles: ");
                for (uint8_t i = 0; i < 6; i++) {
                    Serial.print(angles[i]);
                    Serial.print(" ");
                }
                Serial.println();

                Serial.print("Received speeds: ");
                for (uint8_t i = 0; i < 6; i++) {
                    Serial.print(speeds[i]);
                    Serial.print(" ");
                }
                Serial.println();

                // Pass the arrays to the servo controller
                servoController.moveServo(angles, speeds);
                Serial.println("Servos moved");

                // Display on matrix when a command is executed
                matrix.clear();  // Clear the matrix
                Serial.println("Matrix cleared");

                // Use the ArduinoGraphics methods if the library supports text rendering
                #ifdef MATRIX_WITH_ARDUINOGRAPHICS
                matrix.begin();  // Initialize graphics
                Serial.println("Graphics initialized");
                matrix.set(0, 0, 255, 255, 255); // Set color to white for text
                matrix.print("Servos Moving");  // Display text
                matrix.endDraw();  // Finalize drawing
                Serial.println("Text drawn on matrix");
                #endif

                client.println("HTTP/1.1 200 OK");
                client.println("Content-Type: text/plain");
                client.println("Connection: close");
                client.println();
                client.println("Data received");

                delay(10);
                client.stop();
                Serial.println("Client disconnected.");
            }
        }
    }
}


// Extract array from comma-separated string
void WiFiServerHandler::extractArrayFromString(const String& data, uint16_t* array, uint8_t size) {
    Serial.print("Extracting array from string: ");
    Serial.println(data);
    int start = 0;
    for (uint8_t i = 0; i < size; i++) {
        int index = data.indexOf(',', start);
        if (index == -1) index = data.length();
        array[i] = data.substring(start, index).toInt();
        Serial.print("Extracted value: ");
        Serial.println(array[i]);
        start = index + 1;
    }
}
