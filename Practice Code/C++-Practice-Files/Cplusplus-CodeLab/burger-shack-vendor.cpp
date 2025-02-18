#include <iostream>
#include <string>
using namespace std;

double inputCheck(pair<string, double> menu[], int limit) {//a double function for the user to use for their input. It uses a pair from the main function as well a number 
	cout << "Please pick a " << menu[0].first << "." << endl;//this is printed to the console alongside the title of the pair in the main function.
	for (int menuItem = 1; menuItem < limit; menuItem++) {//for loop for the items in the first part of each pair.
		cout << menuItem << ": " << menu[menuItem].first << " ";//this outputs a number for each element in the array, as well as the element.
	}
	cout << endl;//ends the line so the user input is more easier to write.
	int choice;//the integer refers to the number next to the item.
	cin >> choice;//user input for the item.
	while (cin.fail() || choice < 1 || choice > limit - 1) {//check input, if the inputted number is lower than 1, or higher than the amount that is in the array, an error will occur.
		cout << "Please answer properly." << endl;//prints an error message to the console.
		cin.clear();//clears the previous user input.
		cin.ignore(1000, '\n');//ignores the previous input by 1000 characters or next line.
		cin >> choice;//enter the input again.
	}
	return menu[choice].second;//returns the price number for the item entered by the user.
}

	void payment(double money) {//function for the user to pay for the food.
		double userPayment;//a variable for the payment.
		cout << "Please enter the amount you are going to pay: ";//prints this text to the console.
		cin >> userPayment;//the user can input their amount of money into the console.
		while (cin.fail()) {
			cout << "We need a proper number for the payment." << endl;
			cin.ignore(1000, '\n');
			cin.clear();
			cin >> userPayment;
		}//another error check to make sure they entered a number.
		do {
			double more_userPayment;//another decimal for an addition payment if the first is not enough.
			cout << "You need to pay more as this does not suffice: ";//this message is printed to the console.
			cin >> more_userPayment;//user input for the additional payment.
			while (cin.fail()) {
				cout << "We need a proper number for the payment." << endl;
				cin.ignore(1000, '\n');
				cin.clear();
				cin >> more_userPayment;
			}//another input check for error.
			userPayment += more_userPayment;//the payment is added to the original number.
		} while (userPayment <= money);//this checks if the money entered is too low.
		if (userPayment > money) {//if the entered payment is too high, the user will need some money back.
			double change = userPayment - money;//another decimal variable for more money.
			if (change == 1) {//because I'm a sucker for grammar, if we only have 1 pound to give, it must say so, since it is not plural.
				cout << "Here is your change: " << change << " pound.";//this is outputted to the console when the amount is calculated.
			}
			else {//this is printed if the amount is more or less than 1, since we can use the plural.
				cout << "Here is your change: " << change << " pounds.";
			}
		}
	}


int main() {
	pair <string, double> burgerTypes[4]{ { "burger type", 0 }, { "Beef", 2.99 }, { "Chicken", 2.59 }, { "Vegetarian", 2.55 } };//the first pair array is for the meat of the burger and its price.
	pair <string, double> toppings[6]{ { "topping", 0 }, {"Cheese", 0.35}, {"Tomato", 0}, {"Lettuce", 0}, {"Bacon", 0.5}, {"Onion", 0.2} };//the second is for what goes inside the burger and its price.
	pair <string, double> condiments[5]{ { "condiments", 0 }, { "Mayonnaise", 0 }, { "Ketchup", 0 }, { "Mustard", 0 }, {"BBQ Sauce", 0} };//this one is for the sauces and its price.
	pair <string, double> sides[5]{ { "sides", 0}, {"Fries", 1.0}, {"Chicken Nuggets", 2.0}, {"Salad" , 1.69}, {"No sides", 0}};//this is for the sides and its price.
	pair <string, double> drinks[7]{ { "drink", 0 }, { "Coke", 1.59 }, { "Diet Coke", 1.09 }, { "Coke Zero", 1.0 }, { "Fanta Orange", 1.0 }, {"7-Up", 1.0}, {"Dr Pepper", 1.19} };//finally drinks and prices.

	double userChoice = 0;// a decimal variable for the final price of the order.

	userChoice += inputCheck(burgerTypes, 4);
	userChoice += inputCheck(toppings, 6);
	userChoice += inputCheck(condiments, 5);
	userChoice += inputCheck(sides, 5);
	userChoice += inputCheck(drinks, 7);
	//each option is sent through to the function above so the user can enter their option each time. The number at the end is the limit in the array.
	cout << "The price of your order is " << userChoice << " pounds." << endl;//this is printed to the console. It includes the amount that was totaled in the functions above.
	payment(userChoice);//the number is then taken to the payment function above.

	return 0;
}
