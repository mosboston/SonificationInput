/*
 2 input serialStreamer
 by Keith Simmons
 
 
 Analog pins 0 and 1 are read and streamed as fast as 
 possible over the serial port.
  
 LED pins mirror the analog values by adjusting
 brightness.  
 
 A speaker can be hooked up to generate tones
 
 This example code is in the public domain.
 
 */
 
int fadeAmount = 5;    // how many points to fade the LED by

int brightness0 = 0;    // how bright the LED is
int brightness1 = 0; // how bright led 2 is

int sensorValue0 = 0;
int sensorValue1 = 0;

int sensorPin0 = 0;
int sensorPin1 = 1;

int feedbackPin0 = 9; // LED brightness shows value
int feedbackPin1 = 10;  // LED brightness shows value

int audioPin0 = 11;
int audioPin1 = 11;

void setup()  { 
  // declare pin 9 to be an output:
  pinMode(feedbackPin0, OUTPUT);
  pinMode(feedbackPin1, OUTPUT);
  pinMode(audioPin0, OUTPUT);

  Serial.begin(9600); 

} 

void loop()  { 
  sensorValue0 = analogRead(sensorPin0);    
  sensorValue1 = analogRead(sensorPin1);    
  
  brightness0 = map(sensorValue0, 0, 1023, 0, 255);
  brightness1 = map(sensorValue1, 0, 1023, 0, 255);

  // set the brightness of pin 9:
  analogWrite(feedbackPin0, 255-brightness0); 
  analogWrite(feedbackPin1, 255-brightness1); 
  analogWrite(audioPin0, 255-brightness1); 
               
  Serial.print( sensorValue0 );
  Serial.print( ", ");
  Serial.println( sensorValue1 );
  
}
