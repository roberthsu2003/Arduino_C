# 8前進,後退,旋轉
## MR200安裝圖(M1左輪,M2右輪,注意馬達黑線和白線)
![MR200-M1,M2左右輪](IMG_0352.jpg)

## MR210安裝圖(M1左輪,M2右輪,注意馬達黑線和白線)
![MR210-M1,M2左右輪](IMG_0431.png)

```
MR200
//M1 = 左輪
//M2 = 右輪
M1,M2接線圖,黑白線不行接反

```
![MR200-M1,M2接線圖](IMG_0351.jpg)

```
MR210
//M1 = 左輪
//M2 = 右輪
M1,M2接線圖,黑白線不行接反

```
![MR210-M1,M2接線圖](IMG_0432.png)


```
//停止0

//慢速30
//中速50
//快速75
//高速100

//慢速後退-30
//中速後退-50
//快速後退-75
//高速後退-100
```

```c++
// Name        : car.ino
//以4種速度前進或後退3秒

#include <MatrixMini.h>

MatrixMini Mini;
void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600);           // set up Serial library at 9600 bps

  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  int i=30;
  
  Mini.M1.set(i);  
  Mini.M2.set(i);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}


void loop() { 
  
}
```

```c++
// Name        : car.ino
//以4種速度旋轉3秒

#include <MatrixMini.h>

MatrixMini Mini;
void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600);           // set up Serial library at 9600 bps

  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  int i=30;
  
  Mini.M1.set(i);  
  Mini.M2.set(-i);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}


void loop() { 
  
}
```


```c++
// Name        : car2.ino

#include <MatrixMini.h>
//前進3秒右轉1秒前進3秒
MatrixMini Mini;
void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  
    
  Mini.M1.set(30);  
  Mini.M2.set(30);
  delay(3000);
  Mini.M1.set(30+20);  
  Mini.M2.set(30);
  delay(1000);
  Mini.M1.set(30);  
  Mini.M2.set(30);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}


void loop() { 
  
}
```

```c++
#include <MatrixMini.h>
//前進3秒左轉2秒前進3秒
MatrixMini Mini;
void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  
  int i = 30;
  Mini.M1.set(i);  
  Mini.M2.set(i);
  delay(3000);
  Mini.M1.set(i);  
  Mini.M2.set(i+20);
  delay(2000);
  Mini.M1.set(i);  
  Mini.M2.set(i);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}


void loop() { 
  
}

```


![光敏電阻接線](IMG_0355.jpg)
![光敏電阻連接小車](IMG_0470.jpg)
[影片展示](https://youtu.be/Pf6Lla-hKBw)

```c++
//將光敏電阻插入至A1
#define LIGHT_SENSOR A1
#define LIGHT_DIGITOR A0

//一開始要取得目前光線的平均值
//光線變暗時,向左或向右旋轉3秒
MatrixMini Mini;

int lightAvg;
void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  long lightTotal=0;
  for(int i=0; i<10; i++){
     lightTotal += analogRead(LIGHT_SENSOR);
  }
  lightAvg = lightTotal/10;
  Serial.print("目前光線平均強度");
  Serial.println(lightAvg);
}
void loop() { 
  Serial.println(analogRead(LIGHT_SENSOR));
  int currentLight = analogRead(LIGHT_SENSOR);
  int distance = currentLight - lightAvg;
  if(distance > 100){
    switch(distance%2){
      case 0:
        turn(30);
        break;
      case 1:
        turn(-30);
        break;
    }      
  }
  delay(500);
}

void turn(int i){  
  Mini.M1.set(i);  
  Mini.M2.set(-i);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}
```

![超音波接線](IMG_0357.jpg)
[影片展示](https://youtu.be/_M_bf6qUX-E)

```c++
//永遠保持社交距離的小車
//超音波插入至A1

//藍線A0 - Echo
//白線A1 - Trig
//安裝NewPing Library

#include <NewPing.h> 
#include <MatrixMini.h>
#define TRIGGER_PIN  A1
#define ECHO_PIN     A0
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
MatrixMini Mini;


void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  
}

void loop() { 
  delay(50);
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  Serial.print("Ping: ");
  Serial.print(distance);
  Serial.println("cm");
  if(distance < 10 && distance > 0){
    back(-75);
  }
}

void back(int i){  
  Mini.M1.set(i);  
  Mini.M2.set(i);
  delay(1000);
  Mini.M1.set(0);
  Mini.M2.set(0);
  delay(1000);
  Mini.M1.set(-i);  
  Mini.M2.set(-i);
  delay(1000);
  Mini.M1.set(0);
  Mini.M2.set(0);
  
}

```