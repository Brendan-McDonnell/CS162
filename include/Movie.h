/* Movie.h
 * 
 * Created on 31 October 2018
 * Author: Brendan McDonnell
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <iostream>
#include "Media.h"

class Movie : public Media {

 public:
  // Constructor
  Movie(char* newtitle, int newyear, char* newdirector, float newduration, int newrating);

  // Copy Constructor
  Movie(const Movie& source);

  // Overlaoded Assignment Operator
  Movie& operator=(const Movie& source);

  // Deconstructor
  ~Movie();
  
  // Overloaded insert operator
  friend std::ostream& operator<<(std::ostream& os, const Movie& source);
  
  // Getters
  char* getDirector();
  float getDuration();
  int getRating();

  // Methods
  Media::MediaType getType();
  void print();
  
 private:
  char* director;
  float duration;
  int rating;
  
};

#endif // MOVIE_H_
