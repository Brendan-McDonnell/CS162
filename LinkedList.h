#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include "node.h"

class LinkedList {

public:
	LinkedList();
	LinkedList(Node* head = NULL);
	//LinkedList(const &LinkedList);
	virtual ~LinkedList();

	void insert(Node* newNode) {
		tail->setNext(newNode);
		tail = newNode;
	}
	//void insert(Node* newNode, int targetPosition);
	
	void remove(Node* targetNode);
	//void remove(int targetPosition);
	
	void sort() {
		
	}
	void printAll() {
		
	}
	
	Node* at(int index) const {
		
	}
	//Node* operator[](int index);
	
	Node* getHead() const { return head; }
	//Node* getTail() const { return tail; }
	
private:
	Node* head;
	Node* tail;
	
}

#endif