#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
	int userNumber[10], inputCount = 1;//4 integer variables are declared. 1 of which is an array, and another is initialised as 1.

	cout << "Please enter ten numbers for the database." << endl;//this text is printed to the console.

	for (int inputLoop = 0; inputLoop < 10; inputLoop++) {//this for loop is for going through the array and entering the numbers for it.
		cout << inputLoop + 1 << ". ";//output a number with a dot. The number is the same as the one in the loop plus 1 (since it begins at zero).
		cin >> userNumber[inputLoop];//user input for the number.
		while (cin.fail()) {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Invalid input." << endl;
			cin >> userNumber[inputLoop];
		}//this will check if the user actually does enter a number.
	}

	int maximumNumber = userNumber[0], minimumNumber = userNumber[0];//the max and min numbers start off as the first integer, but it won't matter as it would change if it was bigger/smaller than the previous number anyway.

	for (int countLoop = 0; countLoop < 10; countLoop++){//another for loop to go through the array.

		if (userNumber[countLoop] > maximumNumber) {//if the next number is bigger than the max number so far, the variable will change to that number.
			maximumNumber = userNumber[countLoop];
		}
		if (userNumber[countLoop] < minimumNumber) {
			minimumNumber = userNumber[countLoop];//this is the same but for a number smaller than the previous one.
		}
	}

	cout << "The maximum number is " << maximumNumber << endl << "The minimum number is " << minimumNumber << endl;//this prints the text to the console alongside the two maximum and minimum numbers in the entered sequence.

	cout << "Please enter ten more numbers." << endl;//this text is printed to the console.
	array <int, 10> libraryArray;//an array variable is declared with it being an integer one with 10 values.
	for (int &secondInputLoop : libraryArray) {//this is a range based loop. It will loop through the array just the same as a regular one, however it uses a reference instead to add in the values.
		cout << inputCount << ". ";//the number is printed to the console.
		inputCount++;//the number is then increased per loop.
		cin >> secondInputLoop;//the number is then entered every time it loops.
		while (cin.fail()) {
			cin.ignore(1000, '\n');
			cin.clear();
			cout << "Invalid input." << endl;
			cin >> secondInputLoop;
		}//this checks for errors.
	}

	cout << "The max element of this array is " << *max_element(begin(libraryArray), end(libraryArray)) << endl;
	cout << "The min element of this array is " << *min_element(libraryArray.begin(), libraryArray.end());//this will output the maximum and minimum number of the entered sequence using the built in functions.

	return 0;
}
