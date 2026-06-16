#include <cassert>
#include <cctype>
#include <iostream>
#include "../String/mystring.h"
#include "queue.cpp"
#include "../Stack/arraystack.cpp"

using namespace std;

int main() {
    Queue<MyString> que;
    ArrayStack<MyString> sta;
    // MyString str;

    std::size_t mismatches = 0;

    cout << "Enter a sentence and I will see if it's a word palindrome: " << endl;
    // cin >> str;
    MyString str = "She loves her but I dont. Don't i but Her loves she";
    // cout << "String: " << str << endl;
    MyString backup = str;
    str.to_lowercase();
    str.del_allchar('.');
    str.del_allchar(',');
    str.del_allchar('\'');
    str.del_allchar('\"');
    str.del_allchar('(');
    str.del_allchar(')');
    str.del_allchar('/');

    int i = 0;
    while(str.count_char(' ')){
        std::size_t j = str.search_char(' ');
        MyString word = str.substring(0, j-1);

        cout << "Debug: " << word << endl;

        que.push(word);
        sta.push(word);

        for(size_t k = 0; k <= j; k++){
            str.del_char(0);
        }
    }

    str.del_allchar(' ');
    // cout << "Debug: " << str << endl;

    que.push(str);
    sta.push(str);

    while ((!que.empty( )) && (!sta.empty( ))){
        if (que.front( ) != sta.peek( )){
            ++mismatches;
        }
        que.pop( );
        sta.pop( );
    }

    if (mismatches == 0){
        cout << "That is a palindrome." << endl;
    } else{
        cout << "That is not a palindrome." << endl;
        cout << "Number of mismatches: " << mismatches << endl;
    }

    int cont;

    cin.ignore();
    cin >> cont;
    cin >> cont;
    return 0;
}