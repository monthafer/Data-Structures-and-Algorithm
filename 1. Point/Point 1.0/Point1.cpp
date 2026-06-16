#ifndef POINT1_CPP

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

void Point::operator = (const Point&P)
{
	x=P.x;
	y=P.y;
}

void Point::setValue(int newx, int newy)
{
	x=newx;
	y=newy;
}

int Point::getx()const
{
	return x;
}

int Point::gety()const
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

//void Point::operator * (const Point&P, int c){
//	
//	Point multiplied();
//}
//
//void Point::operator ++ (const Point&P){
//	
//}
//
//std::istream& operator >>(std::istream& ins, point& target){
//	
//}

#endif
