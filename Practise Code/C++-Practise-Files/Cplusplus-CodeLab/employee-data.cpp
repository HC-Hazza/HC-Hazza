#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <iomanip>
#include <algorithm>

using namespace std;

void print(string msg);

struct Employees {

	string name;
	int age;
	char gender;
	string address;
	double salary;
};//the structure for the data in the file.

int main() {

	ifstream employeeFile("employeeData.txt");//the file is called here for it to be opened.

	array<Employees, 9> employeeGroup;//this array will be for the data in the file.

	int loopVariable = 0;//this variable is for the while loop to count upwards for each part of the array.
	int jeffFinder = 0;//this will count up as many times as jeff is located.

	if (employeeFile.is_open()) {//this will check if the file is opened to make sure the file call worked.

		print("Name \t\t | Age \t\t | Gender \t\t | Address \t\t\t\t | Salary");//the beginning of the table is printed at the top.

		while (!employeeFile.eof()) {//this will loop until the program cannot find any more data and reaches the end of the file.
			getline(employeeFile, employeeGroup[loopVariable].name, ',');//this will get the first piece of data until it hits a comma.

			employeeFile >> employeeGroup[loopVariable].age;//this will get the data after the first comma.
			employeeFile.ignore(10, ',');//since it will be an integer, the program needs to be told to ignore the comma string next to the number.

			employeeFile >> employeeGroup[loopVariable].gender;//this will be similar to the age data collection.
			employeeFile.ignore(10, ',');//again, the data will ignore the comma after the letter.

			getline(employeeFile, employeeGroup[loopVariable].address, ',');

			employeeFile >> employeeGroup[loopVariable].salary;
			employeeFile.ignore(10, '\n');//since the salary will be at the end, the program needs to ignore the paragraph split.

			loopVariable++;//the loop count will increase for the next set in the array.

		}

		for (int i = 0; i < employeeGroup.size(); i++) {//the for loop will loop until the end of the file data array.

			int nameWidth = employeeGroup[i].name.length();
			int addressWidth = employeeGroup[i].address.length();
			//these two integer variables check the length of the string inside both the name and address.

			cout << employeeGroup[i].name << setw(20 - nameWidth) << " | " //the name will be printed with 20 spaces minus the amount of letters are in the text.
				<< employeeGroup[i].age << setw(20) << " | " //the age will just be printed with 20 spaces in between.
				<< employeeGroup[i].gender << setw(20) << " | "
				<< employeeGroup[i].address << setw(40 - addressWidth) << " | "//the address will be printed with 40 spaces minus the letters since addresses are a lot longer.
				<< employeeGroup[i].salary << endl;//the salary and gender will print the same as the age.

			transform(employeeGroup[i].name.begin(), employeeGroup[i].name.end(), employeeGroup[i].name.begin(), ::tolower);//after they are printed, the names are made lower case.
			if (employeeGroup[i].name.compare(0, 4, "jeff") == 0) {//the first four characters of the string is checked to see if they match the parameters (being jeff).
				jeffFinder++;//if so, the counter goes up.
			}
		}
		cout << "There are " << jeffFinder << " Jeffs in the table.";//the number is then printed to the console.

		employeeFile.close();//closes the file.
	}

	else {
		print("File could not be opened...");
		return -1;
	}//if the file cannot be opened, this will print.


	return 0;
}

void print(string msg) { cout << msg << endl; }//this will print text to the console if it is called.
