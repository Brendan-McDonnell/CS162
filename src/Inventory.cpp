/*
 * Inventory.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: brend
 */

#include "Inventory.h"

#include <iostream>
#include <vector>

using namespace std;

Inventory::Inventory() {
	gold = 0;
}

Inventory::Inventory(Inventory& source) : items(source.items.size()) {
	gold = source.gold;
	for (size_t i = 0; i < source.items.size(); i++) {
		items[i] = new Item(*source.items[i]);
	}
}

Inventory& Inventory::operator=(const Inventory& source) : items(source.items.size()) {
	if (*this == source) return this;
	gold = source.gold;
	for (size_t i = 0; i < source.items.size(); i++) {
		items[i] = new Item(*source.items[i]);
	}
	return *this;
}

Inventory::Inventory(int newgold) {
	gold = newgold;
}

Inventory::Inventory(vector<Item*> newitems) {
	items = newitems;
	gold = 0;
}

Inventory::Inventory(vector<Item*> newitems, int newgold) {
	items = newitems;
	gold = newgold;
}

Inventory::~Inventory() {
	for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
		delete *it;
}

void Inventory::removeGold(int amount) {
	gold -= amount;
}

void Inventory::addGold(int amount) {
	gold += amount;
}

void Inventory::addItem(Item* item) {
	items.push_back(item);
}

void Inventory::removeItem(char* name) {
	for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
		if (*(*it)->getName() == *name) {
			delete *it;
			delete name;
			items.erase(it);
		}
	}
}

void Inventory::removeItem(Item* item) {
	for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
		if (*it == item) {
			delete *it;
			delete item;
			items.erase(it);
		}
	}
}

void Inventory::clearItems() {
	vector<Item*>::iterator it = items.begin();
	while (items.size() != 0) {
		delete *it;
		it = items.erase(it); // Returns iterator pointer to next element
	}
}
