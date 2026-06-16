#ifndef LINKEDLISTTOOLKIT_H
#define LINKEDLISTTOOLKIT_H

#include "node.cpp"
#include <iostream>

std::size_t list_length(const node* headPtr){
    std::size_t count = 0;
    while (headPtr != nullptr){
        count++;
        // if(headPtr -> next == nullptr){
        //     break;
        // }
        headPtr = headPtr -> next;
    }
    return count;
}

void head_insert(node*& headPtr, node::value_type newdata){
    node* newNode = new node();
    newNode -> data = newdata;
    newNode -> next = headPtr;
    headPtr = newNode;
}

bool head_remove(node*& headPtr){
    if (headPtr == nullptr) {
        return false;
    } else{
        node* temp = headPtr;
        headPtr = headPtr -> next;
        delete temp;
        return true;
    }
}

bool removedata(node*& headPtr, node::value_type target){
    node* previous;
    node* current = headPtr;

    while (current != nullptr && current -> data != target) {
        previous = current;
        current = current -> next;
    }

    if (current == nullptr) {
        return false;
    }

    if (previous == nullptr) {
        headPtr = headPtr -> next;
    } else {
        previous -> next = current -> next;
    }

    delete current;
    return true;

    // for(previous = headPtr; previous -> next -> data != target; 
    //     previous = previous -> next);
    // node* current_target = previous -> next;
    // previous -> next = current_target -> next;
    // delete current_target;

}

bool removenode(node*& headPtr, node*& cursor){
    if(cursor != nullptr){
        if(cursor == headPtr){
            head_remove(headPtr);
            cursor = headPtr;
        } else{
            node* previous;
            for(previous = headPtr; previous -> next != cursor;
                previous = previous -> next);
            previous -> next = cursor -> next;
            cursor = cursor -> next;
        }
        return true;
    } else{
        std::cerr << "Cursor is null!" << std::endl;
        return false;
    }
}

void insert(node*& headPtr, node* cursor, node::value_type newdata){
    if (cursor == nullptr) {
        std::cerr << "Cursor is null! Cannot insert after a null cursor." << std::endl;
        return; 
    }
    node* newNode = new node();
    newNode -> data = newdata;
    newNode -> next = cursor -> next;
    cursor -> next = newNode;
    // node* newNode = new node(newdata, cursor->next);
    // cursor -> next = newNode;
    
    // node* newNode = new node();
    // newNode -> data = newdata;
    // newNode -> next = cursor -> next;
    // cursor -> next = newNode;
}

void print_list(const node* headPtr, const node* cursor){
    while (headPtr != nullptr){
        if(headPtr == cursor){
            std::cout << "<" << headPtr -> data << "> -> ";
        } else{
            std::cout << headPtr -> data << " -> ";
        }
        headPtr = headPtr -> next;
    }
    std::cout << "nullptr" << std::endl;
    // for (temp = headPtr; temp -> next != nullptr; temp = temp-> next){
    //     std::cout << temp -> data << " ";
    // }
}

void reverse(node* headPtr){
    if(headPtr != nullptr){
        reverse(headPtr -> next);
    }
    std::cout << headPtr -> data << " -> ";
}

#endif