#include "Wire.h"
#include "DHT.h"
#include "MQ135.h"
#include "LiquidCrystal_I2C.h"

float temp;
float ppm;
float humi;
char inc_value = 48;

#define dhtpin 7
#define dhttype DHT11
DHT dht(dhtpin , dhttype);
LiquidCrystal_I2C lcd(0x27 ,20 ,4);
MQ135 mq(A1);
void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
dht.begin();
Serial.begin(9600);
pinMode(10 , OUTPUT);
pinMode(11, OUTPUT);
pinMode(12 , OUTPUT);
pinMode(13 , OUTPUT);
digitalWrite( 13 , HIGH);
digitalWrite(12, HIGH);
digitalWrite(11 , HIGH);
digitalWrite(10 , LOW);

}

void loop() {
///////////Read Values\\\\\\\\\\\\
digitalWrite(3 , HIGH);
ppm = mq.getPPM();
temp = dht.readTemperature();
humi = dht.readHumidity();

lcd.print("Temperature:  ");
lcd.print(temp);
lcd.setCursor(0,1);
lcd.print("Humidity :    ");
lcd.print(humi);
lcd.setCursor(0,2);
lcd.print("Pollution :   ");
lcd.print(ppm);
digitalWrite( 3 , LOW);
inc_value = Serial.read();

if (inc_value == '1'){
  digitalWrite(13, HIGH);
}
if (inc_value == '0'){
  digitalWrite(13, LOW);
}
if (inc_value == '3'){
  digitalWrite(12, HIGH);
}
if (inc_value == '2'){
  digitalWrite(12, LOW);
}
if (inc_value == '5'){
  digitalWrite(11, HIGH);
}
if (inc_value == '4'){
  digitalWrite(11, LOW);
}
if (inc_value == '7'){
  digitalWrite(10, LOW);
}
if (inc_value == '6'){
  digitalWrite(10, HIGH);
}


delay(1000);

lcd.clear();
}

