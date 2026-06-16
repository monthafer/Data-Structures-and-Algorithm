#ifndef LINKEDLISTTOOLKIT_H
#define LINKEDLISTTOOLKIT_H

#include "node.h"
#include <iostream>

std::size_t list_length(const node* headPtr);

void head_insert(node*& headPtr, node::value_type data);
void head_remove(node*& headPtr);
bool removedata(node*& headPtr, node::value_type target);
bool removenode(node*& headPtr, node*& cursor);
void insert(node*& headPtr, const node* cursor, node::value_type data);

void print_list(const node* headPtr, const node* cursor);

#include "linkedlisttoolkit.cpp"
#endif