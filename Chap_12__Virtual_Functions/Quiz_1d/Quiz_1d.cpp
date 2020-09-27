/*
ORIGINAL PROGRAM:

#include <iostream>

class Base final
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
		: Base{ value }
	{
	}

	virtual const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{5};
	Base &b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}

PROBLEM: Base is declared as 'final', therefore it cannot be inherited.

SOLUTION: remove 'final' to make Derived inheriting from Base.

*/

#include <iostream>

class Base // 'final' removed
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
		: Base{ value }
	{
	}

	virtual const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}