#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {

	array <array<int, 7>, 2>  temperature = { { {20, 23, 24, 25, 22, 17, 15 }, {16, 13, 19, 3, 10, 15, 28}} };//this is an array variable amongst an array variable for two sets of temperatures for two cities.

	int count = 0, bathTotal = 0, barcTotal = 0, combinedTotal;//four integer variable for the program.

	for (auto &row : temperature) {//auto is a placeholder variable for other variables.
		for (int& output : row) {//The variable here is a reference, like the auto variable above it.
			if (count < 7) {//since there are seven temperatures, it will count up seven times.
				barcTotal += output;//the number in the array is added to the integer.
			}
			else {
				bathTotal += output;//after seven, it will count the other seven and add them together with the other variable.
			}
			count++;//this is so the count variable counts upwards.
			cout << output << endl;//each number is printed to the console.
		}

	}
	combinedTotal = bathTotal + barcTotal;//since both totals together is part of the assignment, I simply added them together with another integer variable.
	cout << "The mean of the temperature for Barcelona is " << barcTotal / 7 << endl << "The mean of the temperature for Bath is " << bathTotal / 7 << endl << "The mean of them combined is " << combinedTotal / 14 << endl;
	//this all shows the mean of both cities temperature as well as their means individually.
	int bathMax, bathMin, barcMax, barcMin;//four more integers for the minimum value and the maximum.
	
	for (int i = 0; i <= 1; i++) {//this will loop only twice for the two cities.
		if (i == 0) {//the first set of temperatures are for barcelona.
			barcMax = *max_element(begin(temperature[i]), end(temperature[i]));//this will identify the maximum element amongst the first array.
			barcMin = *min_element(temperature[i].begin(), temperature[i].end());//this will identify the minimum element amongst the first array.
		}
		else {
			bathMax = *max_element(begin(temperature[i]), end(temperature[i]));
			bathMin = *min_element(temperature[i].begin(), temperature[i].end());
		}//these are the same as the first except they loop through the second.
		cout << "The max element of this array is " << *max_element(begin(temperature[i]), end(temperature[i])) << endl;//this will show both the maximum and minimum of both cities and print it to the console.
		cout << "The min element of this array is " << *min_element(temperature[i].begin(), temperature[i].end()) << endl;
	}

	cout << "The maximum of both is " << max(barcMax, bathMax) << endl;
	cout << "The minimum of both is " << min(barcMin, bathMin) << endl;//this will show the maximum and minimum element of the cities compared to each other.

	return 0;
}
