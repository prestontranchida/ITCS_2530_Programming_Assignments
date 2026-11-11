//Preston Tranchida
//11-8-26
//Week 4 Assigment

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	//Declare Variables
	//File Stream Variable
	ofstream outData;
	//Normal Variables
	string location, name;
	int helicopters, planes, total, option;
	double time;

	//Title Header
	//For loop
	for (int i = 0; i < 2; i++) {
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	}
	cout << "\n		PLANE TRACKER PROJECT" << endl;
	for (int i = 0; i < 2; i++) {
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	}

	//Welcome Message
	cout << "\nPlease enter you first name:" << endl;
	cin >> name;
	cout << "Hello " << name << ", welcome to my plane tracker project." << endl;

	// Do..while loop
	do {
		//Asks user to choose one of the options of what to do below.
		cout << "Please choose an option below. " << endl;
		cout << "1. Create new report. 2. Instructions 3. Exit." << endl;
		cin >> option;

		//While loop
		// Checks that user entered a valid option
		while (option < 1 || option > 3) {
			cout << "Please enter a valid option: 1, 2, or 3" << endl;
			//Input Validation
			cin.clear();
			cin.ignore(200, '\n');

			cin >> option;
		}

		//Uses each case depending on the users input.
		switch (option)
		{
		case 1:
			//Displays message asking for user to imput the type of plane, the number of that type, and their location.
			cout << "Today while you were outside how many planes and helicopters did you see at your current location?" << endl;
			cout << "Please enter the number of Planes and Helicopters you saw (Seperated by a space: Planes Helicopters):" << endl;
			//Inputs
			cin >> planes >> helicopters;
			//Input Validation
			cin.clear();
			cin.ignore(200, '\n');

			cout << " " << endl;

			//Displays message asking for location and time outside.
			cout << "Please enter your location: " << endl;
			//Get line location input
			getline(cin, location);
			cout << "Please also enter how long you were outside for (in Hours: ex. 1.30): " << endl;
			//Time input
			cin >> time;
			
			//Input Validation
			cin.clear();
			cin.ignore(200, '\n');

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

			//compound conditionals
			if (time >= 1.30 && total >= 15)
				cout << "Wow you were  outside for " << time << " hours and saw " << total << " Planes and helicopters. Thats alot!!" << endl;
			else
				cout << "Nice you saw a few planes and helicopters in a short ammount of time." << endl;

			if (helicopters < planes || total > 15)
				cout << "You saw heavy traffic totay!" << endl;
			else
				cout << "Nice! Traffic seemed light today." << endl;
			break;
		case 2:
			cout << "Instructions:" << endl;
			cout << "Enter the count of planes and helicopters that you observed. Make sure to enter planes first and then helicopters after with a SPACE inbetween the two numbers. " << endl;
			cout << "Then enter your current city/location(With no spaces), followed by how long you were outside for. In hours(e.g. 1.30)" << endl;
			cout << "Thats all the info that you need to input your report will generate after that!!" << endl;
			break;
		case 3:
			cout << "Goodbye, " << name << "!" << endl;
			break;
		default:
			cout << "Please enter a valid choice." << endl;
			break;
		}
	} while (option != 3);
	return 0;
}