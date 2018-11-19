/*
 * Item.h
 *
 *  Created on: Nov 14, 2018
 *      Author: brend
 */

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_

#include <iostream>
#include <cstring>

class Item {
public:
	// Constructors and Rule of Three
	Item();
	Item(char* newname);
	Item(char* newname, char* newdescription);
	Item(char* newname, char* newdescription, int newworth, int newquantity);
	Item(Item& source);
	Item& operator=(const Item& source);
	virtual ~Item();

	friend std::ostream& operator<<(std::ostream& os, const Item& source);

	// Getters and Setters
	char* getDescription() const {
		return description;
	}

	void setDescription(char* description) {
		strcpy(this->description, description);
	}

	char* getName() const {
		return name;
	}

	void setName(char* name) {
		strcpy(this->name, name);
	}

	int getWorth() const {
		return worth;
	}

	void setWorth(int worth) {
		this->worth = worth;
	}

	int getQuantity() const {
		return quantity;
	}

	void setQuantity(int quantity) {
		this->quantity = quantity;
	}

private:
	char* name;
	char* description;
	int worth;
	int quantity;
};

#endif /* SRC_ITEM_H_ */
