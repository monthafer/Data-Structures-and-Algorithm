#include "singlelinkedlist.h"
#include "node.cpp"
#include "linkedlisttoolkit.h"
#include <iostream>

SingleLinkedList::SingleLinkedList() {
    headPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other) {
    if (other.headPtr == nullptr) {
        headPtr = nullptr;
        cursor = nullptr;
        size = 0;
    } else {
        node* current = other.headPtr;
        headPtr = new node();
        headPtr -> data = current -> data;
        
        node* temp = headPtr;
        current = current -> next;
        
        while (current != nullptr) {
            temp -> next = new node();
            temp = temp -> next;
            temp -> data = current -> data;
            current = current -> next;
        }
        
        cursor = headPtr;
        size = other.size;
    }
}

SingleLinkedList::~SingleLinkedList() {
    while(headPtr != nullptr) {
        headRemove(headPtr);
    }
    cursor = headPtr;
    size = 0;
}

node* SingleLinkedList::getCursor(){
    return cursor;
}

node* SingleLinkedList::getHeadPtr(){
    return headPtr;
}

std::size_t SingleLinkedList::getSize(){
    return size;
}

void SingleLinkedList::nextCursor(){
    if(cursor != nullptr && cursor -> next!=nullptr){
        cursor = cursor -> next;
    }
}

void SingleLinkedList::resetCursor(){
    cursor = headPtr;
}

void SingleLinkedList::prevCursor(){
    if(cursor != nullptr && cursor != headPtr){
        node* prev = nullptr;
        for(prev = headPtr; prev -> next != cursor; prev = prev -> next);
        // while (prev->next != cursor) {
        //     prev = prev->next;
        // }
        cursor = prev;
    }
}

bool SingleLinkedList::findCursor(value_type value){
    node* newCursor = search(headPtr, value);
    if(newCursor == nullptr){
        return false;
    }
    cursor = newCursor;
    return true;
}

void SingleLinkedList::insertHead(value_type value){
    node* exist = search(headPtr, value);
    if(exist == nullptr){
        headInsert(headPtr, value);
        cursor = headPtr;
        size++;
        return;
    }

    if(exist -> data == value){
        cursor = exist;
    } else{
        headInsert(headPtr, value);
        cursor = headPtr;
        size++;
    }
    
}

void SingleLinkedList::insert(value_type value){
    node* exist = search(headPtr, value);
    if(exist == nullptr){
        if(::insert(headPtr, cursor, value)){
            size++;
        }
        return;
    }

    cursor = exist;
}

void SingleLinkedList::deleteHead(){
    if(headPtr == nullptr){
        return;
    }
    if(cursor -> data == headPtr -> data){
        cursor = headPtr -> next;
    }
    if(headRemove(headPtr)){
        size--;
    }
    
}

void SingleLinkedList::removeData(value_type value){
    node* exist = search(headPtr, value);
    if(exist != nullptr){
        if(::removeData(headPtr, value)){
            size--;
        }
        return;
    }
}

void SingleLinkedList::deleteCurrent(){
    if(cursor == nullptr){
        return;
    }
    if(removeCurrent(headPtr, cursor)){
        size--;
    }
}

void SingleLinkedList::deleteAllNodes(){
    clear(headPtr);
    headPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

void SingleLinkedList::print_list() const{
    printList(headPtr, cursor);
}
void SingleLinkedList::reverseList(){
    printReverse(headPtr);
    std::cout << "nullptr";
}

// void SingleLinkedList::printSortList(){
//     printSortedList(headPtr);
//     // sort(headPtr);
// }

void SingleLinkedList::applySort(){
    sortnode(headPtr);
}
