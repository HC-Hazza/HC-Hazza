#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));//set a seed from random number;
	int randNo = rand() % 100 + 1;//random number between 1-100
	cout << randNo << endl;

	//addcout << randNo << endl; your code here


	return 0;

}
