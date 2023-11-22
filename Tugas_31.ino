#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
int rotigoreng;
byte ciaooo;
 
void setup() {
  for (rotigoreng=6; rotigoreng<=9; rotigoreng++)
    pinMode(rotigoreng,OUTPUT);
    lampulaplap(1,4);
    Serial.begin(9600);
    lcdSaya.begin();
    lcdSaya.autoAddress();
    lcdSaya.setCursor(1,0); 
    
     
     
}

void loop () {  
  
    
  
}

void lampulaplap (byte x,byte y) 
{
  for(ciaooo=x;  ciaooo<=y; ciaooo++)
  {
     Serial.begin(9600); 
     for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
     digitalWrite(rotigoreng,HIGH);
     delay (500);
     Serial.print("sedang ke  ");
     Serial.println(ciaooo); 
     lcdSaya.print("sedang ke ");
     lcdSaya.println(ciaooo);
     delay(1000);
     lcdSaya.clear(); 
      
     for (rotigoreng=6; rotigoreng<=9; rotigoreng++ )
     digitalWrite(rotigoreng , LOW);  
     delay (500);
      
        

      
}
  
}
