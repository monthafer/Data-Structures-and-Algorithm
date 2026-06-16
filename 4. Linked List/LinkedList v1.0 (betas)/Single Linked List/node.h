#ifndef NODE_H
#define NODE_H

struct node 
{
	typedef int value_type;
	value_type data;
	node* next;

	node(const value_type& init_data = value_type( ), node* init_next = nullptr);

	node& operator=(const value_type& new_data);
	node*& operator=(node* new_next);
};

#include "node.cpp"
#endif
