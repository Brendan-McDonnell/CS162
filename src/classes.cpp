#include <iostream>
#include <vector>
#include <cstring>
#include "../include/Media.h"

using namespace std;

// Prototypes
char* getInput();

// Global constants

// Functions

int main() {
  vector<Media*>* data;

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

    }
    else if (!strcmp(commandInput, "ADD")) {

    }
    else if (!strcmp(commandInput, "SEARCH")) {

    }
    else if (!strcmp(commandInput, "DELETE")) {

    }
    else if (!strcmp(commandInput, "QUIT")) {

    }
    else cout << "Command not recognized. Please try again." << endl;
    
  }

  // Garbage collection
  for (vector<Media*>::iterator it = data->begin();
       it != data->end();
       it++) {
    delete *it; // Remove all stored elements from heap
  }
  delete[] data; // Remove data structure itself
  
}
