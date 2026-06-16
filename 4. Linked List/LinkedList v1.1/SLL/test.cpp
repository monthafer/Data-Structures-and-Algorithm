#include <iostream>
#include "singlelinkedlist.h"

void test_insert_head(SingleLinkedList& list) {
    int value;
    std::cout << "Enter value to insert at head: ";
    std::cin >> value;
    list.insert_head(value);
}

void test_remove_head(SingleLinkedList& list) {
    list.remove_head();
}

void test_insert_after(SingleLinkedList& list) {
    int value;
    std::cout << "Enter value to insert after current cursor: ";
    std::cin >> value;
    list.insert_after(value);
}

void test_remove_data(SingleLinkedList& list) {
    int value;
    std::cout << "Enter value to remove from list: ";
    std::cin >> value;
    list.remove_data(value);
}

void test_remove_current(SingleLinkedList& list) {
    list.remove_current();
}

void test_cursor_navigation(SingleLinkedList& list) {
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

void cursor_find(SingleLinkedList& list){
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
    std::cout << "3. Insert After Current\n";
    std::cout << "4. Remove Data\n";
    std::cout << "5. Remove Current\n";
    std::cout << "6. Next Cursor\n";
    std::cout << "7. Previous Cursor\n";
    std::cout << "8. Reset Cursor\n";
    std::cout << "9. Find Data\n";
    std::cout << "0. Exit\n";
}

int main() {
    SingleLinkedList list;
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
                test_insert_after(list);
                break;
            case 4:
                test_remove_data(list);
                break;
            case 5:
                test_remove_current(list);
                break;
            case 6:
                list.c_next();
                break;
            case 7:
                list.c_prev();
                break;
            case 8:
                list.c_reset();
                break;
            case 9:
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