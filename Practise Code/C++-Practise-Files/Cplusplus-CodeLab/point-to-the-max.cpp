#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
using namespace std;

void print(string msg) { cout << msg << endl; }

int main() {

	int userSize, loopCounter = 0;//two integers are declared, one for the user to have and one initialised as zero for the counter.

	print("Please enter the size you want your array to be:");//this text is printed to the console.
	cin >> userSize;//the user inputs the size they want.

	int* userArray = new int[userSize];//an array is declared using a pointer.

	int* loopBegin = userArray;//this will be used to iterate through the array.

	print("Please enter the numbers you want in this array:");//this text is printed to the console.

	int* arrayEnd = &userArray[userSize];//this pointer is determined as the end of the array.

	while (loopBegin != arrayEnd) {
		cout << loopCounter + 1 << ". ";//this loop will print numbers up to the size of the array the user entered.
		cin >> userArray[loopCounter];//the user can then enter as many values as they entered above.
		loopCounter++;
		loopBegin++;
	}

	print("Your array is:");
	for (int i = 0; i < userSize; i++) {
		cout << userArray[i] << ", ";
		Sleep(100);
	}//the array is printed here.

	int bigValue = *max_element(userArray, userArray + userSize);//the maximum number is found using this function.

	cout << "The largest number you've entered is: " << bigValue;//the largest number is printed to the console.

	return 0;
}
