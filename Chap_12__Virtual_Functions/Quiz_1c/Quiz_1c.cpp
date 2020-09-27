/*
ORIGINAL PROGRAM:

#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{value}
	{
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{value}
	{
	}

	virtual const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{5};
	Base b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}

PROBLEM: the problem is that b is not a pointer or reference, but its a Base object itself, initialized
with a Derived object (d). This will cause 'object slicing', such that b will see only the Base portion of d.
In particular, b does not see overriden function Derived::getName(), but only base function Base::getName()

SOLUTION: avoid object slicing. Make b a Base reference to the Derived d object.
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
	Base& b{ d }; // b is now a Base reference to d
	std::cout << b.getName() << '\n';

	return 0;
}