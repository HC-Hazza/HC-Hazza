#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomNumber() {
	srand((unsigned)time(0));
	int randomNumber;
	do{
		randomNumber = (rand() % 1000) + 1;
		cout << randomNumber << endl;
		Sleep(500);
	} while (randomNumber >= 4);
}

int main() {

	randomNumber();
	return 0;
}
