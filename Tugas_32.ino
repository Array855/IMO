#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
int rotigoreng,rotikukus;
bool KondisiLED=HIGH;

void setup() {
  for ( rotigoreng=6; rotigoreng<=9; rotigoreng++)
  pinMode(rotigoreng,OUTPUT);
  Serial.begin(9600);   
  lcdSaya.begin();
  lcdSaya.autoAddress();
  lcdSaya.setCursor(1,0);  
}
void loop() { 
 ledlaplap(1);  
}

void ledlaplap (int  x )  {
  for (rotigoreng=6; rotigoreng<=9; rotigoreng++){
    lcdSaya.print("Geser Kanan ");
    delay(1000);
    lcdSaya.clear(); 
    if (rotigoreng==6)
      digitalWrite(9, !KondisiLED);
    else
      digitalWrite(rotigoreng-1,!KondisiLED);
      digitalWrite(rotigoreng,KondisiLED);
      Serial.println("Geser kanan  ");
      delay(150);
      
  }
  for (rotigoreng=8;rotigoreng>=7;rotigoreng--){
   lcdSaya.print("Geser Kiri ");
   delay(1000);
   lcdSaya.clear();
   if(rotigoreng==9)
     digitalWrite(6,!KondisiLED);
   else
     digitalWrite(rotigoreng+1,!KondisiLED);
     digitalWrite(rotigoreng,KondisiLED);
     Serial.println("Geser kiri ");
     delay(150);
}
   digitalWrite(7,!KondisiLED);
}
