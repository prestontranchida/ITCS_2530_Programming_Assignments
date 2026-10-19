//Preston Tranchida
//10-18-26

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Declare Variables
	string Location;
	int helicopters, planes, total;

	//Displays message asking for user to imput the type of plane, the number of that type, and their location.
	cout << "Today when you were outside how many planes and helicopters did you see at your current location?" << endl;
	cout << "Please enter the number of each, and Location seperated by spaces. (Planes, Helicopers, Location)" << endl;

	//Takes in the user input and stores it.
	cin >> helicopters >> planes >> Location;

	//Calculates the total number of aircraft.
	total = helicopters + planes;

	//Displays the output message with information that the user input.
	cout << "Wow you saw " << helicopters << " helicopters and " << planes << " planes fly over you in " << Location << ". In total you saw " << total << " aircraft. That's very cool!!";
	return 0;
}