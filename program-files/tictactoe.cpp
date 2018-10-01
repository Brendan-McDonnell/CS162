#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

// Prototypes
int playGame(int xWins, int oWins);
void printBoard(vector<int> &b);
int getInput(bool xTurn);
int intToRow(int a);
int intToCol(int a);
int isWin(vector<int> &board);
void endGameOutput(int winner, int &xWins, int &oWins);
int endGame(int xWins, int oWins);

// Main method
int main() {
  return playGame(0, 0);
}

// Methods

/** Starts a new game and handles and controls game logic */
int playGame(int xWins, int oWins) {
  cout << "Playgame() ran" << endl;
  bool xTurn = true;
  vector<int> board;
  vector<int>::iterator it;

  cout << "About to run while loop" << endl;
  int winState = 0;
  while (!(winState = isWin(board))) {
    cout << "Main while loop" << endl;
    printBoard(board);
    char turnChar = xTurn ? 'X' : 'O';
    cout << endl << "It's " << turnChar << "'s turn." << endl;
    board.push_back(getInput(xTurn));
    xTurn = !xTurn;
  }
  endGameOutput(winState, xWins, oWins);
    
  
  return endGame(xWins, oWins);
}

/** Evaluates board and returns:
      0: Game not over
      1: X won
      2: O won
      3: Tie game
*/
int isWin(vector<int> &board) { // Using const to prevent modification
  cout << "Entered isWin()" << endl;
  struct WinChecker {
    vector<int>::iterator ptr;

    static bool isX(int val) {
      return val - 10 < 0;
    };
    
    static bool checkWin(int index, vector<int> &board) {
      cout << "Entered checkWin" << endl;
      cout << "Board size: " << board.size() << endl;
      cout << "Index: " << index << endl;
      if (board.size() < 5) return false; // Earliest turn to win
      int value = board[index];
      cout << "About to enter for loop" << endl;
      for (int i = 1; i <= 4; i++) {
	cout << "inner foil loop, i = " << i << endl;
	bool success = false;
        if (index + 2 * i <= 8 && isX(value) == isX(board[index + i]))
	  success = isX(value) == isX(board[index + 1 * i]) ? true : false;
	if (success) return true;
      }
      cout << "exited for loop" << endl;
    };
  };

  // Check for a win from every play in the top column and left row in the board
  /*
    0 1 2
    3 4 5
    6 7 8
   */
  // 0-3, 6
  int width = 3;
  for (int i = 0; i < width; i++) {
    cout << "About to run checkWin() statements" << endl;
    if (board.size() > i && WinChecker::checkWin(i, board)) return board[i] < 10 ? 1 : 2;
    if (board.size() > i && WinChecker::checkWin(i * width, board)) return board[i] < 10 ? 1 : 2;
  }
  if (board.size() >= 9) return 3; // Tie
  return 0;
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
    // Output overall wins
    break;
  }

  ifstream winsFile("winsRecord");
  if (winsFile.is_open()) {
    cout << endl << "Opened file";
  } else {
    cout << endl << "There was an error with retrieving previous session data" << endl;
  }
  winsFile.close();
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
    return playGame(xWins, oWins);
  }
  else if (tolower(input[0] == 'n')) {
    return 0;
  }
  else {
    cout << "Oops! Invalid input. Let's try that again!" << endl;
    return endGame(xWins, oWins);
  }
}

void printBoard(vector<int> &b) {
  cout << "printBoard run" << endl;

  
  vector<char> output;
  int index = 0;

  while (index < b.size()) {
    cout << "Entered while loop" << endl;
    int n = 3;
    int j;
    for (j = 0; j < n; j++) {
      output.push_back('\t');
      for (int i = 0; i < n; i++) {
	char c = b[i] < 10 ? 'X' : 'O';
	cout << i << ", " << b[i] << ", " << c << endl;
	output.push_back(b[i] < 10 ? 'X' : 'O');
	index++;
	output.push_back('\t');     
      }
      output.push_back(j);
    }
    for (int i = 0; i <= j; i++) {
      output.push_back(char(i + 'A'));
      output.push_back('\t');
    }
  }

  cout << endl;
  vector<char>::iterator ptr;
  for (ptr = output.begin(); ptr < output.end(); ptr++) {
    cout << *ptr;
  }
  cout << endl;
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
    return getInput(xTurn);
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
