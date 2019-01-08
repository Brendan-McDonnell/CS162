#pragma once

class Student {
	public:
	// Constructors
	Student(char* f, char* l, int id = 0, int gpa = 0)
		: firstName(f), lastName(l) {
		this->id = id;
		this->gpa = gpa;
	}
	
	// Getters
	char* getFirstName() { return firstName; }
	char* getLastName() { return lastName; }
	int getId() { return id; }
	int getGpa() { return gpa; }
	
	private:
	char* firstName;
	char* lastName;
	int id;
	int gpa;
}