#include <iostream>
#include "Pointheader.h"

int main(){
	
	Point P1(1,5);
	Point P2((P1*5));
	std::cout << P2.getx() << ", " << P2.gety();
	
//	Point P4;
//	P4.setValue(20, 30);
//	P4 = P5;
	
//	int pointofx = P4.getx();
//	
//	Point P5;
//	P5.setValue(10, 50);
//	P5 = P1;
	
//	int pointofx2 = P5.getx();
//	
//	std::cout << pointofx << " " << pointofx2 << "\n";
//	std::cout << P5.getDist(P4);
}
