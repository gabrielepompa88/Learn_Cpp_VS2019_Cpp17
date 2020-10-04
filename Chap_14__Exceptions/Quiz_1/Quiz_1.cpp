#include <iostream>
#include <stdexcept>

class Fraction 
{
	double m_numerator{};
	double m_denominator{};
	double m_fraction{};

public:

	Fraction(double numerator, double denominator)
		: m_numerator{ numerator }, m_denominator{denominator}
	{
		// check positive denominator
		if(m_denominator <= 0)
			throw std::runtime_error("Invalid denominator.");

		// define the fraction
		m_fraction = m_numerator / m_denominator;
	}

	friend std::ostream& operator<< (std::ostream& out, const Fraction& f);

};

std::ostream& operator<< (std::ostream& out, const Fraction& f)
{
	return out << "Fraction x/y = " << f.m_numerator << "/" << f.m_denominator << " = " << f.m_fraction;
}

int main() 
{
	std::cout << "Numerator: x = ";
	int x{};
	std::cin >> x;

	std::cout << "Denominator: y = ";
	int y{};
	std::cin >> y;

	try 
	{
		Fraction fraction(x, y);
		std::cout << "Fraction: x/y = " << fraction;
	}
	catch (std::exception& exception) 
	{
		std::cout << "std::exception catched: " << exception.what();
	}

	return 0;
}