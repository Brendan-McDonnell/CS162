/*
 * Item.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: brend
 */

#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item() {
	name = nullptr;
	description = nullptr;
	worth = 0;
	quantity = 1;
}

Item::~Item() {
	delete[] name;
	delete[] description;
}

Item::Item(char* newname) {
	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
	description = nullptr;
	worth = 0;
	quantity = 1;
}

Item::Item(char* newname, char* newdescription) {
	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
	description = new char[strlen(newdescription) + 1];
	strcpy(description, newdescription);
	worth = 0;
	quantity = 1;
}

Item::Item(char* newname, char* newdescription, int newworth, int newquantity) {
	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
	description = new char[strlen(newdescription) + 1];
	strcpy(description, newdescription);
	worth = newworth;
	quantity = newquantity;
}

Item::Item(const Item& source) {
	delete[] name;
	delete[] description;
	name = new char[strlen(source.name) + 1];
	description = new char[strlen(source.description) + 1];
	strcpy(name, source.name);
	strcpy(description, source.description);
	worth = source.worth;
	quantity = source.quantity;
}

Item& Item::operator=(const Item& source) {
	if (this == &source) return *this;
	delete[] name;
	delete[] description;
	name = new char[strlen(source.name) + 1];
	description = new char[strlen(source.description) + 1];
	strcpy(name, source.name);
	strcpy(description, source.description);
	worth = source.worth;
	quantity = source.quantity;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Item& source) {
	os << "Item named '" << source.name << "':" << endl;
	os << "Description: " << source.description << endl;
	os << "Worth: " << source.worth << endl;
	os << "Quantity: " << source.quantity << endl;
	return os;
}

void Item::incrementQuantity() {
	this->incrementQuantity(1);
}

void Item::decrementQuantity() {
	this->incrementQuantity(-1);
}

void Item::incrementQuantity(int amount) {
	quantity += amount;
}

// Getters and Setters
// Getters and Setters
char* Item::getDescription() const {
	return description;
}

void Item::setDescription(char* description) {
	delete this->description;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

char* Item::getName() const {
	return name;
}

void Item::setName(char* name) {
	delete this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Item::getWorth() const {
	return worth;
}

void Item::setWorth(int worth) {
	this->worth = worth;
}

int Item::getQuantity() const {
	return quantity;
}

void Item::setQuantity(int quantity) {
	this->quantity = quantity;
}
