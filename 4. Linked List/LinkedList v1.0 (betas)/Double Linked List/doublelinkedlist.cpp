#include "dnode.h"
#include "doublelinkedlist.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList(){
    headPtr = nullptr;
    tailPtr = nullptr;
    cursor = headPtr;
    size = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) {
    if (other.headPtr == nullptr) {
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = headPtr;
        size = 0;
    } else {
        headPtr = new DNode(other.headPtr->data);
        DNode* current = headPtr;
        DNode* otherCurrent = other.headPtr->flink;
        while (otherCurrent != nullptr) {
            current->flink = new DNode(otherCurrent->data);
            current->flink->blink = current;
            current = current->flink;
            otherCurrent = otherCurrent->flink;
        }
        tailPtr = current;
        cursor = headPtr;
        size = other.size;
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    while (headPtr != nullptr) {
        head_remove(headPtr);
    }
    size = 0;
    cursor = nullptr;
    tailPtr = nullptr;
}

DNode::value_type DoubleLinkedList::get_cursor_data(){
    if(cursor != nullptr) {
        return cursor -> data;
    }
}

DNode::value_type DoubleLinkedList::get_headPtr_data(){
    if(headPtr != nullptr) {
        return headPtr -> data;
    }
}

DNode::value_type DoubleLinkedList::get_tailPtr_data(){
    if(tailPtr != nullptr) {
        return tailPtr -> data;
    }
}

DNode* DoubleLinkedList::get_cursor(){
    return cursor;
}

DNode* DoubleLinkedList::get_headPtr(){
    return headPtr;
}

DNode* DoubleLinkedList::get_tailPtr(){
    return tailPtr;
}

void DoubleLinkedList::nextcursor(){
    if(cursor!= nullptr && cursor -> flink!= nullptr){
        cursor = cursor -> flink;
    }
}

void DoubleLinkedList::resetcursor(){
    cursor = headPtr;
}

void DoubleLinkedList::prevcursor(){
    if(cursor!= nullptr && cursor -> blink!= nullptr){
        cursor = cursor -> blink;
    }
}

void DoubleLinkedList::list_head_insert(DNode::value_type newdata){
    head_insert(headPtr, newdata);
}

void DoubleLinkedList::list_head_remove(){
    head_remove(headPtr);
}

void DoubleLinkedList::list_insert(DNode::value_type newdata){
    if(headPtr == nullptr) {
        head_insert(headPtr, newdata);
    } else{
        insert(headPtr, newdata);
    }
}

void DoubleLinkedList::list_removedata(DNode::value_type olddata){
    removedata(headPtr, olddata);
}

void DoubleLinkedList::list_removenode(){
    removenode(headPtr);
}

void DoubleLinkedList::head_insert(DNode*& headPtr, DNode::value_type newdata){
    DNode* newNode = new DNode(newdata);
    newNode -> flink = headPtr;
    if(headPtr!= nullptr) {
        headPtr -> blink = newNode;
    }
    headPtr = newNode;
    if(tailPtr == nullptr) {
        tailPtr = headPtr;
    }
    size++;
}

void DoubleLinkedList::head_remove(DNode*& headPtr){
    if(headPtr!= nullptr) {
        DNode* temp = headPtr;
        headPtr = headPtr -> flink;
        if(headPtr!= nullptr) {
            headPtr -> blink = nullptr;
        } else {
            tailPtr = nullptr;
        }
        delete temp;
        size--;
    }
}

void DoubleLinkedList::insert(DNode*& headPtr, DNode::value_type newdata){
    DNode* newNode = new DNode(newdata);
    newNode -> flink = headPtr;
    if(headPtr!= nullptr) {
        headPtr -> blink = newNode;
    }
    headPtr = newNode;
    if(tailPtr == nullptr) {
        tailPtr = headPtr;
    }
    size++;
}

void DoubleLinkedList::removedata(DNode*& headPtr, DNode::value_type olddata){
    if(headPtr!= nullptr) {
        if(headPtr -> data == olddata) {
            head_remove(headPtr);
            return;
        }
        DNode* current = headPtr;
        while(current -> flink!= nullptr && current -> flink -> data!= olddata) {
            current = current -> flink;
        }
        if(current -> flink!= nullptr && current -> flink -> data == olddata) {
            DNode* temp = current -> flink;
            current -> flink = current -> flink -> flink;
            if(current -> flink!= nullptr) {
                current -> flink -> blink = current;
            } else {
                tailPtr = current;
            }
            delete temp;
            size--;
        }
    }
}

void DoubleLinkedList::removenode(DNode*& headPtr){
    if(cursor!= nullptr) {
        if(cursor == headPtr) {
            head_remove(headPtr);
            cursor = headPtr;
        } else {
            DNode* temp = cursor;
            cursor = cursor -> flink;
            if(cursor!= nullptr) {
                cursor -> blink = temp -> blink;
            } else {
                tailPtr = temp -> blink;
            }
            delete temp;
            size--;
        }
    }
}

void DoubleLinkedList::reverse(DNode*& headPtr){
    DNode* prev = nullptr;
    DNode* current = headPtr;
    DNode* next = nullptr;
    while(current!= nullptr) {
        next = current -> flink;
        current -> flink = prev;
        current -> blink = next;
        prev = current;
        current = next;
    }
    if(next!= nullptr) {
        headPtr = next -> blink;
    }
}
