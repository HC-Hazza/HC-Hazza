#include <iostream>
#include <time.h>
using namespace std;

int main() {

	enum class gameSettings {
		MENU,
		PLAYING,
		PAUSED,
		GAMEOVER
	};//an enum for each setting of the game. Once for the opening menu, one for the game playing, one for the game being paused and one for the game to end.

	int lives = 3;//the user will have 3 lives, losing one each time they get an odd number from a randomiser of 100 numbers.

	gameSettings current_setting = gameSettings::MENU;//the game will open with the menu, so the variable for the switch statement will begin with the menu.

	while (current_setting != gameSettings::GAMEOVER) {//this will loop until the user loses all their lives or they quit the game.

		switch (current_setting) {//a switch statement will go through each setting of the game the user chooses.
		case gameSettings::MENU:
			int menu;//the user can enter an integer for here so they can decide whether or not they want to play the game.
			cout << "Would you like to 1: Play the Game or 2. End the Game?" << endl;
			cin >> menu;
			while (cin.fail() || (menu != 1 && menu != 2)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Please enter a number specified above: ";
				cin >> menu;
			}//if the user enters something other than 1 or 2, or a letter, they will be forced to input again.

			if (menu == 1) {
				current_setting = gameSettings::PLAYING;//if the user enters 1, they will be playing the game.
			}
			else if (menu == 2) {
				current_setting = gameSettings::GAMEOVER;//if they decide to quit, and enter 2, the game will end.
			}
			break;
		case gameSettings::PLAYING: {
			bool playAgain = true;//this boolean variable wil be for the do while loop.

			do {
				srand(time(NULL)); //a random seed is declared.
				int rng = rand() % 100 + 1; //the number for the game will be randomised from 1 to 100.
				int rngCheck = rng % 2;//this will check if that number was odd by using modulus by 2.
				if (rngCheck == 0) {//the output being 0 will mean the number is even, meaning the user wins.
					cout << "You win...this time." << endl;//this will be printed to the console.
				}
				else if (rngCheck == 1) {//the output being 1 will mean the number is odd, meaning the user lost.
					cout << "Shame...You lose...a life!" << endl;//this will be printed to the console.
					lives--;//the number of lives will decrease by one.
					cout << "You have " << lives << " left." << endl;//after a life is lost, the remaining number will be printed will be printed to the console.
				}

				if (lives == 0) {//if the user loses 3 times they will hit the gameover screen and the while loop will end.
					playAgain = false;
					current_setting = gameSettings::GAMEOVER;
				}
				else {
					cout << "Would you like to keep playing? Y or N (N will cause the game to pause.)" << endl;//if the user still has lives, this will be printed to the console.
					char pause;
					cin >> pause;//a character variable is declared and initialised by the user.
					pause = toupper(pause);//the character variable will always be made into a capital letter with this function.
					while (pause != 'Y' && pause != 'N') {
						cin.ignore(1000, '\n');
						cin.clear();
						cout << "Please enter Y or N for yes or no respectively." << endl;
						cin >> pause;
					}//this will check if the user entered y or n to make sure the program doesn't break.
					if (pause == 'N') {//if the user wants to pause the game, they will enter n.
						playAgain = false;//since the game will stop playing, the boolean is changed.
						current_setting = gameSettings::PAUSED;//the switch statement will then go to the pause section.
					}
				}
			} while (playAgain == true);
			break;
		}
		case gameSettings::PAUSED:
			cout << "The game has been paused. \nWould you like to go back to the main menu? Y/N (N will resume the game)" << endl;//if the user pauses the game, this will be printed to the console.
			char play;
			cin >> play;//a character variable is declared and initialised by the user.
			play = toupper(play);//like before, the variable will always be made into a capital letter with this function.
			while (play != 'Y' && play != 'N') {
				cin.ignore(1000, '\n');
				cin.clear();
				cout << "Please enter Y or N for yes or no respectively." << endl;
				cin >> play;
			}//this will make sure the user enters y or n like before.
			if (play == 'N') {
				current_setting = gameSettings::PLAYING;//if the user wants to keep playing, they will press n to resume the game.
			}
			else {
				current_setting = gameSettings::MENU;//if the user wants to exit the game, they can return to the menu.
			}
			break;
		}
	}

	cout << "The game is over...";//if the game ends, the user will be notified when this is printed to the console.

	return 0;
}
