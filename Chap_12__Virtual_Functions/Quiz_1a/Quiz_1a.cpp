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

	const char* getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{value}
	{
	}

	const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{5};
	Base &b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}

PROBLEM: b is a Base reference to the Derive object d, therefore it can see only the Base portion of
Derived object, thus b.getName() resolves to Base::getName() and not to Derived::getName()

SOLUTION: make getName() virtual.
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

	virtual const char* getName() const { return "Base"; } // now virtual
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() const override { return "Derived"; } // override of Base::getName()
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}
