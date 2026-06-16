#include <cassert>
#include <cctype>
#include <iostream>
#include <string>
#include "queue.cpp"
#include "../Stack/arraystack.cpp"

using namespace std;

int main() {
    Queue<char> que;
    ArrayStack<char> sta;
    char letter;

    std::size_t mismatches = 0;

    cout << "Enter a line and I will see if it's a palindrome: " << endl;

    while (cin.peek( ) != '\n'){
        cin >> letter;
        if (isalpha(letter)){
            letter = toupper(letter);
            que.push(letter);
            sta.push(letter);
        }
        // cout << "Queue front: " << que.front() << ", Stack top: " << sta.peek() << endl;
    }

    while ((!que.empty( )) && (!sta.empty( ))){
        if (que.front( ) != sta.peek( )){
            ++mismatches;
        }
        que.pop( );
        sta.pop( );
        // cout << "Queue front: " << que.front() << ", Stack top: " << sta.peek() << endl;
    }

    if (mismatches == 0){
        cout << "That is a palindrome." << endl;
    } else{
        cout << "That is not a palindrome." << endl;
        cout << "Number of mismatches: " << mismatches << endl;
    }

    int cont;

    cin >> cont;
    return 0;
}