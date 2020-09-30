#include <iostream>

template<class T>
class Pair1 {

	// private by default
	T m_first;
	T m_second;

public:
	Pair1(const T& first_value, const T& second_value)
		: m_first{ first_value }, m_second{ second_value }
	{
	}

	// this one is implemented inside the templated function
	const T& first() const { return m_first; }

	// this other one is only declared inside...
	const T& second() const;

};

// ...but defined outside, so it neeeds its own template declaration
template<class T>
const T& Pair1<T>::second() const 
{
	return m_second;
}
int main()
{
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}