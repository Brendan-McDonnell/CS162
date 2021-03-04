#include <iostream>
#include <cstring>

using namespace std;

int playGame();
int playGame(int turn, int xWins, int oWins);
int checkWin(char** board);
int getInput();
int intToCol(int a);
int intToRow(int a);
void printBoard(char** board);
void winsOutput(int output, int xWins, int oWins);

const int BLANK = 0;
const int X = 1;
const int O = 2;

int main() {
  playGame();
}

int playGame() {
  playGame(1, 0, 0);
}

int playGame(int turn, int xWins, int oWins) {
  char** board = new char*[3];
  for (int i = 0; i < 3; i++) {
    char arr[3] = { 0 };
    board[i] = arr;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      cout << board[i][j] << endl;
  }
  
  int winState = BLANK;
  while (!(winState = checkWin(board))) {
    printBoard(board);
    cout << "It's " << (turn == X ? 'X' : 'O') << "'s turn" << endl;
    int input = getInput();
    cout << "input: " << input << endl;
    cout << "intToCol(input): " << intToCol(input) << endl;
    cout << "intToRow(input): " << intToRow(input) << endl;
    cout << "turn: " << turn << endl;
    board[intToCol(input)][intToRow(input)] = turn;
    if (turn == X) turn = O;
    else turn = X;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      cout << board[i][j] << endl;
  }
  
  cout << endl;
  switch (winState) {
  case 0:
    cout << "Tie game!";
    break;
  case 1:
    cout << "X won!";
    xWins++;
    break;
  case 2:
    cout << "O won!";
    oWins++;
    break;
  }
  cout << endl;
  
  printBoard(board);
  winsOutput(turn, xWins, oWins);


  // From let_me_be on Stack Overflow, retrieved 10/3
  for (int i = 0; i < 3; i++)
    delete[] board[i];
  delete[] board;
  
  for(;;) {
    cout << "Play again?" << endl;
    char input[2] = { 0 };
    cin.get(input, 1);
    cin.clear();
    cin.ignore(10000, '\n');
    tolower(input[0]);
    cout << "Your input: " << input[0] << endl;
    if (input[0] == 'y') return playGame(1, xWins, oWins);
    if (input[0] == 'n') return 0;
    cout << "Invalid input" << endl << endl; 
  }
}

int checkWin(char** board) {
  struct WinChecker {
    static bool checkCondition(char** board, int col, int colIncrement, int row, int rowIncrement) {
      bool output = board[col][row];
      if (!output) return false; // If empty
      cout << "output: " << output << endl;
      for (; col < 3 && col >= 0; col += colIncrement) {
	for (; row < 3 && row >= 0; row += rowIncrement) {
	  if (output != board[col][row]) return false;
	}
      }
    };
  };

  for (int i = 0; i < 3; i++) {
    if (WinChecker::checkCondition(board, i, 1, 0, 1)) return board[i][0] == X ? X : O;
    if (WinChecker::checkCondition(board, 0, 1, i, 1)) return board[0][i] == X ? X : O;
    if (WinChecker::checkCondition(board, i, 1, i, 1)) return board[i][i] == X ? X : O;
  }
  if (WinChecker::checkCondition(board, 2, -1, 0, 1)) return board[2][0] == X ? X : 0;
}

void printBoard(char** board) {
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << char('A' + i);
    int j;
    for (j = 0; j < 3; j++) {
      cout << '\t' << board[j][i];
    }
    cout << j << endl;
  }
  cout << endl;
}

void winsOutput(int turn, int xWins, int oWins) {
  //if (turn == X) cout << "X has won!" << endl;
  //else cout << "O has won!" << endl;
  cout << "X has won " << xWins << " times" << endl;
  cout << "O has won " << oWins << " times" << endl;
  cout << endl;
}

int getInput() {
  char input[3] = { 0 };
  int output = -1;

  cout << "What is your move? (e.g. C2)" << endl;
  cin.get(input, 3);
  cin.clear();
  cin.ignore(10000, '\n');

  if (!((input[0] >= 'A' && input[0] <= 'C') ||
	(input[0] >= 'a' && input[0] <= 'c') &&
	(input[1] >= '0' && input[1] <= '2'))) {
    cout << endl << "Invalid input. Please try again." << endl << endl;
    return getInput();
  }

  int col = tolower(input[0]) - 'a';
  int row = input[1] - '0';
  output = 3 * row + col;

  return output;
}

int intToCol(int a) {
  return a % 3;
}

int intToRow(int a) {
  return (a - (a % 3)) / 3;
}
