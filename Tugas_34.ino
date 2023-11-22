#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
int rotigoreng,rotikukus;
bool KondisiLED=HIGH;
#define BUZZER 3
void setup() {
  for ( rotigoreng=6; rotigoreng<=9; rotigoreng++)
  pinMode(rotigoreng,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
  lcdSaya.begin();
  lcdSaya.autoAddress();
  lcdSaya.setCursor(1,0);  
     
  
}
void loop() { 
  rii(1); 
 
}
void rii (byte pingpito) {

 for (rotigoreng=6; rotigoreng<=9; rotigoreng++){
  lcdSaya.print("Geser Kanan ");
  delay(1000);
  lcdSaya.clear(); 
  if (rotigoreng==6)
   digitalWrite(9, !KondisiLED);
  else
   digitalWrite(rotigoreng-1,!KondisiLED);
  digitalWrite(rotigoreng,KondisiLED);
  digitalWrite(BUZZER,KondisiLED);
  Serial.println("Geser kanan & BUZZER ");
  delay(150);
  digitalWrite(BUZZER,!KondisiLED);
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
   digitalWrite(BUZZER,KondisiLED);
   Serial.println("Geser kiri & BUZZER ");
   delay(150);
   digitalWrite(BUZZER,!KondisiLED);
    delay(150);
}
 digitalWrite(7,!KondisiLED);
}   
   
