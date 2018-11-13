/* VideoGame.cpp
 * 
 * Created on 23 October 2018
 * Author: Brendan McDonnell
 */

#include "../include/VideoGame.h"
#include <iostream>
#include <cstring>

using namespace std;

// Constructor
VideoGame::VideoGame(char* newtitle, int newyear, char* newpublisher, float newrating) {
  title = newtitle;
  year = newyear;
  publisher = newpublisher;
  rating = newrating;
}

// Copy Constructor
VideoGame::VideoGame(const VideoGame& source) {
  strcpy(title, source.title);
  strcpy(publisher, source.publisher);
  year = source.year;
  rating = source.rating;
}

// Overloaded Assignment Operator
VideoGame& VideoGame::operator=(const VideoGame& source) {
  if (this == &source) return *this;
  strcpy(title, source.title);
  strcpy(publisher, source.publisher);
  year = source.year;
  rating = source.rating;
  return *this;
}

// Destructor
VideoGame::~VideoGame() {
  delete[] title;
  delete[] publisher;
}

// Overloaded Insert Operator
ostream& operator<<(ostream& os, const VideoGame& source) {
  os << "----- VIDEOGAME -----" << endl
     << "Title: " << source.title << endl
     << "Year: " << source.year << endl
     << "Publisher: " << source.publisher << endl
     << "Rating: " << source.rating << endl
     << "---------------------" << endl
     << endl;
  return os;
}

// Getters
char* VideoGame::getPublisher() {
  return publisher;
}

int VideoGame::getRating() {
  return rating;
}

// Methods
Media::MediaType VideoGame::getType() { return MediaType::VIDEO_GAME; }

void VideoGame::print() {
  cout << "----- VIDEOGAME -----" << endl
     << "Title: " << title << endl
     << "Year: " << year << endl
     << "Publisher: " << publisher << endl
     << "Rating: " << rating << endl
     << "---------------------" << endl
     << endl;
}
