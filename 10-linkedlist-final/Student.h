#ifndef STUDENT_H_
#define STUDENT_H_

#include <cstring>
class Student {
public:
	Student() {
		fName = 0;
		strcpy(fName, "firstname");
		lName = 0;
		strcpy(lName, "lastname");
		id = 0;
		float gpa = 0.0;
	}
	Student(char* fname = new char(0), char* lname = new char(0), int id = 0, float gpa = 0.0) {
		this->fName = new char[strlen(fname) + 1];
		strcpy(this->fName, fname);
		this->lName = new char[strlen(lname) + 1];
		strcpy(this->lName, lname);
		this->id = id;
		this->gpa = gpa;
	}
	char* getFName() { return fName; }
	char* getLName() { return lName; }
	int getId() { return id; }
	float getGpa() { return gpa; }
private:
	char* fName;
	char* lName;
	int id;
	float gpa;
};

#endif