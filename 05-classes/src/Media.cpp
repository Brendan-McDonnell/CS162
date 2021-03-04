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

// Default constructor
Media::Media() {
  title = new char(0x00);
  year = -1;
}

// Constructor
Media::Media(char* newtitle, int newyear) {
  title = new char(0);
  strcpy(title, newtitle);
  year = newyear;
}

// Copy Constructor
Media::Media(const Media& source) {
  year = source.year;
  strcpy(title, source.title); // (ptr, val)
}

// Overloaded Assignment Operator
Media& Media::operator=(const Media& source) {
  if (this == &source) return *this;
  year = source.year;
  strcpy(title, source.title); // (ptr, val)
  return *this;
}

// Destructor
Media::~Media() {
  delete[] title;
}

// Overloaded Insert Operator (friend)
// DEPRECIATED
ostream& operator<<(ostream& os, const Media& source) {
  os << "----- MEDIA -----" << endl
     << "Title: " << source.title << endl
     << "Year: " << source.year << endl
     << "-----------------" << endl;
  return os;
}

// Getters
char* Media::getTitle() { return title; }

int Media::getYear() { return year; }

char* Media::getDirector() { return nullptr; }

float Media::getDuration() { return 0; }

int Media::getRating() { return 0; }

char* Media::getArtist() { return nullptr; }


// Methods
Media::MediaType Media::getType() { return MediaType::MEDIA; }

void Media::print() {
  cout << "----- MEDIA -----" << endl
       << "Title: " << title << endl
       << "Year: " << year << endl
       << "-----------------" << endl
       << endl;
}
