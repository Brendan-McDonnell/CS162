#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include "node.h"

class LinkedList {

public:
	LinkedList(Node* head = NULL, Node* tail = NULL);
	
	
private:
	Node* head;
	Node* tail;
	
}

#endif