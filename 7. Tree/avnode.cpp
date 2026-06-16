#ifndef AVNODE_H
#define AVNODE_H

#include <iostream>

template <class value_type>
struct avnode{
    value_type data;
    avnode* left;
    avnode* right;
    int height;

    avnode(const value_type& init_data = value_type( ), avnode* init_left = nullptr, avnode* init_right = nullptr, int init_height = 1) {
        data = init_data; 
        left = init_left; 
        right = init_right;
        height = init_height;
    }

    bool is_leaf() const {
        return (left == nullptr) && (right == nullptr);
    }
};


#endif