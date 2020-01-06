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
int val = 0;

LIDARLite myLidarLite;

void setup()
{
  Serial.begin(115200); // Initialize serial connection to display distance readings
  myLidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  myLidarLite.configure(0); // Change this number to try out alternate configurations
}

void loop()
{
  val = analogRead(potPin);
  //Serial.println(val);
  // Take a measurement with receiver bias correction and print to serial terminal
  // Take 99 measurements without receiver bias correction and print to serial terminal

  if (myLidarLite.distance() < val) {
    for (int i = 0; i < 99; i++)
    {
      Serial.println(myLidarLite.distance(false));
      Serial.print("M");
    }
    Serial.println(myLidarLite.distance());
  }
  if (myLidarLite.distance() > val) {

    Serial.println(val);
    Serial.print("V");
  }
}
