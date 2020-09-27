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

	virtual const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{5};
	Base &b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}

PROBLEM: Derived::getName() is declared 'const', wherease Base::getName() is non-const. Therefore, 
Derived::getName() is not an override of Base::getName(), even if the program compiles. 

SOLUTION: make also Base::getName() const. Anyway, this situation (compilation ok, execution wrong) 
can be avoided using the 'override' keyword when declaring Derived::getName(), which would make the compiler
check for overriding, which would fail and then raising error:

"member function declared with 'override' does not ovveride a base class member"

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

	virtual const char* getName() const { return "Base"; } // now 'const'
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() const override { return "Derived"; } // 'override' added for safety check
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}