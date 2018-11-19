/*
 * Inventory.h
 *
 *  Created on: Nov 14, 2018
 *      Author: brend
 */

#ifndef SRC_INVENTORY_H_
#define SRC_INVENTORY_H_

#include <iostream>
#include <vector>
#include <cstring>
#include "Item.h"

class Inventory {
public:
	Inventory();
	Inventory(int gold);
	Inventory(std::vector<Item*> newitems);
	Inventory(std::vector<Item*> newitems, int newgold);
	Inventory(Inventory& source);
	Inventory& operator=(const Inventory& source);
	virtual ~Inventory();

	void removeGold(int amount);
	void addGold(int amount);
	void addItem(Item* item);
	void removeItem(char* name);
	void removeItem(Item* item);
	void clearItems();

	int getGold() const {
		return gold;
	}

	void setGold(int gold) {
		this->gold = gold;
	}

	const std::vector<Item*>& getItems() const {
		return items;
	}

	void setItems(const std::vector<Item*>& items) {
		this->items = items;
	}

private:
	std::vector<Item*> items;
	int gold;
};

#endif /* SRC_INVENTORY_H_ */
