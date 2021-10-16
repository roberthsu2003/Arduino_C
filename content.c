#include <iostream>
using namespace std;

int main() {
	int nums;
	cout << "請輸入要排序的數值個數:";
	cin >> nums;
	//建立陣列
	int array[nums];
	//給陣列內容
	for(int i=0; i<nums; i++){
		cout << "請輸入第" << i+1 << "個數值:";
		cin >> array[i];
	}
	//排序前的內容輸出
	cout << "排序前:" << endl;
	for(int i=0; i<nums; i++){
		cout << array[i] << " ";
	}
}
