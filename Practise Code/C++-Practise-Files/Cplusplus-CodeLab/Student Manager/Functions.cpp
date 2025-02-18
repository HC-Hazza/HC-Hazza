#include "Functions.h"//the functions are declared in the function header.

void print(string msg) {
	cout << msg << endl;
}//this function prints text to the console.

int checkInteger() {
	int number;
	print("Input the number: ");
	cin >> number;
	while (cin.fail()) {
		print("Your input is invalid. Please enter again.");
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> number;
	}

	return number;
}//this function checks user input for integers.

int checkMenu() {
	int number;
	print("Input the number for the menu: ");
	cin >> number;
	while (cin.fail() || (number < 1 && number > 6)) {//if the user enters anything outside of 1 or 6, or anything but a number, the error will be called.
		print("Your input is invalid. Please enter again.");
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> number;
	}//they will then be made to enter it again.

	return number;
}