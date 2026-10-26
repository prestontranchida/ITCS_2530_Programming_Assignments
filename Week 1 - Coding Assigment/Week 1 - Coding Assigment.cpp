//Preston Tranchida
//10-25-26
//Week 2 Assigment

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>//
using namespace std;

int main()
{
	//Declare Variables
	//File Stream Variable
	ofstream outData;
	//Normal Variables
	string location, name;
	int helicopters, planes, total;
	double time;

	//Title Header
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\n		PLANE TRACKER PROJECT" << endl;
	cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;

	//Welcome Message
	cout << "\nPlease enter you first name:" << endl;
	cin >> name;
	cout << " " << endl;
	cout << "Hello " << name << ", welcome to my plane tracker project." << endl;
	cout << " " << endl;


	//Displays message asking for user to imput the type of plane, the number of that type, and their location.
	cout << "Today while you were outside how many planes and helicopters did you see at your current location?" << endl;
	cout << "Please enter the number of Planes and Helicopters you saw (Seperated by a space: Planes Helicopters):" << endl;
	//Inputs
	cin >> planes >> helicopters;
	cout << " " << endl;

	//Displays message asking for location and time outside.
	cout << "Please enter your location, and how long you were outside for (in Hours: ex. 1.30) (Seperated by a space: Location Time)" << endl;
	//Inputs
	cin >> location >> time;
	cout << " " << endl;
	
	//Calculates the total number of aircraft.
	total = helicopters + planes;

	//Displays the output message with information that the user input.
	cout << "Wow " << name << " you saw " << helicopters << " helicopters and " << planes << " planes fly over you in " << location << ". In total you saw " << total << " aircraft.That's very cool!!" << endl;
	cout << " " << endl;//Space between summary

	//Outputs summary to console 
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << setfill('.') << left << setw(35) << "User: " << right << " " << name << endl;
	cout << setfill('.') << left << setw(35) << "Location: " << right << " " << location << endl;
	cout << setfill('.') << left << setw(35) << "Plane Count: " << right << " " << planes << endl;
	cout << setfill('.') << left << setw(35) << "Helicopter Count: " << right << " " << helicopters << endl;
	cout << setfill('.') << left << setw(35) << "Total Aircraft Count: " << right << " " << total << endl;
	cout << fixed << setprecision(2); // Sets time to display 0.00
	cout << setfill('.') << left << setw(35) << "Time outside: " << right << " " << time << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	

	//Outputs summary to report.txt
	outData.open("report.txt", ios::app);
	outData << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	outData << setfill('.') << left << setw(35) << "User: " << right << " " << name << endl;
	outData << setfill('.') << left << setw(35) << "Location: " << right << " " << location << endl;
	outData << setfill('.') << left << setw(35) << "Plane Count: " << right << " " << planes << endl;
	outData << setfill('.') << left << setw(35) << "Helicopter Count: " << right << " " << helicopters << endl;
	outData << setfill('.') << left << setw(35) << "Total Aircraft Count: " << right << " " << total << endl;
	outData << fixed << setprecision(2); // Sets time to display 0.00
	outData << setfill('.') << left << setw(35) << "Time outside: " << right << " " << time << endl;
	outData << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	outData.close();
	
	return 0;
}