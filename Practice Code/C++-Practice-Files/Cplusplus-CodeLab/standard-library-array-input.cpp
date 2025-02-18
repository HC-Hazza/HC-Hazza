#include <iostream>
#include <array>//the array include is for array functions and variables.
using namespace std;

int main() {
	array <int, 5> numbers;//an array variable that is an integer and has 5 spaces.
	cout << "Please enter 5 numbers:" << endl;//this is printed to the console.
	for (int &n : numbers) {//the range based for loop needs a reference instead of a value, which is why the & is next to the n.
		cin >> n;//user input for each of the five numbers.
	}
	for (int& i : numbers) {//the loop then uses another reference to output the values.
		cout << i << endl;//output is declared here.
	}
	cout << "Please enter 5 numbers:" << endl;//another piece of text is printed to the console.
	for (int x = 0; x < 5; x++) {//this uses a standard for loop. It counts up to 5 like normal and allows the user to enter.
		cin >> numbers[x];//the input is like usual despite it being an array variable.
	}
	for (int y = 0; y < 5; y++) {//a similar for loop for outputting the numbers.
		cout << numbers[y] << endl;
	}


	return 0;
}
