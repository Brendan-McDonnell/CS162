#include "List.h"
#include "Student.h"
#include <iostream>


List::List() {
	head = NULL;
}

List::List(Student* headData) {
	this->head = new Node(headData);
}


List::~List() {
	destroy(head);
}

void List::display() {
	print(head);
}

void List::insert(Student* value) {
	Node* node = new Node(value);
	
	if (head) {
		Node* tail = head;
		while (tail->getNext() && (tail = tail->getNext()));
		tail->setNext(node);
	}
	else {
		head = new Node(value);
	}
}

void List::insertSorted(Student* value) {
	Node* node = new Node(value);
	// Conditions for inserting at head
	if (head == NULL || value->getId() < head->getStudent()->getId()) {
		node->setNext(head);
		head = node;
	}
	else {
		Node* curr = head;
		while (curr->getNext()  && curr->getNext()->getStudent()->getId() < value->getId()) curr = curr->getNext();
		// Curr is before greater node
		node->setNext(curr->getNext());
		curr->setNext(node);
	}
}

void List::remove(int index) {
	if (index == 0) {
		Node* temp = head;
		head = head->getNext();
		delete temp;
		return;
	}
	int i = 0;
	Node* curr = head;
	while ((curr = curr->getNext()) && ++i < index - 1);
	if (i < index - 1) {
		std::cout << "OUT_OF_BOUNDS" << std::endl;
	}
	Node* temp = curr->getNext();
	curr->setNext(curr->getNext()->getNext());
	delete temp;
}

Student* List::at(int index) {
	if (index == 0) return head->getStudent();
	Node* curr = head;
	for (int i = 1; i <= index; ++i) {
		if (curr && curr->getNext()) curr = curr->getNext();
		else {
			std::cout << "OUT_OF_BOUNDS" << std::endl;
			return NULL;
		}
	}
	return curr->getStudent();
}

float List::average() {
	Node* curr = head;
	int studentCount = 0;
	float totalGpa = 0.0;
	while (curr) {
		totalGpa += curr->getStudent()->getGpa();
		++studentCount;
		curr = curr->getNext();
	}
	return totalGpa / studentCount;
}

/*
 *  The following are private functions used for recursion in public functions
 */
void List::sort() {
	// Makes a copy list and inserts them, sorted.
	// Is relatively efficient as data is stored dynamically and only pointers are tranferred
	List out;
	Node* curr = head;
	while (curr) {
		out.insertSorted(curr->getStudent());
		curr = curr->getNext();
	}
	Node* oldHead = head;
	head = out.head;
	destroy(oldHead); // Removes old list
}

void List::destroy(Node* head) {
	if (!head) return;
	if (head->getNext()) destroy(head->getNext());
	head = NULL;
	delete head;
}

void List::print(Node* head) {
	if (!head) return;
	std::cout << head->getStudent()->getFName() << " "
			  << head->getStudent()->getLName() << ", "
			  << head->getStudent()->getId() << ", "
			  << head->getStudent()->getGpa() << " -> ";
	if (head->getNext()) print(head->getNext());
	else std::cout << "NULL" << std::endl;
}