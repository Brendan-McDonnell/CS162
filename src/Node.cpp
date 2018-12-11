/*
 * Node.cpp
 *
 *  Created on: Dec 5, 2018
 *      Author: brend
 */

#include <iostream>
#include "Node.h"

template<class T>
Node<T>::Node() : value(NULL) {
	previous = nullptr;
	next = nullptr;
}

template<class T>
Node<T>::Node(const T& value, Node<T>* previous, Node<T>* next) {
	this->value = value;
	this->previous = previous;
	this->next = next;
}

template<class T>
Node<T>::~Node() {
	if (next) next->previous = previous;
	if (previous) previous->next = next;
	// Assumes T destruction is handled correctly
}

template<class T>
T Node<T>::getValue() const {
	return value;
}

template<class T>
Node<T>* Node<T>::nextNode() {
	return next;
}

template<class T>
Node<T>* Node<T>::previousNode() {
	return previous;
}

template<class T>
void Node<T>::setValue(const T& value) {
	this->value = value;
}

template<class T>
void Node<T>::setNext(Node* next) {
	this->next = next;
}

template<class T>
void Node<T>::setPrevious(Node* previous) {
	this->previous = previous;
}

template<class T>
void Node<T>::insertBefore(Node<T>* node) {
	if (!node) return;
	this->previous = node->previousNode();
	this->next = node;
	node->setPrevious(this);
}

template<class T>
void Node<T>::insertAfter(Node<T>* node) {
	if (!node) return;
	this->next = node->nextNode();
	this->previous = node;
	node->setNext(this);
}

template<class T>
void Node<T>::deleteBefore() {
	delete previous; // Should rebuild connections
}

template<class T>
void Node<T>::deleteAfter() {
	delete next; // Shoulf rebuild connections
}
