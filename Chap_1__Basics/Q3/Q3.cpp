
#include <iostream>

int main() {

	int x{}, y{};

	std::cout << "Enter an integer: ";
	std::cin >> x;

	std::cout << "Enter another integer: ";
	std::cin >> y;

	std::cout << "x + y = " << x << " + " << y << " = " << x + y << "\n";
	std::cout << "x - y = " << x << " - " << y << " = " << x - y << "\n";
	std::cout << "x * y = " << x << " * " << y << " = " << x * y << "\n";
	std::cout << "x / y = " << x << " / " << y << " = " << x / static_cast<double>(y) << "\n";

	return 0;

}