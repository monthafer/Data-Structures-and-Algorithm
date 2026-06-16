#ifndef BT_CLASS_H
#define BT_CLASS_H

#include <cassert>
#include "node.h"

template <class value_type>
class binary_tree {
    private:
        // bnode<value_type>* root;
        // bnode<value_type>* current;

    public:
        bnode<value_type>* root;
        bnode<value_type>* current;
        
        binary_tree();
        ~binary_tree();

        void create_first_node(const value_type& entry);

        void shift_to_root();
        void shift_up();
        void shift_left();
        void shift_right();

        bool has_parent() const;
        bool has_left_child() const;
        bool has_right_child() const;

        value_type& retrieve();
        bnode<value_type>* get_current() const;
        bnode<value_type>*& get_root() const;
        std::size_t size() const;

    private:
        bnode<value_type>* find_parent(bnode<value_type>* subtree, bnode<value_type>* child) const {
            if (subtree == nullptr || child == nullptr){
                return nullptr;
            }
            if (subtree->left == child || subtree->right == child){
                return subtree;
            }

            bnode<value_type>* leftSearch = find_parent(subtree -> left, child);
            if (leftSearch != nullptr){
                return leftSearch;
            }

            return find_parent(subtree -> right, child);
        }
};


// template <class value_type>
// void printTree(const avnode<value_type>* node, int depth = 0);

// template <class value_type>
// avnode<value_type>* copyTree(const avnode<value_type>* node);

// template <class value_type>
// void clearTree(avnode<value_type>*& node);

// template <class value_type>
// std::size_t treeSize(const avnode<value_type>* node);

#include "btclass.cpp"
#endif