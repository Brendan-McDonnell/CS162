#pragma once

class Student {
	public:
	// Constructors
	Student(char* f, char* l, int id = 0, int gpa = 0)
		: firstName(f), lastName(l) {
		this->id = id;
		this->gpa = gpa;
	}
	
	void print() {
		std::cout << firstName << " " << lastName << ", " << id << ", " << gpa << std::endl;
	}
	
	// Getters
	char* getFirstName() const { return firstName; }
	char* getLastName() const { return lastName; }
	int getId() const { return id; }
	int getGpa() const { return gpa; }
	
	private:
	char* firstName;
	char* lastName;
	int id;
	int gpa;
}