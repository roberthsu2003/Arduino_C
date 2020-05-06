# 亂數和時間操控
```
#arduinoC 控制按鈕
#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin(); 
  Serial.begin(9600);

  Serial.println("\n Matrix Mini Button Test \n");
}

void loop() {
  Serial.print("  Button 1: "); Serial.print(Mini.BTN1.get());
  Serial.print("\tButton 2: "); Serial.print(Mini.BTN2.get());
  Serial.println();
  delay(50);
}
```



```c
#arduino C
#使用randomSeed()
#使用random()

long randNumber;

void setup() {
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

void loop() {
  // print a random number from 0 to 299
  randNumber = random(300);
  Serial.println(randNumber);

  // print a random number from 10 to 19
  randNumber = random(10, 20);
  Serial.println(randNumber);

  delay(1000);
}
```
```c++
break可以跳出迴圈

//============================================================================
// Name        : guess.cpp
//猜數字遊戲
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	int guess;
	int min = 1;
	int max = 99;
	int keyin;
	int count = 0;
	srand(time(NULL));
	guess = rand() % max + min;
	cout << "===============猜數字遊戲=================:\n\n";
	do{
		cout << "猜數字範圍" << min << "~" << max << ":";
		cin >> keyin;
		count++;

		if(keyin >=min && keyin <=max){
			if(keyin == guess){
				cout << "賓果!猜對了,答案是" << guess << endl;
				cout << "您猜了" << count << "次\n\n";
				break;
			}else if (keyin > guess){
				max = keyin;
				cout << "再小一點!";
			}else if (keyin < guess){
				min = keyin;
				cout << "再大一點!";
			}
			cout << "您猜了" << count << "次\n\n";
		}else{
			cout << "請輸入提示範圍內的數字! \n";
		}


	}while(true);

}
```
