#include <DHT11.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2); //GANTI 0x27 kalau LCD ga muncul
#include <DHT.h>

int pin_dht = 14;
DHT dht(pin_dht, DHT11); //pin, Jenis DHT

int powerPin = 12;  //untuk pengganti VCC/5vOLT
int kipas = 4;

void setup() {
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //jadikan pin power sebagai output
  pinMode(powerPin, OUTPUT);//default bernilai LOW
  digitalWrite(powerPin, LOW);
  pinMode(kipas,OUTPUT);
  digitalWrite(kipas, LOW);
  Serial.begin(115200);
  dht.begin();
  }

void loop() {
  digitalWrite(powerPin, HIGH);

  float suhu = dht.readTemperature();

   Serial.print("suhu: ");
   Serial.println(suhu);

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("KIPAS OTOMATIS");
   lcd.setCursor(0,1);
   lcd.print("Suhu: ");
   lcd.setCursor(5,1);
   lcd.print(suhu);
   delay(3000);
  if(suhu >= 70.00)
   {
   digitalWrite(kipas,LOW);
  //  lcd.print("ON");
   }
   else{ 
    digitalWrite(kipas,HIGH);
    // lcd.print("OFF");
   }
   }
  // put your main code here, to run repeatedly: