#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	int fileAmount = 0;//this variable will be used for counting the lines that are in the file.

	ifstream File("randomStrings.txt");//this takes data from a file from the repository.

	if (File.is_open()) {//this will check if the file is actually being used by the program.
		while (!File.eof()) {//the loop will go through the entire file.
			string jumble;//a string variable is declared.
			getline(File, jumble);//the string variable is used to get data from the file.

			fileAmount++;//each time data is taken from the file, the counter goes up.
		}
		File.close();//the file is then closed since it is no longer needed.

		cout << "The amount of lines in the file is " << fileAmount;//the number of lines is then outputted.
	}
	else {//if the file is not opened for whatever reason, the text below will print to the console.
		cout << "The file could not be opened...";
		return -1;
	}//the program will end if the file won't open.


	return 0;
}
