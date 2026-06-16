#include "dnode.cpp"
#include "linkedlisttoolkit.cpp"
#include "doublelinkedlist.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList(){
    headPtr = nullptr;
    tailPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) {
    if(other.headPtr == nullptr) {
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = headPtr;
        size = 0;
    } else{
        headPtr = new dnode(other.headPtr -> data);
        dnode* current = headPtr;
        dnode* otherCurrent = other.headPtr -> flink;
        while(otherCurrent != nullptr) {
            current -> flink = new dnode(otherCurrent -> data);
            current -> flink -> blink = current;
            current = current -> flink;
            otherCurrent = otherCurrent -> flink;
        }
        cursor = other.cursor;
        size = other.size;
    }
}

DoubleLinkedList::~DoubleLinkedList(){
    while(head_remove(headPtr));
    size = 0;
}

dnode* DoubleLinkedList::get_cursor(){
    return cursor;
}

dnode* DoubleLinkedList::get_headPtr(){
    return headPtr;
}

dnode* DoubleLinkedList::get_tailPtr(){
    return tailPtr;
}

void DoubleLinkedList::c_next(){
    if(cursor!= nullptr && cursor -> flink!= nullptr){
        cursor = cursor -> flink;
    }
}

void DoubleLinkedList::c_prev(){
    if(cursor != nullptr && cursor -> blink != nullptr){
        cursor = cursor -> blink;
    }
}

void DoubleLinkedList::c_reset(){
    cursor = headPtr;
}

bool DoubleLinkedList::c_find(dnode::value_type data){
    dnode* temp = headPtr;
    while(temp != nullptr){
        if(temp -> data == data){
            cursor = temp;
            return true;
        }
        temp = temp -> flink;
    }
    return false;
}

void DoubleLinkedList::insert_head(dnode::value_type newdata){
    if(!c_find(newdata)){
        head_insert(headPtr, newdata);
        if(headPtr -> flink == nullptr){
            tailPtr = headPtr;
        }
        size++;
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void DoubleLinkedList::remove_head(){
    if(headPtr != nullptr){
        if(headPtr == tailPtr){
            if(head_remove(headPtr)){
                tailPtr = nullptr;
                size--;
            }
        } else{
            if(head_remove(headPtr)){
                size--;
            }
        }
        if(cursor == nullptr){
            cursor = headPtr;
        }
    }
}

void DoubleLinkedList::insert_tail(dnode::value_type newdata){
    if(!c_find(newdata)){
        if(tailPtr == nullptr){
            insert_head(newdata);
        } else{
            tail_insert(tailPtr, newdata);
            size++;
        }
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void DoubleLinkedList::remove_tail(){
    if(tail_remove(tailPtr)){
        size--;
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void DoubleLinkedList::insert_after(dnode::value_type newdata){
    if(headPtr == nullptr){
        if(!c_find(newdata)){
            head_insert(headPtr, newdata);
            size++;
        }
        if(cursor == nullptr){
            cursor = headPtr;
        }
    } else if(tailPtr == nullptr){
        if(!c_find(newdata)){
            tail_insert(headPtr, tailPtr, newdata);
            size++;
        }
        if(cursor == nullptr){
            cursor = headPtr;
        }
    } else{
        if(!c_find(newdata)){
            insert(headPtr, cursor, newdata);
            size++;
        }
    }
}

void DoubleLinkedList::remove_data(dnode::value_type olddata){
    if(headPtr != nullptr){
        if(headPtr -> data == olddata){
            head_remove(headPtr);
            size--;
        } else if(tailPtr -> data == olddata){
            tail_remove(tailPtr);
            size--;
        } else{
            if(removedata(headPtr, olddata)){
                size--;
            }
        }
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void DoubleLinkedList::remove_current(){
    if(removenode(headPtr, cursor)){
        size--;
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void DoubleLinkedList::print_list(){
    ::print_list(headPtr, cursor);
}

