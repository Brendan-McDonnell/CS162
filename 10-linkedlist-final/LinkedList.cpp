// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Brendan McDonnell 1/8/2019

#include <iostream>
#include <cstdlib>
#include "List.h"

int main() {
	
	/*{
	List list;
	// Sample data generation
	for (int i = 0; i < 10; ++i) {
		list.insert(new Student(new char(0), new char(0), rand() % 10 + 1));
	}
	list.display();

	list.sort();
	list.display();

	list.remove(4);
	list.display();

	list.insert(new Student(new char(0), new char(0), 3));
	list.display();
	}*/
	
	List list;
	using namespace std;
	bool isRunning = true;
	while (isRunning) {
		cout << "Please input a command. Use 'HELP' for more information." << endl;
		char command[8] = { 0 };
		cin.getline(command, 8);
		//cin.clear();
		//cin.ignore(10000, '\n');
		//cin >> command;
		if (strcmp(command, "HELP") == 0) {
			cout << "The following commands are available:" << endl
				 << "HELP: Details available commands" << endl
				 << "ADD: Adds new student" << endl
				 << "PRINT: Prints all stored students" << endl
				 << "DELETE: Deletes a student" << endl
				 << "QUIT: Quits program" << endl
				 << "AVERAGE: Prints the average GPA of all students"
				 << "SORT: Sorts list of students" << endl;
		}
		else if (strcmp(command, "ADD") == 0) {
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
			id = atoi(idBuffer);
			cout << "What is the GPA?" << endl;
			char gpaBuffer[5];
			cin.getline(gpaBuffer, 5);
			gpa = atof(gpaBuffer);
			
			list.insert(new Student(FName, LName, id, gpa));
			cout << "Student added." << endl;
		}
		else if (strcmp(command, "PRINT") == 0) {
			list.display();
		}
		else if (strcmp(command, "DELETE") == 0) {
			cout << "What is the id of the student you want to delete?" << endl;
			char idBuffer[7];
			cin.getline(idBuffer, 7);
			int id = atoi(idBuffer); // Brute force use at() and then delete because I'm tired
			if (list.at(0)->getId() == id) {
				list.remove(0);
			}
			else {
				int i = 1;
				while (list.at(i)) {
					if (list.at(i)->getId() == id) {
						list.remove(i);
						break;
					}
					i++;
				}
				std::cout << "Could not find student" << std::endl;				
			}
		}
		else if (strcmp(command, "QUIT") == 0) {
			cout << "Quitting program..." << endl;
			isRunning = false;
		}
		else if (strcmp(command, "AVERAGE") == 0) {
			std::cout << "Finding average..." << std::endl;
			std::cout << list.average() << std::endl;
		}
		else if (strcmp(command, "SORT") == 0) {
			list.sort();
		}
		else {
			cout << "Command not recognized. Please try again." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << endl;
	}
}

