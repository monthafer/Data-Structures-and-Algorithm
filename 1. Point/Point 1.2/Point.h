#ifndef POINT_H
#include <iostream>

class Point
{
	public:
		// CONSTRUCTOR
//		Point(const Point&P);
		Point();
		Point(const Point&P);
		Point(double initial_x = 0.0, double initial_y = 0.0);
		void set_x(double xx) {
			x = xx;
		}
		void set_y(double yy) {
			y = yy;
		}
		// CONSTANT MEMBER FUNCTIONS
		double get_x( ) const { return x; } 
		double get_y( ) const { return y; }
		
		void operator = (const Point&P);
		
		friend std::istream& operator >>(std::istream& ins, Point& target);
		
	private:
		double x,y;
};

//	double distance(const Point& p1, const Point& p2);
	Point operator ++(const Point& P);
	Point operator *(const Point& P, double c);
//	point middle(const point& p1, const point& p2);
//	point operator +(const point& p1, const point& p2);
//	bool operator ==(const point& p1, const point& p2);
//	bool operator !=(const point& p1, const point& p2);
	std::ostream& operator <<(std::ostream & outs, const Point& source);

#include "Point.cpp"
#endif
