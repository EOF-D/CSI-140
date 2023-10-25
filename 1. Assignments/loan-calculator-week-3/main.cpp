/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Loan calculator
Date Assigned:           9/10/23
Due Date:                10/1/23

Description:
        A loan calculator.

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
#include <iomanip>
#include <iostream>

const void format() {
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}

int main() {
    // borrowed -> total amount borrowed
    // rate -> monthly interest rate
    // payment -> total payment per month
    // M = borrowed(1+rate)^months(rate) / [(1+rate)^n-1]
    float borrowed, rate, payment;

    // total months for the loan
    int months;

    format();

    std::cout << "How much money do you want to borrow? ";
    std::cin >> borrowed;

    std::cout << "What is the yearly interest rate? ";
    std::cin >> rate;

    std::cout << "How many months will this loan take? ";
    std::cin >> months;

    std::cout << "\n";

    rate = rate / 12;

    payment = borrowed * std::pow((1 + rate / 100), months) * rate / 100;
    payment = payment / (std::pow(1 + rate / 100, months) - 1);

    std::cout << std::setw(30) << std::left << "Loan amount:"
        << "$" << borrowed << std::endl;

    std::cout << std::setw(30) << std::left << "Monthly interest rate" << rate
        << "%" << std::endl;

    std::cout << std::setw(30) << std::left << "Number of payments" << months
        << std::endl;

    std::cout << std::setw(30) << std::left << "Monthly payment"
        << "$" << payment << std::endl;

    std::cout << std::setw(30) << std::left << "Total amount paid back"
        << "$" << payment * months << std::endl;

    std::cout << std::setw(30) << std::left << "Total amount paid back"
        << "$" << (payment * months) - borrowed << std::endl;

    return 0;
}