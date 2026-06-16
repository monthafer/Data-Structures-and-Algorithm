#ifndef NODE_H
#define NODE_H

typedef int value_type;

struct node
{
    value_type data;
    node* next;

    node(const value_type& init_data = value_type(), node* init_next = nullptr){
	    data = init_data;
	    next = init_next;
    }
};

struct dnode
{
    value_type data;
    dnode* flink;
    dnode* blink;

    dnode(const value_type& init_data = value_type(), dnode* init_flink = nullptr, dnode* init_blink = nullptr){
	    data = init_data;
	    flink = init_flink;
        blink = init_blink;
    }
};

#endif