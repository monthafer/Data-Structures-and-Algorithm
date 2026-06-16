#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
	public:
		//Constructors
		Point();
		Point(const Point&P);
		Point(double consx, double consy);
		
		void operator = (const Point&P);
		Point operator ++(int i = 1);
		
		void setValue(double newx, double newy);
		
		double getx()const;
		double gety()const;
		
		double getDist(const Point&P);

		friend std::istream& operator >>(std::istream& ins, Point& target);
		
	private:
		double x,y;
};
	
//	Point operator ++(const Point& P);
	Point operator *(const Point& P, double c);

	std::ostream& operator <<(std::ostream & outs, const Point& source);

#include "Point.cpp"
#endif
