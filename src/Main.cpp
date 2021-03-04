/*
 * Main.cpp
 *
 *  Created on: Dec 6, 2018
 *      Author: brend
 */
#include <iostream>
#include "Node.h"

void printStudent(Student*);
void printNode(Node*);
void printList(Node*);

int main() {
	std::cout << "PROOF OF CONCEPT CODE" << std::endl << std::endl;

	std::cout << "*****" << std::endl;
	Student* s1 = new Student((char*) "Student 1");
	Student* s2 = new Student((char*) "Student 2");
	Student* s3 = new Student((char*) "Student 3");
	Student* s4 = new Student((char*) "Student 4");
	Student* s5 = new Student((char*) "Student 5");

	std::cout << "The following Students have been created:" << std::endl;
	printStudent(s1);
	printStudent(s2);
	printStudent(s3);
	printStudent(s4);
	printStudent(s5);
	std::cout << std::endl;
	std::cout << "*****" << std::endl;

	std::cout << std::endl << "*****" << std::endl;

	Node* n1 = new Node(s1);
	Node* n2 = new Node(s2, n1);
	Node* n3 = new Node(s3);
	Node* n4 = new Node(s4);

	std::cout << "The following Nodes have been created:" << std::endl;
	printNode(n1);
	printNode(n2);
	printNode(n3);
	std::cout << "*****" << std::endl;

	std::cout << std::endl << "*****" << std::endl;

	n2->setNext(n3);

	std::cout << "Linked the second and third nodes:" << std::endl;
	printNode(n1);
	printNode(n2);
	printNode(n3);
	std::cout << "*****" << std::endl;

	std::cout << std::endl << "*****" << std::endl;
	n4->insertBefore(n3);

	std::cout << "Inserted a new node between the second and third nodes:"
			<< std::endl;
	printNode(n1);
	printNode(n2);
	printNode(n3);
	printNode(n4);
	std::cout << "*****" << std::endl;

	std::cout << std::endl << "*****" << std::endl;
	n2->setValue(s5);
	std::cout << "Changed the second node's student:" << std::endl;
	printNode(n1);
	printNode(n2);
	printNode(n3);
	printNode(n4);
	std::cout << "*****" << std::endl;

	std::cout << std::endl << "*****" << std::endl;
	delete n4;
	std::cout << "Deleted the third node:" << std::endl;
	printNode(n1);
	printNode(n2);
	printNode(n3);
	printNode(n4);
	std::cout << "*****" << std::endl;

	std::cout << std::endl << "*****" << std::endl;
	std::cout << "Example of recursion with nodes:" << std::endl;
	printList(n1);
	std::cout << "*****" << std::endl;

	delete n1;
	delete n2;
	delete n3;

	return 0;
}

void printStudent(Student* s) {
	if (s)
		std::cout << s->getFirstName() << ' ' << s->getLastName();
	else
		std::cout << "NULL";
}

void printNode(Node* n) {
	std::cout << "Value: ";
	printStudent(n->getValue());
	std::cout << "\tPrevious: ";
	if (n->previousNode())
		printStudent(n->previousNode()->getValue());
	else
		std::cout << "NULL ";
	std::cout << "     Next: ";
	if (n->nextNode())
		printStudent(n->nextNode()->getValue());
	else
		std::cout << "NULL ";
	std::cout << std::endl;
}

void printList(Node* n) {
	while (n->nextNode()) {
		if (n->getValue()->getFirstName()) {
			std::cout << n->getValue()->getFirstName() << " --> ";
			return printList(n->nextNode());
		}
	}
	if (!n->nextNode()) {
		if (n->getValue())
			std::cout << n->getValue()->getFirstName() << std::endl;
		else
			std::cout << "NULL" << std::endl;
	}
}
