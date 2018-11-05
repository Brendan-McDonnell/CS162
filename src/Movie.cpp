/* Movie.cpp
 * 
 * Created on 1 November 2018
 * Author: Brendan McDonnell
 */

#include "../include/Movie.h"
#include <iostream>
#include <cstring>

using namespace std;

// Constructor
Movie::Movie(char* newtitle, int newyear, char* newdirector, float newduration, int newrating) {
  title = newtitle;
  year = newyear;
  director = newdirector;
  duration = newduration;
  rating = newrating;
}

// Copy Constructor
Movie::Movie(const Movie& source) {
  strcpy(title, source.title);
  strcpy(director, source.director);
  year = source.year;
  duration = source.duration;
  rating = source.rating;
}

// Overloaded Assignment Operator
Movie& Movie::operator=(const Movie& source) {
  if (this == &source) return *this;
  strcpy(title, source.title);
  strcpy(director, source.director);
  year = source.year;
  rating = source.rating;
  return *this;
}

// Deconstructor
Movie::~Movie() {
  delete[] title;
  delete[] director;
}

// Overloaded insert operator
ostream& operator<<(ostream& os, const Movie& source) {
  os << "----- MOVIE -----" << endl
     << "Title: " << source.title << endl
     << "Year: " << source.year << endl
     << "Director: " << source.director << endl
     << "Duration: " << source.duration << endl
     << "Rating: " << source.rating << endl
     << "-----------------" << endl;
  return os;
}

// Getters
char* Movie::getDirector() {
  return director;
}

float Movie::getDuration() {
  return duration;
}

int Movie::getRating() {
  return rating;
}

// Methods
int Movie::getType() {
  return 3;
}
