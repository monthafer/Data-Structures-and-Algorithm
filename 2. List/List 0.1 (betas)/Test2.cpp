#include <iostream>
#include "List.h"

using namespace std;

int main(){
	list L;
	L.attach(9);
	L.attach(2);
	L.attach(0);
	L.attach(3);
	system("cls");
	
	cout << L.current() << endl;
//	for (L.start(); L.is_item(); L.advance()) {
//        cout << L.current() << " ";
//    }
	
//	cout << L.is_item() << endl;
	
	L.start();
	cout << L.current() << endl;
	L.advance();
	cout << L.current() << endl;
//	for (L.start(); L.is_item(); L.advance()) {
//        cout << L.current() << " ";
//    }
	
	L.remove_current();
	cout << L.current() << endl;
	L.attach(76);
	cout << L.current() << endl;
	L.start();
	L.show();
	L.show_detail();
}
