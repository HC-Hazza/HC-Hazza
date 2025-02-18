#include "Animal.h"//the animal classes are included.
#include "Functions.h"//the functions specified in another file are included.

int main() {


	{
		Animal animal1;

		animal1.sayHello();
		animal1.makeNoise();
		animal1.animalDetails();
	}//between the parameters is the first animal initialised in the header.

	{
		Animal animal2("Bear", "Harrison", "Grr!", "Brown", 19, 550.7);

		animal2.sayHello();
		animal2.makeNoise();
		animal2.animalDetails();
	}//in these paramaters another animal is created and then put through the functions from the class.

	{
		Animal animal3("Fox", "Jeremy", "AAAAAAAAAAAAAAAAAAAAAAH!", "Orange", 6, 1.5);
		animal3.sayHello();
		animal3.makeNoise();
		animal3.animalDetails();
	}//the same is done for a third animal.

	return 0;
}
