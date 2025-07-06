#include <Wire.h>
#include <RTClib.h>
#include <EEPROM.h>
// Define the pin connected to the sensor
const int sensorPin = A0; // Analog pin where the GP2 sensor is connected
const int photo_sensor = A1; // Analog pin where the GP2 sensor is connected
const int pump_pin = A2; // Analog pin where the GP2 sensor is connected
const int LED_pin = 0; // Analog pin where the GP2 sensor is connected
const int run_moisture_sensor = 1; // Analog pin where the GP2 sensor is connected

RTC_DS3231 rtc;
int start_time = 0;
int start_time_moisture = 0;
void setup() {
  // Start the serial communication
  Serial.begin(9600);
  pinMode(LED_pin, OUTPUT);  // Required for digitalWrite and digitalRead to work properly
  pinMode(run_moisture_sensor, OUTPUT);  // Required for digitalWrite and digitalRead to work properly
  pinMode(photo_sensor, INPUT);  // Required for digitalWrite and digitalRead to work properly
  pinMode(pump_pin, OUTPUT);  // Required for digitalWrite and digitalRead to work properly
 pinMode(sensorPin, INPUT);  // Required for digitalWrite and digitalRead to work properly
  delay(1000);  // Add this
  digitalWrite(LED_pin, HIGH);
  delay(1000);  // Add this
  digitalWrite(LED_pin, LOW);
  digitalWrite(run_moisture_sensor, HIGH);
  delay(1000);  // Add this
  digitalWrite(LED_pin, HIGH);
  digitalWrite(run_moisture_sensor, LOW);
  start_time = millis();  // "Reset" point
  start_time_moisture = millis();  // "Reset" point
/*   if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
  Serial.println("RTC lost power, setting time.");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Set to compile time
  } */
}
int timer = 0;
int timer_moisture = 0;
int sensorValue = 0;
int error_counter = 0;
int shutdown_trigger = 0;
float photo_sensor_raw = 0;
void loop() {


  photo_sensor_raw = analogRead(photo_sensor);
  Serial.print("photo_sensor_raw: ");
Serial.print(photo_sensor_raw);


  timer = millis() - start_time;
  Serial.print("timer: ");
  Serial.println(timer); 

  timer_moisture = millis() - start_time_moisture;
  Serial.print("timer_moisture: ");
  Serial.println(timer_moisture); 
if (timer_moisture > 5000){
  digitalWrite(run_moisture_sensor, HIGH);
  delay(5000);
  start_time_moisture = millis();

  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue); 
}
else{
  digitalWrite(run_moisture_sensor, LOW);
}



 if (shutdown_trigger == 0){

  if (timer > 3600*24*3 && photo_sensor_raw < 4){
    if (sensorValue > 450){
      start_time = millis();
      digitalWrite(run_moisture_sensor, HIGH);
      delay(5000);
      while (sensorValue > 400){

        sensorValue = analogRead(sensorPin); // <- Add this line
        analogWrite(pump_pin, 255);
        delay(1000);
        error_counter += 1;
        if (error_counter > 20){
          Serial.print("error_counter: ");
          Serial.print(error_counter);
          shutdown_trigger = 1;
          break; // exit loop
        }
      }
    error_counter = 0;
    analogWrite(pump_pin, 0);
    }
  }
    
 }
 else{
  Serial.print("shutdown: ");
  Serial.print(shutdown_trigger);
  digitalWrite(LED_pin, LOW);
 }

/*    DateTime now = rtc.now();
Serial.print("now.hour(): ");
Serial.print(now.hour()); */
  delay(1000);
}
