/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Long distance price calculator.
Date Assigned:           9/10/23
Due Date:                10/8/23

Description:
    Long distance call price calculator.

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

const void setup() {
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::string welcome =
        "Starting Time of Call           Rate per Minute\n"
        "00:00 - 06 : 59                           $0.12\n"
        "07 : 00 - 19 : 00                         $0.55\n"
        "19 : 01 - 23 : 59                         $0.35\n";

    std::cout << welcome << std::endl;
}

int main() {
    double startTime, callDuration = 0.0;
    double chargeRate = 0.0;

    setup();

    std::cout << "Enter the starting time in HH.MM format: ";
    std::cin >> startTime;

    std::cout << "Enter the number of minutes of the call: ";
    std::cin >> callDuration;

    if (startTime >= 0.00 && startTime < 0.70) {
        chargeRate = 0.12;  // 00:00-06:59
    }

    else if (startTime >= 0.70 && startTime < 19.00) {
        chargeRate = 0.55;  // 07:00-19:00
    }

    else {
        if (!(startTime >= 19.00 && startTime < 24.00)) {
            std::cout << "Invalid time given." << std::endl;
            return 1;
        }

        chargeRate = 0.35;  // 19:01-23:59
    }

    double totalCharge = callDuration * chargeRate;
    std::cout << "Total charges for the call: $" << totalCharge << std::endl;

    return 0;
}