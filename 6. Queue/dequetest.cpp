#include "deque.cpp"
#include <iostream>

using namespace std;

int main() {
    Deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl << endl;


    dq.push_front(0);

    cout << "Front element: " << dq.front() << endl << endl;

    dq.pop_front();
    cout << "Front element: " << dq.front() << endl << endl;

    dq.pop_back();
    cout << "Back element: " << dq.back() << endl << endl;

    cout << "Deque size: " << dq.size() << endl << endl;

    while (!dq.empty()) {
        cout << "Popping front: " << dq.front() << endl;
        dq.pop_front();
    }

    cout << "Deque is now empty." << endl;

    return 0;
}
