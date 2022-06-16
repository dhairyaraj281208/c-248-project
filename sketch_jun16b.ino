#include<DHT.h>

//  declaring sensor pin
byte sensor_pin = 4;

//  macro for type of sensor used
#define sensor_type DHT11

//  making object using constructor
DHT bmp(sensor_pin , sensor_type);

float dewpoint;

void setup() {
  Serial.begin(9600);
}
  
void loop() {
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");
    
  Serial.print("Humidity = ");
  Serial.print(bmp.readHumidity());
  Serial.println(" Pa");

  Serial.println("Temperature in Fahrenheit: ");
  Serial.print(bmp.readTemperature() * 9/5 + 32);
  Serial.println();

  Serial.println("Temperature in Kelvin: ");
  Serial.print(bmp.readTemperature() + 273.15);
  Serial.println();
  dewpoint = (bmp.readTemperature() - (100 - bmp.readHumidity()) / 5);
  Serial.println("Dew Point: ");
  Serial.print(dewpoint);
  Serial.println();
  
  Serial.println();
  delay(500);
}
