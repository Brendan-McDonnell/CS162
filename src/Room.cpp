/*
 * Room.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: brend
 */

#include "Room.h"

using namespace std;

Room::Room() {
	name = new char;
	description = new char;
	inventory = Inventory(0);
	exits.insert(pair<const char*, Room*>("NORTH", nullptr));
	exits.insert(pair<const char*, Room*>("EAST", nullptr));
	exits.insert(pair<const char*, Room*>("SOUTH", nullptr));
	exits.insert(pair<const char*, Room*>("WEST", nullptr));
}

Room::Room(char* name, char* description) {
	delete[] this->name;
	delete[] this->description;
	this->name = new char[strlen(name) + 1];
	this->description = new char[strlen(description) + 1];
	strcpy(this->name, name);
	strcpy(this->description, description);

	inventory = Inventory(0);
	exits.insert(pair<const char*, Room*>("NORTH", nullptr));
	exits.insert(pair<const char*, Room*>("EAST", nullptr));
	exits.insert(pair<const char*, Room*>("SOUTH", nullptr));
	exits.insert(pair<const char*, Room*>("WEST", nullptr));
}

Room::Room(char* name, char* description, Inventory inventory,
		map<const char*, Room*> exits) {
	delete[] this->name;
	delete[] this->description;
	this->name = new char[strlen(name) + 1];
	this->description = new char[strlen(description) + 1];
	strcpy(this->name, name);
	strcpy(this->description, description);
	this->inventory = inventory;
	this->exits = exits; // TODO: Check if this is the correct methodology for copying maps
}

Room::Room(const Room& source) {
	delete[] name;
	delete[] description;
	strcpy(name, source.name);
	strcpy(description, source.description);
	inventory = Inventory(source.inventory);
	exits = source.exits;
}

Room& Room::operator=(const Room& source) {
//	if (this == source) return *this;
	delete[] name;
	delete[] description;
	strcpy(name, source.name);
	strcpy(description, source.description);
	inventory = Inventory(source.inventory);
	exits = source.exits;
	return *this;
}

Room::~Room() {
	delete[] name;
	delete[] description;
	exits.clear();
}

bool Room::isValid() {
	bool out = true;

	if (name == NULL || description == NULL) out = false;
	for (map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++) {
		if (it->second == nullptr) out = false;
	}

	return out;;
}

void Room::print() {
	cout << "ENTERED PRINT FUNCTION" << endl;
	cout << &name << endl;
	cout << name << endl;
	cout << description << endl;
	cout << "PRINTED BASIC INFO" << endl;
	try {
		cout << "The exits are: " << endl; // TODO: Breaks if pointing to null
		cout << "test: " << &exits.at("NORTH") << endl;
		cout << "\tNORTH: " << exits.at("NORTH")->getName() << endl; // map.at() is C++ 11 functionality.
		cout << "\tEAST: " << exits.at("EAST")->getName() << endl;
		cout << "\tSOUTH: " << exits.at("SOUTH")->getName() << endl;
		cout << "\tWEST: " << exits.at("WEST")->getName() << endl;
	} catch (...) {
		cout << endl;
		cout << "Failed to access exits..." << endl; // TODO: Proper bug handling
	}

	cout << "There are " << inventory.count() << " items in this room." << endl;
	if (inventory.count() > 0) {
		vector<Item*> items = inventory.getItems();
		for (vector<Item*>::iterator it = items.begin(); it != items.end();
				it++) {
			cout << '\t' << (*it)->getName() << endl;
		}
	}
}

char* Room::getDescription() const {
	return description;
}

void Room::setDescription(char* description) {
	delete this->description;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

const map<const char*, Room*>& Room::getExits() const {
	return exits;
}

void Room::setExits(const map<const char*, Room*>& exits) {
	this->exits = exits;
}

const Inventory& Room::getInventory() const {
	return inventory;
}

void Room::setInventory(const Inventory& inventory) {
	this->inventory = inventory;
}

char* Room::getName() const {
	return name;
}

void Room::setName(char* name) {
	delete this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
