#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <iomanip>

using namespace std;

void print(string msg);

struct petrol {
	double litres;
	double cost;
};//this structure will hold both the number of litres and their cost.

int main() {

	ifstream petrolFile("petrolPump.txt");//this takes data from the file.

	array<petrol, 10> Pump;//this array will hold multiple pieces of data for the litres and costs in the structure.

	int fileIterator = 0;//this iterator will be used for the while loop.
	double averagePrice = 0, below48p = 0, totalLitres = 0;//these two doubles will be for the two tasks on the specification.

	if (petrolFile.is_open()) {//this will check if the file had been opened.
		print("No Litres\tCost");//this will print the beginning of the table.

		
		while (!petrolFile.eof()) {//the code will run until it reaches the end of the file.
			petrolFile >> Pump[fileIterator].litres;//the first part of the file will go into the litres double in the struct.
			petrolFile.ignore(10, '\t');//the input will ignore the next ten digits or a tab.

			petrolFile >> Pump[fileIterator].cost;//the same will happen to the next number after the tab.
			petrolFile.ignore(10, '\n');//the program will then ignore the next 10 digits or a new line.

			fileIterator++;//the iterator increases by one.
		}
		for (int i = 0; i < Pump.size(); i++) {//this will loop to the amount that is in the array, which is 10.
			cout << Pump[i].litres << "\t\t" << Pump[i].cost << endl;//this will print the litre numbers then some spaces and then the cost.
			averagePrice += Pump[i].cost * Pump[i].litres;//the average per litre is the cost multiplied by the litres added together.
			totalLitres += Pump[i].litres;//the total number of litres is added up together for the equation below.
			if (Pump[i].cost < 48) {
				below48p += Pump[i].litres;
			}//this conditional will add the litres number to a counting variable if the cost of those litres is below 48.
		}

		averagePrice = averagePrice / totalLitres;//the average number needs to be divided by the amount of litres to be correct.

		cout << "The average price is " << setprecision(2) << averagePrice << endl;//this will print the text with the average to the console.

		print("The number of petrol bought under 48p is " + to_string(below48p));//this will print the text with the number that is added to the integer variable turned into a string.
			
		petrolFile.close();//this will close the file after it is done.
	}
	else {
		print("The file did not open...");
	}//if the file won't open, this will print.


	return 0;
}

void print(string msg) {
	cout << msg << endl;
}//this function is used to print text to the console.
