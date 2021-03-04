#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Student.h"
#include "Node.h"
class List {
public:
	List();
	List(Student*);
	~List();

	void display();

	void insert(Student*);
	void insertSorted(Student*);
	void remove(int);
	void sort();
	Student* at(int);
	float average();
private:
	void destroy(Node* head);
	void print(Node* head);

	Node* head;
};

#endif