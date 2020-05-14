

# 陣列
## 一維陣列初值設定
```
資料型別 陣列名稱[陣列長度 n];
陣列名稱[0] = 值1;
陣列名稱[1] = 值2;
........
```

```c++
// Name        : array1.ino
//建立陣列語法

void setup() {
  Serial.begin(9600);
  int scores[3];
  scores[0] = 70;
  scores[1] = 80;
  scores[2] = 90;
  Serial.println(scores[0]);
  Serial.println(scores[1]);
  Serial.println(scores[2]);
}

void loop() {
  // put your main code here, to run repeatedly:

}

```

### 宣告陣列變數同時設定各元素初始值的語法為:

```
資料型別 陣列名稱[n] = {值1,值2,值3,......,值n}
```

```c++
// Name        : array2.ino
//建立陣列語法
//宣告時同時給值
//============================================================
70,80,90
//============================================================


void setup() {
  Serial.begin(9600);
  int scores[3] = {70, 80, 90};
  Serial.println(scores[0]);
  Serial.println(scores[1]);
  Serial.println(scores[2]);
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

```c++
*問題 fruit_s.ino
建立一個包含三個元素的字串陣列並設定初始值，代表個人的三種最喜愛的水果名稱，再依序顯示:

顯示=========
我喜歡的第一種水果:xxx
我喜歡的第二種水果:xxx
我喜歡的第三種水果:xxxx
```


### 使用迴圈設定陣列
	
```c++
// Name        : score1.ino
//建立一個包含五個元素的整數陣列，讓使用者輸入五位學生的成績，然後計算班級總成績及平均成績
//============================================================
請輸入第1位學的成績78
請輸入第2位學的成績89
請輸入第3位學的成績67
請輸入第4位學的成績90
請輸入第5位學的成績89
全班總成績為:413分,平均為82.6分
//============================================================
const int nums = 5;
int scores[nums];
int sum=0;
double ave;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<nums; i++){
    Serial.print("請輸入第");
    Serial.print(i+1);
    Serial.print("位學生的成績:");
    while(true){
      if(Serial.available()){
        scores[i] = Serial.parseInt();
        Serial.println(scores[i]);
        break;
      }
    }    
  }

  for(int i=0; i<nums; i++){
    sum += scores[i];
  }

  ave = (double)sum / nums;
  Serial.print("全班總成績為:");
  Serial.print(sum);
  Serial.print("分,平均為");
  Serial.print(ave);
  Serial.println("分");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

### 陣列參數
```c++
//============================================================================
// Name        : array11.cpp
//以陣列當作參數，觀查陣列傳遞變化


int ary[] = {212, 328, 765, 986};

void setup() {
  Serial.begin(9600);
  int count = sizeof(ary)/ sizeof(ary[0]);
  Serial.println("呼叫showArray");
  showArray(ary, count);
  sub2(ary, count);
  showArray(ary, count);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void showArray(int tempary[], int count){

  for(int i=0; i<count; i++){
    Serial.print("any[");
    Serial.print(i);
    Serial.print("]=");
    Serial.print(tempary[i]);
    Serial.print("\t");
  }
  Serial.print("\n\n");
}

void sub2(int tempary[], int count){
  for(int i=0; i<count; i++){
    tempary[i] *= 2;
  }
}

```


### 
```c++
// Name        : average.ino
//使用超音波測計算每收集10個的平均距離

//藍線A0 - Echo
//白線A1 - Trig


#include <NewPing.h>
#include <Thread.h> 
#define TRIGGER_PIN  A1
#define ECHO_PIN     A0
#define MAX_DISTANCE 200

 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Thread myThread = Thread();

byte distances[10];
void setup() {
  Serial.begin(9600);
  myThread.onRun(callBack);
  myThread.setInterval(50);
}
 
void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  
}

void callBack(){
  static byte count = 0;
  static int sumDis=0;
  if(count == 10){
    for(int i=0; i<=9; i++){
      sumDis += distances[i];      
    }
    Serial.print(sumDis/10);
    Serial.println("cm");
    count = 0;
    sumDis = 0;
  }
  
  int uS = sonar.ping();  
  distances[count] = uS / US_ROUNDTRIP_CM;
  count++;
}
```

```c++
// Name        : min.ino
//使用光敏電阻計算每收集10個的最小值是

//光敏電阻接A3孔
#include <Thread.h>
#define LIGHT_SENSOR A3
#define LIGHT_DIGITOR A2

Thread myThread = Thread();
int lights[10];
void setup() {
  
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);
  myThread.onRun(callBack);
  myThread.setInterval(50);  
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
}

void callBack(){
  static byte count = 0;
  if(count == 10){
    int min = 1000;
    for(int i=0; i<=9; i++){
      if(lights[i] < min){
        min = lights[i];
      }
    }
    Serial.print("10個值的最小值是:");
    Serial.println(min);
    count = 0;
  }
  lights[count] = analogRead(LIGHT_SENSOR);
  count++;
  
}
```



### 陣列的應用:泡沫排序

```c++
// Name        : bubble.cpp
//使用紅外線感測器收集10個數值,由小到大排序,取出中間值
//============================================================

排序前:
45 78 24 69 91 67 89 54 90 10
排序後:
10 24 45 54 67 69 78 89 90 91
中間值:
69

//============================================================

//紅外線接A3孔
#include <Thread.h>
#define irLeft A2

Thread myThread = Thread();
int irs[10];

void setup() {  
  Serial.begin(9600);
  myThread.onRun(callBack);
  myThread.setInterval(50);  
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
}

void callBack(){
  static byte count = 0;
  if(count == 10){    
    int middle = median(irs);
    Serial.print("中間值是");
    Serial.print(middle);
    count = 0;
  }
  irs[count] = analogRead(irLeft);
  count++;  
}

int median(int ten[]){
  int temp;
  Serial.println("排序前");
  for(int i=0; i<=9; i++){
    Serial.print(ten[i]);
    Serial.print("\t");
  }
  Serial.println();

  //陣列排序
  for(int i=0; i <= 9-1; i++){
    for(int j=i+1; j <=9; j++){
      if(ten[i] > ten[j]){
        temp = ten[i];
        ten[i] = ten[j];
        ten[j] = temp;
      }
    }
  }

  Serial.println("排序後");
  for(int i=0; i<=9; i++){
    Serial.print(ten[i]);
    Serial.print("\t");
  }
  Serial.println();
  return ten[5];
}
```


###  
```c++
//============================================================================
// Name        : biglottery.ino
//撰寫一個大樂透電腦自動選號程式，程式執行會以亂數的方式顯示1-49之間七個不重複的大樂透號碼。
//每按一次按鈕就會產生一次

//============================================================

本期大樂透電腦選號號碼如下:

2 28 8 42 49 20 15

特別號:15

//============================================================

#include <MatrixMini.h>
MatrixMini Mini;

bool buttonState;
int pressCount=0;

void setup() {
  Mini.begin();
  Serial.begin(9600);  
  Serial.println("大樂透電腦選號器"); 
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(buttonState != Mini.BTN1.get()){
    delay(50);
    if(buttonState != Mini.BTN1.get()){
      pressCount++;
      buttonState = !buttonState;
      Serial.println(pressCount);
      callBack();
    }    
  } 
  
}

void lottery(){
  int lot[49];
  int choose[7];
  int num = 7;
  int maxIndex = 48;

  for(int i=0;i<49;i++){
    lot[i] = i+1;   
  }
  
  for(int i=0;i<7;i++){
    int randIndex = random(maxIndex+1);
    Serial.println(randIndex);
    choose[i] = lot[randIndex];
    lot[randIndex] = lot[maxIndex];
    maxIndex--;
  }

  Serial.println("本期大樂透電腦選號號碼如下:\n");
  for(int i=0; i<num; i++){
    Serial.print(choose[i]);
    Serial.print(" ");
  }
  Serial.print("\n\n特別號");
  Serial.print(choose[6]);
  Serial.println();

}

void callBack(){
 if(pressCount % 2 == 0){
  lottery();
 }
}
```

```c++
*問題 ninenine.ino
以程式建立 9 x 9 的二維整數陣列，陣列內容是九九乘法表的乘積，並將之輸出

顯示==========
1*1=1   1*2=2   1*3=3   1*4=4   1*5=5   1*6=6   1*7=7   1*8=8   1*9=9
2*1=2   2*2=4   2*3=6   2*4=8   2*5=10  2*6=12  2*7=14  2*8=16  2*9=18
3*1=3   3*2=6   3*3=9   3*4=12  3*5=15  3*6=18  3*7=21  3*8=24  3*9=27
4*1=4   4*2=8   4*3=12  4*4=16  4*5=20  4*6=24  4*7=28  4*8=32  4*9=36
5*1=5   5*2=10  5*3=15  5*4=20  5*5=25  5*6=30  5*7=35  5*8=40  5*9=45
6*1=6   6*2=12  6*3=18  6*4=24  6*5=30  6*6=36  6*7=42  6*8=48  6*9=54
7*1=7   7*2=14  7*3=21  7*4=28  7*5=35  7*6=42  7*7=49  7*8=56  7*9=63
8*1=8   8*2=16  8*3=24  8*4=32  8*5=40  8*6=48  8*7=56  8*8=64  8*9=72
9*1=9   9*2=18  9*3=27  9*4=36  9*5=45  9*6=54  9*7=63  9*8=72  9*9=81
============================

unsigned short elements[9][9];
void setup() {
  Serial.begin(9600);   
  for(int i = 0; i<9; i++){
    for(int j =0; j<9; j++){
      elements[i][j] = (i+1) * (j+1);
    }
  }

  for(int i = 0; i<9; i++){
    for(int j =0; j<9; j++){
      Serial.print(i+1);
      Serial.print("*");
      Serial.print(j+1);
      Serial.print("=");
      Serial.print(elements[i][j]);
      Serial.print("\t");
    }
    Serial.println();
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

```c++
//蜂鳴器
/*
 I/O腳接 pin3
Melody

*/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(3);
    digitalWrite(3, HIGH);
  }
}

void loop() {
  // no need to repeat the melody.
}
```

