#ifndef POINT1_CPP

#include <cmath>
#include <iostream>

Point::Point()
{
	x=0;
	y=0;
}

Point::Point(double initial_x = 0.0, double initial_y = 0.0)
{
	x = initial_x;
	y = initial_y;
}

Point::Point(const Point&P)
{
	x=P.x;
	y=P.y;
}

void Point::operator = (const Point&P)
{
	x=P.x;
	y=P.y;
}

void Point::setValue(double newx, double newy)
{
	x=newx;
	y=newy;
}

double Point::getx()const
{
	return x;
}

double Point::gety()const
{
	return y;
}

double Point::getDist(const Point&P)
{
	double a = P.x - x; // Difference in x coordinates
	double b = P.y - y; // Difference in y coordinates
	double c_squared = a*a + b*b;
	
	return sqrt(c_squared);
	
//	return ((P.x - x)**2 + (P.y - y)**2)**0.5
}

Point Point::operator * (double c)
{
	double newx = x * c;
	double newy = y * c;
	Point multiplied(newx, newy);
	return multiplied;
}

Point Point::operator ++()
{
	double newx = x + 1;
	double newy = y + 1;
	Point increment(newx, newy);
	return increment;
}

//std::istream& operator >>(std::istream& ins, point& target){
//	
//}

#endif
