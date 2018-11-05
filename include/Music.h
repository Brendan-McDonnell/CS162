/* Music.h
 * 
 * Created on 29 October 2018
 * Author: Brendan McDonnell
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#include "Media.h"
#include <iostream>
#include <cstring>

class Music : public Media {

public:
  // Constructor
  Music(char* newtitle, int newyear, char* newpublisher, char* newartist, float newduration);

  // Copy constructor
  Music(const Music& source);

  // Overloaded Assignment Operator
  Music& operator=(const Music& source);

  // Destructor
  ~Music();

  // Overloaded Insert Operator
  friend std::ostream& operator<<(std::ostream& os, const Music& music);

  // Getters
  char* getPublisher();
  char* getArtist();
  float getDuration();

  // Methods
  int getType();
  
private:
  char* publisher;
  char* artist;
  float duration;
  
};

#endif // MUSIC_H_
