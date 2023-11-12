/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Week 9.4 labs
Date Assigned:           10/29/23
Due Date:                11/12/23

Description:
    Week 9.4 labs

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

#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<string> months = {
    "Janurary", "Feburary", "March",     "April",   "May",      "June",
    "July",     "August",   "September", "October", "November", "December",
};

double squareit(double);
double cubeit(double);
int menu();

string monthNumber(int);
double distance(int, int, int, int);
void shapes();

int main() {
  int choice, month;
  int x1, x2, y1, y2;
  double inputnumber;

  do {
    choice = menu();
    switch (choice) {
    case 1:
      cout << "enter a floating point number\n";
      cin >> inputnumber;

      cout << "Your number squared is " << squareit(inputnumber) << endl;
      cout << "Your number cubed is " << cubeit(inputnumber) << endl;
      break;
    case 2:
      cout << "Enter month number: " << endl;
      cin >> month;

      cout << "Month: " << monthNumber(month) << endl;
      break;
    case 3:
      cout << "Enter x1: ";
      cin >> x1;
      cout << "Enter y1: ";
      cin >> y1;
      cout << "Enter x2: ";
      cin >> x2;
      cout << "Enter y2: ";
      cin >> y2;

      cout << "\nDistance: " << distance(x1, y1, x2, y2) << endl;
      break;
    case 4:
      shapes();
      break;
    case 5:
      exit(0);
    }

  } while (choice < 5);

  return 0;
}

int menu() {
  int c;
  cout << "1. Square and cube" << endl;
  cout << "2. Month" << endl;
  cout << "3. Distance" << endl;
  cout << "4. Areas" << endl;
  cout << "5. Exit" << endl;
  cout << "Make a choice" << endl;
  cin >> c;
  return c;
}

double squareit(double in) {
  double x = in * in;
  return x;
}
double cubeit(double in) {
  double x = in * squareit(in);
  return x;
}

string monthNumber(int number) {
  if (number < 12 || number > 1) {
    return months[number - 1];
  }

  cout << "Invalid month number." << endl;
  exit(1);
}

// d=√((x2 – x1)² + (y2 – y1)²)
double distance(int x1, int y1, int x2, int y2) {
  return sqrt(squareit(x2 - x1) + squareit(y2 - y1));
}

void shapes() {
  int shape = 0;
  bool to_continue = true;
  char run;

  // square
  double side;

  // rectangle
  double length, width;

  // triangle
  double base, height;

  // circle
  double radius;

  while (to_continue) {
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "4. Circle\n";
    cout << "Enter selection: ";
    cin >> shape;

    switch(shape) {
      case 1: {
        cout << "Enter side length: ";
        cin >> side;
        cout << "Square area: " << fixed << setprecision(2) << squareit(side) << endl;

        break;
      }

      case 2: {
        cout << "Enter length: ";
        cin >> length;

        cout << "Enter width: ";
        cin >> width;

        cout << "Rectangle area: " << fixed << setprecision(2) << length * width << endl;
        break;
      }

      case 3: {
        cout << "Enter base: ";
        cin >> base;

        cout << "Enter height: ";
        cin >> height;

        cout << "Triangle area: " << fixed << setprecision(2) << ((base * height) / 2.0) << endl;
        break;
      }

      case 4: {
        cout << "Enter radius: ";
        cin >> radius;
        
        cout << "Circle area: " << fixed << setprecision(2) << (M_PI * squareit(radius)) << endl;
        break;
      }
    }

    cout << "Run again? (Y/N): ";
    cin >> run;

    if (toupper(run) == 'N') {
      to_continue = false;
    }

    else if (toupper(run) == 'Y') {
      to_continue = true;
    }
  }
}
