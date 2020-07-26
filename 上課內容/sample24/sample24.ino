//藍線A0 - Echo
//白線A1 - Trig
//安裝NewPing Library
//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組


#include <NewPing.h>
#include <MatrixMini.h>

#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200
#define irLeft 2
#define irRight 3

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
MatrixMini Mini;

void setup() {
  Serial.begin(9600);
  Mini.begin(); 
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);
  oneTurn();//測試轉一圈
}

void loop() {  
  int uS= sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");

  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.print("left:");
  Serial.println(leftValue);
  Serial.print("right:");
  Serial.println(rightValue);
  delay(500);
}

void oneTurn(){
  int interval = 6500;
  int speed = 20;
  Mini.M1.set(speed);
  Mini.M2.set(-speed);
  delay(interval);
  Mini.M1.set(0);
  Mini.M2.set(0);
  while(true);
}
