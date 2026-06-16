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
void deletechar_func(mystring& str);
void deleteallchar_func(mystring& str);	
void deletestr_func(mystring& str);
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
bool forcompare = false; // inputted a string (used only in B)
char lastused;	 		// function last used (used: all func)
mystring comparest; 	// substring (used: 1, 2, 8)
mystring newcomparest;	// substring new (used: 5)
char comparech; 		// char old (used: 4, 6, 7)
char newcomparech; 		// char new (used: 4)
mystring oldst; 		// oldstring (used: all except func w/t &)
mystring error = "None"; // show error (used: all func except 7)
size_t start_index; 	// for identify old substring/char 's indx (used: 1, 2, 3, 6, 8)
int forcount;			// special case for count func (used only in 7)

int main(){
	enable_textcolor();
	mystring str("Demo");
	do{
		string choice;
		show_array(str);
		details(str);
		mainmenu_prompt();
		
		error = "None";
		lastused = ' ';
		cin >> choice;
		cout << endl;
		
		if(choice == "1"){
			insert_func(str);
		} else if(choice == "2"){
			deletechar_func(str);
		} else if(choice == "3"){
			deleteallchar_func(str);
		} else if(choice == "4"){
			deletestr_func(str);
		} else if(choice == "5"){
			reponechar_func(str);
		} else if(choice == "6"){
			repallchar_func(str);
		} else if(choice == "7"){
			repstr_func(str);
		} else if(choice == "8"){
			searchchar_func(str);
		} else if(choice == "9"){
			countchar_func(str);
		} else if(choice == "A" || choice == "a"){
			searchstr_func(str);
		} else if(choice == "B" || choice == "b"){
			comparestr_func(str);
		} else if(choice == "C" || choice == "c"){
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
	oldst = mystring(str);
	std::size_t indx;
	
	char zeroth = str[0];
	cout << "Index (The 0th index is '" << zeroth << "'): ";
	cin >> indx;
	
	if(indx > str.length()){
		error = "Index out of bounds.";
	} else{
		if(indx == 0){
			cout << "Input the char or string before \"" << str << "\": ";
		} else{		
			cout << "Input the char or string after \"";
			for(size_t i = 0; i < indx; ++i){
				cout << str[i];
			}
			cout << "\": ";
		}
		mystring inserted;
		cin.ignore();
		getline(cin, inserted);
		
		str.insert(indx, inserted);
		cout << "Debug: Insert Func working";
		comparest = inserted;
		start_index = indx;
	}
	lastused = '1';
}

void deletechar_func(mystring& str){
	oldst = mystring(str);
	size_t indx;
	
	char zeroth = str[0];
	cout << "Index (The 0th index is '" << zeroth << "'): ";
	cin >> indx;
	
	if(indx > str.length()){
		error = "Index out of bounds.";
	} else{
		str.del_char(indx);
		comparech = str[indx];
		start_index = indx;
	}
	lastused = '2';
}

void deleteallchar_func(mystring& str){
	oldst = mystring(str);
	
	char target;
	cout << "Input the target Character: ";
	cin >> target;
	
	size_t find_index = str.search_char(target);
	if(find_index == -1){
		error = "Character not found.";
	} else{
		str.del_allchar(target);
	}
	comparech = target;
	lastused = '3';
}

void deletestr_func(mystring& str){
	oldst = mystring(str);
	mystring substr;
	
//	cout << "Debug - Original oldst: " << oldst << endl;
	
	cout << "Input the substring you want to delete: ";
	cin.ignore();
	getline(cin, substr);
	
	size_t find_index = str.search_string(substr);
	if(find_index != -1){
		str.del(substr);
		start_index = find_index;
	} else{
		error = "Substring not found.";
	}
	comparest = substr;
	lastused = '4';
}

void reponechar_func(mystring& str){
	oldst = mystring(str);
	size_t indx;
	
	char zeroth = str[0];
	cout << "Index (The 0th index is '" << zeroth << "'): ";
	cin >> indx;
	
	if(indx > str.length()){
		error = "Index out of bounds.";
	} else{
		char chr;
		cout << "Input a character that will replace the index " << indx << " '" << str[indx] << "': ";
		cin >> chr;
		
		str.replace_char(indx, chr);
		start_index = indx;
	}
	lastused = '5';
}

void repallchar_func(mystring& str){
	oldst = mystring(str);
	
	char target;
	cout << "Input the target Character: ";
	cin >> target;
	
	size_t find_index = str.search_char(target);
	if(find_index == -1){
		error = "Character not found.";
	} else{
		char source;
		cout << "Input a character that will replace all " << target << "-s: ";
		cin >> source;
		
		newcomparech = source;
		str.replace_allchar(target, source);
	}
	comparech = target;
	lastused = '6';
}

void repstr_func(mystring& str){
	oldst = mystring(str);
	mystring target;
	
	cout << "Input the substring you want to replace: ";
	cin.ignore();
	getline(cin, target);
	
	size_t find_index = str.search_string(target);
	if(find_index != -1){
		
		if(find_index == 0){
			cout << "Input the char or string before \"" << str << "\": ";
		} else{		
			cout << "Input the char or string after \"";
			for(size_t i = 0; i < find_index; ++i){
				cout << str[i];
			}
			cout << "\": ";
		}
		mystring source;
		getline(cin, source);
		
//		cout << "Debug: source = " << source << endl;
		
		newcomparest = source;
		str.replace_string(target, source);
		start_index = find_index;
	} else{
		error = "Substring not found.";
	}
	comparest = target;
	lastused = '7';
}

void searchchar_func(mystring str){
	char chr;
	cout << "Input the character you want to search: ";
	cin >> chr;
	
	size_t result = str.search_char(chr);
	if(result == -1){
		error = "Character not found.";
	} else{
		start_index = result;
	}
	comparech = chr;
	lastused = '8';
}

void countchar_func(mystring str){
	char chr;
	cout << "Input the character you want to count: ";
	cin >> chr;
	
	forcount = str.count_char(chr);
	comparech = chr;
	lastused = '9';
}

void searchstr_func(mystring str){
	cout << "Input the substring you want to search: ";
	mystring source;
	cin.ignore();
	getline(cin, source);
	
	size_t result = str.search_string(source);
	if(result == -1){
		error = "Substring not found";
	} else{
		start_index = result;
	}
	
	lastused = 'A';
	comparest = source;
}

void comparestr_func(mystring str) {
	string lr = "\033[91m";
	string lg = "\033[92m";
	string lb = "\033[93m";
	string dg = "\033[95m";
	string re = "\033[0m";
	
	mystring first = str;
	mystring second = "\0";
	
	bool invert = false;
	char lastusedcompare;
	bool togglesecond = false;
	bool alreadyused = false;
	
	system("cls");
	show_array(str);
	details(str);
	mystring operation = "\0";
	mystring inpt;
	
	do{
	    cout << endl;
		if(second == "\0" && !alreadyused){
	    	cout << "Input the 2nd string: ";
	    	cin.ignore();
	    	getline(cin, inpt);
	    	
	    	second = inpt;
	    	cout << endl;
	    	alreadyused = true;
		}
    	
    	system("cls");
    	
    	if(lastusedcompare == '1'){
    		show_array(first);
			details(first);
			cout << endl;
			
	    	cout << "Input the 2nd string: ";
	    	cin.ignore();
	    	getline(cin, inpt);
	    	
	    	second = inpt;
	    	cout << endl;
	    	lastusedcompare = '\0';
	    	system("cls");
		}
		
    	if(invert){
    		mystring temp = first;
    		first = second;
    		second = temp;
    		
    		invert = false;
		}
    	show_array(first);
		details(first);
		cout << endl;
    	show_array(second);
    	details(second);
    	
    	if(lastusedcompare == '2'){
    		
    		if(!togglesecond){
    			cout << endl << first << " != " << second << "\t-> ";
    			if(first != second){
					cout << lg << "True" << re << endl;
				} else{
					cout << lr << "False" << re << endl;
				}
				cout << first << " <= " << second << "\t-> ";
			    if(first <= second){
					cout << lg << "True" << re << endl;
				} else{
					cout << lr << "False" << re << endl;
				}
				cout << first << " >= " << second << "\t-> ";
			    if(first >= second){
					cout << lg << "True" << re << endl;
				} else{
					cout << lr << "False" << re << endl;
				}
				
			} else{
				cout << endl << first << " == " << second << "\t-> ";
			    if(first == second){
					cout << lg << "True" << re << endl;
				} else{
					cout << lr << "False" << re << endl;
				}
				cout << first << " < " << second << "\t-> ";
			    if(first < second){
					cout << lg << "True" << re << endl;
				} else{
					cout << lr << "False" << re << endl;
				}
				cout << first << " > " << second << "\t-> ";
			    if(first > second){
					cout << lg << "True" << re << endl;
				} else{
					cout << lr << "False" << re << endl;
				}
			}
		}
    	
    	cout << endl;
		cout << "[1] " << dg << "CHANGE STRING" << re << ": Change the 2nd string" << endl;
		if(lastusedcompare == '2'){
			cout << "[2] " << dg << "TOGGLE SHOW ALL" << re << ": Toggle Show !=, <= and >= comparisons" << endl;
		} else{	
			cout << "[2] " << dg << "SHOW ALL" << re << ": Show ==, < and > comparisons" << endl;
		}
		cout << "[3] " << dg << "SHOW DETAILS" << re << ": Show detailed comparison" << endl;
		cout << "[4] " << dg << "INVERT" << re << ": Invert the 1st and 2nd string" << endl;
		cout << "[0] " << dg << "BACK" << re << ": Back to the mainmenu (using the mystring \"" << lg << str << re << "\")" << endl << endl;
		cout << "What would you like to do: ";
		cin >> operation;
		
		if(operation == "1"){
			lastusedcompare = '1';
		} else if(operation == "2"){
			lastusedcompare = '2';
			togglesecond = !togglesecond;
		} else if(operation == "3"){
			mystring thirdoper = "\0";
			system("cls");
			cout << lg << "1st String:\t" << re;
			show_array(first);
			cout << lb << "2nd String:\t" << re;
			show_array(second);
			
			cout << endl << "Choose which operation would you like to see detailed(==, !=, <, >, <=, >=): ";
			cin >> thirdoper;
			cout << endl;
			size_t overall_length;
			
			if(first.length() > second.length()){
				overall_length = first.length();
			} else{
				overall_length = second.length();
			}
			
			if(thirdoper == "==" || thirdoper == "=" || thirdoper == "!="|| thirdoper == "!"){
				int false_counter = 0;
				for(int i = 0; i < overall_length; ++i){
					bool size_equal = true;
					string ok = lr + "False" + re;
					string firstchar;
					if(i >= first.length()){
						firstchar = lr + "X" + re;
						size_equal = false;
					} else if(first[i] == '\0'){
						firstchar = "\\0";
					} else{
						firstchar = lg + first[i] + re;
					}
					
					string secondchar;
					if(i >= second.length()){
						secondchar = lr + "X" + re;
						size_equal = false;
					} else if(second[i] == '\0'){
						secondchar = "\\0";
					} else{
						secondchar = lb + second[i] + re;
					}
					
					if(size_equal){
						if(first[i] == second[i]){
							ok = lg + "True" + re;
						} else{
							false_counter++;
						}
					}
					
					cout << i << ": " << firstchar << " == " << secondchar << " -> " << ok << endl;
				}
				cout << "\nthus:\n";
				
				if(false_counter > 0){
					cout << lg << first << re << " != " << lb << second << re << endl;
				} else{
					cout << lg << first << re << " == " << lb << second << re << endl;
				}
				
			} else if(thirdoper == "<" || thirdoper == ">" || thirdoper == "<=" || thirdoper == ">="){
				bool is_greater = false;
				bool is_lesser = false;
				
				for(int i = 0; i < overall_length; ++i){
					bool size_equal = true;
					string ok = lr + "False" + re;
					string firstchar;
					if(i >= first.length()){
						firstchar = lr + "X" + re;
						size_equal = false;
					} else if(first[i] == '\0'){
						firstchar = "\\0";
					} else{
						firstchar = lg + first[i] + re;
					}
					
					string secondchar;
					if(i >= second.length()){
						secondchar = lr + "X" + re;
						size_equal = false;
					} else if(second[i] == '\0'){
						secondchar = "\\0";
					} else{
						secondchar = lb + second[i] + re;
					}
					
					if(size_equal){
						if(first[i] > second[i]){
							ok = lg + "True" + re;
						}
					}
					
					cout << i << ": " << firstchar << " == " << secondchar << " -> " << ok << endl;
				}
				cout << "\nthus:\n";
				
//				if(false_counter > 0){
//					cout << lg << first << re << " != " << lb << second << re << endl;
//				} else{
//					cout << lg << first << re << " == " << lb << second << re << endl;
//				}
			} else{
				break;
			}
			cin >> thirdoper;
			
			lastusedcompare = '3';
		} else if(operation == "4"){
			invert = true;
		} else{
			break;
		}
		
	} while(true);
	
    lastused = 'B';
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
	cout << "[2] " << dg << "DELETE CHARACTER" << re << ": Delete a single character from the string."<< endl;
	cout << "[3] " << dg << "DELETE ALL CHARACTER" << re << ": Delete all occurrences of a specific character."<< endl;
	cout << "[4] " << dg << "DELETE SUBSTRING" << re << ": Delete a substring from the string."<< endl;
	cout << "[5] " << dg << "REPLACE SINGLE CHARACTER" << re << ": Replace the specified single character in a string with a new character." << endl;
	cout << "[6] " << dg << "REPLACE ALL CHARACTER" << re << ": Replace all specified characters in a string with a new character." << endl;
	cout << "[7] " << dg << "REPLACE STRING" << re << ": Replace a portion of a string with another string" << endl;
	cout << "[8] " << dg << "SEARCH CHARACTER" << re << ": Searches a string for the first occurrence of a specified character." << endl;
	cout << "[9] " << dg << "COUNT CHARACTER" << re << ": Counts the number of occurrences of a specified character in a string." << endl;
	cout << "[A] " << dg << "SEARCH STRING" << re << ": Searches through a string for an occurrence of some smaller string." << endl;
	cout << "[B] " << dg << "COMPARE STRING" << re << ": Compare the string to a new inputted string." << endl;
	cout << "[C] " << dg << "CHANGE STRING" << re << ": Reset the allocated space and replace all characters of the string" << endl << endl;
	
	cout << "Choose the action you want to do: ";
}

void details(mystring& str){
	string re = "\033[0m";
	string lr = "\033[91m";
	string lb = "\033[94m";
	string lg = "\033[92m";
	
	cout << "----------------------------------------------" << endl;
	if (lastused == '1' && error == "None") {  // ins - none
        cout << "Old String Form: \"" << oldst << "\"" << endl;
    } else if ((lastused == '4' || lastused == '7') && error == "None") {  // delstr, repstr - red/multi
        cout << "Old String Form: \"";
        for (size_t i = 0; i < oldst.length(); ++i) {
            if (i >= start_index && i < start_index + comparest.length() - 1) {
                cout << lr << oldst[i] << re;
            } else {
                cout << oldst[i];
            }
        }
        cout << "\"" << endl;
    } else if ((lastused == '2' || lastused == '5') && error == "None") {  // delchar, repone - red/single
        cout << "Old String Form: \"";
        for (size_t i = 0; i < oldst.length(); ++i) {
            if (i == start_index) {
                cout << lr << oldst[i] << re;
            } else {
                cout << oldst[i];
            }
        }
        cout << "\"" << endl;
    } else if ((lastused == '3' || lastused == '6') && error == "None") {  // repallch - red/single-multi
        cout << "Old String Form: \"";
        for (size_t i = 0; i < oldst.length(); ++i) {
            if (oldst[i] == comparech) {
                cout << lr << oldst[i] << re;
            } else {
                cout << oldst[i];
            }
        }
        cout << "\"" << endl;
    } else if (lastused == '8' && error == "None") {  // searchch - green/single/none
        cout << "Index of the first occurence of '" << lg << comparech << re << "': " << start_index << endl;
    } else if (lastused == '9' && error == "None") {  // countch - green/single/none
        cout << "Number of times '" << lg << comparech << re << "' occured: " << forcount << endl;
    } else if (lastused == 'A' && error == "None") {  // searchst - green/multi/none
        cout << "Index of the first occurence of \"" << lg << comparest << re << "\": " << start_index << endl;
    }
    else if(error != "None"){
    	cout << lr << "Error: " << error;
    	if(lastused == '1' || lastused == '2'){
    		cout << " (cause: Index must be between 0-" << str.length()-1 << ")" << re << endl;
		} else if(lastused == '4' || lastused == '7' || lastused == 'A'){	
    		cout << " (cause: \"" << comparest << "\" not found)" << re << endl;
		} else if(lastused == '3' || lastused == '6' || lastused == '8'){	
    		cout << " (cause: '" << comparech << "' not found)" << re << endl;
		}
	}
//    cout << "(Supposedly) Old String Form: \"" << oldst << "\"" << endl;
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
	string lg = "\033[92m";
	
	string coma = ", ";
	
	cout << "[";
	
	for(int i=0; i< str.get_allocated(); i++){
		if(str[i] == '\0'){
			extra = str.get_allocated() - i - 1;
			cout << lb << "\\0" << re << coma;
			break;
		} else{
			if(lastused == '1' && error == "None"){ // if insert is the last used function
				if(i >= start_index && i < start_index + comparest.length() - 1){
					cout << lc << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else if(lastused == '5' && error == "None"){ // if reponechar
				if(i == start_index){
					cout << lc << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else if(lastused == '6' && error == "None"){ // if repallchar
				if(str[i] == newcomparech && oldst[i] != newcomparech){
					cout << lc << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else if(lastused == '7' && error == "None"){ // if repstr
				if(i >= start_index && i < start_index + newcomparest.length() - 1){
					cout << lc << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else if(lastused == '8' && error == "None"){ // if searchchar
				if(i == start_index){
					cout << lg << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else if(lastused == '9' && error == "None"){ // if countchar
				if(str[i] == comparech){
					cout << lg << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else if(lastused == 'A' && error == "None"){ // if searchstr
				if(i >= start_index && i < start_index + comparest.length() - 1){
					cout << lg << str[i] << re << coma;
				} else{
					cout << str[i] << ", ";
				}
			} else{
				cout << str[i] << ", ";
			}
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
