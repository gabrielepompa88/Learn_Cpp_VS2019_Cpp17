#include <iostream>
#include <string>

class Fruit {

	std::string m_name{};
	std::string m_color{};

public:

	Fruit(std::string name, std::string color)
		: m_name{ name }, m_color{ color } {}

	friend std::ostream& operator<< (std::ostream& out, const Fruit& fruit);
};

std::ostream& operator<< (std::ostream& out, const Fruit& fruit)
{
	return out << "Fruit of name " << fruit.m_name << " and " << fruit.m_color << " color.";
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
	out << "Apple of fiber " << apple.m_fiber << " that 'is a' ";
	out << static_cast<Fruit>(apple);
	return out;

}

class GrannySmith : public Apple {

	std::string m_quality{};

public:

	GrannySmith(std::string name, std::string color, double fiber, std::string quality) 
		: Apple(name, color, fiber), m_quality{quality} {}

	friend std::ostream& operator<< (std::ostream& out, const GrannySmith& grannySmith);

};

std::ostream& operator<< (std::ostream& out, const GrannySmith& grannySmith)
{
	out << "GrannySmith of " << grannySmith.m_quality <<" quality that 'is a' ";
	out << static_cast<Apple>(grannySmith);
	return out;

}

int main()
{
	const Fruit f{ "Red delicious", "red" };
	std::cout << f << "\n\n";

	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << "\n\n";

	const GrannySmith g{ "Red delicious", "red", 4.2 , "very good"};
	std::cout << g << "\n\n";

	return 0;
}