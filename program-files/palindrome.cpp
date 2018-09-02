/* 
   Created by Brendan McDonnell 9/1/2018
*/
#include <iostream>
#include <cstring>

using namespace std;

bool isAlphanumeric(char in) {
  // if numerical or upper or lower alphabet return true
  if (( in > '0' && in < '9' ) || ( in > 'A' && in < 'Z' ) || ( in > 'a' && in < 'z' )) return true;
  return false;
}
       
bool isPalindrome(char str[]) {
  int n = strlen(str);
  char rev[n];
  for (int i = n - 1; i >= 0; i--) {
    rev[n - i] = str[i];
  }
  if (strcmp(str, rev)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // Get input
  char rawInput[80] = { 0 }; // To initialize every item as 0
  cout << "Input a word or phrase to check" << endl;
  cin.get(rawInput, 80);
  cin.clear();
  cin.ignore(10000, '\n');

  // Trim off null values
  int len = 0;
  int n = strlen(rawInput);
  for (int i = 0; i < n; i++) {
    if (rawInput[i] != 0) len++;
  }
  char input[len];
  int index = 0;
  for (int i = 0; i < len; i++) {
    if (rawInput[i] != 0) {
      input[index] = rawInput[i];
      index++;
    }
  }
  
  // Remove non-alphanumeric values
  int length = 0;
  n = strlen(input);
  for (int i = 0; i < n; i++) {
    if (isAlphanumeric) length++;
  }
  char cleanString[length] = { 0 };
  index = 0;
  for (int i = 0; i < n; i++) {
    if (isAlphanumeric(input[i])) {
      cleanString[index] = input[i];
      index++;
    }
  }
  
  // Reverse
  n = strlen(cleanString);
  char revString[n];
  strcpy(revString, cleanString);
  for (int i = 0; i < n; i++) {
    swap(cleanString[i], revString[n - i]);
  }
  
  // Compare and output
  cout << cleanString << endl;
  cout << revString << endl;
  if (strcmp(cleanString, revString)) {
    cout << "Palindrome." << endl;
  } else {
    cout << "Not a palindrome." << endl;
  }
  
  return 0;
}
