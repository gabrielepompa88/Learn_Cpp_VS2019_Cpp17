#include <iostream>
#include <string>

class Fruit {

protected:

	// made these memebers protected to be able to call them from Apple and Banana 
	//(in theri operator<<) but still hide them from main()
	std::string m_name{};
	std::string m_color{};

public: 

	Fruit(std::string name, std::string color)
		: m_name{ name }, m_color{ color } {}

	friend std::ostream& operator<< (std::ostream& out, const Fruit& fruit);
};

std::ostream& operator<< (std::ostream& out, const Fruit& fruit) 
{
	return out << "is a Fruit.\n";
}

class Apple : public Fruit {

	double m_fiber{};

public:

	Apple(std::string name, std::string color, double fiber)
		: Fruit(name, color), m_fiber{ fiber }{}

	friend std::ostream& operator<< (std::ostream& out, const Apple& apple);

};

std::ostream& operator<< (std::ostream& out, const Apple& apple)
{
	out << "An Apple (" << apple.m_name << ", " << apple.m_color << ", " << apple.m_fiber << ") ";
	out << static_cast<Fruit>(apple);
	return out;

}

class Banana : public Fruit {

public: 

	Banana(std::string name, std::string color) : Fruit(name, color) {}

	friend std::ostream& operator<< (std::ostream& out, const Banana& banana);

};

std::ostream& operator<< (std::ostream& out, const Banana& banana)
{
	out << "A Banana (" << banana.m_name << ", " << banana.m_color << ") ";
	out << static_cast<Fruit>(banana);
	return out;

}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}