#include <iostream>
#include <cstring>
#include "LinkedList.h"
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
	
	LinkedList list();
	
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
			char FName[21];
			char LName[21];
			int id = 0;		
			int gpa = 0;	
			cout << "What is the first name?" << endl;
			cin.getline(FName, 21);
			cout << "What is the last name?" << endl;
			cin.getline(LName, 21);
			cout << "What is the six-digit id?" << endl;
			char idBuffer[7];
			cin.getline(idBuffer, 7);
			id = _atoi(idBuffer);
			cout << "What is the GPA?" << endl;
			char gpaBuffer[5];
			cin.getline(gpaBuffer, 5);
			gpa = _atof(gpaBuffer);
			
			list.insert(new Student(FName, LName, id, gpa));
			cout << "Student added." << endl;
		}
		else if (strcmp(command, Commands::Print) == 0) {
			list.printAll();
		}
		else if (strcmp(command, Commands::Delete) == 0) {
			cout << "What is the id of the student you want to delete?" << endl;
			char idBuffer[7];
			cin.getline(idBuffer, 7);
			id = _atoi(idBuffer);
			Node* curr = list.getHead();
			while (curr && curr->getStudent()->getId() != id) curr = curr.getNext();
			if (!curr) {
				cout << "Student not found." << endl;
			}
			else {
				list.delete(curr);
				cout << "Student deleted" << endl;
			}
		}
		else if (strcmp(command, Commands::Quit) == 0) {
			cout << "Quitting program..." << endl;
			isRunning = false;
		}
		else if (strcmp(command, Commands::Average) == 0) {
			Node* curr = list.head();
			int studentCount = 0;
			float totalGpa = 0.0;
			while (curr) {
				totalGpa += curr->getStudent()->getGpa();
				++studentCount;
				curr = curr->getNext();
			}
		}
		else {
			cout << "Command not recognized. Please try again." << endl;
		}
		cout << endl;
	}
	
	// Garbage collection
	delete list;
	
	return 0;
}