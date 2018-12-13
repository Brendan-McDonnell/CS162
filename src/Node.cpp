/*
 * Node.cpp
 *
 *  Created on: Dec 5, 2018
 *      Author: brend
 */

#include <iostream>
#include "Node.h"

Node::Node(Student* value, Node* previous, Node* next) {
	this->value = value;
	this->previous = previous;
	this->next = next;
}

Node::~Node() {
	if (value) {
		delete value;
		value = nullptr;
	}
	if (previous) previous->setNext(next);
	if (next) next->setPrevious(previous);
}

Student* Node::getValue() const {
	return value;
}

Node* Node::nextNode() const {
	return next;
}

Node* Node::previousNode() const {
	return previous;
}

void Node::setValue(Student* value) {
	delete this->value;
	this->value = nullptr;
	this->value = value;
}

void Node::setNext(Node* next) {
	this->next = next;
}

void Node::setPrevious(Node* previous) {
	this->previous = previous;
}

void Node::insertBefore(Node* node) {
	next = node;
	previous = node->previousNode();
	if(previous) previous->setNext(this);
	node->setPrevious(this);
}

void Node::insertAfter(Node* node) {
	previous = node;
	next = node->nextNode();
	if (next) next->setPrevious(this);
	node->setNext(this);
}
