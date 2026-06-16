#ifndef LINKEDLISTTOOLKIT_H
#define LINKEDLISTTOOLKIT_H

#include "node.cpp"
#include <iostream>

// ---Single Linked List-------------------------------------------------------------
std::size_t list_length(const node* headPtr);
void printReverse(node* headPtr);
// node* reverse(node* headPtr);
// node* merge(node* headPtr1, node* headPtr2);
node* sort(node* headPtr);
void sortnode(node*& headPtr);
// void printSortedList(node* headPtr);
node* search(node* headPtr, value_type target);
// node* locate(node* headPtr, std::size_t position);
void copy(const node* source, node*& headPtr);

void headInsert(node*& headPtr, value_type value);
bool headRemove(node*& headPtr);

bool insert(node*& headPtr, node*& cursor, value_type value);
bool removeCurrent(node*& headPtr, node*& cursor);
bool removeData(node*& headPtr, value_type target);
void clear(node*& headPtr);

void printList(const node* headPtr, const node* cursor);


// ---Double Linked List-------------------------------------------------------------
std::size_t list_length(const dnode* headPtr);
void printReverse(dnode* headPtr);
// dnode* reverse(dnode* headPtr);
// dnode* merge(dnode* headPtr1, dnode* headPtr2);
dnode* sort(dnode* headPtr);
void sortnode(dnode*& headPtr, dnode*& tailPtr);
dnode* search(dnode* headPtr, value_type target);
// dnode* locate(dnode* headPtr, std::size_t position);
void copy(const dnode* source, dnode*& headPtr, dnode*& tailPtr);

void headInsert(dnode*& headPtr, value_type value);
bool headRemove(dnode*& headPtr);
void tailInsert(dnode*& tailPtr, dnode*& headPtr, value_type value);
bool tailRemove(dnode*& tailPtr);

bool insert(dnode*& headPtr, dnode*& cursor, value_type value);
bool removeCurrent(dnode*& headPtr, dnode*& cursor);
bool removeData(dnode*& headPtr, value_type target);
void clear(dnode*& headPtr);

void printList(const dnode* headPtr, const dnode* cursor);


#include "linkedlisttoolkit.cpp"
#endif
