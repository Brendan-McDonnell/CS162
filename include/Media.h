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

  friend std::ostream& operator<<(std::ostream& os, const Media& media);
  
 public:
  // Constructor
  Media(char* newtitle, int titleSize, int newyear);

  // Copy Contructor
  Media(const Media& source);

  // Overloaded Assignment
  Media& operator=(const Media& source);

  // Deconstructor
  ~Media();
  
  // Getters
  char* getTitle();
  int getTitleSize();
  int getYear();

 private:
  char* title;
  int titleSize;
  int year;
  
};


#endif 
