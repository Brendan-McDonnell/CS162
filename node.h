#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

#ifndef NODE_H
#define NODE_H
//node class, contains constructor, destructor, set/get next node, and get student
class Node{
 public:
  Node(Student* s);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newnext);
 private:
  Node* next;
  Student* student;
};
#endif
