/*
 * LinkedList.h
 *
 *  Created on: Dec 8, 2018
 *      Author: brend
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

template<class T>
class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();

	void push_front(T);
	void push_back(T);
	void insert(T, int);
	T at(int) const;
	int length() const;
	void swap(int, int);
};

#endif /* SRC_LINKEDLIST_H_ */
