/*
plog: https://github.com/SergiusTheBest/plog

For Visual Studio 2019 users: to include the header files of plog, preserving the structure "plog/Log.h", 
right click on the project name, then in Properties > C/C++ > General > Additional Include Directories 
add the local system path to the folder where the plog folder has been saved.

*/

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