#include "doublelinkedlist.h"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

void deets(DoubleLinkedList& list){
    string head;
    string tail;
    string cursor;
    if(list.getHeadPtr() == nullptr){
        head = "nullptr";
    } else{
        head = to_string(list.getHeadPtr() -> data);
    }
    if(list.getTailPtr() == nullptr){
        tail = "nullptr";
    } else{
        tail = to_string(list.getTailPtr() -> data);
    }
    if(list.getCursor() == nullptr){
        cursor = "nullptr";
    } else{
        cursor = to_string(list.getCursor() -> data);
    }
    cout << "HeadPtr: " << head << endl;
    cout << "TailPtr: " << tail << endl;
    cout << "Cursor: " << cursor << endl;
    cout << "Size: " << list.getSize() << endl;
}

void displayMenu(DoubleLinkedList& list) {
    list.print_list();
    deets(list);
    cout << "\n------------------------------" << endl;
    cout << "DoubleLinkedList Menu:\n" << endl;
    cout << "1: Insert Head\n";
    cout << "2: Insert Tail\n";
    cout << "3: Insert After Cursor\n";
    cout << "4: Delete Head\n";
    cout << "5: Delete Tail\n";
    cout << "6: Delete Current\n";
    cout << "7: Delete Data\n";
    cout << "8: Find Value\n";
    cout << "9: Display Reverse List\n";
    cout << "10: Sort List\n";
    cout << "D: Next Cursor\n";
    cout << "A: Prev Cursor\n";
    cout << "R: Reset Cursor\n";
    cout << "0: Exit\n" << endl;
    cout << "Enter your choice: ";
}

int main() {
    DoubleLinkedList list;
    std::string choice;
    int value;
    bool exit = false;

    do {
        displayMenu(list);
        cin >> choice;

        system("cls");

        if(choice == "1"){
            cout << "Enter value to insert at head: ";
            cin >> value;
            list.insertHead(value);
        } else if(choice == "2"){
            cout << "Enter value to insert at tail: ";
            cin >> value;
            list.insertTail(value);
        } else if(choice == "3"){
            cout << "Enter value to insert after cursor: ";
            cin >> value;
            list.insert(value);
        } else if(choice == "4"){
            list.deleteHead();
            cout << "Head removed.\n";
        } else if(choice == "5"){
            list.deleteTail();
            cout << "Tail removed.\n";
        } else if(choice == "6"){
            list.deleteCurrent();
            cout << "Current node removed.\n";
        } else if(choice == "7"){
            cout << "Enter value to delete: ";
            cin >> value;
            if (list.removeData(value)) {
                cout << "Value removed.\n";
            } else {
                cout << "Value not found.\n";
            }
        } else if(choice == "8"){
            cout << "Enter value to find: ";
            cin >> value;
            if (list.findCursor(value)) {
                cout << "Value found and cursor updated.\n";
            } else {
                cout << "Value not found.\n";
            }
        } else if(choice == "9"){
            cout << "Reversed list: ";
            list.reverseList();
            cout << "\nNormal list: ";
        } else if(choice == "10"){
            list.sortList();
            cout << "List has been sorted.\n";
        } else if(choice == "d" || choice == "D"){
            list.nextCursor();
        } else if(choice == "a" || choice == "A"){
            list.prevCursor();
        } else if(choice == "r" || choice == "R"){
            list.resetCursor();
        } else{
            exit = true;
        }

    //     switch (choice) {
    //         case "1":
    //             cout << "Enter value to insert at head: ";
    //             cin >> value;
    //             list.insertHead(value);
    //             break;

    //         case "2":
    //             cout << "Enter value to insert at tail: ";
    //             cin >> value;
    //             list.insertTail(value);
    //             break;

    //         case "3":
    //             cout << "Enter value to insert after cursor: ";
    //             cin >> value;
    //             list.insert(value);
    //             break;

    //         case "4":
    //             list.deleteHead();
    //             cout << "Head removed.\n";
    //             break;

    //         case "5":
    //             list.deleteTail();
    //             cout << "Tail removed.\n";
    //             break;

    //         case "6":
    //             list.deleteCurrent();
    //             cout << "Current node removed.\n";
    //             break;

    //         case "7":
    //             cout << "Enter value to find: ";
    //             cin >> value;
    //             if (list.findCursor(value)) {
    //                 cout << "Value found and cursor updated.\n";
    //             } else {
    //                 cout << "Value not found.\n";
    //             }
    //             break;

    //         case "8":
    //             cout << "Reversed list: ";
    //             list.reverseList();
    //             cout << "\nNormal list: ";
    //             break;

    //         case "d":
    //             list.nextCursor();
    //             break;

    //         case "D":
    //             list.nextCursor();
    //             break;
            
    //         case "a":
    //             list.prevCursor();
    //             break;

    //         case "A":
    //             list.prevCursor();
    //             break;
            
    //         case "r":
    //             list.resetCursor();
    //             break;

    //         case "R":
    //             list.resetCursor();
    //             break;

    //         default:
    //             cout << "Exiting Program.\n";
    //             exit = true;
    //             break;
    //     }
    } while (!exit);

    return 0;
}
