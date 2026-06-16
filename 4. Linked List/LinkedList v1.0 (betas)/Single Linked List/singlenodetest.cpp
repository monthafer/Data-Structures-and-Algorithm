#include <iostream>
#include "node.h"
#include "singlelinkedlist.h"

using namespace std;

int main(){
    SingleLinkedList list;
    list.list_head_insert(7);
    list.list_insert(10);
    list.list_insert(15);
    list.list_insert(20);

    list.resetcursor();
    list.nextcursor();

    cout << "Cursor data: " << list.get_cursor_data() << endl;
    cout << "HeadPtr data: " << list.get_headPtr_data() << endl;

    node* cursor = list.get_cursor();
    node* headPtr = list.get_headPtr();

    if (cursor != nullptr) {
        cout << "Cursor data (get_cursor): " << cursor -> data << endl;
    }
    if (headPtr != nullptr) {
        cout << "HeadPtr data (get_headPtr): " << headPtr -> data << endl;
    }

    list.nextcursor();
	cout << "New Cursor data: " << list.get_cursor_data() << endl;
    list.list_print();
    list.prevcursor();
	cout << "New Cursor data: " << list.get_cursor_data() << endl;
    list.list_print();

    list.list_head_insert(5);
	cout << "New HeadPtr data: " << list.get_headPtr_data() << endl;
    list.list_insert(12);
	list.list_print();
    list.list_removedata(10);
	list.list_print();

    list.list_head_remove();
	cout << "New HeadPtr data: " << list.get_headPtr_data() << endl;
    list.list_removedata(15);
	list.list_print();

    return 0;
}

