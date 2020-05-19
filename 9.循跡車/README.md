# 9循跡車
### 紅外線校對
![使用電工膠布](IMG_0359.jpg)  
![紅外線的校對開關](IMG_0360.jpg)

```c++
//紅外線校對
//面對背面方向
//D2 - 紅外線左模組
//D1 - 紅外線右模組

//白色-0
//黑色-1
#define irLeft 3
#define irRight 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.print("left:");
  Serial.println(leftValue);
  Serial.print("right:");
  Serial.println(rightValue);
  delay(500);
}
```

```c++
//循跡車
//人面對背面方向
//D2 - 紅外線左模組
//D1 - 紅外線右模組

//白色-0
//黑色-1
#include <MatrixMini.h>
#include <Thread.h>

MatrixMini Mini;
Thread myThread = Thread();

#define irLeft 3
#define irRight 2

void setup() {
  Mini.begin();
  myThread.onRun(detect);
  myThread.setInterval(50);  
  Serial.begin(9600);
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  delay(1)

}

void detect(){
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.print("leftValue:");
  Serial.println(leftValue);
  Serial.print("rightValue:");
  Serial.println(rightValue);
  int speed = 30;
  if(leftValue == 0 && rightValue == 0){
    //直線
    running(speed, speed);
    Serial.println("直線");
  }else if(leftValue == 0 && rightValue == 1){
    //右轉
    running(speed, speed-=10);
    Serial.println("右轉");
  }else if(leftValue == 1 && rightValue == 0){
    //左轉
    running(speed-=10, speed);
    Serial.println("左轉");
  }else{
    //停止
    running(0, 0);
    Serial.println("停止");
  }
}

void running(int leftMotor, int rightMotor){
  //M1 = 左輪
  //M2 = 右輪
  Mini.M1.set(leftMotor);
  Mini.M2.set(rightMotor);
}
```

