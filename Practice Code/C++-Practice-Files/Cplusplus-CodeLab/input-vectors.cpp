#include <iostream>
#include <vector>//this is for the vector variable.
#include <Windows.h>
using namespace std;

int main() {
	vector <int> userInts(5);//this vector variable is for ints and can hold 5 values.

	int userInput[5];//this is an array for the numbers to the user input.

	cout << "Please enter 5 numbers:" << endl;//this is printed to the console.
	
	for (int inputLoop = 0; inputLoop < 5; inputLoop++) {//for loop for the numbers that the user is going to input.
		cin >> userInput[inputLoop];//the user can input the numbers here.
		while (cin.fail()) {//this checks to see if the user had actually entered a number.
			cout << "Please enter something properly." << endl;//this is printed to the console if the user enters anyhting other than a number.
			cin.clear();//this will clear the input.
			cin.ignore(1000, '\n');//this tells the program to ignore the input by 1000 characters or the next line.
			cin >> userInput[inputLoop];//the user can input their number again until they get it right.
		}
		userInts.insert(userInts.begin() + inputLoop, userInput[inputLoop]);//this puts the numbers entered by the user into the vector.
	}
	for (int outputLoop = 0; outputLoop < 5; outputLoop++) {//another for loop to print the numbers to the console.
		cout << userInts.at(outputLoop) << endl;//the at function directs the program to the specified area in the vector.
		Sleep(200);//this pauses the program for as many milliseconds as there are in the brackets (equivalent to 2 seconds).
	}


	return 0;
}
