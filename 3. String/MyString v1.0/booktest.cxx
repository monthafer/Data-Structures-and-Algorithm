#include <iostream> // Provides cout and cin
#include <cstdlib> // Provides EXIT_SUCCESS
#include "mystring.h" // Provides our new string class

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void match(const mystring& variety, const mystring& mine, const mystring& yours);

// The two strings, mine and yours, are compared. If they are the same, then a
// message is printed saying they are the same; otherwise mine is printed
// in a message. In either case, the string variety is part of the message.

int main() {
    const mystring BLANK(" ");
    mystring me_first("Demo");
    mystring me_last("Program");
    mystring you_first, you_last, you;

    cout << "What is your first name? ";
    cin >> you_first;
    match("first name", me_first, you_first);
    
    cout << "What is your last name? ";
    cin >> you_last;
    match("last name", me_last, you_last);

    you = you_first + BLANK + you_last;
    cout << "I am happy to meet you, " << you << "." << endl;
    
    return EXIT_SUCCESS;
}

void match(const mystring& variety, const mystring& mine, const mystring& yours) {
    if (mine == yours) { // Use overloaded == operator
        cout << "That is the same as my " << variety << '!' << endl;
    } else {
        cout << "My " << variety << " is " << mine << '.' << endl;
    }
}

