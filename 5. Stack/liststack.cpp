#include "liststack.h"
// #include "../Linked List/singlelinkedlist.h" 
// #include "../Linked List/doublelinkedlist.h" 

template <class linkedlist>
ListStack<linkedlist>::ListStack(){
    top_node = nullptr;
    current_size = 0;
}

template <class linkedlist>
ListStack<linkedlist>::~ListStack() {
    while (!empty()) {
        pop();
    }
}

template <class linkedlist>
linkedlist& ListStack<linkedlist>::peek() const {
    if (empty()) {
        throw std::underflow_error("Stack is empty:>");
    }
    return top_node -> data;
}

template <class linkedlist>
linkedlist ListStack<linkedlist>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack is empty:>");
    }

    Node* oldTop = top_node;
    linkedlist topData = oldTop -> data;
    top_node = top_node -> next;
    delete oldTop;
    --current_size;

    return topData;
}

template <class linkedlist>
void ListStack<linkedlist>::push(const linkedlist& newList) {
    Node* newNode = new Node();
    newNode -> data = newList;
    newNode -> next = top_node;
    top_node = newNode;
    ++current_size;
}

template <class linkedlist>
bool ListStack<linkedlist>::empty() const {
    return top_node == nullptr;
}

template <class linkedlist>
size_type ListStack<linkedlist>::size() const {
    return current_size;
}
