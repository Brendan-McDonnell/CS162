#include <iostream>
#include <cstring>
#include "Student.h"

int main() {
	using namespace std;
	
	enum Commands {
		Help = "HELP",
		Add = "ADD",
		Print = "PRINT",
		Delete = "DELETE",
		Quit = "QUIT",
		Average = "AVERAGE"
	};
	
	bool isRunning = true;
	while (isRunning) {
		cout << "Please input a command. Use 'HELP' for more information." << endl;
		char command[8] = 0;
		cin.getline(command, 7);
		if (strcmp(command, Commands::Help) == 0) {
			cout << "The following commands are available:" << endl
				 << "HELP: Details available commands" << endl
				 << "ADD: Adds new student" << endl
				 << "PRINT: Prints all stored students" << endl
				 << "DELETE: Deletes a student" << endl
				 << "QUIT: Quits program" << endl
				 << "AVERAGE: Prints the average GPA of all students" << endl;
		}
		else if (strcmp(command, Commands::Add) == 0) {
			char* newFName = new char[ // TODO HERE
		}
		else if (strcmp(command, Commands::Print) == 0) {
			
		}
		else if (strcmp(command, Commands::Delete) == 0) {
			
		}
		else if (strcmp(command, Commands::Quit) == 0) {
			cout << "Quitting program..." << endl;
			isRunning = false;
		}
		else if (strcmp(command, Commands::Average) == 0) {
			
		}
		else {
			cout << "Command not recognized. Please try again." << endl;
		}
		cout << endl;
	}
	
	// Garbage collection
	
	return 0;
}