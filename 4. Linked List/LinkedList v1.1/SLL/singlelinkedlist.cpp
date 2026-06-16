#include "node.cpp"
#include "linkedlisttoolkit.cpp"
#include "singlelinkedlist.h"
#include <iostream>

SingleLinkedList::SingleLinkedList(){
    headPtr = nullptr;
    cursor = nullptr;
    size = 0;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other) {
    if (other.headPtr == nullptr){
        headPtr = nullptr;
        cursor = nullptr;
        size = 0;
    } else{
        headPtr = new node(other.headPtr -> data);
        node* current = headPtr;
        node* otherCurrent = other.headPtr -> next;
        while(otherCurrent!= nullptr){
            current -> next = new node(otherCurrent -> data);
            current = current -> next;
            otherCurrent = otherCurrent -> next;
        }
        cursor = other.cursor;
        size = other.size;
    }
}

SingleLinkedList::~SingleLinkedList(){
    while(head_remove(headPtr));
    size = 0;
}

node* SingleLinkedList::get_cursor(){
    return cursor;
}

node* SingleLinkedList::get_headPtr(){
    return headPtr;
}

void SingleLinkedList::c_next(){
    if(cursor != nullptr && cursor -> next != nullptr){
        cursor = cursor -> next;
    }
}

void SingleLinkedList::c_prev(){
    if(cursor != headPtr && cursor != nullptr){
        node* temp;
        for(temp = headPtr;temp -> next != cursor; temp = temp->next);
        cursor = temp;
    }
}

void SingleLinkedList::c_reset(){
    cursor = headPtr;
}

bool SingleLinkedList::c_find(node::value_type data){
    node* temp = headPtr;
    while(temp != nullptr){
        if (temp -> data == data){
            cursor = temp;
            return true;
        }
        temp = temp -> next;
    }
    return false;
    // node* temp;
    // for(temp = headPtr;temp -> data != data; temp = temp->next){
    //     if(temp == nullptr){
    //         return false;
    //         break;
    //     }
    // }
    // cursor = temp;
    // return true;
}

void SingleLinkedList::insert_head(node::value_type newdata){
    if(!c_find(newdata)){
        head_insert(headPtr, newdata);
        size++;
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void SingleLinkedList::remove_head(){
    if(head_remove(headPtr)){
        size--;
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void SingleLinkedList::insert_after(node::value_type newdata){
    if(headPtr == nullptr){
        if(!c_find(newdata)){
            head_insert(headPtr, newdata);
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

void SingleLinkedList::remove_data(node::value_type olddata){
    if(headPtr != nullptr){
        if(headPtr -> data == olddata){
            head_remove(headPtr);
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

void SingleLinkedList::remove_current(){
    if(removenode(headPtr, cursor)){
        size--;
    }
    if(cursor == nullptr){
        cursor = headPtr;
    }
}

void SingleLinkedList::print_list(){
    ::print_list(headPtr, cursor);
}

void reverse(){
    ::reverse(headPtr);
}
