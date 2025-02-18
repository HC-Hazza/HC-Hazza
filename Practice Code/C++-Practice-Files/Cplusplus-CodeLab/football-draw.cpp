#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
using namespace std;

vector<string> winningTeams(vector<string>teams, int limit) {//this creates a vector function that requires a vecotr and an integer from the main function.

	srand(time(NULL));//this creates a random seed.

	string team1, team2;//two string variables for the two teams that will be competing against each other.
	int countingVariable = 0;//this will be used to count up to the amount of matches there will be in the tourney.

	vector<string>winningTeams;//another vector to hold the teams that win, so we can eliminate the ones that lost.
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();//creates a random seed to be used in the shuffle of the vector.
	shuffle(teams.begin(), teams.end(), std::default_random_engine(seed));//this will put the teams in a random order each time the function is ran.

	do {
		team1 = teams.at(teams.size() - 1);//in the do while loop, the first string variable will take the team that is last in the vector.
		cout << "Home: " << team1 << endl;//this will print said team on the console.
		teams.pop_back();//that team will then be taken out of that vector.

		Sleep(1000);//this will pause the program for a second.

		team2 = teams.at(teams.size() - 1);//the same thing will happen for the second team, but since the first team is out of the vector, the next to last will be taken.
		cout << "Away: " << team2 << endl;
		teams.pop_back();

		Sleep(1000);

		int team1Score = rand() % 5 + 0, team2Score = rand() % 5 + 0;//the score will be a random number between 1 to 5. This will be applied to two variables representing the two teams.

		cout << team1 << " scored " << team1Score << endl << team2 << " scored " << team2Score << endl << endl;//this will print the scores of each team.

		Sleep(1000);

		if (team1Score > team2Score) {
			cout << team1 << " won!\n" << endl << endl;//this will print if the score of the first team is higher than the score of the second.
			winningTeams.push_back(team1);//that team will then be entered into the winning team vector.
		}
		else if (team1Score < team2Score) {
			cout << team2 << " won!\n" << endl << endl;
			winningTeams.push_back(team2);
		}//the same will occur if the second team has the highest score.
		while (team1Score == team2Score) {
			Sleep(1000);
			cout << "Penalties!" << endl;
			team1Score = rand() % 6 + 0;
			team2Score = rand() % 6 + 0;

			/*if the two teams have an equal score, the game will go into penalties until the scores are different from one another and a winner can be determined.*/

			cout << endl << team1 << " scored " << team1Score << endl << team2 << " scored " << team2Score << endl << endl;//the scores will be printed again since they were changed.
			if (team1Score > team2Score) {
				cout << team1 << " won!\n" << endl << endl;
				winningTeams.push_back(team1);
			}
			else if (team1Score < team2Score) {
				cout << team2 << " won!\n" << endl << endl;
				winningTeams.push_back(team2);
			}//the same thing will happen as before if the teams have different scores.
		}

		Sleep(1000);

		countingVariable++;//this will increase the variable counter so the function can loop through the vector.
	} while (countingVariable != limit);//the limit is half the amount of teams there are in each vector.

	cout << "And the winners are: ";//this will print after the loop is finished.

	for (string winnerOutput : winningTeams) {//this will print the teams that won their matches in the do while loop above.
		cout << winnerOutput << ", ";
		Sleep(1000);
	}

	cout << endl;

	return winningTeams;//the vector is then sent back to the main program.
}

int main() {

	vector<string>footballTeams = { "England", "France", "Germany", "Argentina", "Japan", "Sudan", "Brazil", "Uruguay", "Italy", "Croatia", "Russia", "Ireland", "Scotland", "Morocco", "Nigeria", "Mexico" }, quartarFinal, semiFinal, Final, finalResult;
	//here is the full vector of all 16 teams that are going to be playing.

	quartarFinal = winningTeams(footballTeams, 8);
	semiFinal = winningTeams(quartarFinal, 4);
	Final = winningTeams(semiFinal, 2);
	finalResult = winningTeams(Final, 1);
	//the vector function is ran several times for each of the qualifiers.

	string cupChampion = finalResult.at(0);//the last team will be put into a string variable.

	cout << cupChampion << " takes the cup!";//the user will be told on the console who wins the trophy!

	return 0;
}
