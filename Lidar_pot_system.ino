/*------------------------------------------------------------------------------

  Connections:
  LIDAR-Lite 5 Vdc (red) to Arduino 5v
  LIDAR-Lite I2C SCL (green) to Arduino SCL
  LIDAR-Lite I2C SDA (blue) to Arduino SDA
  LIDAR-Lite Ground (black) to Arduino GND

  (Capacitor recommended to mitigate inrush current when device is enabled)
  680uF capacitor (+) to Arduino 5v
  680uF capacitor (-) to Arduino GND

  ------------------------------------------------------------------------------*/

#include <Wire.h>
#include <LIDARLite.h>
int potPin = 0;
int potVal = 0;
int dist = 0;

LIDARLite myLidarLite;

void setup()
{
  Serial.begin(115200); // Initialize serial connection to display distance readings
  myLidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  myLidarLite.configure(0); // Change this number to try out alternate configurations
}

void loop()
{
  potVal = analogRead(potPin);
  dist = myLidarLite.distance();
  Serial.print("Pot ");
  Serial.println(potVal);
  Serial.print("Dist ");
  Serial.print(dist);
  if (dist < potVal * 9 / 10) {
    Serial.println(" near");
  } else if (dist > potVal * 11 / 10) {
    Serial.println(" far");
  } else {
    Serial.println(" just right");
  }
}
