# 光線感測流程判斷
## 流程控制
```
arduinoC的流程控制的指令分為2部份
1判斷(if else,switch case)
2迴圈(for,whiel,do..while)
```
```
if(條件式){
  程式區塊
  ......
}
```

## 單向選擇(if...)

```c++
//arduinoC
void setup() {
  Serial.begin(9600);
  String password;
  Serial.println("請輸入密碼:");

  while(true){
    if(Serial.available()){
      password = Serial.readString();
      if(password == "1234"){
        Serial.println("密碼正確!歡迎光臨!");        
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

## 雙向選擇(if ... else)

```c++
if (條件式){
    程式區塊一
}else{
    程式區塊二
}

//========================================================

請輸入密碼:5678
密碼錯誤,請重新輸入

//========================================================

//arduinoC
void setup() {
  Serial.begin(9600);
  String password;
  Serial.println("請輸入密碼:");

  while(true){
    if(Serial.available()){
      password = Serial.readString();
      if(password == "1234"){
        Serial.println("密碼正確!歡迎光臨!");
        break;        
      }else{
        Serial.println("密碼錯誤!請重新輸入!");
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
```


```c++
*question 
成績及格判斷
請使用者輸入成績，若成績大於等於60分，則LED1顯示綠燈，否則LED1顯示紅燈。

顯示:
請輸入成績:78
及格!(不及格!)
```

```
//arduinoC
#include <MatrixMini.h>
MatrixMini Mini;
void setup() {
  Mini.begin();
  Mini.LED1.setRGB(0, 0, 0);
  Serial.begin(9600);
  unsigned int score;
  Serial.println("請輸入成績:"); 
}

void loop() {
  if(Serial.available()){
    int score = Serial.parseInt();
      if (score >= 60){
        Serial.println("及格!");
        Mini.LED1.setRGB(0, 255, 0);
      }else{
        Serial.println("不及格!");
        Mini.LED1.setRGB(255, 0, 0);
      }
  }

}

```

```c++
*作業
試用if-else敘述，選寫一個判斷輸入的數字為奇數(LED1亮綠燈)或偶數(LED2亮綠燈)的程式,

顯示=============
請輸入數字:15
您輸入的15是奇數
```
[解題](./odd_even/odd_even.ino)



```c++

```

## 多向選擇(if ... else if..... else)
```c++

if (條件式一){
    程式區塊一
}else if(條件式二){
    程式區塊二
}else if(條件式三){
     程式區塊三
}else{
    程式區塊else
}


//========================================================

請輸入購買金額:130000
實付金額是:104000元

//========================================================



// Name        : discount.ino
//輸入顧客購買金額，若金額在100000元打8折，50000打85折，30000打9折，10000打95折

//ArduinoC
void setup() {
  Serial.begin(9600);
  Serial.print("請輸入購買金額:");  
}

void loop() {
  //必需使用long, 不然會超出範圍
  long money;
  long payMoney;
  if(Serial.available()){
      money = Serial.parseInt();
      Serial.print("您購買的金額是:");
      Serial.println(money);
      
      if(money >= 100000){
        payMoney = money * 0.8;
      }else if(money >= 50000){
        payMoney = money * 0.85;
      }else if(money >= 30000){
        payMoney = money * 0.9;
      }else if (money >= 10000){
        payMoney = money * 0.95;
      }else{
        payMoney = money;
      }
      Serial.print("實付金額是:");
      Serial.print(payMoney);
      Serial.println("元");   
      Serial.println("========================");
  }

}
```

```c++
*question light.ino
*使用光敏電阻,檢查目前的亮度
//小於等於100 很亮
//小於等於200,大於100 亮
//小於等於400,大於200有點亮
//小於等於600,大於400有點暗
//小於等於800,大於600暗
//小於等於1023,大於800 很暗
*當狀態改變時，請閃爍一下LED2

#include <MatrixMini.h>
#define LIGHT_SENSOR A1
#define LIGHT_DIGITOR A0

MatrixMini Mini;

String state;
String preState="";

void setup() {
  Mini.begin();
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(A1);
  
  if(analogValue<100){
    state = "很亮";
  }else if (analogValue<200){
    state = "亮";
  }else if (analogValue<400){
    state = "有點亮";
  }else if(analogValue<600){
    state = "有點暗";
  }else if(analogValue<800){
    state = "暗";
  }else{
    state = "很暗";
  }

  if (state != preState){
    Serial.println("狀態改變");
    Mini.LED2.setRGB(255,0, 0);
    delay(500);
    Mini.LED2.setRGB(0,0, 0);
    preState = state;
  }
  
  Serial.println(state);
  delay(500);
}
```


## switch case:

```c++
switch(表示式){
    case value1:
        程式區塊1
		break;
    case value2:
        程式區塊2
		break;
    case valueN:
        程式區塊n
		break;
    default:
        程式區塊
	
}


//========================================================

num1=20,num2=4
請輸入要執行的運算(+ - * /):+
num1+num2=24

//========================================================


// Name        : calculate.cpp
//讓使用者輸入加、減、乘、除運算子, 就會顯示運算結果

#include <iostream>
using namespace std;

int main() {
	char op;
	int num1 = 20, num2 = 4;
	cout << "num1=20,num2=4\n";
	cout << "請輸入要執行的運算(+-*/):";
	cin >> op;
	switch(op){
	case '+':
		cout << "num1+num2=" << num1+num2 << "\n";
		break;
	case '-':
			cout << "num1-num2=" << num1-num2 << "\n";
			break;
	case '*':
			cout << "num1*num2=" << num1*num2 << "\n";
			break;
	case '/':
			cout << "num1/num2=" << num1/num2 << "\n";
			break;
	default:
			cout << "無法執行運算!\n";
			break;
	}
	return 0;
}


```

```c++
*作業
請使用三元運算子? : 製作一個判斷奇偶數的程式，程式的執行結果。如果是奇數，讓蜂鳴器響一次


顯示========
請輸入任意整數:50
您這個數是:偶數
```
[解題](./ternary/ternary.ino)

```
*question season_s.cpp
讓使用者入1-4的數字，由1到4分別顯示春天、夏天、秋天、冬天。

顯示:
請輸入現在是第幾季(1-4):1
現在是春天!
```


```c++ 
*question robot.cpp
製作如下圖範例，點選中文的選項之後，會顯示對應的英文

顯示===============
1.您好嗎?
2.晚安
3.早安
請選擇中文的選項<1-3>:2
英文是:good evening
```
[解題](https://repl.it/@roberthsu2003/robot)

```c++
*question

下列為綜合所得稅試算
輸入使用者綜合所得淨額後，印出稅率，累進差額，還有今年應納稅額


顯示========================
請輸入綜合所得淨額:1500000

綜合所得淨額: 1500000 元
稅額: 20%
---------------------
稅金: 300000 元
累進差額:1300000
----------------------
今年應納稅額: 170000 元			
```

級別	| 綜合所得淨額			|		   稅額	  |    累進差額
----|---------------|-------------|-----------
1	|	0 ~ 540,000			        | 5%		  |    0
2	| 540,001 ~ 1,200,000		  | 10%	    | 36,400
3	|	1,200,001 ~ 2,420,000	  | 20%     |  130,000
4	|	2,420,001 ~ 4,530,000	  | 30%	    |  365,000
5	|	4,530,001以上          | 40%	    |  805,000		



```c++
*question member.cpp
輸入您的存款金額並給予適當的利率及會員等級.
1存款大於等於1000000利率4%,否則利率2%
2存款大於等於1000000為A級會員，存款500000-999999為B級會員，其他為C級會員

顯示================================
請輸入您的存款:750000

您的利率是2%
會員等級是B級
```




```c++

//parkingFee

//假設某個停車場的費率是停車2小時以內，每半小時30元，超過2小時，但未滿4小時的部份，每半小時40元，超過4小時以上的部份，每半小時60元，未滿半小時部分不計費。
//如果您從早上10點23分停到下午3點20分，請撰寫程式計算共需繳交的停車費
//輸入說明:(24小時制)

顯示:
請輸入進場時間:9 15
請輸入出場時間:13 56
進場時間是9-15
出場時間是13-56
停車的總分數281
停車的總費用是340
```


