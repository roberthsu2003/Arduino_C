#include <iostream>
using namespace std;

int main() {
	int min = 1;
	int max = 99;
	srandom(time(NULL));
	int guess = random() % (max-min+1) + 1;
	cout << guess << endl;
} 
