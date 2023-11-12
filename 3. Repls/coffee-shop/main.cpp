/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Week ten coffee shop
Date Assigned:           10/1/23
Due Date:                11/19/23

Description:
    Coffee shop replit

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

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

constexpr double MENU_ITEMS[8] = {
  2.00, // Coffee
  1.75, // Tea
  1.75, // Hot Chocolate
  2.50, // Cupcake
  2.80, // Soda
  1.00, // Chips
  2.00, // Water
  3.25, // Cake of the day Slice
};

void menu();

double addItem(double, int);
double billDisplay(double, double, double);
void change(double, double);

bool _check_input(int choice) {
  if (choice == 9) {
    return false;
  }

  if (choice > 0 && choice < 9) {
    return true;
  }

  cout << "Invalid selection: `" << choice << "`" << " Reinput." << endl;
  return true;
}

void menu() {
  const string menu = "Coffee Shop Menu\n"
    "1 – Coffee                 $2.00\n"
    "2 – Tea                    $1.75\n"
    "3 – Hot Chocolate          $1.75\n"
    "4 – Cupcake                $2.50\n"
    "5 – Soda                   $2.80\n"
    "6 – Chips                  $1.00\n"
    "7 – Water                  $2.00\n"
    "8 - Cake of the day Slice  $3.25\n"
    "9 – End order\n";

  cout << menu;
}

double addItem(double add, double current) {
  return add + current;
}

double billDisplay(double bill, double tax, double tip) {
  double total = 0;
  total = (bill * tax) + tip + bill;

  cout << "Bill: $" << fixed << setprecision(2) << bill << endl;
  cout << "Tax: $" << fixed << setprecision(2) << tax * bill << endl;
  cout << "Tip: $" << fixed << setprecision(2) << tip << endl;
  cout << "Total amount due: $" << fixed << setprecision(2) << total << endl;

  return total;
}

void change(double tendered, double grand_total) {
  cout << "Change: $" << setprecision(2) << (tendered - grand_total) << endl;
}

int main() {
  int choice = 0;

  double total, grand_total, tendered = 0.0;
  double tax = 0.065, tip = 0;
  menu();

  do {
    cout << "Enter choice(1-9): ";
    cin >> choice;
    
    if (choice != 9) {
      total = addItem(total, MENU_ITEMS[choice]);
    }

  } while (_check_input(choice));

  tip = 10.0 / 100.0 * total;
  grand_total = billDisplay(total, tax, tip);

  cout << "Amount tendered: $";
  cin >> tendered;

  if (tendered < grand_total) {
    while (tendered < grand_total) {
      cout << "Amount tendered is not enough; enter new amount: $";
      cin >> tendered;
    }
  }

  change(tendered, grand_total);
  return 0;
}
