//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組

//白色-0
//黑色-1

#include <MatrixMini.h>
#include <Thread.h>

#define irLeft 2
#define irRight 3

MatrixMini Mini;
Thread myThread = Thread();

void setup() {
  Serial.begin(9600);
  Mini.begin();
  myThread.onRun(detect);
  myThread.setInterval(10);
  
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);

}

void loop() {
  
  if(myThread.shouldRun()){
    myThread.run();
  }
  
  
}

void detect(){
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  int speed1 = 70;
  int g = 70;
  Serial.println("left:"+String(leftValue));
  Serial.println("right:" +String(rightValue));
  if(leftValue == 0 && rightValue == 0){
    running(speed1,speed1);
    Serial.println("直走");
  }else if(leftValue == 0 && rightValue ==1){
    //右轉
    running(speed1,speed1-g);
    Serial.println("右轉");
  }else if(leftValue == 1 && rightValue == 0){
    //左轉
    running(speed1-g,speed1);
    Serial.println("左轉");
  }else{
    running(0,0);
    Serial.println("停止");
  }
}

void running(int leftMotor,int rightMotor){
  Mini.M1.set(leftMotor);
  Mini.M2.set(rightMotor);
}
