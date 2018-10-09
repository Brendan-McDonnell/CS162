#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

/** Prototypes */
char* shortenCString(char* arr);

/** Global Data */
struct Student {
  char firstName[50] = "Billy Bob Joe III";
  char lastName[50] = "the Unfortunate";
  int studentID = 666420;
  float gpa = 6.66;
};

/** Methods */

/*
  TODO: CREATE ADD AND PRINT METHODS
  TEST
*/
int main() {
  vector<Student*>* studentList = new vector<Student*>;

  for(;;) {
    // Get input command
    cout << endl << "Enter a command. Use HELP for more details." << endl;
    char input[6] = { 0 };
    memset(input, 0x00, 6);
    cin.get(input, 7);
    cin.clear();
    cin.ignore(10000, '\n');   
    strcpy(input, shortenCString(input));

    /* COMMANDS
       HELP: Print out all commands and what they do.
       ADD: Create a new entry.
       PRINT: Print out all stored students.
       DELETE: Delete user via ID.
       QUIT: Exit program.
    */

    if (!strcmp(input, "HELP")) {
      cout << endl;
      cout << "************ HELP: COMMAND LIST ***********" << endl;
      cout << "HELP: Print out all commands and what they do." << '\n'
	   << "ADD: Create a new entry." << '\n'
	   << "PRINT: Print out all stored students." << '\n'
	   << "DELETE: Delete user via ID." << '\n'
	   << "QUIT: Exit program." << endl;
      cout << "*******************************************" << endl;
    }
    else if (!strcmp(input, "ADD")) {
      cout << endl;
      cout << "************ ADD *************" << endl;
      studentList.push_back(addStudent());
      cout << "Student added." << endl;
      cout << "******************************" << endl;
    }
    else if (!strcmp(input, "PRINT")) {
      cout << "************ PRINT ************" << endl;
      for (vector<Student*>::iterator it = studentList.begin();
	   it <= studentList.end();
	   it++) {
	printStudent(*it);
      }
      cout << "*******************************" << endl;
    }
    else if (!strcmp(input, "DELETE")) {
      cout << "************ DELETE ************" << endl;
      bool valid;
      char id[7];
      do {
	valid = true;
	memset(id, 0x00, 7);
	cout << "What is the ID of the user you wish to delete?" << endl;
	cin.get(id, 8);
	cin.clear();
	cin.ignore(10000, '\n');

	if (strlen(id) != 6) valid = false;
	for (int i = 0; i < strlen(id); i++)
	  if (id[i] < '0' && id[i] > '9') valid = false;
	if (!valid) cout << "Invalid ID. Please try again." << endl;
      } while (!valid);

      int intID = -1;
      for (int i = 0; i < strlen(id); i++) {
	intID += id[i] * exp(10, strlen(id) - i);
      }
      cout << "ID: " << intID << endl;
      
      for (vector<Student*>::iterator it = studentList.begin();
	   it <= studentList.end();
	   it++) {
	if (*it -> id == intID) {
	  delete studentList[it];
	  studentList.erase(it);
	}
      }

      cout << "Student deleted" << endl;
      cout << "********************************" << endl
    }
    else if (!strcmp(input, "QUIT")) {
      cout << "************ QUIT ************" << endl;
      cout << endl << "Exitting program." << endl;
      cout << "******************************" << endl;
      return 0;
    }
    else {
      cout << "Command not recognized, please try again." << endl;
    }
  }
}

char* shortenCString(char* arr) {
  int length = 0;
  int index = 0;
  while (length == 0) {
    if (arr[index++] == 0x00) length = index + 1;
  }

  char *output = new char[length];
  for (int i = 0; i < length; i++) {
    output[i] = arr[i];
  }

  return output;
}
