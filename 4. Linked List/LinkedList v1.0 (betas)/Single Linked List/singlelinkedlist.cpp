#include "node.h"
#include "singlelinkedlist.h"
#include "linkedlisttoolkit.h"
#include <iostream>

SingleLinkedList::SingleLinkedList(){
    headPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other) {
    if (other.headPtr == nullptr) {
        headPtr = nullptr;
        size = 0;
    } else {
        headPtr = new node();
        headPtr -> data = other.headPtr -> data;
        node* current = headPtr;
        node* otherCurrent = other.headPtr->next;
        while (otherCurrent != nullptr) {
            current -> next = new node();
            current -> next -> data = otherCurrent -> data;
            current = current -> next;
            otherCurrent = otherCurrent -> next;
        }
        current -> next = nullptr;
        size = other.size;
    }
}

SingleLinkedList::~SingleLinkedList() {
    while (headPtr != nullptr) {
        head_remove(headPtr);
    }
    size = 0;
}

node::value_type SingleLinkedList::get_cursor_data(){
    return cursor -> data;
}

node::value_type SingleLinkedList::get_headPtr_data(){
    return headPtr -> data;
}

node* SingleLinkedList::get_cursor(){
    return cursor;
}

node* SingleLinkedList::get_headPtr(){
    return headPtr;
}

void SingleLinkedList::nextcursor(){
    if(cursor != nullptr && cursor -> next != nullptr){
        cursor = cursor -> next;
    } else{
        std::cerr << "Cursor is at the end or just nullptr." << std::endl;
    }
}

void SingleLinkedList::resetcursor(){
    cursor = headPtr;
}

void SingleLinkedList::prevcursor(){
    if (cursor != headPtr && cursor != nullptr){
        node* temp;
        for(temp = headPtr; temp -> next != cursor; 
            temp = temp -> next);
        cursor = temp;
    } else{
        std::cerr << "Cursor is at the head or just nullptr." << std::endl;
    }
}

void SingleLinkedList::list_head_insert(node::value_type newdata){
    head_insert(headPtr, newdata);
    size++;
}

void SingleLinkedList::list_head_remove(){
    head_remove(headPtr);
    size--;
}

void SingleLinkedList::list_insert(node::value_type newdata){
    if(headPtr == nullptr) {
        head_insert(headPtr, newdata);
    } else{
        insert(headPtr, cursor, newdata);
    }
    size++;
}

void SingleLinkedList::list_removedata(node::value_type olddata){
    if(headPtr != nullptr) {
        if(headPtr -> data == olddata) {
            head_remove(headPtr);
            cursor = headPtr;
            size--;
        } else{
            if(removedata(headPtr, olddata)){
                size--;
            }   
        }
    } else{
        std::cerr << "Error: headPtr is null" << std::endl;
    }
}

void SingleLinkedList::list_removenode(){
    if(cursor!= nullptr){
        removenode(headPtr, cursor);
    } else{
        std::cerr << "Error: cursor is null" << std::endl;
    }
}

void SingleLinkedList::list_print(){
    print_list(headPtr, cursor);
}

node::value_type* SingleLinkedList::list_to_array(){
    node* current = headPtr;
    node::value_type* arr = new node::value_type[size];

    for (size_t i=0; i < size; ++i){
        if(current != nullptr){
            arr[i] = current -> data;
            current = current -> next;
        }
    }
    return arr;
}
