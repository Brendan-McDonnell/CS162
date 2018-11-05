/*
 * Media.h
 * 
 * Created on 17 October 2018
 * Author: Brendan McDonnell
 */

#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>

class Media {
  
 public:
  // Default constructor
  Media();

  // Constructor
  Media(char* newtitle, int newyear);

  // Copy Contructor
  Media(const Media& source);

  // Overloaded Assignment
  Media& operator=(const Media& source);

  // Deconstructor
  virtual ~Media();
  
  // Overloaded insert operator
  friend std::ostream& operator<<(std::ostream& os, const Media& movie);

  // Getters
  char* getTitle();
  int getYear();

  // Methods
  virtual int getType();

 protected:
  char* title;
  int year;
  
};


#endif 
