#include <iostream>
using namespace std;

void logMessage(string msg) {//the same function as the previous program, where it prints text to the console.
	cout << msg << endl;
}


void doubleTrouble(int &dub) {//unlike the previous program, this function uses the integer variable as a reference, due to the & sign.
	int result = dub * dub;
	cout << result;
}//the rest of it is the same.



int main() {
	int number;
	//the main function is the exact same as the previous program. The text is printed, the user can input a number and that number is sent to the function.
	logMessage("Please can you enter a number to be doubled:");

	cin >> number;
	doubleTrouble(number);

	return 0;
}
