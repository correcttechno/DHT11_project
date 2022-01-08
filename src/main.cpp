#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

int chk;
float hum;  //Stores humidity value
float temp;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  dht.begin();

}

void loop() {

    hum = dht.readHumidity();
    temp= dht.readTemperature();

    lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
    lcd.print("Temp: "+String(temp)+" C");
    
    lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
    lcd.print("Hum: "+String(hum)+" F");
    delay(2000);
}