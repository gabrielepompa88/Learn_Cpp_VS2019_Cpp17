/*
GOAL: same as Quiz_3, but now the member function first() 
has to return the number of chars in the string (instead of its content)

*/

#include <iostream>
#include <string>


template<class T1, class T2>
class Pair_Base {

protected:
	T1 m_first;
	T2 m_second;

public:
	Pair_Base(const T1& first_value, const T2& second_value)
		: m_first{ first_value }, m_second{ second_value }
	{
	}

	// this one is implemented inside the templated function
	const T1& first() const { return m_first; }

	// this other one is only declared inside...
	const T2& second() const;

	// virtual destructor added
	//virtual ~Pair_Base() {}

};

// ...but defined outside, so it neeeds its own template declaration
template<class T1, class T2>
const T2& Pair_Base<T1, T2>::second() const
{
	return m_second;
}

template<class T1, class T2>
class Pair : public Pair_Base<T1, T2>
{
public:

	Pair(const T1& first_value, const T2& second_value)
		: Pair_Base<T1,T2>(first_value, second_value)
	{
	}


};

template<class T2>
class Pair<std::string, T2> : public Pair_Base<std::string, T2>
{
public:
	Pair(const std::string& s, const T2& second_value)
		: Pair_Base<std::string, T2>(s, second_value)
	{
	}

	// this overloaded version is implemented outside
	int first() const;
};

// notice that this is not a partially-specialized function, which wouldn't be allowed.
// This is the template declaration of a member function of Pair<std::string, T2>
template<class T2>
int Pair<std::string, T2>::first() const {
	// this is necessary https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members
	// because 'm_first' is a 'nondependent name' that the compiler wouldn't look at.
	return (this->m_first).length();
}

int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<std::string, int> svp("Four", 5);
	std::cout << "Pair: " << svp.first() << " chars in string - " << svp.second() << '\n';

	return 0;
}