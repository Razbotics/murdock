
#include <Wire.h>
byte sensor_val[6] = {0, 0, 0, 0, 0, 0};

void setup() {
  Wire.begin();
  Serial.begin(9600);  // start serial for output
}

void loop() {
 byte index = 0;
 Wire.requestFrom(8, 6);
 while(Wire.available() > 0 && index < 6)
  {
    sensor_val[index] = Wire.receive();
    index++;
   }

  for(int i = 0; i < 6; i++){
    Serial.print(sensor_val[i]); Serial.print("  ");
  }
  Serial.println();
  delay(10);

}
