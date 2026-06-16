#ifndef POINT_CPP

#include <cmath>
#include <iostream>


Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(const Point& P)
{
	x = P.x;
	y = P.y;
}

Point::Point(double initial_x = 0.0, double initial_y = 0.0)
{
//	set_x(initial_x);
//	set_y(initial_y);
	x = initial_x;
	y = initial_y;
}

void Point::operator = (const Point&P)
{
	set_x(P.x);
	set_y(P.y);
//	x=P.x;
//	y=P.y;
}

std::istream& operator >>(std::istream& ins, Point& target)
{
	ins >> target.x >> target.y;
	return ins;
}

Point operator * (const Point& P, double c)
{
	double newx = P.get_x() * c;
	double newy = P.get_y() * c;
	Point multiplied(newx, newy);
	return multiplied;
}

Point operator ++(const Point& P)
{
	double newx = P.get_x() + 1;
	double newy = P.get_y() + 1;
	Point increment(newx, newy);
	return increment;
}

std::ostream& operator <<(std::ostream& outs, const Point& source)
{
	outs << source.get_x( ) << " " << source.get_y( );
	return outs;
}

#endif
