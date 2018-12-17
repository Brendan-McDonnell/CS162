/*
 * Student.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: brend
 */

#include <iostream>
#include <cstring>
#include "Student.h"

Student::Student() {
	firstName = new char(0);
	lastName = new char(0);
	id = 0;
	gpa = 0;
}

Student::Student(char* firstName, char* lastName, int id, float gpa) {
	delete[] this->firstName;
	delete[] this->lastName;
	this->firstName = new char[strlen(firstName) + 1];
	this->lastName = new char[strlen(lastName) + 1];
	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
	this->id = id;
	this->gpa = gpa;
}

Student::~Student() {
	delete[] firstName;
	delete[] lastName;
}

char* Student::getFirstName() const {
	return firstName;
}

void Student::setFirstName(char* firstName) {
	this->firstName = firstName;
}

float Student::getGpa() const {
	return gpa;
}

void Student::setGpa(float gpa) {
	this->gpa = gpa;
}

int Student::getId() const {
	return id;
}

void Student::setId(int id) {
	this->id = id;
}

char* Student::getLastName() const {
	return lastName;
}

void Student::setLastName(char* lastName) {
	this->lastName = lastName;
}

void Student::print() const {
	std::cout << firstName << ' ' << lastName << std::endl;
	std::cout << '\t' << id << std::endl;
	std::cout << '\t' << gpa << std::endl;
}
