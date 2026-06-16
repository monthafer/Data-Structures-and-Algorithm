#include "doublelinkedlist.h"
#include "node.cpp"
#include "linkedlisttoolkit.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() {
    headPtr = nullptr;
    tailPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) {
    if (other.headPtr == nullptr) {
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        size = 0;
    } else {
        copy(other.headPtr, headPtr, tailPtr);
        cursor = headPtr;
        size = other.size;
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    clear(headPtr);
    headPtr = nullptr;
    tailPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

dnode* DoubleLinkedList::getCursor() {
    return cursor;
}

dnode* DoubleLinkedList::getHeadPtr() {
    return headPtr;
}

dnode* DoubleLinkedList::getTailPtr() {
    return tailPtr;
}

std::size_t DoubleLinkedList::getSize() {
    return size;
}

void DoubleLinkedList::nextCursor() {
    if (cursor != nullptr && cursor -> flink != nullptr) {
        cursor = cursor -> flink;
    }
}

void DoubleLinkedList::resetCursor() {
    cursor = headPtr;
}

void DoubleLinkedList::prevCursor() {
    if (cursor != nullptr && cursor != headPtr) {
        cursor = cursor -> blink;
    }
}

bool DoubleLinkedList::findCursor(value_type data) {
    dnode* found = search(headPtr, data);
    if (found != nullptr) {
        cursor = found;
        return true;
    }
    return false;
}

void DoubleLinkedList::insertHead(value_type newdata) {
    dnode* exist = search(headPtr, newdata);
    if (exist == nullptr) {
        headInsert(headPtr, newdata);
        if (tailPtr == nullptr) {
            tailPtr = headPtr;
        }
        cursor = headPtr;
        size++;

        if(headPtr -> flink != nullptr) {
            headPtr -> flink -> blink = headPtr;
        }

        return;
    }

    if(exist -> data == newdata){
        cursor = exist;
    } else{
        headInsert(headPtr, newdata);
        if (tailPtr == nullptr) {
            tailPtr = headPtr;
        }
        cursor = headPtr;
        size++;
    }
    
}

void DoubleLinkedList::deleteHead() {
    bool iscursor = false;
    if(cursor == headPtr) iscursor = true;

    if (headPtr == nullptr) return;

    if (headRemove(headPtr)) {
        size--;
        if (size == 0) tailPtr = nullptr;

        if(iscursor) resetCursor();
    }
}

void DoubleLinkedList::insertTail(value_type newdata) {
    dnode* exist = search(headPtr, newdata);
    if(exist == nullptr){
        tailInsert(tailPtr, headPtr, newdata);
        cursor = tailPtr;
        size++;
        return;
    }

    cursor = exist;
}

void DoubleLinkedList::deleteTail() {
    if (tailPtr == nullptr) {
        return;
    }

    bool iscursor = false;
    if(cursor == tailPtr) iscursor = true;

    if (tailRemove(tailPtr)) {
        size--;
        if (size == 0) {
            headPtr = nullptr;
        }
        
        if(iscursor) resetCursor();
    }
}

void DoubleLinkedList::insert(value_type newdata) {
    dnode* exist = search(headPtr, newdata);
    if(exist == nullptr){
        if (::insert(headPtr, cursor, newdata)) {
            size++;
        }
        return;
    }
    cursor = exist;
}

bool DoubleLinkedList::removeData(value_type olddata) {
    bool iscursor = false;
    if(cursor -> data == olddata) {
        iscursor = true;
    } 

    if(olddata == tailPtr -> data){
        if (tailRemove(tailPtr)) {
            size--;
            return true;
        }
    }

    if (::removeData(headPtr, olddata)) {
        size--;
        resetCursor();
        return true;
    }
    return false;
}

void DoubleLinkedList::deleteCurrent() {
    if (cursor == nullptr) {
        return;
    }
    if(cursor == tailPtr){
        if(tailRemove(tailPtr)){
            size--;
            resetCursor();
            return;
        }
    }
    if (removeCurrent(headPtr, cursor)) {
        size--;
        resetCursor();
    }
}

void DoubleLinkedList::print_list() {
    printList(headPtr, cursor);
}

void DoubleLinkedList::reverseList() {
    std::cout << "nullptr -> ";
    printReverse(headPtr);
    std::cout << "nullptr";
}

void DoubleLinkedList::sortList(){
    sortnode(headPtr, tailPtr);
}
