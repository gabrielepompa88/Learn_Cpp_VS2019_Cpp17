#include <iostream>
#include <memory> // for std::shared_ptr

class Something; // assume Something is a class that can throw an exception

int main()
{
	// PROBLEM: is Something throws an exception, one of the Something objects might not be 
	// deallocated properly
	//doSomething(std::shared_ptr<Something>(new Something), std::shared_ptr<Something>(new Something));

	// SOLUTION: use make_shared
	//doSomething(std::make_shared<Something>(), std::make_shared<Something>());
	
	return 0;
}