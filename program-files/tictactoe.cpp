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
  return playGame();
}

// Methods

int playGame() {
  bool xTurn = true;
  vector<int> board;
  vector<int>::iterator it;

  while (!isWin(board)) {
    printBoard(board);
    char turnChar = xTurn ? 'X' : 'O';
    cout << endl << "It's " << turnChar << "'s turn." << endl;
    board.pushBack(getInput(xTurn));
  }
  endGame(isWin(board));
  
  return checkReplay();
}

int isWin() {
  
}

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

int getInput(bool xTurn) {
  char input[3] = { 0 };
  int output = -1;

  // Get input
  cout << "What is your move? (e.g C2)" << endl;
  cin.get(input, 3);
  cin.clear();
  cin.ignore(10000, '\n');

  // Validate input
  if (!((input[0] >= 'A' && input[0] <= 'C') ||
	(input[0] >= 'a' && input[0] <= 'c') &&
	(input[1] >= '0' && input[1] <= '2'))) {
    cout << endl << "Invalid input. Please try again." << endl << endl;
    return getInput();
  }

  // Convert to single number
  int col = tolower(input[0]) - 'a';
  int row = input[1] - '0';
  output = 3 * row + col;

  if (!xTurn) output += 10;
  
  return output;
}

int intToCol(int a) {
  return a % 3;
}

int intToRow(int a) {
  return (a - (a % 3)) / 3;
}
