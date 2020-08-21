#include <Wire.h>

#define SENSOR_0 7
#define SENSOR_1 8
#define SENSOR_2 9
#define SENSOR_3 10
#define SENSOR_4 11
#define SENSOR_5 12

int led = LED_BUILTIN;
byte sensor_val[6] = {0, 0, 0, 0, 0, 0};

void setup() {
  pinMode(led, OUTPUT);
  Wire.begin(8);              
  Wire.onRequest(requestEvent); 
  pinMode(SENSOR_0, INPUT_PULLUP);
  pinMode(SENSOR_1, INPUT_PULLUP);
  pinMode(SENSOR_2, INPUT_PULLUP);
  pinMode(SENSOR_3, INPUT_PULLUP);
  pinMode(SENSOR_4, INPUT_PULLUP);
  pinMode(SENSOR_5, INPUT_PULLUP);
}

void loop() {
  sensor_val[0] = digitalRead(SENSOR_0); // read the sensors 
  sensor_val[1] = digitalRead(SENSOR_1);
  sensor_val[2] = digitalRead(SENSOR_2);
  sensor_val[3] = digitalRead(SENSOR_3);
  sensor_val[4] = digitalRead(SENSOR_4);
  sensor_val[5] = digitalRead(SENSOR_5);
}

void requestEvent()
{
  digitalWrite(led, HIGH);  // briefly flash the LED
  Wire.write(sensor_val, 6); 
  digitalWrite(led, LOW);
}
