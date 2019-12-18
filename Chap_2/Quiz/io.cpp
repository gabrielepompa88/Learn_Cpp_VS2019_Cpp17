#include "io.h"
#include <iostream>

int readNumber() {

	std::cout << "Input number: ";
	int n{};
	std::cin >> n;

	return n;
}

void writeAnswer(int n) {

	std::cout << "The sum is: " << n;
}