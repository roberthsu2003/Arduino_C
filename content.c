#include <iostream>
using namespace std;

int main() {
	int min = 1;
	int max = 99;
	int keyin;
	int count = 0;
	srandom(time(NULL));
	int guess = random() % (max-min+1) + 1;
	cout << "=================猜數字遊戲================\n\n";
	while(true){
		cout << "猜數字範圍" << min << "~" << max << ":";
		cin >> keyin;
		count += 1;
		if(keyin >= min && keyin <= max){
			cout << "範圍正確" << endl;
			break;
		}else{
			cout << "請輸入提示範圍內的數字" << endl;
		}
	}

	cout << "遊戲結束" << endl;
} 
