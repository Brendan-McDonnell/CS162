/* Music.cpp
 * 
 * Created on 29 October 2018
 * Author: Brendan McDonnell
 */

#include "../include/Music.h"
#include <iostream>
#include <cstring>

using namespace std;

// Constructor
Music::Music(char* newtitle, int newyear, char* newpublisher, char* newartist, float newduration) {
  strcpy(title, newtitle);
  delete[] newtitle;

  publisher = new char(0);
  strcpy(publisher, newpublisher);
  delete[] newpublisher;

  artist = new char(0);
  strcpy(artist, newartist);
  delete[] newartist;  

  year = newyear;
  duration = newduration;
}

// Copy Constructor
Music::Music(const Music& source) {
  publisher = new char(0);
  artist = new char(0);
  strcpy(title, source.title);
  strcpy(publisher, source.publisher);
  strcpy(artist, source.artist);
  year = source.year;
  duration = source.duration;
}

// Overloaded Assignment Operator
Music& Music::operator=(const Music& source) {
  if (this == &source) return *this;
  strcpy(title, source.title);
  strcpy(publisher, source.publisher);
  strcpy(artist, source.artist);
  year = source.year;
  duration = source.duration;
  return *this;
}

// Destructor
Music::~Music() {
  delete[] title;
  delete[] publisher;
  delete[] artist;
}

// Overloaded Insert Operator
ostream& operator<<(ostream& os, const Music& source) {
  os << "----- MUSIC -----" << endl
     << "Title: " << source.title << endl
     << "Year: " << source.year << endl
     << "Publisher: " << source.publisher << endl
     << "Artist: " << source.artist << endl
     << "Duration: " << source.duration << endl
     << "----------------" << endl
     << endl;
  return os;
}

// Getters
char* Music::getPublisher() {
  return publisher;
}

char* Music::getArtist() {
  return artist;
}

float Music::getDuration() {
  return duration;
}

// Methods
Media::MediaType Music::getType() { return MediaType::MUSIC; }

void Music::print() {
  cout << "----- MUSIC -----" << endl
     << "Title: " << title << endl
     << "Year: " << year << endl
     << "Publisher: " << publisher << endl
     << "Artist: " << artist << endl
     << "Duration: " << duration << endl
     << "----------------" << endl
     << endl;
}
