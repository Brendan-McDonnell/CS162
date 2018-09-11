#include <iostream>

using namespace std;

const int PLAY_EMPTY = 0;
const int PLAY_X = 1;
const int PLAY_O = 2;

// Prototypes


// Main method
int main() {

  int** ptrBoard = new int*[3];
  for (int i = 0; i < 3; i++) {
    ptrBoard[i] = new int[3];
  }
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ptrBoard[i][j] = 0;
    }
  }
  
  
  
  return 0;
}

// Methods

void printBoard(int** b) {
  system("CLS");
  char output[24];
  // OUTPUT
