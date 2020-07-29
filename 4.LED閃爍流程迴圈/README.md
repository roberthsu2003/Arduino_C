# LED閃爍流程迴圈
# 迴圈

## 執行固定次數的迴圈for
```
for ([變數初始化宣告]; [條件判斷]; [改變量]){
	程式區塊
}
```

```c++
//============================================================================
// Name        : for1.ino
//計算2 - 10所有偶數的總和
//================================================================
第 1 次迴圈的 i = 2,總和為:2
第 2 次迴圈的 i = 4,總和為:6
第 3 次迴圈的 i = 6,總和為:12
第 4 次迴圈的 i = 8,總和為:20
第 5 次迴圈的 i = 10,總和為:30
//=================================================================
#define BUZZER 3

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH); //一開始不要有聲音
  
  int sum = 0;
  for(int i=2;i<=10;i+=2){
    sum += i;
    Serial.print("第");
    Serial.print(i/2);
    Serial.print("次迴圈的i=");
    Serial.print(i);
    Serial.print(",總和為");
    Serial.println(sum);
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    delay(1000);
  }
}

void loop() {

}
```


### 

```c++
//============================================================================
// Name        : for2.ino
//計算固定中的支出，媽媽每天會將家裡的花費記錄下來，並且計算本週的花費總和
//每輸入一次就響一次
//================================================================
請輸入星期1 的支出567
請輸入星期2 的支出456
請輸入星期3 的支出567
請輸入星期4 的支出890
請輸入星期5 的支出345
請輸入星期6 的支出534
請輸入星期日 的支出678
本星期的支出為:4037元
//==================================================================

#define BUZZER 3

void setup() {
  //啟動BUZZER
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,HIGH);
  Serial.begin(9600);

  int n = 0;
  int sum = 0;
  for(int i=1; i<=7; i++){
    digitalWrite(BUZZER,LOW);
    delay(100);
    digitalWrite(BUZZER,HIGH);
    
    if(i==7){
      Serial.print("請輸入星期日的支出:");      
    }else{
      Serial.print("請輸入星期"+(String)i+"的支出:");
    }
    

    while(true){
      if(Serial.available()){
        n = Serial.parseInt();
        Serial.println(n);
        sum += n;
        break;
      }
    }
  }

  Serial.print("本星期的支出為:" + (String)sum + "元");
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

### 
```c++
//=======================================================================
// Name        : forNest2.ino
//利用2層迴圈列印九九乘法表
//=======================================================================
1*1=1   1*2=2   1*3=3   1*4=4   1*5=5   1*6=6   1*7=7   1*8=8   1*9=9
2*1=2   2*2=4   2*3=6   2*4=8   2*5=10  2*6=12  2*7=14  2*8=16  2*9=18
3*1=3   3*2=6   3*3=9   3*4=12  3*5=15  3*6=18  3*7=21  3*8=24  3*9=27
4*1=4   4*2=8   4*3=12  4*4=16  4*5=20  4*6=24  4*7=28  4*8=32  4*9=36
5*1=5   5*2=10  5*3=15  5*4=20  5*5=25  5*6=30  5*7=35  5*8=40  5*9=45
6*1=6   6*2=12  6*3=18  6*4=24  6*5=30  6*6=36  6*7=42  6*8=48  6*9=54
7*1=7   7*2=14  7*3=21  7*4=28  7*5=35  7*6=42  7*7=49  7*8=56  7*9=63
8*1=8   8*2=16  8*3=24  8*4=32  8*5=40  8*6=48  8*7=56  8*8=64  8*9=72
9*1=9   9*2=18  9*3=27  9*4=36  9*5=45  9*6=54  9*7=63  9*8=72  9*9=81
	
//=======================================================================

void setup() {
  Serial.begin(9600);
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
      Serial.print(i);
      Serial.print("*");
      Serial.print(j);
      Serial.print("=");
      Serial.print(i*j);
      Serial.print("\t");
    }
    Serial.print("\n");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

## 巢狀迴圈
```c++
//============================================================================
// Name        : forNest1.cpp
//利用2層迴圈列印「井」字，將其排列成直角三角形
//每輸出一個「井」字，就BTN2就閃爍一次，每輸出2個「井」字，就BTN2就閃爍2次....
//=======================================================
#
##
###
####
#####
//====================================================


#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  
  for(int i=1; i<=5; i++){
    for(int j=1; j<=i; j++){
      Serial.print("#");
      Mini.LED2.setRGB(255, 0, 0);
      delay(100);
      Mini.LED2.setRGB(0, 0, 0);
      delay(100);
    }
    Serial.println();
    delay(1000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
```


## 不固定次數的迴圈
```c++
while(條件判斷)
{
	程式敘述;
	........
}
```

```c++
while迴圈要特別注意，必須設定條件判斷的中止條件，以便可以停止迴圈的執行，否則會進入無窮迴圈的窘境
//可以指定執行次數的while迴圈
int n=1, sum;
while(n<10){
	sum += n;
}
```

	
```c++
//============================================================================
// Name        : while2.cpp
//小明想要存錢買一輛機車,機車每輛30000元，他將每月存的錢輸入，當存款足夠買機車時，就顯示提示訊息告知。
//存款不足，顯示紅燈，響一次
//存款足夠，顯示綠燈，響音樂
//============================================================================
請輸入第1個月份的存款:4567
請輸入第2個月份的存款:3456
請輸入第3個月份的存款:4567
請輸入第4個月份的存款:4567
請輸入第5個月份的存款:4567
請輸入第6個月份的存款:5678
請輸入第7個月份的存款:7890
恭喜! 已經存夠了，存了7個月的總存款為:35292元。
//============================================================================



#include <MatrixMini.h>

MatrixMini Mini;
int num=0, inputNum;
long deposit=0; 

void setup() {
  Serial.begin(9600);
  Mini.begin();
  Mini.LED1.setRGB(255,0, 0);
  Mini.LED2.setRGB(255,0, 0);

   while(deposit < 30000){
    num++;
    Serial.print("請輸入第");
    Serial.print(num);
    Serial.print("個月份的存款:");
    while(true){
      if(Serial.available()){        
        inputNum = Serial.parseInt();
        Serial.println(inputNum);
        deposit += inputNum;
        break;
      }
    }
    Mini.LED1.setRGB(255,0, 0);
    Mini.LED2.setRGB(255,0, 0);
  }
  Mini.LED1.setRGB(0,255, 0);
  Mini.LED2.setRGB(0,255, 0);
  Serial.print("恭喜!已經存夠了,存了");
  Serial.print(num);
  Serial.print("個月的總存款為:");
  Serial.print(deposit);
  Serial.println("元");
}

void loop() {
 
}
```


```c++
while迴圈取代for迴圈
for(int i=0; i<=5; i++)
{
	cout << "這是第" << i << "次迴圈";
}

//使用while迴圈達到相同結果
int i=0;
while(i<=5){
	cout << "這是第" << i << "次迴圈";
	i++;
}
```



```c++
先執行再判斷
do{
	程式敘述;
	.........
}while(條件判斷);

//============================================================================
// Name        : dowhile2.cpp
//預設的密碼為5678，使用者若輸入的密碼錯誤，將不斷出現輸入密碼訊息，直到輸入的密碼正確才顯示正確訊息
//密碼錯誤,發出單一聲音,燈光顯示紅燈
//密碼正確,發出不同聲音,燈光顯示綠燈
//
//============================================================================
請輸入密碼:1234
請輸入密碼:2345
請輸入密碼:3456
請輸入密碼:4567
請輸入密碼:5678
恭喜!您的密碼正確了!請進
//============================================================================
//copy sound.h和sound.cpp
#include "sound.h"
//蜂鳴器接D1
String password;
Sound s(3);
void setup() {
  Serial.begin(9600);  
  
  do{
    Serial.print("請輸入密碼:");
    while(true){
      if(Serial.available()){
        password = Serial.readString();
        Serial.println(password);
        break;
      }
    }
    s.beep(200);
  }while(password != "5678");
  Serial.println("恭喜!你的密碼正確了!請進");
  s.bee();
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
```



## break可以跳出迴圈
```c++
while1_s.ino
小美是一位教師，請你以while迴圈方式為小美設計一個輸入成績的程式，如果同時按BTN1和BTN2表示成績輸入結束，在輸入成績結束後顯示班上總成績及平均成績。

顯示===============
請輸入第1位學生的成績:89
請輸入第2位學生的成績:78
請輸入第3位學生的成績:68
請輸入第4位學生的成績:89
全班總成績為:XXX分, 平均為XX.XX分
=========================================
#蜂鳴器接D4

#include "sound.h"
#include <MatrixMini.h>

Sound s(6);
MatrixMini Mini;

void setup() {
  Serial.begin(9600);
  Mini.begin();
  bool state = false;
  int num = 0;
  int score=0;
  int sum=0;
  do{
    Serial.print("請輸入第");
    Serial.print(num+1);
    Serial.print("學生的成績:");
    while(true){
      if(Serial.available()){
        score = Serial.parseInt();
        Serial.println(score);
        s.beep(200);        
        break;
      }
      if(Mini.BTN1.get()==1 && Mini.BTN2.get()==1){
        state = true;
        break;
      }
    }
    
    if(state){
      Serial.println();
      break;
    }
    sum += score;
    num += 1;
  }while(true);
  s.beep(500);
  
  Serial.print("全班總成績為:");
  Serial.print(sum);
  Serial.print("平均分數為");
  Serial.println((float)sum / num);
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

## continue強制回到迴圈起始位置
```c++
continue.ino

請設計一個程式，讓使用者輸入數值(響一短音)，只有加總正偶數值，不加總正奇數值，如果輸入負數，結束程式(響一長音)。
顯示:========================================
請輸入第1個數值:456
請輸入第2個數值:455
請輸入第3個數值:123
請輸入第4個數值:-1
所有輸入的正偶數的加總是:xxxxxxx
=================================
#import "sound.h"
Sound s(6);

void setup() {
  Serial.begin(9600);
  int num=0;
  int inputNum;
  int sum=0;
  do{
    Serial.print("請輸入第");
    Serial.print(num + 1);
    Serial.print("個數值:");

    while(true){
      if(Serial.available()){
        inputNum = Serial.parseInt();
        Serial.println(inputNum);
        s.beep(200);
        break;
      }
    }
    
    if(inputNum < 0){
      s.beep(1000);
      break;
    }
    num ++;
    
    if(inputNum % 2 == 1){
      continue;
    }
    sum += inputNum;

  }while(true);
  Serial.print("所有輸入的正偶數的加總是:");
  Serial.println(sum);
}

void loop() {
  // put your main code here, to run repeatedly:

}

```



```c++ 
*問題 nestedLoop1.ino
試寫出下列數字排列的程式
顯示1個數字(響1次,並燈光亮1次)
顯示2個數字(響2次,並燈光亮2次) 
.... 
顯示=================================
	5
   44
  333
 2222
11111



#include "sound.h"
#include <MatrixMini.h>

Sound s(6);
MatrixMini Mini;

void setup() {
  Serial.begin(9600);
  Mini.begin();
  for(int i=5; i >= 1; i--){
    for(int j=1; j <= 5; j++){
      if(j >= i){
        Serial.print(i);
        s.beep(200);
        Mini.LED1.setRGB(255,0, 0);        
        Mini.LED2.setRGB(255,0, 0);
        delay(200);
        Mini.LED1.setRGB(0,0, 0);        
        Mini.LED2.setRGB(0,0, 0);

      }else{
        delay(200);
        Serial.print(' ');
      }
      
    }
    delay(200);
    Serial.println();
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
```


