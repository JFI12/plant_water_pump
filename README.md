# plant_water_pump
Automatic plant watering with 3V water pump and raspberry pi pico w. The pico w can easily be connected to WIFI to check and change plant moisture status


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
1. const int sensorPin = A0; //To moisture-sensor
2. const int photo_sensor = A1; //To fotodiode 
3. const int pump_pin = A2; //To transistor 1 to determine when to turn on the pump
4. const int LED_pin = 0; //Connect to LED with pull-up resistor in between 
5. const int run_moisture_sensor = 1; //To transistor 2 to determine when to fetch moisture sensor data
