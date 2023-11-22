#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
int rotigoreng;
int rotikukus; 
bool KondisiLED=HIGH;
 
#define BUZZER 3
void setup() {
  for (rotigoreng=6; rotigoreng<=9; rotigoreng++)
    pinMode(rotigoreng,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  lampulaplap(1);
  Serial.begin(9600);
  lcdSaya.begin();
  lcdSaya.autoAddress();
  lcdSaya.setCursor(1,0); 
}
void loop () {   
  lampulaplap(1); 
}

void lampulaplap (int cuee ) { 
 for(rotikukus=1;  rotikukus <5; rotikukus++){
   lcdSaya.print("lAP LAP ");
   delay(1000);
   lcdSaya.clear();
   Serial.begin(9600);
   Serial.print("Sedang ke  ");
   Serial.println(rotikukus);
 for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
   digitalWrite(rotigoreng,HIGH);
   digitalWrite(BUZZER,HIGH);
   delay (500);
 for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
   digitalWrite(rotigoreng , LOW);
   digitalWrite(BUZZER , LOW);
   delay (500);
}
 for (rotigoreng=6; rotigoreng<=9; rotigoreng++){
  lcdSaya.print("ka-ki ");
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
 
 
