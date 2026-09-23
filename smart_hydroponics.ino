/*
 * Smart Hydroponics / Automatic Valve System
 * Developed by: Goti Esmoris Tech
 * Description: Monitors soil moisture via potentiometer and actuates 
 * a water control valve using a servo and safety relay.
 */

#include <Servo.h>

// Pin Definitions
const int MOISTURE_SENSOR_PIN = A0; 
const int SAFETY_RELAY_PIN = 7;     
const int VALVE_SERVO_PIN = 9;      // Servo data pin

// Objects
Servo waterValve;

// Calibration Thresholds
const int DRY_THRESHOLD = 30;       
const int WET_THRESHOLD = 70;       

void setup() {
  Serial.begin(9600);
  
  pinMode(SAFETY_RELAY_PIN, OUTPUT);
  digitalWrite(SAFETY_RELAY_PIN, LOW); // Relay safe mode (OFF)
  
  waterValve.attach(VALVE_SERVO_PIN);
  waterValve.write(0);                 // Valve completely closed (0 degrees)
  
  Serial.println("System Online. Ready for irrigation monitoring...");
}

void loop() {
  int rawValue = analogRead(MOISTURE_SENSOR_PIN);
  int moisturePercentage = map(rawValue, 0, 1023, 0, 100);
  
  Serial.print("Soil Moisture Status: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  
  // Logic Control
  if (moisturePercentage < DRY_THRESHOLD) {
    digitalWrite(SAFETY_RELAY_PIN, HIGH); // Enable power line
    waterValve.write(90);                 // Open valve to 90 degrees (Water Flowing)
    Serial.println(">> Alert: Soil Dry! Opening water valve.");
  } 
  else if (moisturePercentage > WET_THRESHOLD) {
    waterValve.write(0);                  // Close valve (0 degrees)
    digitalWrite(SAFETY_RELAY_PIN, LOW);  // Cut power line for safety
    Serial.println(">> Status: Soil Hydrated. Closing water valve.");
  }
  
  delay(1000);
}
