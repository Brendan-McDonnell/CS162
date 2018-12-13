/*
 * Node.h
 *
 *  Created on: Dec 5, 2018
 *      Author: brend
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include "Student.h"

/*
 * Contains three pointers: a stored value, the next node, and the previous node.
 * If there is no attached previous/next node, it defaults to nullptr
 */

// Note: No built-in deep copying as that would copy entire LinkedList
class Node {
public:
	Node(Student* value = nullptr, Node* previous = nullptr, Node* next = nullptr);
	virtual ~Node(); // Destructs value and links the previous and next node together

	Student* getValue() const; // Gets value at node
	Node* nextNode() const; // Gets next node
	Node* previousNode() const; // Gets previous node

	void setValue(Student* value); // Sets new value and deletes old value
	void setNext(Node* next); // Sets new next node
	void setPrevious(Node* previous); // Sets new previous node

	void insertBefore(Node* node); // Inserts this pefore node
	void insertAfter(Node* node); // Inserts this after node

private:
	Student* value;
	Node* previous;
	Node* next;
};

#endif /* NODE_H_ */
