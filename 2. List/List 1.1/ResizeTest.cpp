#include <iostream>
#include "List2.h"

using namespace std;

int main(){
	string re = "\033[0m";
	string dr = "\033[31m";
	string dg = "\033[32m";
	string db = "\033[34m";
	string dp = "\033[35m";
	string lr = "\033[91m";
	string lg = "\033[92m";
	string lb = "\033[34m";
	string blw = "\033[1;97m";
	
	list L;
	L.insert(4);
	L.insert(1);
	L.insert(3);
	L.insert(-7);
	L.insert(5);
	L.start();
		
	while(true){
		system("cls");
		cout << "----------------------------------------------" << endl;
		cout << "ALL items: ";
		L.show_all();
		
		cout << "\n\n" << "More Details: " << endl;
		L.show_detail();
		cout << "----------------------------------------------";
		
		cout << endl << endl;
		cout << "Select which would you like to do:" << endl << endl;
		cout << "[1] " << db << "Start" << re << ": Set the list index to the beginning" << endl;
		cout << "[2] " << dg << "Advance" << re << ": Move to the next item in the list" << endl;
		cout << "[3] " << lr << "Remove Current" << re << ": Remove the current item" << endl;
		cout << "[4] " << dr << "Empty List" << re << ": Clear all values from the list" << endl;
		cout << "[5] " << blw << "Attach" << re << ": Attach a numeric value after the current item" << endl;
		cout << "[6] " << blw << "Insert" << re << ": Insert a numeric value before the current item" << endl;
		cout << "[0] " << dp << "Exit" << re << ": Just exit, no other meanings" << endl << endl;
		
		cout << "Input: ";
		int choice;
		cin >> choice;
		if (choice == 1){
			L.start();
		} else if(choice == 2){
			L.advance();
		} else if (choice == 3){
			L.remove_current();	
		} else if (choice == 4){
			L.remove_all();
		} else if (choice == 5){
			double val;
			cout << "Enter a value: ";
			cin >> val;
			L.attach(val);
		} else if (choice == 6){
			double val;
			cout << "Enter a value: ";
			cin >> val;
			L.insert(val);
		} else{
			system("cls");
			cout << "alskjdalskjdaslkdj";
			break;
		}
	}
}
