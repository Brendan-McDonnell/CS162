/* VideoGame.h
 *
 * Created on 18 October 2018
 * Author: Brendan MCDonnell
 */

#ifndef VIDEO_GAME_H_
#define VIDEO_GAME_H_

#include <iostream>
#include "Media.h"

class VideoGame : public Media {
  
public:

  // Constructor
  VideoGame(char* newtitle, int newyear, char* newpublisher, float newrating);

  // Copy Constructor
  VideoGame(const VideoGame& source);

  // Overloaded Assignment Operator
  VideoGame& operator=(const VideoGame& source);

  // Destructor
  ~VideoGame();

  // Overloaded Insert Operator
  friend std::ostream& operator<<(std::ostream& os, const VideoGame& source);

  // Getters
  char* getPublisher();
  int getRating();

  // Methods
  Media::MediaType getType();
  void print();
  
private:
  char* publisher;
  float rating;
  
};

#endif
