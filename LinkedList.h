#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include "node.h"

class LinkedList {

public:
	LinkedList(Node* head = NULL, Node* tail = NULL);
	LinkedList(const &LinkedList);
	virtual ~LinkedList();
	
	void insert(Node* newNode);
	void insert(Node* newNode, int targetPosition);
	void insertAfter(Node* newNode, Node* targetNode);
	void insertSorted(Node* newNode);
	
	void remove(Node* targetNode);
	void remove(int targetPosition);
	
	void sort();
	
	Node* at(int index) const;
	Node* operator[](int index);
	
private:
	Node* head;
	Node* tail;
	
}

#endif