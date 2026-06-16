#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>
// #include "../Linked List/singlelinkedlist.h"
// #include "../Linked List/doublelinkedlist.h"


// #ifndef VALUE_TYPE
// #define VALUE_TYPE SingleLinkedList<int>
// #endif

// typedef DoubleLinkedList linkedlist;
typedef std::size_t size_type;

template <class linkedlist>
class ListStack {
private:
    struct Node {
        linkedlist data;
        Node* next;     
    };

    Node* top_node;
    size_type current_size;

public:
    ListStack();
    ~ListStack();
    
    linkedlist& peek() const;
    linkedlist pop();
    void push(const linkedlist& newList);

    bool empty() const;
    size_type size() const;
};

#include "liststack.cpp"
#endif
