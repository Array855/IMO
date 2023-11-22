#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
#define BUZZER 3
#define tombol 2
int rotigoreng;
int rotikukus;

void setup() {
 for (rotigoreng=6; rotigoreng<=9; rotigoreng++)
  pinMode(rotigoreng,OUTPUT);
 pinMode(BUZZER ,OUTPUT);
 pinMode(tombol,INPUT);
 lcdSaya.begin();
 lcdSaya.autoAddress();
 lcdSaya.setCursor(1,0);

}

void loop() {
   rayy(1); 
}
void rayy (byte x)
{
  
  if (digitalRead(tombol)){
   for(rotikukus=1;  rotikukus <5; rotikukus++)
    {
      lcdSaya.print("sedang ke ");
      lcdSaya.print(rotikukus);
      delay(1000);
      lcdSaya.clear();
      Serial.begin(9600);
      for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
      digitalWrite(rotigoreng,HIGH);
      digitalWrite(BUZZER,HIGH);
      Serial.print("sedang ke  ");
      Serial.println(rotikukus);
      delay (500);
      for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
      digitalWrite(rotigoreng,LOW);
      digitalWrite(BUZZER,LOW);
      delay (500);
    }
}
}
