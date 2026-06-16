#include <iostream>
#include "doublelinkedlist.h"

void test_insert_head(DoubleLinkedList& list) {
    int value;
    std::cout << "Enter value to insert at head: ";
    std::cin >> value;
    list.insert_head(value);
}

void test_remove_head(DoubleLinkedList& list) {
    list.remove_head();
}

void test_insert_tail(DoubleLinkedList& list) {
    int value;
    std::cout << "Enter value to insert at tail: ";
    std::cin >> value;
    list.insert_tail(value);
}

void test_remove_tail(DoubleLinkedList& list) {
    list.remove_tail();
}

void test_insert_after(DoubleLinkedList& list) {
    int value;
    std::cout << "Enter value to insert after current cursor: ";
    std::cin >> value;
    list.insert_after(value);
}

void test_remove_data(DoubleLinkedList& list) {
    int value;
    std::cout << "Enter value to remove from list: ";
    std::cin >> value;
    list.remove_data(value);
}

void test_remove_current(DoubleLinkedList& list) {
    list.remove_current();
}

void test_cursor_navigation(DoubleLinkedList& list) {
    char choice;
    std::cout << "Do you want to move cursor next (n) or previous (p) or reset (r)? ";
    std::cin >> choice;

    if (choice == 'n') {
        list.c_next();
        std::cout << "Cursor moved to next: " << (list.get_cursor() ? list.get_cursor()->data : -1) << std::endl;
    } else if (choice == 'p') {
        list.c_prev();
        std::cout << "Cursor moved to previous: " << (list.get_cursor() ? list.get_cursor()->data : -1) << std::endl;
    } else if(choice == 'r'){
        list.c_reset();
        std::cout << "Cursor reset to head: " << (list.get_cursor() ? list.get_cursor()->data : -1) << std::endl;    
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

void cursor_find(DoubleLinkedList& list){
    int value;
    std::cout << "Enter value to find from list: ";
    std::cin >> value;
    if(list.c_find(value)){
        std::cout << "Value found: " << list.get_cursor()->data << std::endl;
    } else{
        std::cout << "Value not found: " << value << std::endl;
    }
}

void display_menu() {
    std::cout << "Choose an option:\n";
    std::cout << "1. Insert at Head\n";
    std::cout << "2. Remove Head\n";
    std::cout << "3. Insert at Tail\n";
    std::cout << "4. Remove Tail\n";
    std::cout << "5. Insert After Current\n";
    std::cout << "6. Remove Data\n";
    std::cout << "7. Remove Current\n";
    std::cout << "8. Next Cursor\n";
    std::cout << "9. Previous Cursor\n";
    std::cout << "10. Reset Cursor\n";
    std::cout << "11. Find Data\n";
    std::cout << "0. Exit\n";
}

int main() {
    DoubleLinkedList list;
    int choice;

    while (true) {
        list.print_list();
        display_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                test_insert_head(list);
                break;
            case 2:
                test_remove_head(list);
                break;
            case 3:
                test_insert_tail(list);
                break;
            case 4:
                test_remove_tail(list);
                break;
            case 5:
                test_insert_after(list);
                break;
            case 6:
                test_remove_data(list);
                break;
            case 7:
                test_remove_current(list);
                break;
            case 8:
                list.c_next();
                break;
            case 9:
                list.c_prev();
                break;
            case 10:
                list.c_reset();
                break;
            case 11:
                cursor_find(list);
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    return 0;
}