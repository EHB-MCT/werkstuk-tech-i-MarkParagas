#include <Servo.h>

Servo myservo;  // Control
const int LS = A0;
int input = 0;
int pos = 0;    // Position
int led = 9;

void setup() {
  myservo.attach(8);  // Pin 8 gelink
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  input = analogRead(LS); // Work
  Serial.print("LS Value is: ");
  Serial.println(input);
  delay(1000);

  if (input <= 20){
    for (pos = 50; pos <= 150; pos++) { // tussen rotation 50~150
        myservo.write(pos);            
        delay(5);  
      }
    for (pos = 150; pos >= 50; pos--) { 
        myservo.write(pos);   
        delay(5);             
      }
    } else {
    for (pos = 50; pos <= 150; pos++) { // tussen rotation 50~150
        myservo.write(pos);            
        delay(15);  
    }
    for (pos = 150; pos >= 50; pos--) { 
        myservo.write(pos);   
        delay(15);  
    }
   };
   // LED
   if (input <= 20) {
      digitalWrite(led, LOW); // LED Aan
      delay(1000);
   } else {
      digitalWrite(led, LOW); // LED Aan
      delay(500);
      digitalWrite(led, HIGH); // LED Uit
      delay(500);
   };
}
