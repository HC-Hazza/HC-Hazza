#include <iostream>

using namespace std;

void logMessage(string msg) {//this is a function that can be used to print text to the console.
	cout << msg << endl;
}


void doubleTrouble(int dub) {//this function multiplies the number by itself.
	int result = dub * dub;//the number is a value.
	cout << result;
}



int main() {
	int number;//an integer for the user input.

	logMessage("Please can you enter a number to be doubled:");
	//this will print the text inside the brackets to the console.
	cin >> number;//user input for the number.
	doubleTrouble(number);//the inputted number is sent to the function above.

	return 0;
}
