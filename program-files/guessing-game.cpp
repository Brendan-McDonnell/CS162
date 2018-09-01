#include <iostream>

using namespace std;

int main() {
  return playGame();
}

int mainplayGame() {
  // Set up
  int answer = getRandomInt(100, true);
  int guess = -1; // Outside range, so the guess can't randomly be correct before they even make one
  int guessCount = 0;

  // Start game
  cout << "A random number between zero and one hundred (inclusive) has been generated." << endl
       << "Your job? You need to guess what that number is. I'll help you out, don't worry." << endl;
  guess = getGuess();
  guessCount++;
  while(guess != answer) {
    // Give response
    int responsePicker = getRandomInt(3, true);
    switch(responsePicker) {
    case 1:
      cout << "Oh no! You're guess what incorrect. But I'm nice, so I'll give you a hint:" << endl;
      break;
    case 2:
      cout << "Nope. Sorry. You guess wasn't the answer. I suppose you might want a hint... " << endl
	   << "Not that I care whether or not you do! I'm giving you one no matter what:" << endl;
      break;
    case 3:
      cout << "Wrong! I'll give you a hint, so you might get it on try number " << guessCount
	   << ":" << endl;
      break;
    default:
      cout << "You're so special that you got a response my program can't give you... huh."
	   << "As a reward, here's the answer! " + answer + endl;
      cout << "It took you " << guessCount << " tries to break my program. Congrats?" << endl;
      cout << "Oh, and because you broke me and I'm scared of you now, I won't give the the \"Play again option\". Please leave." << endl;
      return 1;
    }

    // Give hint
    if (guess < answer) {
      cout << "Hint: Your guess (" << guess << ") was less than the answer." << endl;
    } else {
      cout << "Hint: You guess (" << guess << ") was greater than the answer." << endl;
    }

    // Get next guess
    guess = getGuess();
  }

  // Left for loop. Therefore, guess is correct.
  int responsePicker = getRandomInt(3, true);
  switch (reponsePicker) {
  case 1:
    cout << "WOOOO-HOOOOOO!! YEAH! Oh. Um. Yeah, maybe a little too much enthusiasm?" << endl
	 << "Anyway, uh, you won. The answer was " << answer << " and it took you... " << guessCount
	 << " tries. I'm going to go now. Yeah. Uh. Bye." << endl;
    break;
  case 2:
    cout << "Wow, you sure are amaaaazing. Guessing some random number out of a small range" << endl
	 << "while a computer literally guided you to the input. I'm sooo impressed." << end1
	 << "It took took you " << guessCount << " whole tries to guess " << answer << ". Cool." <<end1;
    break;
  case 3:
    cout << "Oh yeah, I'm supposed to be either pushing or committing frequenty, and this is such a small project I should probably do that right now."
        
  return 0;
}

int getRandomInt(int range, bool inclusive) {
  srand(time(NULL)); // Set psuedorandom number generation seed
  if (inclusive) {
    return rand(100) % range + 1;
  } else { // Else not strictly necessary, just easier to quickly understand
    return rand(100) % range;
  }
}

int getGuess() {
  cout << "Your guess is?" << endl;
  return cin;
}
