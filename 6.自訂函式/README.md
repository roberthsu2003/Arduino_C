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
// Name        : function1.cpp
//定義函式，顯示「歡迎光臨」。

#include <iostream>
using namespace std;

void sayHello(){
	cout << "歡迎光臨!" << endl;
}

int main() {
	sayHello();
	return 0;
}
```

### 
```c++
// Name        : function2.cpp
//輸入攝氏溫度，求華氏溫度
/*=============================

攝氏10度轉華氏溫度=50
==========================
請輸入攝氏溫度:19
華氏溫度=66.2

===============================*/


#include <iostream>
using namespace std;

float temperature(int value){
	return 1.8 * value + 32;
}

int main() {
	cout << "攝氏10度轉華氏溫度=" << temperature(10) << endl;
	cout << "----------------\n";
	int value;
	float result;
	cout << "請輸入攝氏溫度:";
	cin >> value;
	result = temperature(value);
	cout << "華氏溫度=" << result << endl;
	return 0;
}
```

```
*問題 transtemperature.cpp
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


#include <iostream>
using namespace std;

void showNum(int n){
	int i = 1;
	while(true){
		if (i > n){
			return;
		}
		cout << i << " ";
		i++;
	}

}

int main() {
	int inputNum;
	cout << "請輸入數字 n:";
	cin >> inputNum;
	showNum(inputNum);
	cout << endl;
	return 0;
}
```

### 參數
### 傳值呼叫(call by value)
```c++
// Name        : callByValue1.cpp
//callByValue

#include <iostream>
using namespace std;
int turbo(int);

int main() {
	int speed;
	cout << "請輸入初始速度:";
	cin >> speed;
	speed = turbo(speed);
	cout << "加速後的速度:" << speed << endl;
	return 0;
}
int turbo(int speed){
	cout << "加速前速度:" << speed << endl;
	return speed += 10;
}
```


### 傳參考呼叫(call by reference)
```c++
// Name        : callByReference.cpp
//callByReference

#include <iostream>
using namespace std;
void turbo(int&);

int main() {
	int speed;
	cout << "請輸入初始速度:";
	cin >> speed;
	turbo(speed);
	cout << "加速後的速度:" << speed << endl;
	return 0;
}
void turbo(int& speed){
	cout << "加速前速度:" << speed << endl;
	speed += 10;
}
```
	
### 傳址呼叫(call by address)
```c++
// Name        : callByAddress.cpp
//call by address

#include <iostream>
using namespace std;
void turbo(int*);

int main() {
	int speed;
	cout << "請輸入初始速度:";
	cin >> speed;
	turbo(&speed);
	cout << "加速後的速度:" << speed << endl;
	return 0;
}
void turbo(int* speed){
	cout << "加速前速度:" << *speed << endl;
	*speed += 10;
}
```

