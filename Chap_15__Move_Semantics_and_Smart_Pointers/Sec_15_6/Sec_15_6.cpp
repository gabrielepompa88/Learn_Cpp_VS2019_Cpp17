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
	//std::shared_ptr<Fraction> ptr1{ new Fraction(3, 5) };
	auto ptr1{ std::make_shared<Fraction>(3,5) };
	std::shared_ptr<Fraction> ptr2;	// Start as nullptr

	std::cout << "ptr1 is " << (static_cast<bool>(ptr1) ? "not null\n" : "is null\n");
	std::cout << "ptr2 is " << (static_cast<bool>(ptr2) ? "not null\n" : "is null\n");

	std::cout << "ptr2 = ptr1 \n";
	ptr2 = ptr1;

	std::cout << "ptr1 is " << (static_cast<bool>(ptr1) ? "not null\n" : "is null\n");
	std::cout << "ptr2 is " << (static_cast<bool>(ptr2) ? "not null\n" : "is null\n");

	std::cout << "ptr1 = nullptr \n";
	ptr1 = nullptr;

	std::cout << "ptr1 is " << (static_cast<bool>(ptr1) ? "not null\n" : "is null\n");
	std::cout << "ptr2 is " << (static_cast<bool>(ptr2) ? "not null\n" : "is null\n");

	return 0;
}