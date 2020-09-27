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

	virtual const char* getName() = 0;
};

const char* Derived::getName()
{
	return "Derived";
}

int main()
{
	Derived d{5};
	Base &b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}
 
PROBLEM: Derived::getName() is a 'pure virtual' function (even if it has a body), making Derived an 'abstract' class.
Therefore Derived object d cannot be instantiated in the first place.

SOLUTION: probably it makes more sense to make Base::getName() pure virtual with a body that guarantees default behavior.

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

	virtual const char* getName() = 0;
};

const char* Base::getName()
{
	// body of pure-virtual function
	return "Base";
}

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() override 
	{ 
		std::cout << "Derived::getName() returns: ";
		return "Derived"; 
	}

};

class OtherDer : public Base
{
public: 
	OtherDer(int value)
		: Base(value) 
	{
	}

	virtual const char* getName() override
	{
		std::cout << "OtherDer::getName() returns: ";
		return Base::getName();
	}
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	OtherDer d1{ 7 };
	Base& b1{ d1 };
	std::cout << b1.getName() << '\n';

	return 0;
}