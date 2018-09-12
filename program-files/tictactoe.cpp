#include <iostream>
#include <cstring>

using namespace std;

// Prototypes
void printBoard(char** b);
int getInput();
int intToRow(int a);
int intToCol(int a);


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
  int input = getInput();

  cout << intToRow(input) << ", " << intToCol(input) << endl;
  
  return 0;
}

// Methods

void printBoard(char** b) {
  cout << endl << endl;
  char output[34];
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
         output[index++] = '\t';
         output[index++] = row + '0';
         output[index++] = '\n';
         output[index++] = '\n';
      }
    }
  }
  output[index++] = 'A';
  output[index++] = '\t';
  output[index++] = 'B';
  output[index++] = '\t';
  output[index++] = 'C';
  output[index++] = '\n';
  
  cout << output << endl;
}

int getInput() {
  char input[3] = { 0 };
  
  cout << "What is your move? (column row)" << endl;
  cin.get(input, 2);
  cin.clear();
  cin.ignore(10000, '\n');

  tolower(input[0]);
  
  return 3 * (input[1] - 'a') + input[0];
}

int intToRow(int a) {
  return a - (a % 3) / 3;
}

int intToCol(int a) {
  return a % 3;
}
