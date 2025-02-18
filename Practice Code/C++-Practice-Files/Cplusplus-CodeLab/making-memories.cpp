#include <iostream>
#include <string>
using namespace std;

int main() {

	int* numPointer;//an integer pointer is declared.
	string* wordPointer;//a string pointer is declared.

	int num = 19;//an integer is delcared and initialised.
	string word = "Hazza";//a string is declared and initialised.

	numPointer = &num;//the pointer will look for the position of the integer in the memory.
	wordPointer = &word;//this pointer will also look for the position of the string in the memory.

	cout << "The position of the number is: " << numPointer << "\nThe position of the string is: " << wordPointer << endl;//the position of both the integer and the string will be printed to the console.

	cout << "The integer value is: " << *numPointer << "\nThe string value is: " << *wordPointer << endl;//the values stored in those memories will be printed to the console.

	*numPointer = 20;//the integer is altered via a deferenced pointer.
	*wordPointer = "Jake";//the string is also altered via a dereferenced pointer.

	cout << "The altered number is: " << *numPointer << "\nThe altered string is: " << *wordPointer << endl;//the altered integer and string is printed to the console.

	return 0;
}
