#include "Dog.h"
using namespace std;

Dog woof(const Dog& d1, const Dog& d2) {
	if (d1.age > d2.age) {
		return d1;
	}
	else {
		return d2;
	}
}

int main() {

	Dog firstDog;
	firstDog.dogPrint();

	Dog secondDog("Dogmeat", "Golden Retriever", 12);
	secondDog.dogPrint();

	Dog oldestDog = woof(firstDog, secondDog);

	cout << oldestDog.name << " is the oldest \nWoof!";

	return 0;
}
