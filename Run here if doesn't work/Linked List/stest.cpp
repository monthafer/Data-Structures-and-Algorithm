#include "singlelinkedlist.h"
#include <iostream>

using namespace std;

void displayMenu(SingleLinkedList& list) {
    list.print_list();
    cout << "\nSingleLinkedList Menu:\n";
    cout << "1. Insert Head\n";
    cout << "2. Insert After Cursor\n";
    cout << "3. Delete Head\n";
    cout << "4. Delete Current\n";
    cout << "5. Find Value\n";
    cout << "6. Display Reverse List\n";
    cout << "7. Next Cursor\n";
    cout << "8. Prev Cursor\n";
    cout << "9. Reset Cursor\n";
    cout << "10. Apply Sort\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    SingleLinkedList list;
    int choice;
    int value;

    do {
        displayMenu(list);
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insertHead(value);
                break;

            case 2:
                cout << "Enter value to insert after cursor: ";
                cin >> value;
                list.insert(value);
                break;

            case 3:
                list.deleteHead();
                cout << "Head removed.\n";
                break;

            case 4:
                list.deleteCurrent();
                cout << "Current node removed.\n";
                break;

            case 5:
                cout << "Enter value to find: ";
                cin >> value;
                if (list.findCursor(value)) {
                    cout << "Value found and cursor updated.\n";
                } else {
                    cout << "Value not found.\n";
                }
                break;

            case 6:
                cout << "Reversed list: ";
                list.reverseList();
                cout << "\nNormal List: ";
                break;

            case 7:
                list.nextCursor();
                break;

            case 8:
                list.prevCursor();
                break;

            case 9:
                list.resetCursor();
                break;

            case 10:
                cout << "Sort Applied.\n";
                list.applySort();
                break;

            default: 
                cout << "Exiting program.\n";
                break;
        }
    } while (choice < 11 && choice > 0);

    return 0;
}
