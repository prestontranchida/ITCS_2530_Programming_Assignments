//Preston Tranchida
//11-15-26
//Week 5 Assigment

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
// Week 6 - Aircraft observation category
enum TrafficLevel { LIGHT, MODERATE, HEAVY };

//Color Function
//If color green set changes text to green else, back to default.
void setConsoleColor(string color)
{
	if (color == "green") {
		cout << "\033[1;32m";
	}
	else {
		cout << "\033[0m";
	}
}

//banner Function
//Displays project title, and welcome message to user after they enter their name.
//Headers lines are green, title is white.
string banner()
{
	//Declare Local Variable
	string name;

	//Call Color Function to set color to green.
	setConsoleColor("green");
	//Title Header
	//For loop(runs twice)
	//Prints top lines.
	for (int i = 0; i < 2; i++) {
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	}
	//Call Color Function to reset color to default.
	setConsoleColor("reset");

	//Prints project title
	cout << "\n		PLANE TRACKER PROJECT\n" << endl;

	//Call Color Function to set color to green.
	setConsoleColor("green");
	//Prints bottom lines.
	for (int i = 0; i < 2; i++) {
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	}
	//Call Color Function to reset color to default.
	setConsoleColor("reset");

	//Welcome Message
	cout << "\nPlease enter you first name:" << endl;
	cin >> name;
	cout << "Hello " << name << ", welcome to my plane tracker project." << endl;
	return name;
}

//menu Function
//Asks user to choose an option on what to do. 1: Fill out new report. 2: Instructions. 3: Exit
int menu()
{
	//Declare Local Variable
	int option;
	//Asks user to choose one of the options of what to do below.
	cout << "Please choose an option below. " << endl;
	cout << "1. Create new report. 2. Instructions 3. Exit." << endl;
	cin >> option;

	//While loop
	//Checks that user entered a valid option
	while (option < 1 || option > 3) {
		cout << "Please enter a valid option: 1, 2, or 3" << endl;
		//Input Validation
		cin.clear();
		cin.ignore(200, '\n');

		cin >> option;
	}
	return option;
}

//userInput Function
//Gets user input, planes, helicopters, location and time.
void userInput(int& planes, int& helicopters, string& location, double& time)
{
	//Displays message asking for user to imput the type of plane, the number of that type, and their location.
	cout << "Today while you were outside how many planes and helicopters did you see at your current location?" << endl;
	cout << "Please enter the number of Planes and Helicopters you saw (Seperated by a space: Planes Helicopters):" << endl;
	//Inputs
	cin >> planes >> helicopters;
	//Input Validation
	cin.clear();
	cin.ignore(200, '\n');

	//Formatting
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
}

//calculation Function
//Calculates total aircraft.
int calculation(int helicopters, int planes)
{
	int total;
	//Calculates the total number of aircraft.
	total = helicopters + planes;
	return total;
}
// Week 6 - Store aircraft observations in an array
void collectObservations(int observations[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter aircraft count for observation "
			<< i + 1 << ": ";
		cin >> observations[i];

		// Validate each entry
		while (cin.fail() || observations[i] < 0)
		{
			cin.clear();
			cin.ignore(200, '\n');

			cout << "Please enter 0 or a positive number: ";
			cin >> observations[i];
		}
	}
}

// Week 6 - Calculate the total from the array
int calculateObservationTotal(int observations[], int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum = sum + observations[i];
	}

	return sum;
}

//report Function
//Creates report to console and to report.txt file.
void report(string name, string location, int planes, int helicopters, int total, double time, int observationTotal)
{
	//Displays the output message with information that the user input.
	cout << "Wow " << name << " you saw " << helicopters << " helicopters and " << planes << " planes fly over you in " << location << ". In total you saw " << total << " aircraft.That's very cool!!" << endl;
	cout << " " << endl;//Space between summary

	//Outputs summary to console 
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << setfill('.') << left << setw(35) << "User: " << right << " " << name << endl;
	cout << setfill('.') << left << setw(35) << "Location: " << right << " " << location << endl;
	cout << setfill('.') << left << setw(35) << "Plane Count: " << right << " " << planes << endl;
	cout << setfill('.') << left << setw(35) << "Helicopter Count: " << right << " " << helicopters << endl;
	cout << setfill('.') << left << setw(35) << "Total Aircraft Count: " << right << " " << total << endl;
	// Week 6 - Display total from the array
	cout << setfill('.') << left << setw(35) << "Observation Total: " << right << " " << observationTotal << endl;
	cout << fixed << setprecision(2); // Sets time to display 0.00
	cout << setfill('.') << left << setw(35) << "Time outside: " << right << " " << time << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

	
	//Outputs summary to report.txt
	ofstream outData("report.txt", ios::app);
	outData << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	outData << setfill('.') << left << setw(35) << "User: " << right << " " << name << endl;
	outData << setfill('.') << left << setw(35) << "Location: " << right << " " << location << endl;
	outData << setfill('.') << left << setw(35) << "Plane Count: " << right << " " << planes << endl;
	outData << setfill('.') << left << setw(35) << "Helicopter Count: " << right << " " << helicopters << endl;
	outData << setfill('.') << left << setw(35) << "Total Aircraft Count: " << right << " " << total << endl;
	// Week 6 - Display total from the array
	outData << setfill('.') << left << setw(35) << "Observation Total: " << right << " " << observationTotal << endl;	
	outData << fixed << setprecision(2); // Sets time to display 0.00
	outData << setfill('.') << left << setw(35) << "Time outside: " << right << " " << time << endl;
	outData << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	outData.close();
}

//main Function
int main()
{
	//Declare Local Variables
	string location, name;
	int helicopters, planes, total, option;
	double time;
	// Week 6 - Store three aircraft observations
	int observations[3] = { 0, 0, 0 };

	//Call Banner Function
	name = banner();

	//Do..while loop
	//While exit(3) is not selected the program will ask for input/will run.
	do {
		//Call Menu function
		option = menu();

		//Uses each case depending on the users input.
		switch (option)
		{
		case 1: { // Create new report
			// Call userInput Function
			userInput(planes, helicopters, location, time);

			// Call calculation Function
			total = calculation(helicopters, planes);

			// Week 6 - Fill the aircraft observations array
			collectObservations(observations, 3);

			// Week 6 - Calculate and display the array total
			int observationTotal = calculateObservationTotal(observations, 3);

			cout << "Total aircraft across all 3 observations: "
				<< observationTotal << endl;


			// Call report Function
			report(name, location, planes, helicopters, total, time, observationTotal);

			//compound conditionals
			//If user inputs time greater than or equal to 1.30(hrs) and total (aircraft) greater than or eqal to 15, output thats alot message, else wow you saw a lot in a short time message.
			if (time >= 1.30 && total >= 15)
				cout << "Wow you were  outside for " << time << " hours and saw " << total << " Planes and helicopters. Thats alot!!" << endl;
			else
				cout << "Nice you saw a few planes and helicopters in a short ammount of time." << endl;
			//If there are less helicopters than planes or more than 15 total aircraft output heavy traffic message else output light message.
			// Week 6 - Use enum to determine aircraft traffic
			TrafficLevel traffic;

			if (total >= 15)
				traffic = HEAVY;
			else if (total >= 5)
				traffic = MODERATE;
			else
				traffic = LIGHT;

			switch (traffic)
			{
			case LIGHT:
				cout << "Nice! Traffic seemed light today." << endl;
				break;

			case MODERATE:
				cout << "You saw moderate aircraft traffic today." << endl;
				break;

			case HEAVY:
				cout << "You saw heavy aircraft traffic today!" << endl;
				break;
			}
			break;
		}
		case 2: // Instructions
			cout << "Instructions:" << endl;
			cout << "Enter the count of planes and helicopters that you observed. Make sure to enter planes first and then helicopters after with a SPACE inbetween the two numbers. " << endl;
			cout << "Then enter your current city/location(With no spaces), followed by how long you were outside for. In hours(e.g. 1.30)" << endl;
			cout << "Thats all the info that you need to input your report will generate after that!!" << endl;
			// Week 6 - Observation instructions
			cout << "\nAdditional Observations:" << endl;
			cout << "Enter the number of aircraft seen during three "
				<< "separate observation periods." << endl;
			cout << "These counts are added together and shown separately "
				<< "from your original plane and helicopter total." << endl;
			break;
		case 3: // Exit
			cout << "Goodbye, " << name << "!" << endl;
			break;
		}
	} while (option != 3); //While option 3 is NOT chosen run program.
	return 0; //Exits program.
}