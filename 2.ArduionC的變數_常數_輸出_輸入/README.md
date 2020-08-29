# 2.ArduionC的變數_常數_輸出_輸入

```c++
//arduinoC
//arduinoC的輸出
void setup() {
  Serial.begin(9600);  
  Serial.println("您好,Arduino");
}

void loop() {
  // put your main code here, to run repeatedly:
}


```

```c++
//arduinoC
//arduinoC的輸入輸出
void setup() {
  Serial.begin(9600);
  int englishScore = 60;
  Serial.println("請輸入您的英文分數:");
  
  while(true){
    if(Serial.available()){
      englishScore = Serial.parseInt();
      break;
    }
  }

  Serial.print("Hello! 您的英文分數是:");
  Serial.println(englishScore);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

# 資料型別和變數
```
宣告變數
資料型別 變數名稱 [ = 初始值]
```

```c++
//沒有初始值
int intA;
char a;
```

```c++
//有初始值
int intA = 100;
char a = 's';
```

## 變數的命名規則
```c++
第一個字元，只可以是英文字
第一個字元符號，只可以是_
文字內不可以有特殊符號,不可有空格
```

## 數值型別
數值型別 | 記憶體大小 | 範圍
------|------ | ---
char | 1 Byte | -128 ~ 127
byte | 1 Byte | 0 ~ 255
unsigned char | 1 Byte | 0 ~ 255
short | 2 Byte | -32768 ~ 32767
unsigned short | 2 Byte | 0 ~ 65535	
int | 4 Byte | -2147483648 ~ 2147483647
unsigned int | 4 Byte | 0 ~ 4294967295
long | 4 Byte | -2147483648 ~ 2147483647
long long | 8 Byte | ——————————-
unsigned long | 4 Byte | 0 ~ 4294967295
float | 4 Byte | 6,7位數
double | 8 Byte | 15位數


```
特殊字元
\'
\"
\n 換行
\t tab
```

```

請輸出:  
姓名      座號      電話  
李振聲    11        0229435437  
張四聲    13        0229435467  
```


```c++
//arduinoC
void setup() {
  Serial.begin(9600);
  
  Serial.print("姓名\t 座號 \t 電話\n");
  Serial.print("李振聲\t 11 \t 0220435437\n");
  Serial.print("張四聲\t 12 \t 0221435896\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

## 字元型別
```c++
char chrB;
chrB = ’A‘;
char chrC;
chrC = 65;
```


```c++
//arduinoC
//arduinoC的輸出
void setup() {
  Serial.begin(9600);  
  char characterA;
  characterA = 'A';
  Serial.print("characterA=");
  Serial.print('\'');
  Serial.print(characterA);
  Serial.println('\'');
  
  Serial.print("\n");
  //字串相加
  Serial.print("characterA=\'"+ (String)characterA + "\'");

  char characterB;
  characterB = 65;
  Serial.print("characterB=");
  Serial.print('\'');
  Serial.print(characterB);
  Serial.println('\'');
  
  Serial.print("\n");
  //字串相加
  Serial.print("characterB=\'"+ (String)characterB + "\'");
}

void loop() {
  // put your main code here, to run repeatedly:
}

```

## 字串型別(string)
```c++
string str1;
string str2 = "這是字串";
string str3 = "這是 \" C++ \",非常簡單";
cout << "\nstr1:" << str1 << "\n";
cout << "str2:" << str2 << endl;
cout << "str3:" << str3 << "\n";
```

```c++
//arduinoC
void setup() {
  Serial.begin(9600);
  String str1;
  String str2 = "這是字串";
  String str3 = "這是 \" ArduinoC \",非常簡單";

  Serial.print("str1:");
  Serial.println(str1);
  Serial.print("str2:");
  Serial.println(str2);
  Serial.print("str3:");
  Serial.println(str3);
}

void loop() {
  // put your main code here, to run repeatedly:

}

```

## 布林型別(bool)
```c++
bool bolA = true;
bool bolB = false;

cout << bolA;
cout << bolB;

true 代表 1
false 代表 0

1,2,3...代表true
只有0 ...代表false
``` 

```c++
//arduinoC
void setup() {
  Serial.begin(9600);
  bool bolA = true;
  bool bolB = false;

  Serial.println("bolA=" + (String)bolA);
  Serial.println("bolB=" + (String)bolB);
}

void loop() {
  // put your main code here, to run repeatedly:

}

```

## 型別轉換
#### 型別自動轉換
```c++
//C語言寫法
運算式中若含有不同的數值型別，編譯器會自動以值域較大的型別為轉換依據

float PI = 3.14159;
int radius = 10;
//PI * radius * radius 自動轉換為float
cout << "圓面積=" << PI * radius * radius; 
```

```c++
//arduinoC
//arduino已經有訂義PI
int radius = 10;

void setup() {
  Serial.begin(9600);
  Serial.print("area=");
  Serial.println(PI * radius * radius);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

```c++
如果是指字式，編譯器會自動將=右邊的資料型別轉換為左邊的資料型別。

int area;
area = PI * radius * radius; //自動由float轉換為int
```

```c++
//arduinoC
int area;
int radius = 10;

void setup() {
  Serial.begin(9600);
  area = PI * radius * radius;
  Serial.print("圓面積=");
  Serial.println(area);
  while(true){
    
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

```c++
short a = 3000;
int b;
b = a; //可以小轉大
char c;
c = b; //大轉小，資料會遺失
```

## 強制轉換

```
(資料型別) 變數名稱;
```

```c++
short a = 123;
int b;
b = (int) a; //可以強制小轉大
```

```c++
int a = 1234567;
short b;
b = (short)a; //大轉小，資料會遺失
```

```c++
//arduinoC
unsigned short chinese = 0, english = 0, math = 0;

void setup() {
  Serial.begin(9600);
  
  Serial.print("請輸入國文成績:(0~100):");  
  while(true){
    if(Serial.available()){
      chinese = Serial.parseInt();
      Serial.println(chinese);
      break;
    }
  }

  Serial.print("請輸入英文成績:(0~100):");  
  while(true){
    if(Serial.available()){
      english = Serial.parseInt();
      Serial.println(english);
      break;
    }
  }

  Serial.print("請輸入數學成績:(0~100):");  
  while(true){
    if(Serial.available()){
      math = Serial.parseInt();
      Serial.println(math);
      break;
    }
  }

  int sum = chinese + english + math;
  float average = sum / 3.0;
  Serial.print("您的總分是:");
  Serial.println(sum);

  Serial.print("您的平均是:");
  Serial.println(average);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
```



### Arduino C 的輸出


```c++ 
//使用Serial.print()方法
//輸出我們人類看的懂的文字
/*
  Uses a for loop to print numbers in various formats.
*/
void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  // print labels
  Serial.print("NO FORMAT");  // prints a label
  Serial.print("\t");         // prints a tab

  Serial.print("DEC");
  Serial.print("\t");

  Serial.print("HEX");
  Serial.print("\t");

  Serial.print("OCT");
  Serial.print("\t");

  Serial.print("BIN");
  Serial.println();        // carriage return after the last label

  for (int x = 0; x < 64; x++) { // only part of the ASCII chart, change to suit
    // print it out in many formats:
    Serial.print(x);       // print as an ASCII-encoded decimal - same as "DEC"
    Serial.print("\t\t");  // prints two tabs to accomodate the label lenght

    Serial.print(x, DEC);  // print as an ASCII-encoded decimal
    Serial.print("\t");    // prints a tab

    Serial.print(x, HEX);  // print as an ASCII-encoded hexadecimal
    Serial.print("\t");    // prints a tab

    Serial.print(x, OCT);  // print as an ASCII-encoded octal
    Serial.print("\t");    // prints a tab

    Serial.println(x, BIN);  // print as an ASCII-encoded binary
    // then adds the carriage return with "println"
    delay(200);            // delay 200 milliseconds
  }
  Serial.println();        // prints another carriage return
}
```

### Arduino輸入
```c++
//arduinoC
void setup() {  
  // initialize the serial communication:
  Serial.begin(9600);    
}

void loop() {
  String value;
  
  // check if data has been sent from the computer:
  if (Serial.available()) {    
    value = Serial.readString();
    //輸出字串
    Serial.println(value);    
  }
}
```

### Arduino C 的輸入輸出
```c++
//RGBLED燈
#讀取整數
#Serial.parseInt()

#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  
}

void loop() {
  //因為使用byte只能讀取0-255
  byte value;
  // check if data has been sent from the computer:
  if (Serial.available()) {
    // 只能解析0~255的數字
    value = Serial.parseInt();
    // set the brightness of the LED:
    Serial.println(value,DEC);
    Mini.LED1.setRGB(value, 0, 0);
    delay(2000);
    Mini.LED1.setRGB(0, 0, 0);
  }
}
```



