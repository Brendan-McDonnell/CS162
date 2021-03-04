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
	Item(const Item& source);
	Item& operator=(const Item& source);
	virtual ~Item();

	friend std::ostream& operator<<(std::ostream& os, const Item& source);

	void incrementQuantity();
	void decrementQuantity();
	void incrementQuantity(int amount);

	// Getters and Setters
	char* getDescription() const;
	void setDescription(char* description);
	char* getName() const;
	void setName(char* name);
	int getWorth() const;
	void setWorth(int worth);
	int getQuantity() const;
	void setQuantity(int quantity);

private:
	char* name;
	char* description;
	int worth;
	int quantity;
};

#endif /* SRC_ITEM_H_ */
