/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Week six lab part two
Date Assigned:           10/1/23
Due Date:                11/19/23

Description:
    Week six lab part two

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which
may then retain a copy of this assignment on its database for the purpose of
future plagiarism checking)
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void record();
void search();
void display();

void verify(string SSN) {
  if (SSN.size() != 11) {
    cerr << "Invalid SSN format" << endl;
    exit(1);
  }

  if (!(SSN[3] == '-' && SSN[6] == '-')) {
    cerr << "Invalid SSN format: Please use 000-00-0000" << endl;
    exit(1);
  }

  for (int i = 0; i < 9; i++) {
    if (i == 3 || i == 6) {
      continue;
    }

    if (!isdigit(SSN[i])) {
      cerr << "Invalid SSN: Received a non digit." << endl;
      exit(1);
    }
  }
}

void menu() {
  cout << "1. Add a record" << endl;
  cout << "2. Find a person by SSN" << endl;
  cout << "3. Display all records" << endl;
  cout << "4. Exit" << endl;
}

// declare as static when constructing file stream.
ifstream &get_input() {
  static ifstream input("data.txt", ios::in);
  if (!input) {
    cerr << "Error reading `data.txt`" << endl;
    exit(1);
  }

  return input;
}

ofstream &get_output() {
  static ofstream output("data.txt", ios::app);
  if (!output) {
    cerr << "Error reading `data.txt`" << endl;
    exit(1);
  }

  return output;
}

int main() {
  int choice;

  do {
    menu();
    cin >> choice;

    switch (choice) {
    case 1: {
      record();
      break;
    }

    case 2: {
      search();
      break;
    }

    case 3: {
      display();
      break;
    }

    default: {
      cerr << "Invalid chocice: " << choice << endl;
      break;
    }
    }

  } while (choice != 4);
}

void record() {
  ofstream &file = get_output();

  string SSN, name;
  double lab, pa, quiz, midterm, final;
  char attendance;

  cout << "SSN: ";
  cin >> SSN;
  verify(SSN);

  cout << "Full name: ";

  cin.ignore();
  getline(cin, name);

  cout << "Attendance: ";
  cin >> attendance;

  cout << "Lab: ";
  cin >> lab;

  cout << "PA: ";
  cin >> pa;

  cout << "Quiz: ";
  cin >> quiz;

  cout << "Midterm: ";
  cin >> midterm;

  cout << "Final: ";
  cin >> final;

  file << SSN << endl;
  file << name << endl;
  file << attendance << endl;
  file << lab << " " << pa << " " << quiz << " " << midterm << " " << final
       << endl;

  file.close();
}

void search() {
  ifstream &file = get_input();
  string SSN;

  cout << "SSN: ";
  cin >> SSN;

  verify(SSN);

  string buffer;
  while (!file.eof()) {
    if (file.eof()) {
      break;
    }

    file >> buffer;
    if (buffer == SSN) {
      string name;
      char attendance;
      double lab, pa, quiz, midterm, final;

      file.ignore();
      getline(file, name);

      file >> attendance;
      file >> lab >> pa >> quiz >> midterm >> final;

      cout << "SSN: " << SSN << " Name: " << name
           << " Attendance: " << attendance
           << " Lab: " << lab
           << " PA: " << pa
           << " Quiz: " << quiz
           << " Midterm: " << midterm
           << " Final: " << final
           << endl;

      break;
    }

    // ignore 3 lines if buffer != SSN.
    file.ignore(3, '\n');
  }

  file.close();
}

void display() {
  ifstream &file = get_input();
  double labPercent = 0.15;
  double paPercent = 0.25;
  double quizPercent = 0.15;
  double midtermPercent = 0.20;
  double finalPercent = 0.25;
  double total;

  while (!file.eof()) {
    if (file.eof()) {
      break;
    }

    string name, SSN;
    char attendance;
    double lab, pa, quiz, midterm, final;

    file.ignore();
    file >> SSN;
    verify(SSN);

    file.ignore();
    getline(file, name);

    file >> attendance;
    file >> lab >> pa >> quiz >> midterm >> final;

    total = lab * labPercent;
    total += pa * paPercent;
    total += quiz * quizPercent;
    total += midterm * midtermPercent;
    total += final * finalPercent;

    cout << "SSN: " << SSN << endl;
    cout << "Name: " << name << endl;
    cout << "Attendance: " << attendance << endl;
    cout << "Average: " << total << endl;
  }

  file.close();
}