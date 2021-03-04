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

Inventory::Inventory(const Inventory& source) : items(source.items.size()) { // Initialize items for more efficient member copying
	gold = source.gold;
	for (size_t i = 0; i < source.items.size(); i++) {
		items[i] = new Item(*source.items[i]);
	}
}

Inventory& Inventory::operator=(const Inventory& source) {
	if (this == &source) return *this;
	gold = source.gold;
	for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
		delete *it;
	}
	items.clear();
	for (size_t i = 0; i < source.items.size(); i++) {
		items[i] = new Item(*source.items[i]); // Copy constructor functionality
	}
	return *this;
}

Inventory::Inventory(Item* item) {
	gold = 0;
	items.push_back(item);
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

int Inventory::count() {
	return items.size();
}

void Inventory::removeGold(int amount) {
	gold -= amount;
}

void Inventory::addGold(int amount) {
	gold += amount;
}

void Inventory::addItem(Item* item) {
	// Up quantity if already have one, add new version otherwise
	for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
		if (*(*it)->getName() == *item->getName()) {
			(*it)->incrementQuantity();
			return;
		}
	}
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

// Getters and Setters
int Inventory::getGold() const {
	return gold;
}

void Inventory::setGold(int gold) {
	this->gold = gold;
}

const std::vector<Item*>& Inventory::getItems() const {
	return items;
}

void Inventory::setItems(const std::vector<Item*>& items) {
	this->items = items;
}

bool Inventory::contains(char* name) {
	for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
		if (!strcmp(name, (*it)->getName())) return true;
	}
	return false;
}

Item* Inventory::takeItem(char* name) {
	for (vector<Item*>::iterator it = items.begin(); it!= items.end(); it++) {
		if (!strcmp(name, (*it)->getName())) {
			Item* out = *it;
			items.erase(it);
			return out;
		}
	}
	return NULL;
}
