#include <iostream>
#include <time.h>

using namespace std;
int main() {
	srand(time(NULL));	
	int max = 200;
	int min = 100;
	int randValue = rand() % (max-min+1) + min;
	cout << "100~200之間的亂數:" << randValue << endl;
	return 0;
}
