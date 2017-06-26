#include <Servo.h>
#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  //added
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 150) {  
    Serial.print("Got you!:" );
    Serial.print(distance);
    Serial.println(" cm");
    for (int x=0;x<4;x++)
    {
    
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);            // waits 5ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                     // waits 5ms for the servo to reach the position
    delay(5);
  } 
    }
    delay(3);
}
Serial.print("Distance:" );
    Serial.print(distance);
    Serial.println(" cm");
  
}

