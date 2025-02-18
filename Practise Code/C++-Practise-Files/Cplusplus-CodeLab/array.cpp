#include <iostream>
#include <string>
using namespace std;

int main() {
	int x;
	string month[12]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
	
	for (x = 0; x < 12; x++) {
		cout << month[x] << endl;
	}


	return 0;
}
