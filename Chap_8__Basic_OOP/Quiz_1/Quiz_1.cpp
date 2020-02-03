#include <iostream>
#include <cmath>

class Point2d {

    //non-static variable directly initialized
    double m_x{ 0.0 };
    double m_y{ 0.0 };

public:
        
    //default constructor
    Point2d() = default;

    //additional constructor
    Point2d(double x, double y): m_x{x}, m_y{y}{};

    //const print function
    void print() const;

    // const member function to calculate the distance from the current Point2d
    double distanceTo(const Point2d &otherPoint) const;

    // friend non-member function to calculate the distance between any 2 Point2d
    friend double distanceFrom(const Point2d& p1, const Point2d& p2);

};

void Point2d::print() const 
{
    std::cout << "Point2d(x,y) = (" << m_x << ", " << m_y << ")\n";
}

double Point2d::distanceTo(const Point2d &otherPoint) const 
{
    return std::sqrt((m_x - otherPoint.m_x) * (m_x - otherPoint.m_x) + 
                     (m_y - otherPoint.m_y) * (m_y - otherPoint.m_y));
}

double distanceFrom(const Point2d& p1, const Point2d& p2)
{
    return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) +
                     (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();

    std::cout << "Distance from the first point: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}