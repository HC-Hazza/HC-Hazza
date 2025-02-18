#include <iostream>
#include <string>
#include <tuple>//this will allow the code to use tuples.
using namespace std;

int main() {
	pair<string, int> footballTeam {"Chelsea.", 1};//a pair lets me assign two types of variables into one variable.
	cout << "The football team is " << footballTeam.first << endl << "They are number " << footballTeam.second << " in the league." << endl;
	//the text above is printed to the console along with the two things I wrote in the pair variable.
	tuple<string, double, int> city{ "Swindon.", 10.7, 6 };//a tuple allows me to assign three types of variables to one full variable.
	cout << endl << "Today's forecast is over " << get<0>(city) << endl << "The temperature today is " << get<1>(city) << ". \nThe wind speed is downwards at " << get<2>(city) << "km/h." << endl;
	//the text here is printed to the console along with the three items I entered into the tuple.
	return 0;
}
