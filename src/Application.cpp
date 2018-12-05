/*
 * Application.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: Brendan McDonnell
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "Room.h"
#include "Inventory.h"
#include "Item.h"

using namespace std;

vector<Item*> getItems();
vector<Room*> getRooms(vector<Item*>);
void buildRoomMap(vector<Room*>);
Room* getRoomFromRooms(vector<Room*>, char*);
void printStartGame();
void scrollPrint(char*, int);

int main() {
	printStartGame();

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
	cout << "Initalization:" << endl;
	items = getItems(); // Build all items to be used
	cout << "Items done." << endl;
	rooms = getRooms(items); // Build all rooms to be used
	cout << "Rooms done." << endl;
	buildRoomMap(rooms); // Connect all rooms together with pointers
	Room* currentRoom = *rooms.begin(); // = starting room;
	cout << "Initialized." << endl;

//	printStartGame();

	bool gameOver = false;
	while (!gameOver) {
		// MAIN GAME LOOP

		// Initial print
		cout << endl << "**********************************" << endl;
		if (currentRoom->isValid())
			currentRoom->print();
		else {
			cout << "Room invalid.\nTerminating program..." << endl;
			break;
		}

		// Handle commands
		bool isGettingCommands = true;
		while (isGettingCommands) {
			isGettingCommands = false;
			cout << endl << "What do you do? ";
			char* command = 0;
			cin >> command; // NOTE: One word only
			for (unsigned int i = 0; i < strlen(command); i++)
				command[i] = toupper(command[i]);
			cout << endl;
			if (!strcmp(command, "HELP")) {
				cout << "COMMAND LIST: " << endl;
				cout << "\tEXIT: Exits current room in an inputed direction."
						<< endl;
				cout << "\tTAKE: Takes item from current room." << endl;
				cout << "\tDROP: Drops item from inventory." << endl;
				cout << "\tQUIT: Terminates game." << endl;
			} else if (!strcmp(command, "EXIT")) {
				map<const char*, Room*> roomExits;
				char* direction = 0;
				cout << "In what direction? " << endl;
				cin >> direction;
				for (unsigned int i = 0; i < strlen(direction); i++)
					direction[i] = toupper(direction[i]);
				roomExits = currentRoom->getExits();
				currentRoom = roomExits[direction];
				delete[] direction;
			} else if (!strcmp(command, "TAKE")) {
				char* itemName = 0;
				cout << "What item would you like to take?" << endl;
				cin >> itemName;
				if (currentRoom->getInventory().contains(itemName)) {
					player.addItem(
							currentRoom->getInventory().takeItem(itemName));
				} else {
					cout << "Item could not be found." << endl;
				}
				delete[] itemName;
			} else if (!strcmp(command, "DROP")) {
				char* itemName = 0;
				cout << "What item would you like to drop?" << endl;
				cin >> itemName;
				if (player.contains(itemName)) {
					currentRoom->getInventory().addItem(
							player.takeItem(itemName));
				} else {
					cout << "Item could not be found." << endl;
				}
				delete[] itemName;
			} else if (!strcmp(command, "QUIT")) {
				gameOver = true;
			} else {
				cout << "Command not recognized. Please try again." << endl
						<< endl;
				isGettingCommands = true;
			}
		}

		// Check win condition
		if (!gameOver) {
			// TODO: UPdate win condition
		}
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

	return 0; // Exit program
}

inline vector<Item*> getItems() { // NOTE: Ignores worth / quantity as they are no longer implemented
	vector<Item*> out;

	out.push_back(
			new Item((char*) "Spirit's Tear",
					(char*) "A strangely heavy and luminescent tear. It's important for the plot."));
	out.push_back(
			new Item((char*) "Wooden Sword",
					(char*) "A dull and useless stick"));
	out.push_back(
			new Item((char*) "Fake Tear",
					(char*) "Oh hey look. A milky puddle that glows."));
	out.push_back(
			new Item((char*) "Steel Sword",
					(char*) "A significant improvement over a wooden sword. If only there was combat!"));

	return out;
}

inline vector<Room*> getRooms(vector<Item*> items) {
	cout << "Entered." << endl;
	vector<Room*> out;

	Item* tear =
			new Item((char*) "Spirit's Tear",
					(char*) "A strangely heavy and luminescent tear. It's important for the plot.");
	cout << "Survived Tear creation" << endl;

	// 1
	out.push_back(new Room((char*) "Field", (char*) "Food grows here"));
	cout << "Survived normal room." << endl;
	// 2
	out.push_back(
			new Room((char*) "Path", (char*) "It has dirt and rocks everywhere",
					Inventory(tear)));
	cout << "Survived Room with tear." << endl;
	// 3
	out.push_back(
			new Room((char*) "Glade",
					(char*) "This is where the tears go. Get three of them."));
	// 4
	out.push_back(
			new Room((char*) "Village",
					(char*) "Plot things happened here. Gasp!",
			Inventory(items[1])));
	// 5
	out.push_back(
			new Room((char*) "Forest",
					(char*) "There's trees. This is the first of many forests",
			Inventory(items[2])));
	// 6
	out.push_back(
			new Room((char*) "Jungle",
					(char*) "It's not really a jungle, its just like the rest of the forest.",
			Inventory(items[3])));
	// 7
	out.push_back(
			new Room((char*) "Park",
					(char*) "'Park' May be a synonym for forest, but this place doesn't look like a park."));
	// 8
	out.push_back(
			new Room((char*) "Wood",
					(char*) "As in the type of forest and not the organic material"));
	// 9
	out.push_back(
			new Room((char*) "Copse",
					(char*) "I don't think it could be a copse of trees if its already in the forest, but whatever."));
	// 10
	out.push_back(
			new Room((char*) "Meadow", (char*) "Flowers! And plot! Yay!",
					Inventory(tear)));
	// 11
	out.push_back(new Room((char*) "Thicket", (char*) "With four C's"));
	// 12
	out.push_back(
			new Room((char*) "Mountain Path",
					(char*) "Good views. Steep. Work hard. Fall bad."));
	// 13
	out.push_back(
			new Room((char*) "Tunnel",
					(char*) "Kinda thin in here. And pretty dark."));
	// 14
	out.push_back(new Room((char*) "Cavern", (char*) "Its empty, sorry",
			Inventory(items[4])));
	// 15
	out.push_back(
			new Room((char*) "Underwater Lake",
					(char*) "Smeagle leaves the last tear on the ground for you. How precious.",
					Inventory(tear)));
	return out;
}

inline void buildRoomMap(vector<Room*> rooms) {
	vector<Room*>::iterator it = rooms.begin();

//	(*it)->getExits()["DIR"] = getRoomFromRooms(rooms, (char*) "NAME");
	// Field
	(*it)->getExits()["NORTH"] = getRoomFromRooms(rooms, (char*) "Village");
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Path");
	it++;

	// Path
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Field");
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Glade");

	// Glade
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Path");

	// Village
	(*it)->getExits()["NORTH"] = getRoomFromRooms(rooms, (char*) "Forest");
	(*it)->getExits()["SOUTH"] = getRoomFromRooms(rooms, (char*) "Field");

	// Forest
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Thicket");
	(*it)->getExits()["SOUTH"] = getRoomFromRooms(rooms, (char*) "Village");
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Jungle");

	// Jungle
	(*it)->getExits()["NORTH"] = getRoomFromRooms(rooms, (char*) "Copse");
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Forest");
	(*it)->getExits()["SOUTH"] = getRoomFromRooms(rooms, (char*) "Park");

	// Park
	(*it)->getExits()["NORTH"] = getRoomFromRooms(rooms, (char*) "Jungle");
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Wood");

	// Wood
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Park");

	// Copse
	(*it)->getExits()["SOUTH"] = getRoomFromRooms(rooms, (char*) "Jungle");
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Meadow");

	// Meadow
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Copse");

	// Thicket
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms, (char*) "Forest");
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms,
			(char*) "Mountain Path");

	// Mountain Path
	(*it)->getExits()["NORTH"] = getRoomFromRooms(rooms, (char*) "Tunnell");
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Thicket");

	// Tunnel
	(*it)->getExits()["NORTH"] = getRoomFromRooms(rooms, (char*) "Cavern");
	(*it)->getExits()["EAST"] = getRoomFromRooms(rooms,
			(char*) "Underground Lake");
	(*it)->getExits()["SOUTH"] = getRoomFromRooms(rooms,
			(char*) "Mountain Path");

	// Cavern
	(*it)->getExits()["SOUTH"] = getRoomFromRooms(rooms, (char*) "Tunnel");

	// Underground Lake
	(*it)->getExits()["WEST"] = getRoomFromRooms(rooms, (char*) "Tunnel");

}

// Throw efficiency away
inline Room* getRoomFromRooms(vector<Room*> rooms, char* name) {
	for (vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); it++) {
		if (!strcmp((*it)->getName(), name))
			return *it;
	}
	return 0;
}

inline void printStartGame() {
	ifstream plot;
	const int MAX_LINE_SIZE = 320;
	char* out = new char[MAX_LINE_SIZE];
	plot.open("opening_storyline");
	while (plot.getline(out, MAX_LINE_SIZE))
		scrollPrint(out, 2);
	delete[] out;
	plot.close();
}

inline void scrollPrint(char* string, int speed) {
	if (speed < 1)
		speed = 1;
	if (speed > 10)
		speed = 10;
	int n = strlen(string);
	bool insertNewLine = false;
	int newLineCount = 0;
	for (int i = 0; i < n; i++) {
		newLineCount++;
		if (newLineCount >= 80)
			insertNewLine = true;
		if (insertNewLine && string[i] == ' ') {
			cout << "\n\t";
			insertNewLine = false;
			newLineCount = 0;
		} else {
			cout << string[i];
		}
		cout.flush();
		usleep(300); // Only works in POSIX systems but hey it'll work for us
	}
}
