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
void inorder(Process f, BTNode* node_ptr){
    
    if (node_ptr != NULL) {
        inorder(f, node_ptr -> left);
        f(node_ptr -> data);
        inorder(f, node_ptr -> right);
    }
}

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr){
    if (node_ptr != NULL) {
        f(node_ptr -> data);
        preorder(f, node_ptr -> left);
        preorder(f, node_ptr -> right);
    }
}

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr){
    if (node_ptr != NULL) {
        postorder(f, node_ptr -> left);
        postorder(f, node_ptr -> right);
        f(node_ptr -> data);
    }
}

template <class value_type, class SizeType>
void print(const bnode<value_type>* node_ptr, SizeType depth){
    std::cout << std::setw(4 * depth) << ""; // Indentation
    if (node_ptr == NULL) { // Fallen off the tree
        std::cout << "[Empty]" << std::endl;
    } else if (node_ptr -> is_leaf( )) { //A leaf
        std::cout << node_ptr -> data;
        std::cout << " [leaf]" << std::endl;
    } else { //A nonleaf
        std::cout << node_ptr -> data << std::endl;
        print(node_ptr -> right, depth + 1);
        print(node_ptr -> left, depth + 1);
    }
}

template <class value_type>
void tree_clear(bnode<value_type>*& root_ptr) {
    bnode<value_type>* child;
    if (root_ptr != NULL) {
        child = root_ptr -> left;
        tree_clear(child);
        child = root_ptr -> right;
        tree_clear(child);
        delete root_ptr;
            root_ptr = NULL;
    }
}

template <class value_type>
bnode<value_type>* tree_copy (const bnode<value_type>* root_ptr) {
    bnode<value_type> *l_ptr;
    bnode<value_type> *r_ptr;
    if (root_ptr == NULL)
        return NULL;
    else {
        l_ptr = tree_copy(root_ptr -> left);
        r_ptr = tree_copy(root_ptr -> right);
        return new bnode<value_type> (root_ptr -> data, l_ptr, r_ptr);
    }
}

template <class value_type>
std::size_t tree_size(const bnode<value_type>* node_ptr){
    if (node_ptr == NULL)
        return 0;
    else
        return 1 + tree_size(node_ptr -> left) + tree_size(node_ptr -> right);
}

#endif
