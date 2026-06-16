#ifndef NODE_H
#define NODE_H

struct node
{
    typedef int value_type;
    value_type data;
    node* next;

    node(const value_type& init_data = value_type(), node* init_next = nullptr){
	    data = init_data;
	    next = init_next;
    }

    node& operator=(const value_type& new_data){
        data = new_data;
        return *this;
    }

    node*& operator=(node* new_next) {
        next = new_next;
        return next;
    }

    bool operator==(const node& other) const {
        return this -> data == other.data;
    }
};

#endif
