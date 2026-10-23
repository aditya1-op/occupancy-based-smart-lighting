/*
  ICT3129 - Fundamentals of Internet of Things
  Assignment 2 - Mini Project
  Project: Occupancy-Based Smart Lighting

  Components:
    - Arduino UNO
    - PIR motion sensor
    - Photoresistor (LDR) module
    - LED and current-limiting resistor

  Logic:
    LED ON = Motion detected AND darkness detected
*/

const int PIR_PIN = 2;
const int LDR_PIN = A0;
const int LED_PIN = 9;

// In this Wokwi setup, a higher LDR ADC reading generally indicates darkness.
const int DARK_THRESHOLD = 600;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  Serial.println("================================");
  Serial.println("OCCUPANCY BASED SMART LIGHTING");
  Serial.println("================================");
  Serial.println("System Initialized");
}

void loop() {
  const int motion = digitalRead(PIR_PIN);
  const int lightValue = analogRead(LDR_PIN);

  const bool occupied = (motion == HIGH);
  const bool isDark = (lightValue > DARK_THRESHOLD);
  const bool lightON = occupied && isDark;

  digitalWrite(LED_PIN, lightON ? HIGH : LOW);

  Serial.println("-----------------------------");
  Serial.print("PIR Status: ");
  Serial.println(occupied ? "Motion Detected" : "No Motion");

  Serial.print("LDR Value: ");
  Serial.println(lightValue);

  Serial.print("Room Condition: ");
  Serial.println(isDark ? "DARK" : "BRIGHT");

  Serial.print("LED Status: ");
  Serial.println(lightON ? "ON" : "OFF");

  delay(1000);
}
