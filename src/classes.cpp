#include <iostream>
#include <vector>
#include <cstring>
#include "../include/Media.h"
#include "../include/VideoGame.h"
#include "../include/Music.h"
#include "../include/Movie.h"

using namespace std;

// Prototypes
char* getInput();
void getInput(int&);
void getInput(char&);
void getInput(float&);
void addMedia(vector<Media*>*);

// Global constants

// Functions

int main() {
  vector<Media*>* data = new vector<Media*>();

  for(;;) { // Command loop
    /* COMMANDS:
       HELP: Outputs all commands and their descriptions.
       ADD: Add a chosen form of media with populated fields.
       SEARCH: Prints all media that have an inputted title or year.
       DELETE: Deletes all media that match an inputted title or year (with confirmation).
       QUIT: Exits the program.
    */

    cout << "Please input a command. Use HELP for more information." << endl;
    char* commandInput = getInput();
    for(unsigned int i = 0; i < strlen(commandInput); i++)
      commandInput[i] = toupper(commandInput[i]); // Make uppercase
    if (!strcmp(commandInput, "HELP")) {
      cout << "------ HELP ------" << endl
	   << "COMMANDS:" << endl
	   << "HELP: Outputs all commands and their descriptions." << endl
	   << "ADD: Add a chosen form of media with populated fields." << endl
	   << "SEARCH: Prints all media that have an inputted title or year." << endl
	   << "DELETE: Deletes all media that match an inputted title or year." << endl
	   << "QUIT: Exits the program." << endl
	   << "------------------" << endl;
    }
    else if (!strcmp(commandInput, "ADD")) addMedia(data);
    else if (!strcmp(commandInput, "SEARCH")) {
      
    }
    else if (!strcmp(commandInput, "DELETE")) {
      
    }
    else if (!strcmp(commandInput, "QUIT")) {
      
    }
    else cout << "Command not recognized. Please try again." << endl;
    cout << endl; // Spacing after each command handle or error
  }

  // Garbage collection
  for (vector<Media*>::iterator it = data->begin();
       it != data->end();
       it++) {
    delete *it; // Remove all stored elements from heap
  }
  delete[] data; // Remove data structure itself
  
}

char* getInput() {
  char delim = '\n';
  int n = 1;
  char* arr = new char[n];
  
  do {
    arr[n - 1] = cin.get();
    char* temp = new char[n + 1];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    delete arr;
    arr = temp;
  } while (arr[n++ - 1] != delim);
  
  return arr;
}

void getInput(int& a) {}

void getInput(char& a) {}

void getInput(float& a) {}

void addMedia(vector<Media*>* data) {
  cout << "------ ADD -------" << endl;

 BEGIN_ADD:
  cout << "Please enter a type by number:" << endl
       << "0: Media" << endl
       << "1: Video Game" << endl
       << "2: Music" << endl
       << "3: Movie" << endl;
  // Get input as an integer
  // This is done in this manner for input validation and bug handling
  int* intInput = new int(-1);
  getInput(*intInput);
  int input = *intInput;
  delete intInput;
  if (input < 0 || input > 3) {
    cout << "Invalid media type. Please try again." << endl;
    goto BEGIN_ADD;
  }

  // Get fields and add new Media to data vector
  switch (input) {
  case 0:
    { // Add new scope to the stack to isolate variable names to be repeated in other cases
      // Media
      char* newtitle = 0x00; int newyear = -1;
      cout << "Title of media:" << endl;
      getInput(*newtitle); // Address of the dereferenced newtitle
      cout << "Year released:" << endl;
      getInput(newyear); // Simple pass by reference
      data->push_back(new Media(newtitle, newyear));
    }
    break;
  case 1:
    // VideoGame
    {
      char* newtitle = 0x00; int newyear = -1; char* newpublisher = 0x00; int newrating = -1;
      cout << "Title of media:" << endl;
      getInput(*newtitle);
      cout << "Year released:" << endl;
      getInput(newyear);
      cout << "Publisher of video game:" << endl;
      getInput(*newpublisher);
      cout << "Rating of video game:" << endl;
      getInput(newrating);
      data->push_back(new VideoGame(newtitle, newyear, newpublisher, newrating));
    }
    break;
  case 2:
    // Music
    {
      char* newtitle = 0x00; int newyear = -1; char* newpublisher = 0x00; char* newartist = 0x00; float newduration = -1;
      cout << "Title of music:" << endl;
      getInput(*newtitle);
      cout << "Year released:" << endl;
      getInput(newyear);
      cout << "Publisher of music:" << endl;
      getInput(*newpublisher);
      cout << "Artist of music:" << endl;
      getInput(*newartist);
      cout << "Duration of music:" << endl;
      getInput(newduration);
      data->push_back(new Music(newtitle, newyear, newpublisher, newartist, newduration));
    }
    break;
  case 3:
    // Movie
    {
      char* newtitle = 0x00; int newyear = -1; char* newdirector = 0x00; float newduration = -1.0; int newrating = -1;
      cout << "Title of movie:" << endl;
      getInput(*newtitle);
      cout << "Year released:" << endl;
      getInput(newyear);
      cout << "Director of movie:" << endl;
      getInput(*newtitle);
      cout << "Duration of movie:" << endl;
      getInput(newduration);
      cout << "Rating of movie:" << endl;
      getInput(newrating);
      data->push_back(new Movie(newtitle, newyear, newdirector, newduration, newrating));
    }
    break;
  default:
    cout << "An unknown error occured with handling your input. Exiting 'ADD' command." << endl;
    cout << "----------------" << endl;
    return;
  }

  cout << "'" << data->back()->getTitle() <<"' was added." << endl;
  cout << "------------------" << endl;

}
