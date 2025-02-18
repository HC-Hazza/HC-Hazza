#include "Functions.h"//the functions are declared in the function header.

void print(string msg) {
	cout << msg << endl;
}//this function prints text to the console.

int checkInteger() {
	int number;
	print("Input the number");
	cin >> number;
	while (cin.fail()) {
		print("Your input is invalid. Please enter again.");
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> number;
	}

	return number;
}//this function checks user input for integers.