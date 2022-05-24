#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
 double alpha=0.75;
   int period=20;
   double refresh=0.0;
   

dht DHT;

#define DHT11_PIN 4

void setup(){
  lcd.begin(16, 2);
   Serial.begin(9600);
    pinMode(A4,INPUT);
   lcd.begin(16,2);
   lcd.clear();
   lcd.setCursor(0,0);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(5000);




  static double oldValue=0;
   static double oldrefresh=0;
 
   int beat=analogRead(A4);
  
   double value=alpha*oldValue+(0-alpha)*beat;
   refresh=value-oldValue;
  
  
 
   lcd.setCursor(0,0);
   lcd.print("Heart Rate     "); 
   lcd.setCursor(0,1);
   lcd.print("                ");
   lcd.setCursor(0,1); 
   lcd.print(beat/10);
   oldValue=value;
   oldrefresh=refresh;
   delay(period*100);

  
}
