#include<iostream>

class Point2d {

	double m_x{ 0.0 };
	double m_y{ 0.0 };

public:

	Point2d() {
		std::cout << "Default constructor called\n";
	}

	// appropriate converting constructor from int to Point2d
	Point2d(const double x, const double y = 0.0): m_x(x), m_y(y){
		std::cout << "Int --> Point2d converting constructor called with (x = " << x << ", y = " << y << ")\n";
	}

	//copy constructor
	Point2d(const Point2d& p) {
		std::cout << "Copy constructor called with " << p << "\n";
		m_x = p.m_x;
		m_y = p.m_y;
	}

	//overloaded operator=
	Point2d& operator=(const Point2d &p) {
		std::cout << "Overloaded operator= called with " << p << "\n";

		//self-assignment check
		if (this == &p)
			return *this;

		m_x = p.m_x;
		m_y = p.m_y;

		return *this;

	}

	//overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Point2d& p) {
		return out << "(p_x=" << p.m_x << ", p_y=" << p.m_y << ")";
	}
};

int main() {

	// This will call the default constructor to initialize p1 as (x1,y1) = (0,0)
	Point2d p1;
	std::cout << "p1: " << p1 << "\n\n";

	// This will call the Int-to-Point2d converting constructor to do 5 --> Point2d(5,0) 
	// and then copy-initialize p2 as (x2,y2) = (5,0), eventually eliding the copy-constructor
	Point2d p2 = 5;
	std::cout << "p2: " << p2 << "\n\n";

	// This will call the copy-constructor to initialize p3 as (x3,y3) = (5,0) from p2
	Point2d p3 = p2;
	std::cout << "p3: " << p3 << "\n\n";

	// This will call the Int-to-Point2d converting constructor to do 7 --> Point2d(7,0) 
	// and then the overloaded operator= to reset p3 (already initialized, thus no need to copy-construct)
	// as (x3,y3) = (7,0)
	p3 = 7;
	std::cout << "p3: " << p3 << "\n\n";

	return 0;
}