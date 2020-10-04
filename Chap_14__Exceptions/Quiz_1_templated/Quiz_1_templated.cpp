#include <iostream>
#include <stdexcept>

class MyDoubles
{
	double m_num{17};

public:

	MyDoubles() = default;

	MyDoubles(double num) : m_num{ num } {}

	~MyDoubles()
	{
		std::cout << "~MyDoubles(" << *this << ") called\n";
	}

	friend MyDoubles operator/ (const MyDoubles& a, const MyDoubles& b);

	friend bool operator<= (const MyDoubles& a, double b);

	friend std::ostream& operator<< (std::ostream& out, const MyDoubles& d);

	friend std::istream& operator>> (std::istream& in, MyDoubles& d);
};


MyDoubles operator/ (const MyDoubles& a, const MyDoubles& b)
{
	return MyDoubles(a.m_num / b.m_num);
}


bool operator<= (const MyDoubles& a, double b)
{
	return a.m_num <= b;
}

std::ostream& operator<< (std::ostream& out, const MyDoubles& d)
{
	return out << d.m_num;
}

std::istream& operator>> (std::istream& in, MyDoubles& d)
{
	return in >> d.m_num;
}

template<class T>
class Fraction
{
	T m_numerator{};
	T m_denominator{};
	T m_fraction{};

public:

	Fraction(T& numerator, T& denominator)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		// check positive denominator
		if (m_denominator <= 0)
			throw std::runtime_error("Invalid denominator.");

		// define the fraction: here an exception will be thrown if class T doesn't implement operator/
		m_fraction = m_numerator / m_denominator;
	}

	/*
	// this operator<< is friend of Fraction<T> only
	friend std::ostream& operator<< (std::ostream& out, const Fraction& f)
	{
		return out << f.m_numerator << "/" << f.m_denominator << " = " << f.m_fraction;
	}
	*/

	template <class T>
	friend std::ostream& operator<< (std::ostream& out, const Fraction<T>& f);

};


template<class T>
std::ostream& operator<< (std::ostream& out, const Fraction<T>& f)
{
	return out << f.m_numerator << "/" << f.m_denominator << " = " << f.m_fraction;
}


int main()
{
	/*

	std::cout << "Numerator: x = ";
	double x{};
	std::cin >> x;

	std::cout << "Denominator: y = ";
	double y{};
	std::cin >> y;

	try
	{
		Fraction<double> fraction(x, y);
		std::cout << "Fraction: x/y = " << fraction << "\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "std::exception catched: " << exception.what() << "\n";
	}

	*/

	std::cout << "Numerator: MyDoubles x = ";
	MyDoubles x1{-111};
	std::cin >> x1;

	std::cout << "Denominator: MyDoubles y = ";
	MyDoubles y1{-112};
	std::cin >> y1;

	try
	{
		Fraction<MyDoubles> fraction(x1, y1);
		std::cout << "Fraction: x/y = " << fraction << "\n";
	}
	catch (std::runtime_error& exception)
	{
		std::cout << "std::runtime_error catched: " << exception.what() << "\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "std::exception catched: " << exception.what() << "\n";
	}


	return 0;
}