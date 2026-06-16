#ifndef POINT1_H

class Point
{
	public:
		//Constructor
		Point();
		Point(const Point&P);
		
		void operator = (const Point&P);
		void setValue(int newx, int newy);
		int getx()const;
		int gety()const;
		double getDist(const Point&P);
//		void operator * (const Point&P, int c);
//		void operator ++ (const Point&P);
//		friend std::istream& operator >>(std::istream& ins, point& target);
//		friend std::ostream& operator <<(std::ostream& outs, point& target);
	private:
		int x,y;
};



#include "Point1.cpp"
#endif
