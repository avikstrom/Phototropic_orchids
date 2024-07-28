//Author: Abigail Vikstrom
//date: February 2024
//purpose: This code changes the color of an RGB LED (output) based on light intensity detected by a photoresistor (input)


int sensorPin = A0;
int sensorValue = 0;

int red = 11;  // these are our output pins for three LED colors
int green = 10;
int blue = 9;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(red, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(blue, OUTPUT);
 
}

void RGB_color(int red_value, int green_value, int blue_value) {
// custom function to set three PWM color channels to any given mixture (pulse width modulation)
//all pins with tilde can give an analogue like PMW output
 
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}


void loop() {
  // put your main code here, to run repeatedly:
 
 // Pulse the builtin LED for a time determined by the sensor
  sensorValue = analogRead(sensorPin);
  
   if (sensorValue > 0 && sensorValue <= 256){
    RGB_color(125, 0, 0); // red
    delay(250);
  }
  else if (sensorValue > 256 && sensorValue <= 512){
    RGB_color(125, 80, 0); // yellow-ish
    delay(250);
  }
  else if (sensorValue > 512 && sensorValue <= 768) {
    RGB_color(0, 125, 125); // blue-ish
    delay(250);
  }
  else if (sensorValue > 768 && sensorValue < 1024) {
    RGB_color(125, 125, 125); // white
    delay(250);
  }
  
   // Read the analog sensor value and send it to serial
  Serial.println(sensorValue);
  delay(sensorValue);

}
