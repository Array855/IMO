#include <Servo.h>   //servo library
Servo servo;     
int pos = 0;
#define trigPin  5   //pin trigger sensor
#define echoPin  6   //pin echo sensor
#define servoPin  8  //pin sinyal servo
int duration, distance, triger;   

void setup() {       
 Serial.begin(9600);
 servo.attach(servoPin);  
 pinMode(trigPin, OUTPUT);  
 pinMode(echoPin, INPUT);  
 servo.write(0); // biar pas dinyalain nutup dulu
 delay(100); 
} 

void measure() {  
  digitalWrite(10,HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;    // jarak
  triger = (distance);
}
void loop() { 
  measure();                 
  Serial.println(distance);
  if (triger <50){
    for (pos = 0; pos <= 180; pos += 1) { 
      servo.write(pos);              
        delay(15);                      
    }
    delay(3000);  
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      }
  }
}
         
 
