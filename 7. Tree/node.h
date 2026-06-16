#ifndef NODE_H
#define NODE_H

#include <cassert> 
#include <cstdlib>  
#include <iomanip> 
#include <iostream>

template <class value_type>
struct bnode{
    value_type data;
    bnode* left;
    bnode* right;

    bnode(const value_type& init_data = value_type( ), bnode* init_left = nullptr, bnode* init_right = nullptr) {
        data = init_data; 
        left = init_left; 
        right = init_right;
    }

    bool is_leaf() const {
        return (left == nullptr) && (right == nullptr);
    }
};

// NONMEMBER FUNCTIONS for the binary_tree_node<Item>:
template <class Process, class BTNode>
void inorder(Process f, BTNode* nodePtr);

template <class Process, class BTNode>
void preorder(Process f, BTNode* nodePtr);

template <class Process, class BTNode>
void postorder(Process f, BTNode* nodePtr);

template <class value_type, class SizeType>
void print(const bnode<value_type>* nodePtr, SizeType depth);

template <class value_type>
void tree_clear(bnode<value_type>*& rootPtr);

template <class value_type>
bnode<value_type>* tree_copy (const bnode<value_type>* rootPtr);

template <class value_type>
std::size_t tree_size(const bnode<value_type>* nodePtr);

#include "binarytree.cpp"
#endif
