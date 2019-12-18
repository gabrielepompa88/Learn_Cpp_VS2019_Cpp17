#include <iostream>
#include "plog/Log.h" // Step 1: include the logger header

int getUserInput()
{
	LOGD << "getUserInput() called"; // LOGD is defined by the plog library

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;
	return x;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

	LOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x = getUserInput();
	std::cout << "You entered: " << x;

	return 0;
}