#include <Arduino.h>

// Step & Dir Pins for X and Y Axes
#define X_STEP_PIN 2
#define X_DIR_PIN  5
#define Y_STEP_PIN 3
#define Y_DIR_PIN  6

void parseGCode(String command);
void moveLine(float xTarget, float yTarget);

void setup() {
    Serial.begin(115200);
    pinMode(X_STEP_PIN, OUTPUT);
    pinMode(X_DIR_PIN, OUTPUT);
    pinMode(Y_STEP_PIN, OUTPUT);
    pinMode(Y_DIR_PIN, OUTPUT);
    
    Serial.println("G-Code Motion Controller Ready.");
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        parseGCode(command);
    }
}

void parseGCode(String command) {
    command.trim();
    if (command.startsWith("G0") || command.startsWith("G1")) {
        // Example parsing logic for linear interpolation (G1 X10 Y20)
        Serial.println("Executing Linear Interpolation: " + command);
        moveLine(10.0, 20.0);
    }
}

void moveLine(float xTarget, float yTarget) {
    // Bresenham's algorithm or linear stepping logic
    digitalWrite(X_DIR_PIN, HIGH);
    digitalWrite(Y_DIR_PIN, HIGH);
    
    for (int i = 0; i < 200; i++) {
        digitalWrite(X_STEP_PIN, HIGH);
        digitalWrite(Y_STEP_PIN, HIGH);
        delayMicroseconds(500);
        digitalWrite(X_STEP_PIN, LOW);
        digitalWrite(Y_STEP_PIN, LOW);
        delayMicroseconds(500);
    }
}
