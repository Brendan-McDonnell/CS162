#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#include "../include/Media.h"
#include "../include/VideoGame.h"
#include "../include/Music.h"
#include "../include/Movie.h"

using namespace std;

// Prototypes
char* getInput();
bool getInput(int&);
bool getInput(char&);
bool getInput(float&);
int cstringToInt(char*);
Media* addMedia();
vector<Media*> searchMedia(vector<Media*>, char*);
vector<Media*> searchMedia(vector<Media*>, int);
vector<Media*> searchMedia(vector<Media*>, char*, int, bool);

// Global constants

// Functions

int main() {
  vector<Media*> data;

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
      cout << "******* HELP ******" << endl
	   << "COMMANDS:" << endl
	   << "HELP: Outputs all commands and their descriptions." << endl
	   << "ADD: Add a chosen form of media with populated fields." << endl
	   << "SEARCH: Prints all media that have an inputted title or year." << endl
	   << "DELETE: Deletes all media that match an inputted title or year." << endl
	   << "QUIT: Exits the program." << endl
	   << "******************" << endl;
    }
    else if (!strcmp(commandInput, "ADD")) {
      cout << endl;
      cout << "****** ADD ******" << endl;
      data.push_back(addMedia());
      cout << "*****************" << endl;
    }
    else if (!strcmp(commandInput, "SEARCH")) {
      cout << endl;
      cout << "******* SEARCH *******" << endl;
      vector<Media*> foundMedia;
      cout << "Would you like to search via the title of the media or the year the media was released?" << endl;
      cout << "0: Title" << endl;
      cout << "1: Year" << endl;
      int intInput = -1;
      while (!getInput(intInput)) cout << "Invalid input. Please try again." << endl;

      if (!intInput) { // Title
	cout << "What is the title you would like to search for?" << endl;
	foundMedia = searchMedia(data, getInput());
      } else { // Year
	cout << "What is the year you would like to search for?" << endl;
	while(!getInput(intInput)) cout << "Invalid input. Please try again.";
	foundMedia = searchMedia(data, intInput);
      }

      if (foundMedia.size() > 0)
	cout << foundMedia.size() << " media found:" << endl;
      else cout << "No media found." << endl;
      for (vector<Media*>::iterator it = foundMedia.begin();
	   it != foundMedia.end();
	   it++)
	(*it)->print();
      cout << "**********************" << endl;
    }
    else if (!strcmp(commandInput, "DELETE")) {
      cout << endl;
      cout << "******* DELETE *******" << endl;
      vector<Media*> foundMedia;
      cout << "What would you like to use to search for the media to delete?" << endl;
      cout << "0: Title" << endl;
      cout << "1: Year" << endl;
      int intInput = -1;
      while (!getInput(intInput)) cout << "Invalid input. Please try again." << endl;

      if (!intInput) { // Title
	cout << "What is the title of the media you would like to delete?" << endl;
	foundMedia = searchMedia(data, getInput());
      } else { // Year
	cout << "What is the year of the media you would like to delete?" << endl;
	getInput(intInput);
	foundMedia = searchMedia(data, intInput);
      }

      if (foundMedia.size() > 0)
	cout << "Deleting " << foundMedia.size() << " media..." << endl;
      else cout << "No media found." << endl;
      for (vector<Media*>::iterator it = foundMedia.begin();
	   it != foundMedia.end();
	   it++)
	delete *it; // Calls destructor of media objects
      cout << "Media deleted." << endl;
      cout << "**********************" << endl;
    }
    else if (!strcmp(commandInput, "QUIT")) {
      for (vector<Media*>::iterator it = data.begin();
	   it != data.end();
	   it++)
	delete *it;
      return 0;
    }
    else cout << "Command not recognized. Please try again." << endl;
    cout << endl; // Spacing after each command handle or error
  }

  // This code should never be run, but if it is garbage is collected before exit
  for (vector<Media*>::iterator it = data.begin();
       it != data.end();
       it++) {
    delete *it; // Remove all stored elements from heap
  }
  return 1;
}

char* getInput() {
  vector<char> vec;
  char in;
  while ((in = cin.get()) != '\n')
    vec.push_back(in);
  vec.push_back(0);

  char* out = new char[vec.size()];
  copy(vec.begin(), vec.begin() + vec.size(), out);
  return out;
}

bool getInput(int& a) {
  char* arr = getInput();
  a = 0;
  for (unsigned int i = 0; i < strlen(arr) - 1; i++) {
    if (arr[i] < '0' || arr[i] > '9') return false;
  }
  a = cstringToInt(arr);
  delete[] arr;
  return true;
}

bool getInput(char*& a) {
  a = getInput();
  return true;
}

bool getInput(float& a) {
  a = 0.0;
  char* arr = getInput();
  int n = strlen(arr);
  
  for (int i = 0; i < n; i++) {
    if (!(arr[i] >= '0' && arr[i] <= '9') && arr[i] != '.') return false;
  }

  int periodPosition = -1;
  for (int i = 0; i < n; i++) if (arr[i] == '.') periodPosition = i;
  char* intComponent = new char[periodPosition + 1]; // -1 for size, +1 for next after period
  char* decComponent = new char[n - 1 - periodPosition];
  memcpy(intComponent, arr, periodPosition);
  intComponent[periodPosition] = 0;
  memcpy(decComponent, arr + periodPosition + 1, n - 1 - periodPosition);

  a += cstringToInt(intComponent);
  a += float(cstringToInt(decComponent)) / float(pow(10, strlen(decComponent)));
  
  delete[] arr;
  delete[] intComponent;
  delete[] decComponent;
  return a;
}

int cstringToInt(char* arr) {
  int a = 0;
  int n = strlen(arr);
  for (int i = n - 1; i >= 0; i--) {
    a += (arr[i] - '0') * pow(10, n - (i + 1));
  }
  return a;
}

Media* addMedia() {
  Media* newMedia = nullptr;
  
 BEGIN_ADD:
  cout << "Please enter a type by number:" << endl
       << "0: Media" << endl
       << "1: Video Game" << endl
       << "2: Music" << endl
       << "3: Movie" << endl;
  // Get input as an integer
  // This is done in this manner for input validation and bug handling
  int input;
  while(!getInput(input)) cout << "Invalid input. Please try again." << endl;
  if (input < 0 || input > 3) {
    cout << "Invalid input. Please try again." << endl;
    goto BEGIN_ADD;
  }

  // Get fields and add new Media to data vector
  switch (input) {
  case 0:
    { // Add new scope to the stack to isolate variable names to be repeated in other cases
      // Media
      char* newtitle; int newyear = -1;
      cout << "Title of media:" << endl;
      getInput(newtitle); // Address of the dereferenced newtitle
      cout << "Year released:" << endl;
      while (!getInput(newyear)) cout << "Invalid input. Please try again." << endl; // Simple pass by reference
      newMedia = new Media(newtitle, newyear);
    }
    break;
  case 1:
    // VideoGame
    {
      char* newtitle = 0x00; int newyear = -1; char* newpublisher = 0x00; int newrating = -1;
      cout << "Title of video game:" << endl;
      getInput(newtitle);
      cout << "Year released:" << endl;
      while (!getInput(newyear)) cout << "Invalid input. Pease try again." << endl;
      cout << "Publisher of video game:" << endl;
      getInput(newpublisher);
      cout << "Rating of video game:" << endl;
      while (!getInput(newrating)) cout << "Invalid input. Please try again." << endl;
      newMedia = new VideoGame(newtitle, newyear, newpublisher, newrating);
    }
    break;
  case 2:
    // Music
    {
      char* newtitle = 0x00; int newyear = -1; char* newpublisher = 0x00; char* newartist = 0x00; float newduration = -1;
      cout << "Title of music:" << endl;
      getInput(newtitle);
      cout << "Year released:" << endl;
      while(!getInput(newyear)) cout << "Invalid input. Please try again." << endl;
      cout << "Publisher of music:" << endl;
      getInput(newpublisher);
      cout << "Artist of music:" << endl;
      getInput(newartist);
      cout << "Duration of music:" << endl;
      while(!getInput(newduration)) cout << "Invalid input. Please try again." << endl;
      newMedia = new Music(newtitle, newyear, newpublisher, newartist, newduration);
    }
    break;
  case 3:
    // Movie
    {
      char* newtitle = 0x00; int newyear = -1; char* newdirector = 0x00; float newduration = -1.0; int newrating = -1;
      cout << "Title of movie:" << endl;
      getInput(newtitle);
      cout << "Year released:" << endl;
      while(!getInput(newyear)) cout << "Invalid input. Please try again." << endl;
      cout << "Director of movie:" << endl;
      getInput(newdirector);
      cout << "Duration of movie:" << endl;
      while(!getInput(newduration)) cout << "Invalid input. Please try again." << endl;
      cout << "Rating of movie:" << endl;
      while(!getInput(newrating)) cout << "Invalid input. Please try again." << endl;
      newMedia = new Movie(newtitle, newyear, newdirector, newduration, newrating);
    }
    break;
  default:
    cout << "An unknown error occured with handling your input. Exiting 'ADD' command." << endl;
    return nullptr;
  }

  cout << "Media '" << newMedia->getTitle() <<"' was successfully created." << endl;
  return newMedia;
}



vector<Media*> searchMedia(vector<Media*> data, char* title) {
  return searchMedia(data, title, 0, false);
}

vector<Media*> searchMedia(vector<Media*> data, int year) {
  return searchMedia(data, nullptr, year, true);
}

vector<Media*> searchMedia(vector<Media*> data, char* title, int year, bool searchByYear) {
  vector<Media*> found;
  
  for (vector<Media*>::iterator it = data.begin();
       it != data.end();
       it++) {
    if (!searchByYear) { // title
      if (!strcmp((*it)->getTitle(), title)) {
	found.push_back(*it);
      }
    } else // year
      if ((*it)->getYear() == year)
	found.push_back(*it);
  }
  
  return found;
}
