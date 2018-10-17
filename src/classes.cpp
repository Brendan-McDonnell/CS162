#include <iostream>
#include "../include/Media.h"

using namespace std;

// Prototypes

// Global constants

// Functions

int main() {
  char* title;
  //  char* titlePtr = &title;
  Media med(title, 5, 2001);
  cout << med << endl;
  delete title;
}
