# 函式
##　定義和呼叫函式
```
語法:
回傳值的資料型別  函式名稱([參數串列]){

	程式碼;
	[return value]
}
```

```c++
//============================================================================
// Name        : function1.ino
//定義函式，顯示「歡迎光臨」。

void setup() {
  Serial.begin(9600);
  sayHello();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void sayHello(){
  Serial.println("歡迎光臨!");
}
```

### 
```c++
// Name        : function2.ino
//輸入攝氏溫度，求華氏溫度
/*=============================

攝氏10度轉華氏溫度=50
==========================
請輸入攝氏溫度:19
華氏溫度=66.2

===============================*/

int value;
float result;

void setup() {
  Serial.begin(9600);
  Serial.print("攝氏10度轉華氏溫度=");
  Serial.println(temperature(10));
  Serial.println();
  Serial.print("請輸入攝氏溫度:");
  while(true){
    if(Serial.available()){
      value = Serial.parseInt();
      Serial.println(value);
      result = temperature(value);
      break;
    }
  }
  Serial.print("華氏溫度=");
  Serial.println(result);
}

void loop() {
  // put your main code here, to run repeatedly:

}

float temperature(int value){
  return 1.8 * value + 32;
}
```

```
*問題 transtemperature.ino
輸入華氏溫度，求攝氏溫度
顯示=====================
請輸入華氏溫度:xx
攝氏溫度=xx.xxxx
```

### return返回呼叫函式
在函式中return會傳回返回值，並會立即結束函式，也可以用以強迫結束函式，返回呼叫的程式
```
return <返回值>
```

```c++
// Name        : return1.cpp
//自鍵盤輸入一個數字n,顯示1...n。
/*=============================

請輸入數字 n:10
1 2 3 4 5 6 7 8 9 10

===============================*/


int inputNum;

void setup() {
  Serial.begin(9600);
  Serial.print("請輸入數字 n:");
  while(true){
    if(Serial.available()){
      inputNum = Serial.parseInt();
      Serial.println(inputNum);
      showNum(inputNum);
      Serial.println();
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void showNum(int n){
  int i = 1;
  while(true){
    if (i > n){
      return;
    }
    Serial.print(i);
    Serial.print(" ");
    i++;
  }

}

```

### 參數
### 傳值呼叫(call by value)
```c++
// Name        : callByValue1.ino
//callByValue


int speed;

void setup() {
  Serial.begin(9600);
  Serial.print("請輸入初始速度:");
  while(true){
    if(Serial.available()){
      speed = Serial.parseInt();
      Serial.println(speed);
      speed = turbo(speed);
      Serial.print("加速後的速度:");
      Serial.println(speed);
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

int turbo(int speed){
  Serial.print("加速前速度:");
  Serial.println(speed);
  return speed += 10;
}


```


### 傳參考呼叫(call by reference)
```c++
// Name        : callByReference.ino
//callByReference


int speed;

void setup() {
  Serial.begin(9600);
  Serial.print("請輸入初始速度:");
  while(true){
    if(Serial.available()){
      speed = Serial.parseInt();
      Serial.println(speed);
      turbo(speed);
      Serial.print("加速後的速度:");
      Serial.println(speed);
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void turbo(int& speed){
  Serial.print("加速前速度:");
  Serial.println(speed);
  speed += 10;
}


```
	
### 傳址呼叫(call by address)
```c++
// Name        : callByAddress.ino
//call by address


int speed;

void setup() {
  Serial.begin(9600);
  Serial.print("請輸入初始速度:");
  while(true){
    if(Serial.available()){
      speed = Serial.parseInt();
      Serial.println(speed);
      turbo(&speed);
      Serial.print("加速後的速度:");
      Serial.println(speed);
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void turbo(int* speed){
  Serial.print("加速前速度:");
  Serial.println(*speed);
  *speed += 10;
}
```

