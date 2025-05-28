#include "Wire.h"
#include "DHT.h"
#include "MQ135.h"
#include "LiquidCrystal_I2C.h"
/////////////////Varibles//////////////////
float sensor;
float temp;
float soil;
float ppm;
float humi;
///////////////Sensor define//////////////
#define dhtpin 7
#define dhttype DHT11
DHT dht(dhtpin , dhttype);
LiquidCrystal_I2C lcd(0x27 ,20 ,4);
MQ135 mq(A1);
///////////////////////////////////////////
void setup() {
lcd.init();
lcd.backlight();
dht.begin();
Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(3 , HIGH);
digitalWrite(6 , HIGH);
////////////////////Reading all values////// ///////////////////
sensor = analogRead(A0);
soil = abs(((sensor-1020)/550)*100);
if (soil>100){
  soil = 100;
}
ppm = mq.getPPM();
temp = dht.readTemperature();
humi = dht.readHumidity();
////////////////////Send values////////////////////////////
Serial.print(temp);
Serial.print(" °C|");
Serial.print(humi);
Serial.print(" %|");
Serial.print(ppm);
Serial.print("|");
Serial.print(soil);
Serial.println(" %");
//////////////////////////Print on LCD/////////////////////////////////
lcd.print("Temperature :  ");
lcd.print(temp);
lcd.setCursor(0,1);
lcd.print("Humidity :     ");
lcd.print(humi);
lcd.setCursor(0,2);
lcd.print("Pollution :    ");
lcd.print(ppm);
lcd.setCursor(0,3);
lcd.print("Soil Moisture: ");
lcd.print(soil);
delay(3500);
lcd.clear();
////////////////////////Checking for warning/////////////////////////
if (temp> 35){
  digitalWrite(3,LOW);
  lcd.setCursor(2, 1);
  lcd.print("TEMPRATURE HIGH!");
  lcd.setCursor(7, 2);
  lcd.print("FAN ON");
  delay(7000);
  lcd.clear();
}
else if (humi> 95){
  digitalWrite(3,LOW);
  lcd.setCursor(3,1);
  lcd.print("HUMIDITY HIGH!");
  lcd.setCursor(7,2);
  lcd.print("FAN ON");
  delay(7000);
  lcd.clear();
}

else if (ppm > 60){
  digitalWrite(3,LOW);
  lcd.setCursor(5,1);
  lcd.print("AIR Q. BAD");
  lcd.setCursor(5, 2);
  lcd.print("EXHAUST ON");
  delay(10000);
  lcd.clear();
  
}
else if (soil <= 60) {
  digitalWrite(6,LOW);
  lcd.setCursor(1,1);
  lcd.print("SOIL MOISTURE LOW!");
  lcd.setCursor(6,2);
  lcd.print("PUMP ON.");
  delay(5000);
  lcd.clear();
}

}
