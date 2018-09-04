/* 
   Created by Brendan McDonnell 9/1/2018
   Last Modified by Brendan McDonnell 9/3/2018
*/

/*
  TODO: Known bug where under some unknown conditions data outside of variable bounds will be filled between steps.
*/

#include <iostream>
#include <cstring>

using namespace std;

bool isAlphanumeric(char in) {
  // if numerical or upper or lower alphabet return true
  if (( in >= '0' && in <= '9' ) || ( in >= 'A' && in <= 'Z' ) || ( in >= 'a' && in <= 'z' )) return true;
  return false;
}

int main() {
  bool bugTesting = true;
  
  char inputStr[80];
  char cleanStr[80];
  char revStr[80];
  
  int index = 0;
  int n = 0;
  
  // Get input
  memset(inputStr, 0x00, 80); // Fill with null values
  cin.get(inputStr, 80);
  cin.clear();
  cin.ignore(10000, '\n');
  cout << endl; //cin.get();
  if (bugTesting) cout << "Got input: " << inputStr << endl;

  // Limit to alphanumeric characters
  memset(cleanStr, 0x00, 80);
  index = 0;
  for (int i = 0; i < strlen(inputStr); i++) {
    if (isAlphanumeric(inputStr[i]) || inputStr[i] == '\0') {
      cleanStr[index] = inputStr[i];
      index++;
    }
  }
  if (bugTesting) cout << "Cleaned string: " << cleanStr << endl;

  // Remove excess null characters
  n = strlen(cleanStr);
  char shortStr[n];
  memset(shortStr, 0x00, n);
  for (int i = 0; i < n; i++) {
    shortStr[i] = cleanStr[i];
  }
  if (bugTesting) cout << "Shortened string: " << shortStr << endl;

  // Lowercase
  for (int i = 0; i < strlen(cleanStr); i++) {
    cleanStr[i] = tolower(cleanStr[i]);
  }
  if (bugTesting) cout << "Converted to lowercase: " << cleanStr << endl;

  // Reverse string
  memset(revStr, 0x00, n);
  for (int i = 0; i < n; i++) {
    revStr[i] = cleanStr[n - 1 - i];
  }
  if (bugTesting) cout << "Reversed String: " << revStr << endl;

  // Check if palindrome and output accordingly
  if (strcmp(cleanStr, revStr) == 0) {
    cout << "Palindrome." << endl;
  } else {
    cout << "Not a palindrome." << endl;
  }
  
  return 0;
}
