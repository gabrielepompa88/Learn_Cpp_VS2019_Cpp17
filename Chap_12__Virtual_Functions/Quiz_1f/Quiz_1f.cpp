/*

ORIGINAL PROGRAM:

#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}

	virtual const char* getName() { return "Derived"; }
};

int main()
{
	auto* d{ new Derived(5) };
	Base* b{ d };
	std::cout << b->getName() << '\n';
	delete b;

	return 0;
}

PROBLEM: Derived(5) is dynamically allocated. No destructors are provided, which make the compiler creating
a (non-virtual) destructor ~Base() which will be called by 'delete b', which will delete only the Base-portion of Derived(5),
making the rest leaking memory. This will make the destructor ~Derived() - the only responsible for releasing dynamically allocate memory - never called.

SOLUTION: create a virtual destructor ~Base(), overriden by ~Derived().

*/

#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() { return "Base"; }

	virtual ~Base() // virtual destructor added
	{
		std::cout << "~Base() called.\n";
	};
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}

	virtual const char* getName() { return "Derived"; }

	virtual ~Derived() {
		std::cout << "~Derived() called.\n";
	};
};

int main()
{
	auto* d{ new Derived(5) };
	Base* b{ d };
	std::cout << b->getName() << '\n';
	delete b;

	return 0;
}