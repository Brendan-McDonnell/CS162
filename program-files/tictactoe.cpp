#include <iostream>
#include <cstring>

using namespace std;

// Prototypes
void printBoard(char** b);

// Main method
int main() {

  char** ptrBoard = new char*[3];
  for (int i = 0; i < 3; i++) {
    ptrBoard[i] = new char[3];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ptrBoard[i][j] = '.';
    }
  }

  printBoard(ptrBoard);

  return 0;
}

// Methods

void printBoard(char** b) {
  cout << endl << endl;
  char output[22];
  memset(output, 0x00, 34);
  
  int index = 0;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (col == 0) {
	output[index++] = b[row][col];
	output[index++] = '\t';
      }
      else if (col == 1) {
	output[index++] = b[row][col];
	output[index++] = '\t';
      }
      else if (col == 2) {
	output[index++] = b[row][col];
	output[index++] = '\n';
	output[index++] = '\n';
      }
    }
  }
  
  cout << output << endl;
}
