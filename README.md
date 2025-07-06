# plant_water_pump
3V water pump and raspberry pi pico w for automatic plant watering. Can easily be connected to WIFI to check plant moisture status


Hardware is:
1. Raspberry pi pico w
2. 2 transistors to handle 3V and 100 mA
3. One photo diode.
4. One LED-light
5. One parallel battery holder for 2 st 1.5V to make 3V output
6. One 3V, 100 mA water pump and tube to transport water.
7. One moisture sensor.
8. One resistor.
9. One bread board.
10. Several conductors, soldering setup and electric tape.


Total cost is less than 50 USD  


Connect pinout like this:
const int sensorPin = A0; //To moisture-sensor
const int photo_sensor = A1; //To fotodiode 
const int pump_pin = A2; //To transistor 1 to determine when to turn on the pump
const int LED_pin = 0; //Connect to resistor with resistor in between 
const int run_moisture_sensor = 1; //To transistor 2 to determine when to fetch moisture sensor data
