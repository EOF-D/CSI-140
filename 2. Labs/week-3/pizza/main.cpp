/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Lab week 3
Date Assigned:           9/12/23
Due Date:                9/18/23

Description:
	Calculates how many pizzas to buy.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>

constexpr float SLICE_SIZE = 14.125;
constexpr int SLICES_PER = 4;
constexpr float PI = 3.142;

int main() {
	double diameter, radius, area;
	int slices, people, slices_needed, pizzas_needed;

	std::cout << "============ JOE\'S PIZZA PALACE ============" << std::endl << std::endl;
	std::cout << "Input diameter: ";
	std::cin >> diameter;

	std::cout << "How many people in total?: ";
	std::cin >> people;

	radius = diameter / 2;
	area = PI * radius * radius;
	slices = area / SLICE_SIZE;

	slices_needed = people * SLICES_PER;
	pizzas_needed = std::ceil(slices_needed / slices);

	std::cout << "Amount of slices: " << slices << std::endl;
	std::cout << "Total pizzas needed: " << pizzas_needed << std::endl;

	return 0;
}