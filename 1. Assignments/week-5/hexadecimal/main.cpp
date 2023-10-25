/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Week Five Homework Assignment.
Date Assigned:           9/17/23
Due Date:                10/15/23

Description:
        Week 5 homework. Converting hexadecimal.

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
#include <string>
#include <sstream>

constexpr auto HEX = "0123456789ABCDEF";

using namespace std;

int main() {
    int number = 0;
    string parsed = "";

    while (true) {
        cout << "Enter a number(base 10): ";
        cin >> number;

        if (cin.bad() || cin.fail()) {
            cout << "Received non numeric input. Try again." << endl;

            // clearing error state & clearing input buffer
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            continue;
        }

        if (number < 0) {
            cout << "Number must be a positive number." << endl;
        }

        else {
            // conversion to hex
            while (number > 0) {
                parsed = HEX[number % 16] + parsed;
                number /= 16;
            }

            break;
        }
    }

    cout << "Converted hex: " << parsed << endl;
    return 0;
}