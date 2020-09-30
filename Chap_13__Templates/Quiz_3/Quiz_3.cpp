
#include <iostream>
#include <string>

template<class T1, class T2>
class Pair {

	// private by default
	T1 m_first;
	T2 m_second;

public:
	Pair(const T1& first_value, const T2& second_value)
		: m_first{ first_value }, m_second{ second_value }
	{
	}

	// this one is implemented inside the templated function
	const T1& first() const { return m_first; }

	// this other one is only declared inside...
	const T2& second() const;

};

// ...but defined outside, so it neeeds its own template declaration
template<class T1, class T2>
const T2& Pair<T1, T2>::second() const
{
	return m_second;
}

template<class T2>
class StringValuePair : public Pair<std::string, T2>
{
public:
	StringValuePair(const std::string &s, const T2& second_value)
		: Pair<std::string, T2>{ s, second_value }
	{
	}
};

int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}