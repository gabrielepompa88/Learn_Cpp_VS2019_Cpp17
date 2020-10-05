#include <iostream>
#include <stdexcept>

class MyDoubles
{
	double m_num{-1.0};

public:

	// default constructor
	MyDoubles()
	{
		std::cout << "MyDoubles(" << *this << ") default constructor called\n";
	}

	// standard constructor
	MyDoubles(double num) : m_num{ num }
	{
		std::cout << "MyDoubles(" << *this << ") standard constructor called\n";
	}

	// copy constructor
	MyDoubles(const MyDoubles &d) : m_num{ d.m_num }
	{
		std::cout << "MyDoubles(" << *this << ") copy constructor called\n";
	}

	// destructor
	~MyDoubles()
	{
		std::cout << "~MyDoubles(" << *this << ") destructor called\n";
	}

	// assignment operator overloaded
	MyDoubles& operator= (const MyDoubles& d)
	{
		std::cout << "MyDoubles(" << *this << ") = MyDoubles(" << d << ") overloaded operator= called\n";

		//self-assignment check
		if (this == &d)
			return *this;

		this->m_num = d.m_num;
		return *this;
	}

	// division operator overloaded
	friend MyDoubles operator/ (const MyDoubles& a, const MyDoubles& b);

	// comparison MyDoubles <= double operator overloaded
	friend bool operator<= (const MyDoubles& a, double b);

	// output operator overloaded
	friend std::ostream& operator<< (std::ostream& out, const MyDoubles& d);

	// input operator overloaded
	friend std::istream& operator>> (std::istream& in, MyDoubles& d);
};


MyDoubles operator/ (const MyDoubles& a, const MyDoubles& b)
{
	std::cout << "start MyDoubles(" << a << ") / MyDoubles(" << b << ") overloaded operator/ called\n";

	// verbose to serparate initialization of 'd' from return statement
	MyDoubles d{ MyDoubles(a.m_num / b.m_num) }; // standard constructor called

	std::cout << "end MyDoubles(" << a << ") / MyDoubles(" << b << ") --> MyDoubles(" << d << ") overloaded operator/ called\n";

	return d; // copy constructor called
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

		std::cout << "start Fraction constructor called\n";

		// check positive denominator
		if (m_denominator <= 0)
			throw std::runtime_error("Invalid denominator.");

		// define the fraction
		m_fraction = m_numerator / m_denominator;

		std::cout << "end Fraction(" << *this << ") constructor called\n";
	}

	~Fraction()
	{
		std::cout << "~Fraction(" << *this << ") destructor called\n";
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

	std::cout << "Start of main()\n";

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

	MyDoubles x1{};
	std::cout << "Numerator: MyDoubles x = ";
	std::cin >> x1;

	MyDoubles y1{};
	std::cout << "Denominator: MyDoubles y = ";
	std::cin >> y1;

	try
	{
		Fraction<MyDoubles> fraction(x1, y1);
		std::cout << "Fraction: x/y = " << fraction << "\n";
	} // fraction goes out-of scope here, calling three times ~MyDoubles
	catch (std::runtime_error& exception)
	{
		std::cout << "std::runtime_error catched: " << exception.what() << "\n";
	}
	catch (std::exception& exception)
	{
		std::cout << "std::exception catched: " << exception.what() << "\n";
	}

	std::cout << "End of main()\n";

	return 0;
}

/*

1) OUTPUT if VALID INPUT (user sets x=2, y=3)

Start of main()
MyDoubles(-1) default constructor called
Numerator: MyDoubles x = 2
MyDoubles(-1) default constructor called
Denominator: MyDoubles y = 3
MyDoubles(2) copy constructor called
MyDoubles(3) copy constructor called
MyDoubles(-1) default constructor called
start Fraction constructor called
start MyDoubles(2) / MyDoubles(3) overloaded operator/ called
MyDoubles(0.666667) standard constructor called
end MyDoubles(2) / MyDoubles(3) --> MyDoubles(0.666667) overloaded operator/ called
MyDoubles(0.666667) copy constructor called
~MyDoubles(0.666667) destructor called
MyDoubles(-1) = MyDoubles(0.666667) overloaded operator= called
~MyDoubles(0.666667) destructor called
end Fraction(2/3 = 0.666667) constructor called
Fraction: x/y = 2/3 = 0.666667
~Fraction(2/3 = 0.666667) destructor called
~MyDoubles(0.666667) destructor called
~MyDoubles(3) destructor called
~MyDoubles(2) destructor called
End of main()
~MyDoubles(3) destructor called
~MyDoubles(2) destructor called

C:\Users\gabri\source\repos\Learn_Cpp_VS2019_Cpp17\Chap_14__Exceptions\Debug\Quiz_1_templated.exe (process 15084) exited with code 0.
Press any key to close this window . . .


2) OUTPUT if INVALID INPUT (user sets x=2, y=0)

Start of main()
MyDoubles(-1) default constructor called
Numerator: MyDoubles x = 2
MyDoubles(-1) default constructor called
Denominator: MyDoubles y = 0
MyDoubles(2) copy constructor called
MyDoubles(0) copy constructor called
MyDoubles(-1) default constructor called
start Fraction constructor called
~MyDoubles(-1) destructor called
~MyDoubles(0) destructor called
~MyDoubles(2) destructor called
std::runtime_error catched: Invalid denominator.
End of main()
~MyDoubles(0) destructor called
~MyDoubles(2) destructor called

C:\Users\gabri\source\repos\Learn_Cpp_VS2019_Cpp17\Chap_14__Exceptions\Debug\Quiz_1_templated.exe (process 10468) exited with code 0.
Press any key to close this window . . .

*/