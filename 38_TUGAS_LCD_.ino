#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
bool nilai, nilai2, y;
byte button = 2, BUZZER = 3;

void setup(){
  pinMode(button, INPUT);
  pinMode(BUZZER,OUTPUT);
  lcdSaya.begin();
  lcdSaya.autoAddress();
  lcdSaya.setCursor(1,0);
  Serial.begin(9600);
}

void loop(){
  nilai  = digitalRead(button);
  
  if(nilai == 1 && y == 0){
    Benar();
  }
  
  else if(nilai == 1 && y == 1){
    Salah();
  }
}

void Benar(){
  digitalWrite(BUZZER,HIGH);
  {
    Serial.println("BUZZER BUNYI");
    lcdSaya.print("BUZZER BUNYI");
    delay(1000);
    lcdSaya.clear();
  }
    y += 1;
}

void Salah(){
  digitalWrite(BUZZER, LOW);
  {
    Serial.println("BUZZER DIAM");
    lcdSaya.print("BUZZER DIAM");
    delay(1000);
    lcdSaya.clear();
  }
    y -= 1;
}
