/*
 * Media.h
 * 
 * Created on 17 October 2018
 * Author: Brendan McDonnell
 */

#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>

/*
 * Media is treated as a interface for dynamic polymorphism
 */
class Media {
  
 public:
  // Contains all derived classes for getType() functionality
  enum class MediaType { MEDIA, VIDEO_GAME, MUSIC, MOVIE };
  
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
  friend std::ostream& operator<<(std::ostream& os, const Media& media);

  // Getters
  virtual char* getTitle();
  virtual int getYear();
  virtual char* getDirector();
  virtual float getDuration();
  virtual int getRating();
  virtual char* getArtist();

  // Methods
  virtual Media::MediaType getType();
  virtual void print();

 protected:
  char* title;
  int year;
  
};


#endif 
