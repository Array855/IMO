#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
const int button = 2, button2 = 4;
int y = 0, x = 0, durasi = 100;
int nilai, nilai2, LED;

void setup() {
  pinMode(button,INPUT);
  pinMode(button2,INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  lcdSaya.begin();
  lcdSaya.autoAddress();
  lcdSaya.setCursor(1,0);
}

void loop() {
  vara(1);
  
 }
void vara (byte lii){
  nilai = digitalRead(button);
  nilai2= digitalRead(button2);
  if(nilai == 1 || y >= 1){
    y += 1;
    for(LED=6; LED<=9; LED++){
      digitalWrite(LED,HIGH);
      Serial.println("Tombol ON ");
      lcdSaya.print( "Tombol ON ");
      delay(1000);
      lcdSaya.clear(); 
      delay(durasi);
      digitalWrite(LED, LOW);
      delay(durasi);
    }
    if(nilai2 == 1){
        y = 0;
    }
  }
  else if(nilai2 == 1 || x >= 1){
    x += 1;
    Serial.println("Tombol OFF");
    lcdSaya.print( "Tombol OFF ");
    delay(1000);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
}
