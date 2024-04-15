#include <Servo.h> // include servo library
#define Grove_Water_Sensor 8 
int pirPin = 3; // define PIR sensor pin
int servoPin = 9; // define servo motor pin
Servo servo; // create servo object
int soundSensor = 4

void setup() {
  pinMode(pirPin, INPUT); // set PIR sensor pin as input
  pinMode(soundSensor, INPUT);
  servo.attach(servoPin); // attach servo to servo pin
  pinMode(Grove_Water_Sensor, INPUT); 
  Serial.begin(9600);
}

void loop() {
  if( digitalRead(Grove_Water_Sensor) == HIGH) {
      Serial.println("Bed is wet. Change it");
      delay(1000);}
  else if(digitalRead(pirPin) == HIGH) { // if PIR sensor detects movement
         Serial.println("Baby is moving");
          for(int angle = 0; angle <= 180; angle++) { // move servo from 0 to 180 degrees
              servo.write(angle); // write servo angle
              delay(10); // delay for smooth movement
               }
           for(int angle = 180;angle>=0;angle--)//move servo from 180 to 0 degrees
          {
              servo.write(angle);
              delay(10);
              }
  }
  else if(digitalRead(soundSensor)==HIGH){
        Serial.println("Baby is crying");
          for(int angle = 0; angle <= 180; angle++) { // move servo from 0 to 180 degrees
              servo.write(angle); // write servo angle
              delay(10); // delay for smooth movement
               }
           for(int angle = 180;angle>=0;angle--)//move servo from 180 to 0 degrees
          {
              servo.write(angle);
              delay(10);
              }
  }
  else { // if PIR sensor does not detect movement
        servo.write(0); // stop servo movement
         Serial.println("Baby is sleeping");
         delay(10000);
  }
  }