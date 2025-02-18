#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <time.h>
#include <array>
#include <chrono>
#include <random>
using namespace std;

int main() {
	vector<int> integers = { 6, 18, 12, 20, 16, 4, 14, 8, 10, 2 };//a vector of ten integers.

	for (int firstOutput = 0; firstOutput < 10; firstOutput++) {//this loop will be used to print each number in the vector to the console
		cout << integers.at(firstOutput) << endl;
		Sleep(100);//each time the number prints the program waits for 0.1 of a second.
	}
	cout << endl;

	int bigValue = *max_element(integers.begin(), integers.end());//this function is able to get the maximum value by cycling through the vector to find it.
	int smallValue = *min_element(integers.begin(), integers.end());//this function does the same but for the minimum value.

	cout <<  bigValue << endl;
	cout << smallValue << endl;//both the large value and the small value is printed to the console.

	integers.resize(20);//creates 20 spaces for 10 more values.
	cout << endl;

	int loopCounter = 0;//this is an integer that will be used to put the integers from a randomised array into the first vector.

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	array<int, 10> newIntegers = { 28, 22, 34, 40, 26, 32, 36, 24, 38, 30 };//an array for additional values for the vector
	shuffle(newIntegers.begin(), newIntegers.end(), std::default_random_engine(seed));//these values are then entered into the vector at random through a shuffle.;
	for (int i = 10; i < integers.size(); i++) {
		integers.at(i) = newIntegers.at(loopCounter);
		loopCounter++;
	}//this loop places the integers into the vector.


	for (int secondOutput = 0; secondOutput < integers.size(); secondOutput++) {
		cout << integers.at(secondOutput) << endl;//this loop will print all the integers including the new ones to the console.
		Sleep(100);
	}

	integers.push_back(42);
	integers.push_back(44);
	//this will push two new integers into the vector.
	cout << endl;
	for (int secondOutput = 0; secondOutput < integers.size(); secondOutput++) {
		cout << integers.at(secondOutput) << endl;
		Sleep(100);
	}

	for (int pop = 0; pop < 2; pop++) {
		integers.pop_back();
	}//this will delete them from the vector.

	cout << endl;
	for (int secondOutput = 0; secondOutput < integers.size(); secondOutput++) {
		cout << integers.at(secondOutput) << endl;
		Sleep(100);
	}

	cout << endl << integers.front() << endl << integers.back() << endl << endl;//this will print the first and last integer from the vector to the console.

	integers.clear();//this will delete all the values in the vector.

	cout << integers.size() << endl << endl;//this will print the size of the vector, which should be zero.

	cout << integers.empty();//this will print 1 if the vector is empty.

	return 0;
}
