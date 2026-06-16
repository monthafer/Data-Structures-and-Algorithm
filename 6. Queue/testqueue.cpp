#include "queue.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    try {
        Queue<int> intQueue;

        intQueue.push(10);
        intQueue.push(20);
        intQueue.push(30);
        cout << "Front element (after pushes): " << intQueue.front() << endl;

        intQueue.pop();
        cout << "Front element (after pop): " << intQueue.front() << endl;

        intQueue.push_priority(15);
        cout << "Front element (after priority push): " << intQueue.front() << endl;

        cout << "\nQueue elements in order: " << endl;
        while (!intQueue.empty()) {
            cout << intQueue.front() << " ";
            intQueue.pop();
        }
        cout << endl;

        for (int i = 0; i < 100; ++i) {
            intQueue.push(i);
        }

        intQueue.push(101); // 101st ele

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    try {
        Queue<string> stringQueue;

        stringQueue.push("apple");
        stringQueue.push("orange");
        stringQueue.push_priority("banana");
        cout << "\nFront element (after priority push): " << stringQueue.front() << endl;
        cout << "Queue elements in order: " << endl;
        while (!stringQueue.empty()) {
            cout << stringQueue.front() << " ";
            stringQueue.pop();
        }
        cout << endl;

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
