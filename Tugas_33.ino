#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
int rotigoreng;
int rotikukus;
byte ciaooo; 
#define BUZZER 3
void setup() {
 for (rotigoreng=6; rotigoreng<=9; rotigoreng++)
  pinMode(rotigoreng,OUTPUT);
 pinMode(BUZZER,OUTPUT);
 lampulaplap(1,5); 
 Serial.begin(9600);
 lcdSaya.begin();
 lcdSaya.autoAddress();
 lcdSaya.setCursor(1,0);  
}   
void loop () {    
}

void lampulaplap (byte x,byte y) {
  for(ciaooo=x;  ciaooo <y; ciaooo++){
   Serial.begin(9600);
   for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
   digitalWrite(rotigoreng,HIGH);
   digitalWrite(BUZZER,HIGH);
   Serial.print("sedang ke  ");
   Serial.println(ciaooo);
   lcdSaya.print("sedang ke ");
   lcdSaya.println(ciaooo);
   lcdSaya.clear(); 
   delay(1000);
   for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
   digitalWrite(rotigoreng , LOW);
   digitalWrite(BUZZER , LOW);
   delay (500);
}
}
