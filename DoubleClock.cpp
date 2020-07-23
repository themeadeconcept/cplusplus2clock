//Name: Torrey Meade
//Course: CS 210 - Programming Languages
//Project 1
//01/17/2020

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//function displays both clocks
char DoubleClock(int numHours, int numMins, int numSeconds, int dayNite, int newHours = 0) {
	char bottomLine;

	//conversion for am or pm to an int and determining time of day
	if (dayNite == 2) {
		newHours += 12;
	}

	//displays both clocks in two separate columns using setw for the width and setfill for the fill characters
	cout << left << setw(25) << setfill('*') << "*" << "     " << right << setw(25) 
		 << setfill('*') << "*"<<  endl;
	cout << left << "*     " << "12-HOUR CLOCK" << "     *" 
		 << right << "     " << "*     " <<  "24-HOUR CLOCK" << "     *" << endl;
	cout << right << "*      " << setw(2) << setfill('0') << numHours << ":";
	cout << right << setw(2) << setfill('0') << numMins << ":";
	cout << right << setw(2) << setfill('0') << numSeconds << " ";
	//determines AM or PM
	if (dayNite == 1) {
		cout << left << "AM      *" << "     ";
	}
	else {
		cout << left << "PM      *" << "     ";
	}
	cout << "*       " << right << setw(2) << setfill('0') << numHours << ":";
	cout << right << setw(2) << setfill('0') << numMins << ":";
	cout << right << setw(2) << setfill('0') << numSeconds << " " << "       *" << endl;

	cout << left << setw(25) << setfill(' ') << "*************************" << "     "
		<< left << setw(24) << setfill(' ') << "************************";

	bottomLine = '*';

	return bottomLine;
}

//function for adding time and exiting the program
int TimeChoices() {
	int userChoice;

	//displays decision choices
	cout << setw(14) << setfill(' ') << " " << setw(25) << setfill('*') << "*" 
		 << setw(14) << setfill(' ') << " " << endl;
	cout << setw(14) << setfill(' ') << " " << "* " << "1 - Add One Hour" << "      *" 
		 << setw(14) << setfill(' ') << " " << endl;
	cout << setw(14) << setfill(' ') << " " << "* " << setw(2) << setfill('0') << "2 - Add One Minute" << "    *" 
		 << setw(14) << setfill(' ') << " " << endl;
	cout << setw(14) << setfill(' ') << " " << "* " << setw(2) << setfill('0') << "3 - Add One Second" << "    *" 
		 << setw(14) << setfill(' ') << " " << endl;
	cout << setw(14) << setfill(' ') << " " << "* " << setw(2) << setfill('0') << "4 - Exit Program" << "      *" 
		 << setw(14) << setfill(' ') << " " << endl;
	cout << setw(14) << setfill(' ') << " " << "*************************" 
		 << setw(14) << setfill(' ') << " " << endl;

	cout << setw(10) << setfill(' ') << " " << "Please make a selection: " 
		 << setw(10) << setfill(' ') << " " << endl;
	cin >> userChoice;

	return userChoice;
}

//switch function for adding time and exiting program
int UserChoiceLoop(int userChoice, int &hours, int &minutes, int &seconds, int timePlaceholder) {
	
	switch (userChoice) {
	case 1:
		++hours;
		system("CLS");
		cout << left << setw(25) << DoubleClock(hours, minutes, seconds, timePlaceholder) << endl;
		break;
	case 2:
		++minutes;
		system("CLS");
		cout << left << setw(25) << DoubleClock(hours, minutes, seconds, timePlaceholder) << endl;
		break;
	case 3:
		++seconds;
		system("CLS");
		cout << left << setw(25) << DoubleClock(hours, minutes, seconds, timePlaceholder) << endl;
		break;
	default:
		//ends program
		exit(0);
	}

	return userChoice;
}

int main() {
	int hours;
	int minutes;
	int seconds;
	string timePlaceholder;
	int selection;
	int i, x;

	//ask for input of current time, if the time is an invalid time, loops asks for new input
	cout << "Please enter current Hour: " << endl;
	cin >> hours;
	while (hours > 12) {
		cout << "Exceeds 12 hours, please re-enter the hour: " << endl;
		cin >> hours;
	}

	cout << "Please enter current Minutes: " << endl;
	cin >> minutes;
	while (minutes > 59) {
		cout << "Exceeds 59 minutes, please re-enter the minutes: " << endl;
		cin >> minutes;
	}

	cout << "Please enter current seconds: " << endl;
	cin >> seconds;
	while (seconds > 59) {
		cout << "Exceeds 59 seconds, please re-enter the seconds: " << endl;
		cin >> seconds;
	}

	cout << "Please enter time of day (am or pm): " << endl;
	cin >> timePlaceholder;
	
	//conversion of time of day to and integer
	if (timePlaceholder == "am" || timePlaceholder == "AM") {
		i = 1;
	}
	else if (timePlaceholder == "pm" || timePlaceholder == "PM") {
		i = 2;
	}
	
	system("CLS");

	//function call to display clocks next to each other
	cout << left << setw(25) << DoubleClock(hours, minutes, seconds, i) << endl;

	//function call for adding time or exiting program
	selection = TimeChoices();
	//returns the choice to selection variable
	cout << selection;

	//continuous loop to re-enter choice loop if the selection is not 4
	for (x = selection; x < 4; ++x) {
		if (x < 4 && x > 0) {
			UserChoiceLoop(selection, hours, minutes, seconds, i);
			selection = TimeChoices();
			system("CLS");
			cout << "PERFECT!" << flush; //flush forces the printing to the screen before it clears
			system("CLS");

			cout << left << setw(25) << DoubleClock(hours, minutes, seconds, i) << endl;
			//must reduce x each time to ensure the only exit would be the selection of 4
			--x;
		}
		else {
			//exits the loop
			break;
		}
	}
}