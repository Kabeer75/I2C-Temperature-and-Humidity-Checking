#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27 , 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup (){
  dht.begin();
  lcd.init();
  lcd.backlight();
}
void loop(){
  delay(2000);
  float humi=dht.readHumidity();
  float tempC= dht.readTemperature();
  if (isnan(humi)||isnan(tempC)){
    lcd.setCursor(0,0);
    lcd.print("Boom");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print((char)223);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humi: ");
    lcd.print(humi);
    lcd.print("%");
  
  }
  
}
