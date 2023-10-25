/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Lab week 4
Date Assigned:           9/26/23
Due Date:                9/26/23

Description:
	A CLI menu lab.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>
#include <iomanip>
#include <map>
#include <cctype>

std::map<int, float>gravity = {
	{1, 0.78},
	{2, 0.39},
	{3, 2.65},
	{4, 1.17},
	{5, 1.05},
	{6, 1.23},
};

int exit() {
	std::cout << "Incorrect selection.\n";
	return 1;
}

const void print() {
	std::cout << "-----------Week 4 Lab----------\n\n";
	std::cout << "Choice menu." << std::endl;

	std::cout << "   1. Age decider"
		<< std::endl;

	std::cout << "   2. Grades"
		<< std::endl;

	std::cout << "   3. Space boxing"
		<< std::endl;
}

const void age() {
	int age = 0;
	std::string prompt = "";

	std::cout << "How old are you? ";
	std::cin >> age;

	if (age < 16) {
		prompt = "You can't drive.";
	}

	else if (age < 18) {
		prompt = "You can't vote.";
	}

	else if (age < 25) {
		prompt = "You can't rent a car.";
	}

	else {
		prompt = "You can do anything that's legal.";
	}

	std::cout << prompt << std::endl;
}

const void grade() {
	char grade;
	std::string prompt;

	std::cout << "What letter grade did you receive? ";
	std::cin >> grade;

	switch (std::toupper(grade)) {
	case 'A':
		prompt = "You earned greater than a 90%";
		break;
	case 'B':
		prompt = "You earned a 80%-90%";
		break;
	case 'C':
		prompt = "You earned a 70%-80%";
		break;
	case 'D':
		prompt = "You earned a 60%-70%";
		break;
	case 'F':
		prompt = "You got less than a 60%..";
		break;

	default:
		exit();
	}

	std::cout << prompt << std::endl;
}

const void space() {
	double weight = 0.0;

	std::cout << "Enter earth weight. " << std::endl;
	std::cin >> weight;

	const std::string prompt = "#	Planet	Relative gravity\n"
		"1	Venus	0.78\n"
		"2	Mars	0.39\n"
		"3	Jupiter	2.65\n"
		"4	Saturn	1.17\n"
		"5	Uranus	1.05\n"
		"6	Neptune	1.23\n";


	std::cout << prompt << std::endl;
	std::cout << "Enter which planet number. " << std::endl;

	int planet = 0;
	std::cin >> planet;

	float converted = gravity[planet] * weight;
	std::cout << "Your weight would be " << converted << std::endl;
}

int main() {
	print();

	int choice = 0;
	std::cin >> choice;

	switch (choice) {
	case 1: {
		age();
		break;
	}

	case 2: {
		grade();
		break;
	}

	case 3: {
		space();
		break;
	}

	default:
		return exit();
	}

	return 0;
}