#include <iostream>
#include <vector>

class Shape {

public:

	// pure-virtual print function
	virtual std::ostream& print(std::ostream& out) const = 0;

	// overloaded operator<< forward declaration
	friend std::ostream& operator<< (std::ostream& out, const Shape& shape);

	// virtual destructor
	~Shape()
	{
		std::cout << "~Shape() called.\n";
	}
};

std::ostream& operator<< (std::ostream& out, const Shape& shape) {

	return shape.print(out);
}

class Point
{
private:
	int m_x{ 0 };
	int m_y{ 0 };
	int m_z{ 0 };

public:
	Point(int x, int y, int z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
		return out;
	}
};

class Circle : public Shape {

private:
	Point m_center{ 0, 0, 0};
	int m_radius{ 1 };

public:

	Circle(const Point &p, int r) : m_center{ p }, m_radius{ r }
	{
	}

	// override of pure-virtual Shape::print() function
	virtual std::ostream& print(std::ostream& out) const override
	{
		return out << "Circle(" << m_center << ", radius " << m_radius << ")";
	}

	int getRadius() const { return m_radius; }

	// virtual destructor
	~Circle()
	{
		std::cout << "~Circle() called.\n";
	}

};

class Triangle : public Shape {

private:
	Point m_p1{ 1, 0, 0 };
	Point m_p2{ 0, 1, 0 };
	Point m_p3{ 0, 0, 1 };

public:

	Triangle(const Point &p1, const Point &p2, const Point &p3) : m_p1{ p1 }, m_p2{ p2 }, m_p3{ p3 }
	{
	}

	// override of pure-virtual Shape::print() function
	virtual std::ostream& print(std::ostream& out) const override
	{
		return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
	}

	// virtual destructor
	~Triangle()
	{
		std::cout << "~Triangle() called.\n";
	}

};

/*
int main()
{
	Circle c{ Point{ 1, 2, 3 }, 7 };
	std::cout << c << '\n';

	Triangle t{ Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9} };
	std::cout << t << '\n';

	return 0;
}
*/

int getLargestRadius(std::vector<Shape*> &shapes)
{
	int largestRadius{ 0 };

	for (const Shape* shape : shapes) {
	
		const Circle* s = dynamic_cast<const Circle*>(shape);

		if (s) // non-null checking, that is if shape was a Shape pointer to a Circle (and not to a Triangle)
		{
			int s_radius{ s->getRadius() };
			if (s_radius > largestRadius) { largestRadius = s_radius; }
		}
	}

	return largestRadius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{1, 2, 3}, 7},
	  new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
	  new Circle{Point{4, 5, 6}, 30},
	  new Circle{Point{4, 5, 6}, 3}
	};

	// print each shape in vector v on its own line here
	for (const Shape* shape : v)
	{
		std::cout << *shape << "\n";
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; 

	// delete each element in the vector here
	for (const Shape* shape : v)
	{
		delete shape;
	}


	return 0;
}
