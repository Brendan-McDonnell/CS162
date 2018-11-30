/*
 * Application.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: Brendan McDonnell
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Inventory.h"
#include "Item.h"

using namespace std;

vector<Item*> getItems();
vector<Room*> getRooms(vector<Item*>);
void buildRoomMap(vector<Room*>);

int main() {
	/*
	 * THEORY:
	 *
	 * Setup
	 * 	Build items
	 * 	Build rooms
	 * 	Build room map
	 * 	Set up player
	 * 	Set up win condition
	 *
	 * Loop
	 * 	Print current condition
	 * 	Get command
	 * 	Process command
	 *
	 * Clean up
	 * 	Delete all dynamically allocated memory
	 *
	 */

	vector<Item*> items;
	vector<Room*> rooms;
	Inventory player = Inventory(100);

	// Initial set up
	items = getItems(); // Build all items to be used
	rooms = getRooms(items); // Build all rooms to be used
	buildRoomMap(rooms); // Connect all rooms together
	Room* currentRoom = new Room(); // = starting room;

	while (1 /* END GAME CONDITION */) {
		// MAIN GAME LOOP

		// Initial print
		cout << endl << "**********************************" << endl;
		if (currentRoom->isValid()) currentRoom->print();
		else {
			cout << "Room invalid.\nTerminating program..." << endl;
			break;
		}

		// Handle commands
		cout << endl << "What do you do? ";
		cin.get();
		cin.clear();
		cin.ignore(10000, '\n');
		/* HANDLE COMMANDS */

		cout << "**********************************" << endl;
	}
	cout << "Exited main game loop." << endl;

	// Garbage collection
	{ // Scope for iterator name declaration
		cout << "Erasing items..." << endl;
		vector<Item*>::iterator it = items.begin();
		while (items.size() != 0) {
			cout << "Erasing '" << (*it)->getName() << "'... ";
			it = items.erase(it);
			cout << "Success." << endl;
		}
		cout << "Items erased." << endl;
	}
	{ // Scope for iterator name declaration
		cout << "Erasing rooms..." << endl;
		vector<Room*>::iterator it = rooms.begin();
		while (rooms.size() != 0) {
			delete *it;
			it = rooms.erase(it);
		}
		cout << "Rooms erased." << endl;
	}
	return 0;
}

inline vector<Item*> getItems() {
	vector<Item*> out;
	out.push_back(
			new Item((char*) "Test Name", (char*) "Test Description", 100, 3));
	return out;
}

inline vector<Room*> getRooms(vector<Item*> items) {
	vector<Room*> out;
	return out;
}

inline void buildRoomMap(vector<Room*> rooms) {

}
