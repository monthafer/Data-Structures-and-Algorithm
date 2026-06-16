#include "Point.h"

#include <cmath>

Point::Point()
{
	x=0;
	y=0;
}

Point::Point(const Point&P)
{
	x=P.x;
	y=P.y;
}

Point::Point(double consx, double consy)
{
	x=consx;
	y=consy;
}

void Point::operator = (const Point&P)
{
	x=P.x;
	y=P.y;
}

Point Point::operator ++(int i = 1)
{
	double nnx = x + 1 + i;
	double nny = y + 1 + i;
	return Point(nnx,nny);
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

//Point& operator ++(const Point& P)
//{
//	Point newP(P.getx() + 1, P.gety() + 2);
//	return newP;
////	newP.setValue(P.x + 1, P.y + 2)
//}

Point operator * (const Point& P, double c)
{
	double newx = P.getx() * c;
	double newy = P.gety() * c;
	Point multiplied(newx, newy);
	return multiplied;
}

std::ostream& operator<<(std::ostream &outs, const Point &source)
{
//	outs << "The value of x is " << source.getx() << " and y is " << source.gety();
	outs << "(" << source.getx() << ", " << source.gety() << ")";
	return outs;
}

std::istream& operator>>(std::istream& ins, Point& target)
{
	double x, y;
	ins >> x >> y;
	target.setValue(x, y);
	return ins;
}
