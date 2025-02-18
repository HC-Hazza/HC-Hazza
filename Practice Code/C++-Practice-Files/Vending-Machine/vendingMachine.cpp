#define NOMINMAX//not include the max/min functions from Windows.h
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <limits>
using namespace std;

char validateChar();//calls a function to validate user inputted char variables.
int validateInt(int limit);//calls a function to validate user inputted int variables.
int validatePrice(int limit);

void print(string text) {
	cout << text << endl;
}//this function is used to print string as a replacement to cout.

struct moneyPoints {
	int cp = 0, sp = 0, gp = 0;
};//a structure is used to return multiple varaibles. In this case, it declares 3 integers.

moneyPoints askMoney(){//the structure in then used to create a function.
	moneyPoints points;//a variable referring to the struct is declared.
	print("How much money do you have, adventurer?");//the text is printed onto the console.
	Sleep(500);//pauses the program for half a minute.
	print("CP: ");//prints this to ask for the copper points of the user.
	points.cp = validatePrice(std::numeric_limits<int>::max());//this is used to have the user input the copper points, using the maximum limited number as the limit.
	print("SP: ");
	points.sp = validatePrice(std::numeric_limits<int>::max());//same user input and validation used for silver points.
	print("GP: ");
	points.gp = validatePrice(std::numeric_limits<int>::max());//same user input and validation used for gold points.
	return points;//all numbers entered are returned as a structure.
}


int menu() {//declares the integer function menu.
	int menuNumber;
	print("Which menu would you like? \n 1. Squalid (3 cp) \n 2. Poor (6 cp) \n 3. Modest (3 sp) \n 4. Comfortable (8 sp) \n 5. Wealthy (2 gp) \n 6. Aristocratic (4 gp) \n");//a list of menus are printed, representing an integer.
	menuNumber = validateInt(6);//the menu number that is entered represents one of the menu types written at the top. Since 6 is the highest number in the list, it is the limit.
	return menuNumber;//the menu number is then returned.
}
int products(string list[], string cost) {//declares the integer function products, with two strings declared to be used inside the function, one of which being an array.
	int choice;//declares an integer called choice.
	print("What do you want from the menu?");//outputs the text to the console.
	for (int i = 0; i < 10; i++) {//the for loop counts up to the number 9 from 0.
		if (i == 9){//once the for loop reaches the last number, it will output the final option.
			cout << i + 1 << ". " << "Go Back" << endl;//since the array begins at 0, for user experience, we don't want it to show the number 0, and instead start at one in the output.
		}//the number here therefore outputs 10.
		else {
			cout << i + 1 << ". " << list[i] << endl;//as the for loop loops, it will output a number as well as the string inside the array.
		}
		
	}
	choice = validateInt(10);//when a choice is entered by the user, it will be validated as an int with the limit of 10.
	choice--;//since we are dealing with an array, and the user will assume the list begins at 1, the number inputted is decremented.
	if (choice != 9) {
		cout << "You have selected " << list[choice] << " that costs " << cost << endl;
	}//if the choice is not 9, as nine is wanted to be used to return to the previous menu, the choice that has been chosen from the menu is outputted.
	return choice;//since picking items out of arrays works with numbers, a number is returned to be used in the main function.
}

int main() {//the main function is where the code is executed to the console. If the function is not called main, it will show an error.
	moneyPoints totalCost;//the structure from above is declared here as a variable called totalCost.

	string squalidProducts[] = { "Humble Pie", "Acorn soup", "Rice and peas", "Green chili stew", "Grilled snake and macadamia", "Frogs on skewers", "Onion soup", "Lizard gruel with nutbread", "Crisped worm skewers and potatoes" };
	//the squalid menu is the cheapest, being only 3 cp. It is selected through the number 1 being entered.
	string poorProducts[] = { "Porridge", "Mushroom stew with corn bread", "Mutton meatloaf", "Bread-bowl stew", "Wren pot pie and cattail soup", "Squash and fish soup", "Rabbit and baked pumpkin", "Bog-beetle dumplings", "Barbecued gopher legs on a stick" };
	//the poor menu comes up to 6 cp. It is selected through the number 2 being entered.
	string modestProducts[] = { "Grilled wild boar chops", "Broiled salmon and potatoes", "Roast chicken and potatoes", "Smoked sausage, goose eggs and dates", "Cheese pie and onion soup", "Baked boar and greens", "Minted pea soup", "Baked goat flank", "Lemming and berry soup" };
	//the modest menu begins the silver points. It is 3 sp. It is selected through the number 3 being entered.
	string comfortableProducts[] = { "Venison and bean stew", "Buffaloaf and honeyed corn", "Pork chop & curds", "Elven bread", "Baked loin of pork with gravy", "Roasted cod and mashed potatoes", "Beef steak and kidney pie", "Clams and garlic", "Toasted delfarnbread with spiced snail-butter" };
	//the comfortable menu comes up to 8 sp. It is selected through the number 4 being entered.
	string wealthyProducts[] = { "Grayling prawns poached with plovers eggs", "Baked pheasant with leeks", "Smoked salmon and wild berries", "Chocolate covered ants and roast pelican", "Barbecued tiger fish and papaya", "Roast chicken with thyme", "Stuffed trout, cabbage, succotash and plum pudding", "Braised beef and pears with ginger", "Meerkat dumplings with sage" };
	//the wealthy menu uses gold points. It costs 2 gp. It is selected through the number 5 being entered.
	string aristocraticProducts[] = { "Roast stag in antler sauce", "Poached and peppered quail eggs", "Spiced monkey tail and cashews", "Roast heron and chopped sundew", "Lobster in tomato cream sauce", "Crab-stuffed lobster tail", "Roast pheasant in oyster sauce", "Poached duck with farro", "Fried ostrich and egg omelet" };
	//the aristocratic menu is the most expensive of them all, coming at 4 gp. It is selected through the number 6 being entered.
	
	int productChoice = 0;//an integer is initialised as 0 so it can be used in the do while loop below. 
	char continuePurchase = 'y';//this is used to keep the do while loop looping.
	vector <string> userPurchasedItems;
	vector <string> costOfPurchases;//two vectors are declared. This will be used with the items taken from the array. The vectors are useful because it easier to put items and, as well as remove them.

	do {//beginning of the do while loop.
		int menuChoice = menu();//the integer variable menuChoice uses the number returned from the menu function for the if statements below.
			//copper
			if (menuChoice == 1) {//if 1 is entered from the menu function.
				productChoice = products(squalidProducts, "3 cp");//the integer we initliased earlier is now initialised using the products function.
				if(productChoice != 9){//this is for a fault check in case the number 9 is entered.
					print("Here is your " + squalidProducts[productChoice]);
					userPurchasedItems.push_back(squalidProducts[productChoice]);//push back puts the variable, or in this case array, into a vector. This would be the specified string in the array from the user.
					costOfPurchases.push_back("3cp");//since this is the squalid menu, 3 cp is sent to the second vector, for the cost.
				}
			}

			else if (menuChoice == 2) {
				productChoice = products(poorProducts, "6 cp");
				if (productChoice != 9) {
					print("Here is your " + poorProducts[productChoice]);
					userPurchasedItems.push_back(poorProducts[productChoice]);
					costOfPurchases.push_back("6cp");
				}
			}
			else if (menuChoice == 3) {
				//silver
				productChoice = products(modestProducts, "3 sp");
				if (productChoice != 9) {
					print("Here is your " + modestProducts[productChoice]);
					userPurchasedItems.push_back(modestProducts[productChoice]);
					costOfPurchases.push_back("3sp");
				}

			}
			else if (menuChoice == 4) {
				productChoice = products(comfortableProducts, "8 sp");
				if (productChoice != 9) {
					print("Here is your " + comfortableProducts[productChoice]);
					userPurchasedItems.push_back(comfortableProducts[productChoice]);
					costOfPurchases.push_back("8sp");
				}
			}
			else if (menuChoice == 5) {
				//gold
				productChoice = products(wealthyProducts, "2 gp");
				if (productChoice != 9) {
					print("Here is your " + wealthyProducts[productChoice]);
					userPurchasedItems.push_back(wealthyProducts[productChoice]);
					costOfPurchases.push_back("2gp");
				}
			}
			else if (menuChoice == 6) {
				productChoice = products(aristocraticProducts, "4 gp");
				if (productChoice != 9) {
					print("Here is your " + aristocraticProducts[productChoice]);
					userPurchasedItems.push_back(aristocraticProducts[productChoice]);
					costOfPurchases.push_back("4gp");
				}
			}
			else {
				print("That was not the answer I was looking for.");//if anything else other than the first 6 numbers is entered, this error message will appear, and the user input will be on loop.
			}

			if (productChoice != 9) {
				print("Would you like to make another purchase? (Y/N)");//this is ran if the user does not enter 10, which is converted to 9, and displays the previous menu.
				continuePurchase = validateChar();//user character input is validated to make sure it is y or n.
				if (continuePurchase == 'n') {
					char removeSelection = 'y';//this character variable is set to y for yes already. It will be used in a do while loop later.
					do {
						for (int i = 0; i < userPurchasedItems.size(); i++) {//in this for loop, the count begins at 0 and ends at the number of strings stored in the vector, which is what the size function is used for.
							cout << i + 1 << ". " << userPurchasedItems[i] << " costing " << costOfPurchases[i] << endl;//both the item and the cost is printed to show the user what they have bought and what has been registered to the system.
						}

						print("Would you like to remove an item from your selection? (Y/N)");//prints the question to the console to ask for a user input about a removal from the two vectors.
						removeSelection = validateChar();//the input is validated to make sure it is a y or n.
						if (removeSelection == 'y') {
							print("Pick the number next to the item you wish to remove:");
							int removeNum = validateInt(userPurchasedItems.size());//an integer called removeNum is initialised and validated with the size of the items vector being the limit.
							userPurchasedItems.erase(userPurchasedItems.begin() + removeNum - 1);//if the user wishes to remove an item, all they need to do is select a number that appears next to their item and it will be deleted from the vector.
							costOfPurchases.erase(costOfPurchases.begin() + removeNum - 1);//the same happens in the price vector.
							cout << endl;
						}
					} while (removeSelection == 'y');//since the user may want to remove more than one item, the decision is looped.

					print("Would you like to make another purchase? (Y/N)");//if a user would rather replace an item, they have the option to purchase again after they have removed something from their basket.
					continuePurchase = validateChar();//the user input is validated.
				}
			}
			else { 
				continuePurchase = 'y';//if the user chooses nine, then the first list will appear for them to pick a different menu.
			}
	} while (continuePurchase == 'y');//this will loop until the character is changed away from y.
	

	for (int i = 0; i < costOfPurchases.size(); i++) {//the count now loops from 0 to how many strings are inside the second vector.
		if (costOfPurchases[i].substr(1, 2) == "cp") {//substr checks if a part of a string. In this case, we want to see if that part is equivalent to cp.
			totalCost.cp += stoi(costOfPurchases[i].substr(0, 1));//stoi changes a string into an integer, if it fits that bill. Here, it is added together to the struct we defined above.
		}//this compensates for if the user buys from multiple menus, with multiple items.
		else if (costOfPurchases[i].substr(1, 2) == "sp") {//this is the same as above, but the substr wants sp.
			totalCost.sp += stoi(costOfPurchases[i].substr(0, 1));
		}
		else if (costOfPurchases[i].substr(1, 2) == "gp") {//this time, it wants gp.
			totalCost.gp += stoi(costOfPurchases[i].substr(0, 1));
		}
	}

	cout << "CP: " << totalCost.cp << endl << "SP: " << totalCost.sp << endl << "GP: " << totalCost.gp << endl;//the program will then tell them the full price for all three point groups.
	moneyPoints userMoney = askMoney();//the console will then ask the user to enter their own money to see if they can pay for what they've ordered.
	bool finishPurchase = 0;//this boolean variable will be used to carry on a do while loop.
	do {
		if (userMoney.cp >= totalCost.cp && userMoney.sp >= totalCost.sp && userMoney.gp >= totalCost.gp) {//this checks if the user has entered sufficient numbers for the prices.
			print("You have purchased: ");
			for (int i = 0; i < userPurchasedItems.size(); i++) {
				cout << i + 1 << ". " << userPurchasedItems[i] << " for " << costOfPurchases[i] << endl;
			}//the loop will then print what the user has purchased, excluding anything they may have deleted.
			Sleep(500);
			print("Enjoy!");//a nice message at the end of it.
			finishPurchase = 1;//the boolean is changed to true, or 1 in binary, stopping the do while.
		}
		else {//if the user does not have a sufficient amount, this else statement will occur.
			print("This is not enough. Maybe you could check some more pockets? (Y/N)");//asks in console if the user would like to recheck.
			char re_enterPrice = validateChar();//user input is validated to make sure y or n is entered.
			
			if (re_enterPrice == 'y') {//if the user wants to re-enter their money amount
				moneyPoints userMoney = askMoney();//the structure function is reused for them to do so. 
			}
			else if (re_enterPrice == 'n') {//if not
				print("Get out of my establisment, then!");
				finishPurchase = 1;//then the boolean variable is changed and the do while ends.
			}
		}
	} while (finishPurchase == 0);
	
	return 0;
}//the program ends after the user enters their money and finishes their purchase.

int validatePrice(int limit) {//this is the function used to make sure the prices entered is properly.
	int price;
	cin >> price;//the user enters the integer variable for each of the prices.
	while (cin.fail() || price < 0 || price > limit) {//cin.fail checks to see if the user input is the same as the variable they entered it into. For example, this must be a number, or it will fail.
		cout << "That's not the answer I am looking for." << endl;//an error message will appear on the console if the user input is wrong.
		cin.clear();//the user input will be deleted.
		cin.ignore(256, '\n');//the user input will be ignored as well.
		cin >> price;//then it will be re-entered.
	}//this will loop until whatever must be entered is correct.
	return price;//the number is then returned to the main function.
}

int validateInt(int limit) {//this is similar to the price function, but the beginning number is different.
	int num;
	cin >> num;
	while (cin.fail() || num < 1 || num > limit) {//the different number is one, as you don't want the number 0 since it is not an option. It can be however for the amount of money.
		cout << "That's not the answer I am looking for." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> num;
	}//same error checking as the price variable.
	return num;
}
char validateChar() {//this is similar to the int validation, but for characters.
	char character;
	cin >> character;
	character = tolower(character);//if the user enters a capital letter, it will be changed to lower case.
	while (character != 'y' && character != 'n') {//since all of the char checks are about y or n, this is what is checked for the validation.
		cout << "That's not the answer I am looking for." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> character;
	}//the user input is cleared and re-entered, similar to the int validation.
	return character;//the user inputted character is then returned to the main function.
}
