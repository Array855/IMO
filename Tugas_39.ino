#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdSaya(20,4);
bool nilai, nilai2;
byte buzzer = 3, button1 = 2, button2 = 4;
int y, x, rotigoreng, LED ,durasi = 500;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(buzzer, OUTPUT);
  for ( rotigoreng=6; rotigoreng<=9; rotigoreng++)
  pinMode(rotigoreng,OUTPUT);
  Serial.begin(9600);
  lcdSaya.begin();
  lcdSaya.autoAddress();
  lcdSaya.setCursor(1,0);
}

void loop() {
  arvaa (1);
}

void arvaa (byte ri){
   nilai = digitalRead(button1);
  nilai2= digitalRead(button2);
  if(nilai == 1 || y >= 1){
    y += 1;
    for(LED=6; LED<=9; LED++){
      digitalWrite(LED,HIGH);
      Serial.println("Tombol ON ");
      lcdSaya.print( "Tombol ON ");
      delay(1000);
      lcdSaya.clear(); 
      
   
        
    }
     delay(durasi);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
    if(nilai2 == 1){
        y = 0;
    }
  }
  else if(nilai2 == 1 || x >= 1){
    x += 1;
    Serial.println("Tombol OFF");
    lcdSaya.print( "Tombol OFF ");
    delay(1000);
    lcdSaya.clear(); 
    for(LED=6; LED<=9; LED++){
    digitalWrite(LED, LOW);
  }
       
    }
    }
    
   
 
