/*
  Created by Brendan McDonnell on 9/1/2018

  "Guessing Game" is a school project that generates a random number and 
  lets the user guess their way to the correct answer with some guiding help.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void displayGuessBar(int guesses[50], int answer) {
  int guessSpace[100];
  for (int i = 0; i < 100; i++) {
    guessSpace[i] = 0; // Manually filling with zero because I don't know if there's a better way
  }
  for (int i = 0; i < 50; i++) { // Guesses has a length of 50
    if (guesses[i] != 0) { // Guess exists
      guessSpace[guesses[i]] = 1; // Fill every guessed location with a 1
    }
  }
  cout << endl;
  
  char output[102];
  output[0] = '[';
  output[101] = ']';
  for (int i = 1; i < 101; i++) { // Between brackets
    if (guessSpace[i] != 0) { // Guess has been made
      if (i < answer) {
	output[i] = '<';
      } else if (i > answer) {
	output[i] = '>';
      } else {
	output[i] = '=';
      }
    } else { // No guess
      output[i] = '.';
    }
  }

  cout << output << endl;
}

int getGuess() {
  int guess = -1;
  cout << "What is your guess?" << endl;
  cin >> guess;
  // cin.get(guess, 3);
  cin.clear();
  cin.ignore(10000, '\n');
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
  int guesses[50];
  for (int i = 0; i < 50; i++) {
    guesses[i] = 0;
  }
  
  // Start game
  cout << endl;
  cout << "A random number between zero and one hundred (inclusive) has been generated." << endl
       << "Your job? You need to guess what that number is. I'll help you out, don't worry." << endl;
  guess = getGuess();
  guesses[guessCount] = guess; // not guessCount++ because guessCount not yet incremented
  guessCount++;
  while(guess != answer) {
    // Give response
    cout << endl;

    // If game going too long
    if (guessCount >= 50) {
      cout << "Sorry, I'm going to cut you off here. You've taken 50 guesses and not gotten the answer!" << endl
	   << "That's so disgraceful I suggest that you not try this program again. Goodbye." << endl;
    }
    
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
    displayGuessBar(guesses, answer);
    guess = getGuess();
    guesses[guessCount] = guess; // not guessCount++ because guessCount not yet incremented
    guessCount++;
  } // end of guessing for loop

  // Left for loop. Therefore, guess is correct.
  cout << endl;
  displayGuessBar(guesses, answer);
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
  char input = 'a';
  bool inputGiven = false;
  while (!(input == 'y' || input == 'n')) {
    //if (!inputGiven) {
      cout << endl << "Play again? (y/n)" << endl;
      cin.get(input);
      cin.clear();
      cin.ignore(10000, '\n'); // Skip any characters beyond the first
      input = tolower(input);
      //      inputGiven = true;
      //}
    if (input == 'y') {
      return playGame();
    } else if (input == 'n') {
      cout << endl << "See you later!" << endl;
      return 0;
    } else {
      cout << "Please input either \"y\" or \"n\"." << endl;
      //inputGiven = false;
    }
  }
  return 1; // Line should never be reached
}

int main() {
  return playGame();
}

