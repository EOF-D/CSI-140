/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Lab week 4 formatting
Date Assigned:           9/29/23
Due Date:                9/29/23

Description:
	A formatting lab.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>

const void format() {
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
}

std::string prompt(std::string ask) {
	std::string userinput;

	std::cout << ask;
	std::getline(std::cin, userinput);

	return userinput;
}

std::vector<std::tuple<std::string, float>> prompt_grades() {
	// Ex: {(Lab, 78.00), (PA, 89.00)}
	std::vector<std::tuple<std::string, float>> grades;

	// Setting vector of names
	std::vector<std::string>names = {
		"Lab",
		"PA",
		"Quiz",
		"Midterm",
		"Final"
	};


	for (auto name : names) {
		float input = 0;

		std::cout << "Whats your " << name << " grade? ";
		std::cin >> input;

		std::tuple<std::string, float> pair
			= std::make_tuple(name, input);

		grades.push_back(pair);
	}

	return grades;
}

int main() {
	format();

	std::string name = prompt("Whats your name? ");
	std::string SSN = prompt("Whats your SSN? ");

	// {Excellent, Good, Poor}
	char attendence = 0;

	std::cout << "Whats your attendence? ";
	std::cin >> attendence;

	// vector of grades for easy printing
	std::vector<std::tuple<std::string, float>> grades = prompt_grades();

	std::cout
		<< std::setw(20)
		<< std::left
		<< name
		<< SSN
		<< std::endl;

	std::cout
		<< std::setw(20)
		<< std::left
		<< "Attendence "
		<< attendence
		<< std::endl;

	for (auto pair : grades) {
		std::cout
			<< std::setw(15)
			<< std::left
			<< std::get<0>(pair)
			<< std::get<1>(pair)
			<< std::endl;
	}

	// Averaging to get final grade
	float final = 0;
	for (auto grade : grades) {
		final += std::get<1>(grade);
	}

	final /= 5;

	std::cout
		<< std::setw(20)
		<< std::left
		<< "FINAL GRADE"
		<< final
		<< std::endl;

	return 0;
}