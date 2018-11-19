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
	name = newname;
	description = nullptr;
	worth = 0;
	quantity = 1;
}

Item::Item(char* newname, char* newdescription) {
	name = newname;
	description = newdescription;
	worth = 0;
	quantity = 1;
}

Item::Item(char* newname, char* newdescription, int newworth, int newquantity) {
	name = newname;
	description = newdescription;
	worth = newworth;
	quantity = newquantity;
}

Item::Item(Item& source) {
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
	if (*this == source) return *this;
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

std::ostream& operator <<(std::ostream& os, const Item& source) {
	os << "Item named '" << source.name << "':" << endl;
	os << "Description: " << source.description << endl;
	os << "Worth: " << source.worth << endl;
	os << "Quantity: " << source.quantity << endl;
	return os;
}
