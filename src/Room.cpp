/*
 * Room.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: brend
 */

#include "Room.h"

using namespace std;

Room::Room() {
	name = 0;
	description = 0;
	inventory = Inventory(0);
	exits = {
		"NORTH" = nullptr,
		"EAST" = nullptr,
		"SOUTH" = nullptr,
		"WEST" = nullptr
	};
}

Room::Room(char* name, char* description) {
	this->name = name;
	this->description = description;
	inventory = Inventory(0);
	exits = {
		"NORTH" = nullptr,
		"EAST" = nullptr,
		"SOUTH" = nullptr,
		"WEST" = nullptr
	};
}

Room::Room(char* name, char* description, Inventory inventory,
		map<const char*, Room*> exits) {
	this->name = name;
	this->description = description;
	this->inventory = inventory;
	this->exits = exits;
}

Room::Room(Room& source) {
	delete[] name;
	delete[] description;
	strcpy(name, source.name);
	strcpy(description, source. description);
	inventory = Inventory(source.inventory);
	exits = source.exits;
}

Room& Room::operator=(const Room& source) {
	if (*this == source) return *this;
	delete[] name;
	delete[] description;
	strcpy(name, source.name);
	strcpy(description, source. description);
	inventory = Inventory(source.inventory);
	exits = source.exits;
	return *this;
}

Room::~Room() {
	delete[] name;
	delete[] description;
	exits.clear();
}
