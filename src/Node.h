/*
 * Node.h
 *
 *  Created on: Dec 5, 2018
 *      Author: brend
 */

#ifndef NODE_H_
#define NODE_H_

#include "Student.h"

// Note: No built-in deep copying as that would copy entire LinkedList
template<class T = int> // Allows for any class to be used for values
class Node {
public:
	Node();
	Node(const T& value, Node<T>* previous = nullptr, Node<T>* next = nullptr);
	virtual ~Node();

	T getValue() const;
	Node<T>* nextNode();
	Node<T>* previousNode();

	void setValue(const T& value);
	void setNext(Node* next);
	void setPrevious(Node* previous);

	void insertBefore(Node<T>* node);
	void insertAfter(Node<T>* node);
	void deleteBefore();
	void deleteAfter();

private:
	T value;
	Node* previous;
	Node* next;
};

#endif /* NODE_H_ */
