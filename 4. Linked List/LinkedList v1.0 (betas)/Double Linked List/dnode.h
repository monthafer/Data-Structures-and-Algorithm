#ifndef DNODE_H
#define DNODE_H

struct DNode 
{
	typedef int value_type;
	value_type data;
	DNode* flink;
	DNode* blink;

	DNode(const value_type& init_data = value_type( ), DNode* init_flink = nullptr, DNode* init_blink = nullptr);

	DNode& operator=(const value_type& new_data);
};

#include "dnode.cpp"
#endif
