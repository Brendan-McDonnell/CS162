#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int playGame(int xWins, int oWins);
int checkWin(char board[][3]);
int getInput();
int intToCol(int a);
int intToRow(int b);
void printBoard(char board[][3]);

const char BLANK = '.';
const char X = 'X';
const char O = 'O';

int main() {
  return playGame(0, 0);
}

int playGame(int xWins, int oWins) {
  bool turn = 0;
  char board[3][3] {
  {BLANK,BLANK,BLANK},
    {BLANK,BLANK,BLANK},
  	{BLANK,BLANK,BLANK}
  };

  int winState = 0;
  do {
    cout << winState << endl;
    
    printBoard(board);
    char move = turn ? O : X;
    cout << move << "'s turn" << endl << endl;
    int input = getInput();
    if (board[intToCol(input)][intToRow(input)] == BLANK) {
      board[intToCol(input)][intToRow(input)] = move;
      turn = !turn;
    } else {
      cout << endl << "Space already taken. Try again." << endl;
    }
  } while ((winState = checkWin(board)) == 0);

  printBoard(board);
  
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

  cout << "X has won " << xWins << " times." << endl;
  cout << "O has won " << oWins << " times." << endl;

  
  for(;;) {
    cout << "Play again?" << endl;
    char input[2] = { 0 };
    cin.get(input, 2);
    cin.clear();
    cin.ignore(10000, '\n');
    tolower(input[0]);
    cout << "Your input: " << input[0] << endl;
    if (input[0] == 'y') return playGame(xWins, oWins);
    if (input[0] == 'n') return 0;
    cout << "Invalid input" << endl << endl; 
  }

}

void printBoard(char board[][3]) {
  cout << endl;
  for (int row = 0; row < 3; row++) {
    cout << row;
    for (int col = 0; col < 3; col++) {
      cout << '\t' << board[col][row];
    }
    cout << endl << endl;
  }
  cout << " " << '\t' << 'A' << '\t' << 'B' << '\t' << 'C' << endl;
}

int checkWin(char board[][3]) {
  bool filled = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      if (board[i][j] == BLANK) filled = false;
  }
  if (filled) return 3;

  for (int i = 0; i < 3; i++) {
    if (board[i][0] != BLANK && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == X) return 1;
      return 2;
    }
    if (board[0][i] != BLANK && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      if (board[0][i] == X) return 1;
      return 2;
    }
  }
  
  if (board[0][0] != BLANK && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == X) return 1;
    return 2;
  }
    
  if (board[0][2] != BLANK && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == X) return 1;
    return 2;
  }
  
  return 0;
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
