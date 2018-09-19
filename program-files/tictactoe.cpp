#include <iostream>
#include <cstring>

using namespace std;

// Prototypes
void printBoard(char** b);
int getInput();
int intToRow(int a);
int intToCol(int a);
int isWin(const vector<int> &board);
void endGameOutput(int winner, int &xWins, int &oWins);
int endGame(int xWins, int oWins);

// Main method
int main() {
  return playGame(0, 0);
}

// Methods

/** Starts a new game and handles and controls game logic */
int playGame(int xWins, int oWins) {
  bool xTurn = true;
  vector<int> board;
  vector<int>::iterator it;

  while (!isWin(&board)) {
    printBoard(board);
    char turnChar = xTurn ? 'X' : 'O';
    cout << endl << "It's " << turnChar << "'s turn." << endl;
    board.pushBack(getInput(xTurn));
  }
  endGameOutput(isWin(&board));
  
  return endGame();
}

/** Evaluates board and returns:
      0: Game not over
      1: X won
      2: O won
      3: Tie game
*/
int isWin(const vector<int> &board) { // Using const to prevent modification
  
}

void endGameOutput(int winner, int &xWins, int &oWins) {
  // For each case, output the winner, wins this session, total wins
  cout << endl;
  switch (winner) {
  case 1: // X Won
    xWins++;
    cout << "X won the game!" << endl;
    cout << "In this session, X has won " << xWins << " times and O has won "
	 << oWins << " times." << endl;
    // Output overall wins
    break;
  case 2: // O Won
    oWins++;
    cout << "O won the game!" << endl;
    cout << "In this session, X has won " << xWins << " times and O has won "
	 << oWins << " times." << endl;
    // Output overall wins
    break;
  case 3:
    // Tie game
    cout << "Tie game!" << endl;
    cout << "In this session, X has won " << xWins << " times and O has won "
	 << oWins << " times." << endl;
    break;
  }
}

/** Returns the next game's value to main.
    Checks if playing again and updates files if necessary */
int endGame(int xWins, int oWins) {
  char input[2];
  cout << endl << "Would you like to play again? (y/n)" << endl;
  cin.get(input, 2);
  cin.clear();
  cin.ignore(10000, '\n');
  
  if (tolower(input[0]) == 'y') { 
    return playGame();
  }
  else if (tolower(input[0] == 'n')) {
    return 0;
  }
  else {
    cout << "Oops! Invalid input. Let's try that again!" << endl;
    return endGame();
  }
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
