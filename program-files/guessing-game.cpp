#include <iostream>

using namespace std;


int getGuess() {
  int guess;
  cout << "What is your guess?" << endl;
  cin >> guess;
  return guess;
}

int getRandomInt(int range, bool inclusive) {
  if (inclusive) {
    return rand() % range + 1;
  } else { // Else not strictly necessary, just easier to quickly understand
    return rand() % range;
  }
}

int playGame() {
  srand(time(NULL)); // Set psuedorandom number generation seed
  // Set up
  int answer = getRandomInt(100, true);
  int guess = -1; // Outside range, so the guess can't randomly be correct before they even make one
  int guessCount = 0;

  // Start game
  cout << endl;
  cout << "A random number between zero and one hundred (inclusive) has been generated." << endl
       << "Your job? You need to guess what that number is. I'll help you out, don't worry." << endl;
  guess = getGuess();
  guessCount++;
  while(guess != answer) {
    // Give response
    cout << endl;
    int responsePicker = -1;
    responsePicker = getRandomInt(3, true);
    switch(responsePicker) {
    case 1:
      cout << "Oh no! Your guess what incorrect. But I'm nice, so I'll give you a hint!" << endl;
      break;
    case 2:
      cout << "Nope. Sorry. Your guess wasn't the answer. I suppose you might want a hint... " << endl
	   << "Not that I care whether or not you do! I'm giving you one no matter what." << endl;
      break;
    case 3:
      cout << "Wrong! I'll give you a hint, so you might get it on try number " << guessCount + 1
	   << ":" << endl;
      break;
    default:
      cout << "You're so special that you got a response my program can't give you... huh."
	   << "As a reward, here's the answer! " << answer << endl;
      cout << "It took you " << guessCount << " tries to break my program. Congrats?" << endl;
      cout << "Oh, and because you broke me and I'm scared of you now, I won't give the the \"Play again option\". Please leave." << endl;
      return 1;
    }

    // Give hint
    if (guess < answer) {
      cout << "Hint: Your guess (" << guess << ") was less than the answer." << endl;
    } else {
      cout << "Hint: Your guess (" << guess << ") was greater than the answer." << endl;
    }

    // Get next guess
    cout << endl;
    guess = getGuess();
    guessCount++;
  } // end of guessing for loop

  // Left for loop. Therefore, guess is correct.
  cout << endl;
  int responsePicker = -1;
  responsePicker = getRandomInt(3, true);
  switch (responsePicker) {
  case 1:
    cout << "WOOOO-HOOOOOO!! YEAH! Oh. Um. Yeah, maybe a little too much enthusiasm?" << endl
	 << "Anyway, uh, you won. The answer was " << answer << " and it took you... " << guessCount
	 << " tries. I'm going to go now. Yeah. Uhm... Bye." << endl;
    break;
  case 2:
    cout << "Wow, you sure are amaaaazing. Guessing some random number out of a tiny selection of possibilities" << endl
	 << "while a computer literally guided you to the input. I'm sooo impressed." << endl
	 << "It took took you " << guessCount << " whole tries to guess " << answer << ". Cool." <<endl;
    break;
  case 3:
    if (guessCount > 7) {
      cout << "You got it! I think you can work on your strategy, though." << endl
	   << "That took you " << guessCount << " tries to guess " << answer << ", after all.";
    } else {
      cout << "You got it! Either you're pretty lucky, or you've worked with data before. Nice either way!" << endl
	   << "It took you only " << guessCount << " tries to guess " << answer << "." << endl;
    }
    break;
  }

  // Ask for play again. If yes, just return the new method,
  //   as a value of 1 would eventually be returned to 1 in the event of "return 1;" being called.
  cout << endl;
  char input = 0;
  while (!(input == 'y' || input == 'n')) {
    input = 0;
    cout << "Play again? (y/n)" << endl;
    cin >> input;
    input = char(tolower(int(input))); // Not sure if casting from char to int in implicit in c++
    if (input == 'y') {
      cout << "Okay!" << endl;
      return playGame();
    }
    else if (input == 'n') {
      cout << endl << "See you later!" << endl;
      return 0;
    } else {
      cout << endl << "Please either input \"y\" or \"n\". Thank you," << endl;
    }
  }
  return 1; // Line should never be reached
}

int main() {
  return playGame();
}

