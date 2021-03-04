/*
 * Room.h
 *
 *  Created on: Nov 16, 2018
 *      Author: brend
 */

#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Inventory.h"

using namespace std;

class Room {
public:
	Room();
	Room(char* name, char* description);
	Room(char* name, char* description, Inventory inventory);
	Room(char* name, char* description, Inventory inventory, map<const char*, Room*> exits);
	Room(const Room& source);
	Room& operator=(const Room& source);
	virtual ~Room();

	bool isValid();
	void print();

	char* getDescription() const;
	void setDescription(char* description);
	map<const char*, Room*>& getExits();
	void setExits(const map<const char*, Room*>& exits);
	Inventory& getInventory();
	void setInventory(const Inventory& inventory);
	char* getName() const;
	void setName(char* name);

private:
	char* name;
	char* description;
	Inventory inventory;
	map<const char*, Room*> exits;
};

#endif /* SRC_ROOM_H_ */
