#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string bio;//a string variable for outputting the string in the file.

	ofstream textFile( "bio.txt" );//this is used to create and open a file called bio.txt.

	textFile << "Name: Hazza\nAge: 19\nHometown: Bath\n";//this will input text into the file that was just opened.

	textFile.close();//this will close the file after use.

	ifstream textFile2( "bio.txt" );//this is used to open a file to read.

	if (textFile2.is_open()) {//this is used to check if the file opened in case of error.

		while (getline(textFile2, bio, '\n')) {//this will get all the text from the file.

			cout << bio << endl;//this is used to print the text to the console from the file.

		}


		textFile.close();//the file is closed again to prevent data leakage.
	}
	else {
	cout << "File cannot be accessed. Terminating program" << endl;
	return -1; //exit program
		}//if the file doesn't open, this will print.

	return 0;
}
