#include <iostream>

void a()
{
	std::cout << "a() called\n";
}

void b()
{
	std::cout << "b() called\n";
	a();
}

int main()
{	// put breakpoints on lines 5 and 10 and examine the Call Stack
	a(); 
	b();

	return 0;
}