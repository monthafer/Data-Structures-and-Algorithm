#include "node.h"
#include <iostream>
#include <cassert> 
#include <cstdlib>  
#include <iomanip>

template <class Process, class BTNode>
void inorder(Process f, BTNode* nodePtr){
    
    if (nodePtr != NULL) {
        inorder(f, nodePtr -> left);
        f(nodePtr -> data);
        inorder(f, nodePtr -> right);
    }
}

template <class Process, class BTNode>
void preorder(Process f, BTNode* nodePtr){
    if (nodePtr != NULL) {
        f(nodePtr -> data);
        preorder(f, nodePtr -> left);
        preorder(f, nodePtr -> right);
    }
}

template <class Process, class BTNode>
void postorder(Process f, BTNode* nodePtr){
    if (nodePtr != NULL) {
        postorder(f, nodePtr -> left);
        postorder(f, nodePtr -> right);
        f(nodePtr -> data);
    }
}

template <class value_type, class SizeType>
void print(const bnode<value_type>* nodePtr, SizeType depth){
    std::cout << std::setw(4 * depth) << "";
    if (nodePtr == NULL) {
        std::cout << "[Empty]" << std::endl;
    } else if (nodePtr -> is_leaf( )) {
        std::cout << nodePtr -> data;
        std::cout << " [leaf]" << std::endl;
    } else { //A nonleaf
        std::cout << nodePtr -> data << std::endl;
        print(nodePtr -> right, depth + 1);
        print(nodePtr -> left, depth + 1);
    }
}

template <class value_type>
void tree_clear(bnode<value_type>*& rootPtr) {
    bnode<value_type>* child;
    if (rootPtr != NULL) {
        child = rootPtr -> left;
        tree_clear(child);
        child = rootPtr -> right;
        tree_clear(child);
        delete rootPtr;
            rootPtr = NULL;
    }
}

template <class value_type>
bnode<value_type>* tree_copy (const bnode<value_type>* rootPtr) {
    bnode<value_type> *l_ptr;
    bnode<value_type> *r_ptr;
    if (rootPtr == NULL)
        return NULL;
    else {
        l_ptr = tree_copy(rootPtr -> left);
        r_ptr = tree_copy(rootPtr -> right);
        return new bnode<value_type> (rootPtr -> data, l_ptr, r_ptr);
    }
}

template <class value_type>
std::size_t tree_size(const bnode<value_type>* nodePtr){
    if (nodePtr == NULL)
        return 0;
    else
        return 1 + tree_size(nodePtr -> left) + tree_size(nodePtr -> right);
}
