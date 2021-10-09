#include <iostream>
using namespace std;

int main() {
	int nums;
	int min = 99999;
	int max = 0;
	cout << "請輸入數值的數量:";
	cin >> nums;
	int values[nums];

	for(int i=0; i<nums; i++){
		cout << "請輸入第" << i+1 << "數值:";
		cin >> values[i];
	}

	for(int i=0; i<nums; i++){
		cout << "第" << i+1 << "個數值是" << values[i] << endl;
		min = min < values[i] ? min : values[i];
		max = max > values[i] ? max : values[i];
	}

	cout << "最大值是:" << max << ",最小值:" << min << endl;
	return 0;	
}
