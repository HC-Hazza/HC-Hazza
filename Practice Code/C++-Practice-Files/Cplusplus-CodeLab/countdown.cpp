#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	
	for (int countdown = 10; countdown > 0; countdown--) {
		cout << countdown << "\n";
		Sleep(3600000);
	}
	cout << "We have lift-off!";
	return 0;
}
