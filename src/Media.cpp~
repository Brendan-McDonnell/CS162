/*
 * Media.cpp
 * 
 * Created on 17 October 2018
 * Author: Brendan McDonnell
 */

#include "../include/Media.h"
#include <iostream>
#include <cstring>

using namespace std;

// Constructor
Media::Media(char* newtitle, int titleSize, int newyear) {
  title = newtitle;
  year = newyear;
}

// Copy Constructor
Media::Media(const Media& source) {
  year = source.year;
  title = new char;
  strcpy(title, source.title); // (ptr, val)
}

// Overloaded Assignment Operator
Media& Media::operator=(const Media& source) {
  year = source.year;
  strcpy(title, source.title); // (ptr, val)
}

// Destructor
Media::~Media() {
  delete[] title;
}

// Overloaded Insert Operator (friend)
ostream& operator<<(ostream& os, const Media& media) {
  os << "----- MEDIA -----" << endl
     << "Title: " << media.title << endl
     << "Year: " << media.year << endl
     << "-----------------" << endl;
  return os;
}

// Getters
char* Media::getTitle() { return title; }

int Media::getTitleSize() { return titleSize; }

int Media::getYear() { return year; }
