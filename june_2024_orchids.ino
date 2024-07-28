//phototropic lego orchids
//Author: Abi
//Date: 2024-06-01
//purpose: This code controls the up-down motion of orchid flowers controlled with an SG90 servo via string. Two photoresistors located in flower stamens provide input
//the servo reels in or releases string based on which of the two orchids has greater light exposure.

#include <Servo.h>          // Servo library for controlling our SG90 servo

int sensorPin1 = A0;
int sensorValue1 = 0;
int sensorPin2 = A1;
int sensorValue2 = 0;
int direction = 0;

const uint8_t SERVO_PIN = 24;
Servo myservo;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 myservo.attach(SERVO_PIN);  // Servo control is on SERVO_PIN
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue1 = analogRead(sensorPin1);
sensorValue2 = analogRead(sensorPin2);

  // Read the analog sensor value and send it to serial
//Serial.println(sensorValue1);
//Serial.println(sensorValue2);
//delay(500);

if (sensorValue1 > (sensorValue2+20)){
  // First sweep from 0 degrees to 180 degrees
  //for (int direction = 0; direction <= 180; direction += 2) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    direction += 2;  // goes from 0 degrees to 180 degrees
    if (direction > 90){
      direction = 90;
    }
    myservo.write(direction);  // tell servo to go to position in variable 'direction'
    delay(10);
  }

if (sensorValue2 > (sensorValue1+20)){
  // First sweep from 0 degrees to 180 degrees
  //for (int direction = 0; direction <= 180; direction += 2) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    direction -= 2;  // goes from 0 degrees to 180 degrees
    myservo.write(direction);  // tell servo to go to position in variable 'direction'
    delay(10);
  }

}
