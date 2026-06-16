#ifndef POINT1_H
#include <iostream>

class Point
{
	public:
		//Constructor
		Point();
		Point(double initial_x = 0.0, double initial_y = 0.0);
		Point(const Point&P);
		void operator = (const Point&P);
		void setValue(double newx, double newy);
		double getx()const;
		double gety()const;
		double getDist(const Point&P);
		Point operator * (double c);
		Point operator ++();
//		friend std::istream& operator >>(std::istream& ins, point& target);
//		friend std::ostream& operator <<(std::ostream& outs, point& target);
	private:
		double x,y;
};



#include "Pointheader.cpp"
#endif
