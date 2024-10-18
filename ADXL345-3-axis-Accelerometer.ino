#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel;

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Accelerometer Test");
  if(!accel.begin())
  {
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }

  //accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
   accel.setRange(ADXL345_RANGE_2_G);
}

void loop(void) 
{
  sensors_event_t event; 
  accel.getEvent(&event);
 
  Serial.print("X: "); 
  Serial.print(event.acceleration.x); 
  Serial.print("  ");
  
  Serial.print("Y: "); 
  Serial.print(event.acceleration.y); 
  Serial.print("  ");
  
  Serial.print("Z: "); 
  Serial.print(event.acceleration.z); 
  Serial.print("  ");
  
  Serial.println("m/s^2 ");
  delay(500);
}
