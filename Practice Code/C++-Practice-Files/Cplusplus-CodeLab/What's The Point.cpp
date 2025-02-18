#include <iostream>
using namespace std;

int main() {
	int userNumber;//this integer is going to be used for the user input.

	cout << "Please enter a number: ";//prints text to the console.
	cin >> userNumber;//the user can input into the integer.
	cout << "Your number is: " << userNumber << endl;//the user's number is first printed to the console.

	int* IntPointer = &userNumber;//this int pointer looks for where the data the user entered in the memory.
	cout << "Your number is stored at this location: " << IntPointer << endl;//this will output a hexideciaml that indicates where the number has been stored.

	cout << "This is the number dereferenced from said location: " << *IntPointer;//this will output what is stored in that memory, which would be the number again.


	return 0;
}
