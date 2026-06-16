#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "avnode.cpp"

template <class value_type>
class AVLTree {
private:
    avnode<value_type>* root;

    int getHeight(avnode<value_type>* node) const;
    avnode<value_type>* rightRotate(avnode<value_type>* y);
    avnode<value_type>* leftRotate(avnode<value_type>* x); 
    int getBalanceFactor(avnode<value_type>* node) const;
    avnode<value_type>* balance(avnode<value_type>* node); 
    
    avnode<value_type>* insert(avnode<value_type>* node, const value_type& value);
    avnode<value_type>* deleteNode(avnode<value_type>* node, const value_type& value);
    avnode<value_type>* getMinValueNode(avnode<value_type>* node) const;

    void clear(avnode<value_type>*& node);
    // avnode<value_type>* copy(avnode<value_type>* node);  
    std::size_t getSize(avnode<value_type>* node) const;

    template <class Process>
    void inorder(avnode<value_type>* node, Process process) const;

    template <class Process>
    void preorder(avnode<value_type>* node, Process process) const;

    template <class Process>
    void postorder(avnode<value_type>* node, Process process) const;

    const avnode<value_type>* find(const avnode<value_type>* node, const value_type& key) const;
    void printTree(const avnode<value_type>* node, int depth = 0) const;

public:
    AVLTree();
    ~AVLTree();

    void insert(const value_type& value);
    void remove(const value_type& value);
    bool find(const value_type& value) const;
    void clear();
    std::size_t size() const;

    template <class Process>
    void inorder(Process process) const;

    template <class Process>
    void preorder(Process process) const;

    template <class Process>
    void postorder(Process process) const;

    void printTree() const;
};

#include "avltree.cpp"
#endif
