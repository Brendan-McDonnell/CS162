#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

/** Prototypes */
struct Student;
char* shortenCString(char* arr);
Student* addStudent();
void printStudent(Student*);
int strToInt(char* arr, int len);

/** Global Data */
struct Student {
  char firstName[50] = "Billy Bob Joe III";
  char lastName[50] = "the Unfortunate";
  int id = 666420;
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
       SORT: Sorts students by ID number.
       DELETE: Delete user via ID.
       QUIT: Exit program.
    */

    if (!strcmp(input, "HELP")) {
      cout << endl;
      cout << "************ HELP: COMMAND LIST ***********" << endl;
      cout << "HELP: Print out all commands and what they do." << '\n'
	   << "ADD: Create a new entry." << '\n'
	   << "PRINT: Print out all stored students." << '\n'
	   << "SORT: Sorts students by chosen data." << '\n'
	   << "DELETE: Delete user via ID." << '\n'
	   << "QUIT: Exit program." << endl;
      cout << "*******************************************" << endl;
    }
    else if (!strcmp(input, "ADD")) {
      cout << endl;
      cout << "************ ADD *************" << endl;
      studentList -> push_back(addStudent());
      cout << "Student added." << endl;
      cout << "******************************" << endl;
    }
    else if (!strcmp(input, "PRINT")) {
      cout << "************ PRINT ************" << endl;
      cout << "---" << endl;
      for (vector<Student*>::iterator it = studentList -> begin();
	   it < studentList -> end();
	   it++) {
	printStudent(*it);
      }
      cout << "*******************************" << endl;
    }
    else if (!strcmp(input, "SORT")) {
      cout << "************ SORT *************" << endl;
      cout << "What would you like to sort the students by?" << endl
	   << "1: First name" << endl
	   << "2: Last name" << endl
	   << "3: ID number" << endl
	   << "4: GPA" << endl;
      
    }
    else if (!strcmp(input, "DELETE")) {
      cout << "************ DELETE ************" << endl;
      bool valid;
      bool success = false;
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

      int intID = strToInt(id, 6);
            
      for (vector<Student*>::iterator it = studentList -> begin();
	   it < studentList -> end();
	   it++) {
	if ((*it) -> id == intID) {
	  delete *it;
	  studentList -> erase(it);
	  success = true;
	  break; // Only delete one at a time.
	}
      }

      if (success) cout << "Student deleted" << endl;
      else cout << "Student deletion was unsuccessful." << endl;
      cout << "********************************" << endl;
    }
    else if (!strcmp(input, "QUIT")) {
      cout << "************ QUIT ************" << endl;
      cout << "Exitting program." << endl;
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


Student* addStudent() {
  Student* output = new Student();
  
  cout << "What is the new student's first name?" << endl;
  cin.get(output -> firstName, 50);
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "What is the new student's last name?" << endl;
  cin.get(output -> lastName, 50);
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "What is the new student's ID number?" << endl;
  char input[7];
  cin.get(input, 7);
  output -> id = strToInt(input, 6);
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "What is the new student's GPA?" << endl;
  cin >> output -> gpa;

  return output;
}

int strToInt(char* arr, int len) {
  int output = 0;
  for (int i = 0; i < len; i++) {
    output += int(arr[i] - '0') * pow(10, len - 1 - i);
  }
  return output;
}

void printStudent(Student* student) {
  cout << "Name: " << student -> firstName << " " << student -> lastName << endl;
  cout << "ID: " << student -> id << endl;
  cout << "GPA: " << student -> gpa << endl;
  cout << "---" << endl;
}
