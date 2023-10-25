/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Week 7 lab
Date Assigned:           10/01/23
Due Date:                10/15/23

Description:
        Week 7 Lab, looping menu with problems.

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
#include <iostream>
#include <string>

using namespace std;

template <typename T> T prompt(string ask) {
    T userinput;

    cout << ask;
    cin >> userinput;

    return userinput;
}

void loop1() {
    int number = prompt<int>("Enter a number: ");

    // for-loop for AxB = A*B
    for (int i = 1; i <= 12; i++) {
        cout << number << "x" << i << " = " << number * i
            << endl;
    }
}

void loop2() {
    string filename = prompt<string>("Which file?: ");
    if (!(filename == "1nums.txt" || filename == "2nums.txt" || filename == "3nums.txt")) {
        cout << "Invalid filename given. Must be one of `1nums.txt`, `2nums.txt` or `3nums.txt`";
        exit(1);
    }

    ifstream integers(filename, ios::in);
    if (!integers) {
        cout << "Failed to open: " << filename << endl;
        exit(1);
    }

    int sum = 0;
    while (!integers.eof()) {
        int number = 0;

        integers >> number;
        sum += number;

        if (integers.eof()) {
            break;
        }
    }

    cout << "Sum: " << sum << endl;
    integers.close();
}

void loop3() {
    // iterate from 1-90 and check if sum is 60 and difference is 14.
    for (int i = 1; i < 100; i++) {

        for (int idx = 1; idx < 100; idx++) {
            if (i + idx == 60 && abs(i - idx) == 14) {
                cout << "Pair: " << i << " & " << idx << endl;
            }
        }
    }
}

void loop4() {
    for (int i = 1; i <= 56; i++) {
        int first = i / 10;
        int second = i % 10;

        if (first + second > 10) {
            cout << "Number: " << i << endl;
        }
    }
}

void loop5() {
    int number = prompt<int>("Enter number: ");
    int total = 0;

    for (int i = 1; i <= number; i++) {
        total += i;
    }

    cout << "Total: " << total << endl;
}


int main() {

    int choice = 1;

    while (choice > 0 and choice < 7) {
        for (int i = 1; i < 6; i++) {
            cout << i << ". Problem " << i << endl;
        }

        cin >> choice;
        switch (choice) {
        case 1: {
            loop1();
            break;
        }

        case 2: {
            loop2();
            break;
        }

        case 3: {
            loop3();
            break;
        }

        case 4: {
            loop4();
            break;
        }

        case 5: {
            loop5();
            break;
        }

        default: {
            cout << "Invalid loop selection" << endl;
            exit(1);
        }
        }
    }
}