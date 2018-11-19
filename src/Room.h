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
	Room(char* name, char* description, Inventory inventory, map<const char*, Room*> exits);
	Room(Room& source);
	Room& operator=(const Room& source);
	virtual ~Room();

private:
	char* name;
	char* description;
	Inventory inventory;
	map<const char*, Room*> exits;
};

#endif /* SRC_ROOM_H_ */
