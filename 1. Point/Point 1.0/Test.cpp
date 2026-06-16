#include <iostream>
#include "Point1.h"

int main(){
	Point P1, P2;
	Point P3(P2);
	P1 = P3;
	
	Point P4;
	P4.setValue(20, 30);
//	P4 = P5;
	
	int pointofx = P4.getx();
	
	Point P5;
	P5.setValue(10, 50);
//	P5 = P1;
	
	int pointofx2 = P5.getx();
	
	std::cout << pointofx << " " << pointofx2 << "\n";
	std::cout << P5.getDist(P4);
}
