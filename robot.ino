  
#include <NewPing.h>
int distance = 100;
const int motor1_high = 13;
const int motor1_low = 8;
const int motor2_high = 12;
const int motor2_low = 6 ;
 #define TRIG_PIN A4 
#define MAX_DISTANCE 200 

#define ECHO_PIN A5 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
//motor1 is the left side motor and motor2 is on right side of the body
void setup() {
  
  // put your setup code here, to run once:
  pinMode(motor1_high,OUTPUT); 
  pinMode(motor1_low,OUTPUT);
  pinMode(motor2_high,OUTPUT);
  pinMode(motor2_low,OUTPUT);
  distance = readPing();      
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

}
 

void loop() {
  // put your main code here, to run repeated
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
if(distance<=15)
 {
  moveStop();
  delay(100);
  backward();
  delay(300);
 
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turn_right();
   moveStop();
  }else
  {
    turn_left();
    moveStop();
  }
 }else
 {
  forward();
 }
distance = readPing();
}
int lookRight()
{
    digitalWrite(motor1_high,1);
  digitalWrite(motor1_low,0);
  digitalWrite(motor2_high,1);
  digitalWrite(motor2_low,1);
  delay(300);
    int distance = readPing();
    delay(100);
   
    return distance;
}

int lookLeft()
{
    digitalWrite(motor1_high,1);
  digitalWrite(motor1_low,1);
  digitalWrite(motor2_high,0);
  digitalWrite(motor2_low,1);
  delay(2000 );
    int distance = readPing();
    delay(100);
    return distance;
    delay(100);
}
int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

int turn_left(){
  digitalWrite(motor1_high,1);
  digitalWrite(motor1_low,1);
  digitalWrite(motor2_high,0);
  digitalWrite(motor2_low,1);
  delay(1000);
 forward();

}

int turn_right(){
  digitalWrite(motor1_high,1);
  digitalWrite(motor1_low,0);
  digitalWrite(motor2_high,1);
  digitalWrite(motor2_low,1);
  delay(1000);
  forward();
   

}

void forward(){
  digitalWrite(motor1_high,1);
  digitalWrite(motor1_low,0);
  digitalWrite(motor2_high,0);
  digitalWrite(motor2_low,1);
}

void backward(){
  digitalWrite(motor1_high,0);
  digitalWrite(motor1_low,1);
  digitalWrite(motor2_high,1);
  digitalWrite(motor2_low,0);
  delay(1000);
}
void moveStop()
{
  digitalWrite(motor1_high,0);
  digitalWrite(motor1_low,0);
  digitalWrite(motor2_high,0);
  digitalWrite(motor2_low,0);
    }

  
    
