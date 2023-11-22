#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
#define BUZZER 3
#define tombol 2
byte rotigoreng ;
bool KondisiLED =HIGH;

void setup() {
 for ( rotigoreng=6; rotigoreng<=9; rotigoreng++)
   pinMode(rotigoreng,OUTPUT);
 pinMode(BUZZER,OUTPUT);
 pinMode(tombol,INPUT);
 Serial.begin(9600);
 lcdSaya.begin();
 lcdSaya.autoAddress();
 lcdSaya.setCursor(1,0);    
}
void loop() {
  vaa(1);
}
void vaa (byte ya) {
 lcdSaya.print("tekan tombol ");  
 delay(1000);
 lcdSaya.clear(); 
  if (digitalRead(tombol)){
   for (rotigoreng=6; rotigoreng<=9; rotigoreng++) {
      if (rotigoreng==6)
      digitalWrite(9, !KondisiLED);
      else
      digitalWrite(rotigoreng-1,!KondisiLED);
      digitalWrite(rotigoreng,KondisiLED);
      digitalWrite(BUZZER,KondisiLED);
      Serial.println("Geser kanan & BUZZER ");
      delay(100);
      digitalWrite(BUZZER,!KondisiLED);
      delay(100);
 }
  for (rotigoreng=8;rotigoreng>=7;rotigoreng--){
      if(rotigoreng==9)
      digitalWrite(6,!KondisiLED);
      else
      digitalWrite(rotigoreng+1,!KondisiLED);
      digitalWrite(rotigoreng,KondisiLED);
      digitalWrite(BUZZER,KondisiLED);
      Serial.println("Geser kiri & BUZZER ");
      delay(100);
      digitalWrite(BUZZER,!KondisiLED);
      delay(100);   
}
  digitalWrite(7,!KondisiLED);     
}
}
