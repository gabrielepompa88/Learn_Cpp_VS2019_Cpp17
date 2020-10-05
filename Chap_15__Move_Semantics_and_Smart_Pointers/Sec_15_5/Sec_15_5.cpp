#include <iostream>
#include <memory> // for std::unique_ptr

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		std::cout << "Fraction " << *this << " acquired.\n";
	}

	~Fraction()
	{
		std::cout << "Fraction " << *this << " destroyed.\n";
	}

	 

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* const ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
}

int main()
{
	// DUMB POINTER IMPLEMENTATION
	/*
	auto* ptr{ new Fraction{ 3, 5 } };

	printFraction(ptr);

	delete ptr;
	*/

	// UNIQUE POINTER IMPLEMENTATION
	
	//using dumb pointer: auto* ptr{ new Fraction{ 3, 5 } };
	// std::unique_ptr<Fraction> ptr{ new Fraction{ 3, 5 } };
	auto ptr{ std::make_unique<Fraction>(3,5) };

	//using dumb pointer: printFraction(ptr);
	printFraction(ptr.get()); //ptr.get() returns a pointer to the Fraction

	// no explicit delete is needed

	return 0;
}