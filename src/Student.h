/*
 * Student.h
 *
 *  Created on: Dec 11, 2018
 *      Author: brend
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

class Student {
public:
	Student();
	Student(char* firstName = new char(0), char* lastName = new char(0), int id = 0, float gpa = 0);
	virtual ~Student();
	void print() const;
	char* getFirstName() const;
	void setFirstName(char* firstName);
	float getGpa() const;
	void setGpa(float gpa);
	int getId() const;
	void setId(int id);
	char* getLastName() const;
	void setLastName(char* lastName);

private:
	char* firstName;
	char* lastName;
	int id;
	float gpa;
};

#endif /* SRC_STUDENT_H_ */
