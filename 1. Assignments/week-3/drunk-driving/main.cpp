/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Drunk driving
Date Assigned:           9/10/23
Due Date:                9/29/23

Description:
        A calculator for BAC.

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

#include <iomanip>
#include <iostream>

#define MULTIPLY 0.42
#define H_MULTIPLY 0.017
#define Y_MULTIPLY 8

const void format() {
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}

int main() {
    // beers -> total beers
    // duration -> duration in hours when consumed
    // weight -> weight of person in pounds

    int beers, duration;
    float weight;

    // BAC level
    float level = 0.0;

    format();

    std::cout << "Number of beers (12oz) consumed: ";
    std::cin >> beers;

    std::cout << "Weight (pounds): ";
    std::cin >> weight;

    std::cout << "Duration (hours) in which consumed: ";
    std::cin >> duration;

    level = (beers * MULTIPLY) * (Y_MULTIPLY / weight) - (duration * H_MULTIPLY);

    std::cout << "Your BAC level is: " << level << std::endl;

    if (level > 0.08) {
        std::cout << "You are not safe to drive." << std::endl;
    }
    else {
        std::cout << "You are legally allowed to drive." << std::endl;
    }

    return 0;
}