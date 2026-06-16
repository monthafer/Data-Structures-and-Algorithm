#ifndef LINKEDLISTTOOLKIT_H
#define LINKEDLISTTOOLKIT_H

#include "dnode.cpp"
#include <iostream>

std::size_t list_length(const dnode* headPtr){
    std::size_t count = 0;
    while (headPtr!= nullptr){
        count++;
        headPtr = headPtr -> flink;
    }
    return count;
}

dnode* head_to_tail(dnode* headPtr){
    while(headPtr != nullptr && headPtr -> flink != nullptr){
        headPtr = headPtr -> flink;
    }
    return headPtr;
}

dnode* tail_to_head(dnode* tailPtr){
    while(tailPtr != nullptr && tailPtr -> blink != nullptr){
        tailPtr = tailPtr -> blink;
    }
    return tailPtr;
}

void head_insert(dnode*& headPtr, dnode::value_type newdata){
    dnode* newNode = new dnode();
    newNode -> data = newdata;
    newNode -> flink = headPtr;
    newNode -> blink = nullptr;
    if (headPtr != nullptr) {
        headPtr -> blink = newNode;
    }
    // newNode -> flink -> blink = newNode;
    headPtr = newNode;

}

bool head_remove(dnode* headPtr){
    if(headPtr == nullptr){
        return false;
    } else{
        dnode* temp = headPtr;
        headPtr = headPtr -> flink;
        headPtr -> blink = nullptr;
        delete temp;
        return true;
    }
}

void tail_insert(dnode*& tailPtr, dnode::value_type newdata){
    dnode* newNode = new dnode();
    newNode -> data = newdata;
    newNode -> flink = nullptr;
    newNode -> blink = tailPtr;
    if(tailPtr != nullptr) {
        tailPtr -> flink = newNode;
    }
    // newNode -> blink -> flink = newNode;
    tailPtr = newNode;
}

bool tail_remove(dnode*& tailPtr){
    if(tailPtr == nullptr){
        return false;
    } else{
        dnode* temp = tailPtr;
        tailPtr = tailPtr -> blink;
        tailPtr -> flink = nullptr;
        delete temp;
        return true;
    }
}

bool removedata(dnode*& headPtr, dnode::value_type target){
    dnode* targetnode = headPtr;

    while (targetnode != nullptr && targetnode -> data != target) {
        targetnode = targetnode -> flink;
    }

    if (targetnode == nullptr) {
        return false;
    }

    if (targetnode -> blink == nullptr) {
        if(!head_remove(headPtr)){
            return false;
        }
    } else if(targetnode -> flink == nullptr) {
        if(!tail_remove(head_to_tail(headPtr))){
            return false;
        }
    } else {
        targetnode -> blink -> flink = targetnode -> flink;
        targetnode -> flink -> blink = targetnode -> blink;
        targetnode -> flink = nullptr;
        targetnode -> blink = nullptr; //unnecessary but necessary
    }

    delete targetnode;
    return true;
}

bool removenode(dnode*& headPtr, dnode*& cursor){
    if(cursor != nullptr){
        if(cursor == headPtr){
            head_remove(headPtr);
            cursor = headPtr;
        } else if(cursor == head_to_tail(headPtr)){
            tail_remove(head_to_tail(headPtr));
            cursor = head_to_tail(headPtr);
        } else{
            cursor -> blink -> flink = cursor -> flink;
            cursor -> flink -> blink = cursor -> blink;
            cursor -> flink = nullptr;
            cursor -> blink = nullptr; //unnecessary but necessary
        }
        return true;
    } else {
        return false;
    }
}

bool insert(dnode*& headPtr, dnode* cursor, dnode::value_type newdata){
    if(cursor == nullptr){
        return false;
    } else{
        dnode* newNode = new dnode();
        newNode -> data = newdata;
        newNode -> flink = cursor -> flink;
        newNode -> blink = cursor;
        cursor -> flink = newNode;
        if(newNode -> flink != nullptr){
            newNode -> flink -> blink = newNode;
        }
        return true;
    }
}

void print_list(const dnode* headPtr, const dnode* cursor){
    if(headPtr == nullptr){
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << "nullptr <- ";
    while (headPtr != nullptr){
        if(headPtr == cursor){
            std::cout << "<" << headPtr -> data << "> <=> ";
        } else{
            std::cout << headPtr -> data << " <=> ";
        }
        headPtr = headPtr -> flink;
    }
    std::cout << "nullptr" << std::endl;
}

#endif
