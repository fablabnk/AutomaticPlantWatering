
// based on arduino sweep servo control example

#include <Servo.h>

Servo myservo;                      // create servo object to control a servo

int pos = 0;                        // variable to store the servo position
int servopin=9;                     // set servo control pin
int settle_time=500;                // time required for servo to settle after being turned on
int open_position=120;              // full-open valve position in degrees
//int watering_time=10000;          // amount of time to have water valve open. time in ms. 1 second = 1000 ms
int watering_time=5000;              // short watering time for testing
//long watering_delay=86400000;        // amount of time between watering cycles (24 x 3600 x 1000) 24 hour wait period between cycles
//long watering_delay=3600000;        // 1000 x 3600 x 1 = 3600000 = 1 hour delay
long watering_delay=30000;           // test watering delay

void setup() {
  myservo.attach(servopin);         // attach servo
  myservo.write(0);                 // tell servo to go to zero - make sure valve is closed at loop start
}

void loop() {
  myservo.attach(servopin);         // re-attach servo
  delay(settle_time);               // wait for servo to settle
  myservo.write(0);                 // tell servo to go to zero - make sure valve is closed at loop start

  myservo.write(open_position);     // tell servo to go to open position

  delay(watering_time);             // water plant for defined period of time
  
  myservo.write(0);              // tell servo to go to position in variable 'pos'

  delay(1000);                  //give system enough time to finish move

  myservo.detach();                 // detach servo, to stop sending updates & stop hunting
  
  delay(watering_delay);            // time between cycles
  
}
