#include <iostream>
#include "mystring.h"
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif


using namespace std;

void show_array(mystring& str);
void mainmenu_prompt();
void details(mystring& str);
void enable_textcolor();

void insert_func(mystring& str);
void delete_func(mystring& str);
void reponechar_func(mystring& str);
void repallchar_func(mystring& str);
void repstr_func(mystring& str);
void searchchar_func(mystring str);
void countchar_func(mystring str);
void searchstr_func(mystring str);
void comparestr_func(mystring str);
void changestr_func(mystring& str);

bool is_compare;
bool is_old;
string lastused;
mystring comparest;
mystring oldst;
mystring error = "None";
size_t start_index;

int main(){
	enable_textcolor();
	mystring str("Demo");
//	str.reserve(10);
	do{
		string choice;
		show_array(str);
		details(str);
		mainmenu_prompt();	
		cin >> choice;
		
		cout << endl;
		error = "None";
		
		if(choice == "1"){
			insert_func(str);
		} else if(choice == "2"){
			delete_func(str);
		} else if(choice == "3"){
			reponechar_func(str);
		} else if(choice == "4"){
			repallchar_func(str);
		} else if(choice == "5"){
			repstr_func(str);
		} else if(choice == "6"){
			searchchar_func(str);
		} else if(choice == "7"){
			countchar_func(str);
		} else if(choice == "8"){
			searchstr_func(str);
		} else if(choice == "9"){
			comparestr_func(str);
		} else if(choice == "A"){
			changestr_func(str);
		}
		else{
			break;
		}
		system("cls");
	} while(true);
	
	return 0;
}

void insert_func(mystring& str){
	mystring inserted;
	char zeroth = str[0];
	std::size_t indx;
	oldst = str;
	
	cout << "Index (The 0th index is '" << zeroth << "'): ";
	cin >> indx;
	
	cout << "Input the char or string after \"";
	for(size_t i = 0; i < indx; ++i){
		cout << str[i];
	}
	cout << "\": ";
	cin.ignore();
	getline(cin, inserted);
	
	str.insert(indx, inserted);
	lastused = "1";
	comparest = inserted;
	start_index = indx;
}

void delete_func(mystring& str){
	mystring substr;
	oldst = str;
	
	cout << "Input the substring you want to delete: ";
	cin >> substr;
	
	size_t find_index = str.search_string(substr);
	if(find_index != -1){
		str.del(substr);
	} else{
		error = "Substring not found.";
	}
	start_index = find_index;
	comparest = substr;
	lastused = "2";
}

void reponechar_func(mystring& str){
	int intdex;
	cout << "Index: ";
	cin >> intdex;
	std::size_t indx = intdex;
	
	char chr;
	cout << "Character: ";
	cin >> chr;
	
	str.replace_char(indx, chr);
}

void repallchar_func(mystring& str){
	char target;
	cout << "Target Character: ";
	cin >> target;
		
	char source;
	cout << "Source Character: ";
	cin >> source;
	
	str.replace_allchar(target, source);
}

void repstr_func(mystring& str){
	mystring target;
	cout << "Target Character: ";
	cin >> target;
		
	mystring source;
	cout << "Source Character: ";
	cin >> source;
	
	str.replace_string(target, source);
}

void searchchar_func(mystring str){
	char chr;
	cout << "Character: ";
	cin >> chr;
	
	std::size_t result = str.search_char(chr);
	if(result == -1){
		cout << "There are no result" << endl;
	} else{
		cout << chr << " is in the " << result << " index." << endl;
	}
}

void countchar_func(mystring str){
	char chr;
	cout << "Character: ";
	cin >> chr;
	
	int result = str.count_char(chr);
	if(result == 0){
		cout << "There are no " << chr << " in the string" << endl;
	} else{
		cout << "There are " << result << " " << chr << " in the string" << endl;
	}
}

void searchstr_func(mystring str){
	mystring source;
	cout << "String: ";
	cin >> source;
	
	std::size_t result = str.search_string(source);
	if(result == -1){
		cout << "There are no result" << endl;
	} else{
		cout << source << " starts in the " << result << " index." << endl;
	}
}

//void comparestr_func(mystring str){
//	mystring inpt;
//	mystring operation = "\0";
//	cout << "Input a string: ";
//	cin >> inpt;
//	
//	do{
//		cout << str << " __ " << inpt << endl;
//		cout << "Input a operator to compare those two (==, !=, >=, <=, >, <): ";
//		cin >> operation;
//		if(operation != "\0"){
//			
//			cout << "\r"; // Move cursor back to the beginning of the line
//            for (size_t i = 0; i < 62 + inpt.length() + operation.length() + 4; ++i) {
//                cout << " "; // Overwrite with spaces
//            }
//            cout << "\r"; // Move cursor back to the beginning again
//			
////			for(size_t i = 0; i < 62 + inpt.length() + operation.length() + 4; ++i){
////					cout << "\b";
////			}
//			cout << operation << " " << inpt << " = ";
//			
//			if(operation == "==" || operation == "="){
//				if(str == inpt){
//					cout << "True" << endl;
//				} else{
//					cout << "False" << endl;
//				}
//			} else if(operation == "!="){
//				if(str != inpt){
//					cout << "True" << endl;
//				} else{
//					cout << "False" << endl;
//				}
//			} else if(operation == ">="){
//				if(str >= inpt){
//					cout << "True" << endl;
//				} else{
//					cout << "False" << endl;
//				}
//			} else if(operation == "<="){
//				if(str <= inpt){
//					cout << "True" << endl;
//				} else{
//					cout << "False" << endl;
//				}
//			} else if(operation == ">"){
//				if(str > inpt){
//					cout << "True" << endl;
//				} else{
//					cout << "False" << endl;
//				}
//			} else if(operation == "<"){
//				if(str < inpt){
//					cout << "True" << endl;
//				} else{
//					cout << "False" << endl;
//				}
//			} else if(operation == "0"){
//				break;
//			} else {
//				cout << "Not in choices." << endl;
//			}
//		}
//	} while(true);
//}

void comparestr_func(mystring str) {
    mystring inpt;
    mystring operation = "\0";
    cout << "Input a string: ";
    cin >> inpt;

    do {
        cout << str << " __ " << inpt << endl;
        cout << "Input an operator to compare those two (==, !=, >=, <=, >, <): ";
        cin >> operation;

        if (operation != "\0") {
            // ANSI escape code to move cursor up one line and clear the line
            cout << "\033[A\33[2K";  // Move cursor up and clear the line

            cout << operation << " " << inpt << " = ";

            if (operation == "==" || operation == "=") {
                cout << (str == inpt ? "True" : "False") << endl;
            } else if (operation == "!=") {
                cout << (str != inpt ? "True" : "False") << endl;
            } else if (operation == ">=") {
                cout << (str >= inpt ? "True" : "False") << endl;
            } else if (operation == "<=") {
                cout << (str <= inpt ? "True" : "False") << endl;
            } else if (operation == ">") {
                cout << (str > inpt ? "True" : "False") << endl;
            } else if (operation == "<") {
                cout << (str < inpt ? "True" : "False") << endl;
            } else if (operation == "0") {
                break;
            } else {
                cout << "Not in choices." << endl;
            }
        }
    } while (true);
}

void changestr_func(mystring& str){
	mystring input;
	cout << "New string: ";
	cin.ignore();
	getline(cin, input);
	str = input;
}

void mainmenu_prompt(){
	string dg = "\033[95m";
	string re = "\033[0m";
	
	cout << endl << endl;
	
	cout << "[1] " << dg << "INSERT" << re << ": Insert a string at a given position in another string."<< endl;
	cout << "[2] " << dg << "DELETE" << re << ": Delete a portion of a string."<< endl;
	cout << "[3] " << dg << "REPLACE SINGLE CHARACTER" << re << ": Replace the specified single character in a string with a new character." << endl;
	cout << "[4] " << dg << "REPLACE ALL CHARACTER" << re << ": Replace all specified characters in a string with a new character." << endl;
	cout << "[5] " << dg << "REPLACE STRING" << re << ": Replace a portion of a string with another string" << endl;
	cout << "[6] " << dg << "SEARCH CHARACTER" << re << ": Searches a string for the first occurrence of a specified character." << endl;
	cout << "[7] " << dg << "COUNT CHARACTER" << re << ": Counts the number of occurrences of a specified character in a string." << endl;
	cout << "[8] " << dg << "SEARCH STRING" << re << ": Searches through a string for an occurrence of some smaller string." << endl;
	cout << "[9] " << dg << "COMPARE STRING" << re << ": Compare the string to a new inputted string." << endl;
	cout << "[A] " << dg << "CHANGE STRING" << re << ": Using assignment operator, replace all characters of the string" << endl << endl;
	cout << "Choose the action you want to do: ";
}

void details(mystring& str){
	string re = "\033[0m";
	string lr = "\033[91m";
	string lb = "\033[94m";
	
	cout << "----------------------------------------------" << endl;
	cout << "String Form: \"" << str << "\"" << endl;
	cout << "Number of Valid Characters: " << str.length() << " (including the " << lb << "\\0" << re << ")" << endl;
	cout << "Number of Allocated Space: " << str.get_allocated() << endl;
	cout << "Index of the " << lb << "\\0" << re << ": " << str.length() - 1 << endl;
	cout << "----------------------------------------------" << endl;
}

void show_array(mystring& str){
	int extra;
	string re = "\033[0m";
	string lr = "\033[91m";
	string lb = "\033[94m";
	string lc = "\033[96m";
	
	string coma = ", ";
	
	cout << "[";
	
	for(int i=0; i< str.get_allocated(); i++){
		if(str[i] == '\0'){
			extra = str.get_allocated() - i - 1;
			cout << lb << "\\0" << re << coma;
			break;
		} else{
			cout << str[i] << ", ";
		}
	}
	
	if (extra > 0) {
 	   for (int i = 0; i < extra; i++) {
 	       if (i == extra - 1) {
 	           coma = "]";
 	       }
 	       cout << lr << "X" << re << coma;
 	   }
	} else {
	    cout << "]";
}

	cout << endl << endl;
}

void enable_textcolor(){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
