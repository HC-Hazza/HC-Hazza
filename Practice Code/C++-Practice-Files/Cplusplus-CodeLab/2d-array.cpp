#include <iostream>
using namespace std;

int main() {
	int total = 0, columnTotal;//these two integers are used in the calculation for adding together the rows.
	int timestables[5][3]{
		{2 , 4 , 6},
		{3, 6, 9},
		{4, 8, 12},
		{5, 10, 15},
		{6, 12, 18},//this is the 2D array, they go down by one and multiplied through up to their third.
	};
	for (int column = 0; column < 5; column++) {//this for loop cycles through the column of the 2d array.
		for (int row = 0; row < 3; row++) {//this nested for loop cycles through the row of the 2d array.
			cout << timestables[column][row] << " ";//this is used to show in the console that the numbers are going through the loop.
			int addition = timestables[column][row];//this integer becomes the number from the 2d array row.
			total = timestables[column][row] + total;//this is one of the integers before, now being initialised as the number from the row plus itself to slowly make a larger number.
			columnTotal = timestables[column][row] + addition;//each number in the row is added together to create a total for each column.
		}
		cout << endl << "The total of this column is: " << columnTotal << endl;//the total of each column is then printed to the console.
	}
	cout << "The total of this 2D array is: " << total;//the entire total is also printed to the console.


	return 0;
}
