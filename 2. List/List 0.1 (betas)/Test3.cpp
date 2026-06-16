#include <iostream>
#include "List.h"

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
		cout << "    ALL items: ";
		L.show_all();
		
		cout << "\nCURRENT items: ";
		L.show_item();
		
		cout << "\n\n" << "More Details: " << endl;
		L.show_detail();
		cout << "----------------------------------------------";
		
		cout << endl << endl;
		cout << "Select which would you like to do:" << endl << endl;
		cout << "[1] " << db << "Start" << re << ": Set the list index to 0" << endl;
		cout << "[2] " << dg << "Advance" << re << ": Add 1 to the list index" << endl;
		cout << "[3] " << lr << "Remove Current" << re << ": Remove the current index value" << endl;
		cout << "[4] " << dr << "Remove All" << re << ": Remove all values from the list" << endl;
		cout << "[5] " << blw << "Attach" << re << ": Attach a numeric value to the list" << endl;
		cout << "[6] " << blw << "Insert" << re << ": Insert a numeric value into the list" << endl;
		cout << "[0] " << dp << "Exit" << re << ": IDK what this does" << endl << endl;
		
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
