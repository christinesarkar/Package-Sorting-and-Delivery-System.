#include <Servo.h>

Servo servo;

int angle=30;

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 2
int frequency1,frequency2,frequency3 = 0;

void setup() {

  servo.attach(8);
  servo.write(angle);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
 
  frequency1 = pulseIn(sensorOut, LOW);

  Serial.print("R= ");
  Serial.print(frequency1);
  Serial.print("  ");
  delay(500);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  frequency2 = pulseIn(sensorOut, LOW);
 
  Serial.print("G= ");
  Serial.print(frequency2);
  Serial.print("  ");
  delay(500);
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
 
  frequency3 = pulseIn(sensorOut, LOW);
  
  Serial.print("B= ");
  Serial.print(frequency3);
  Serial.println("  ");
  delay(500);

  compare();
}

void compare()
{

//  R= freq1 G = freq2, B = freq 3

//  for red
  if (frequency1 < frequency2 && frequency1 < frequency2) {
  
//  if(frequency1>90 && frequency1<120)
//  {
    Serial.println("Red");
     // scan from 0 to 180 degrees
    
     angle = 0;                             
    servo.write(angle);               
    delay(1500);
    angle=30; 
    servo.write(angle);
    delay(1500);                  
  }
//  else if (frequency3>20 && frequency3<35)
 else if (frequency3 < frequency1 && frequency3 < frequency2) 
  {
    Serial.println("Blue");
    // now scan back from 180 to 0 degrees
      angle = 60;                          
    servo.write(angle);           
    delay(1500);
    angle=30;
    servo.write(angle); 
    delay(1500);       
  }
  delay(500);
}
