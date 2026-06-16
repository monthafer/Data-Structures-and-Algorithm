#include <cassert>
#include "node.h"
#include "btclass.h"

template <class value_type>
binary_tree<value_type>::binary_tree(){
    root = nullptr;
    current = nullptr;
}

template <class value_type>
binary_tree<value_type>::~binary_tree() { 
    tree_clear(root); 
}

template <class value_type>
void binary_tree<value_type>::create_first_node(const value_type& entry) {
    assert(root == nullptr);
    root = new bnode<value_type>(entry);
    current = root;
}

template <class value_type>
void binary_tree<value_type>::shift_to_root() {
    assert(root != nullptr);
    current = root;
}

template <class value_type>
void binary_tree<value_type>::shift_up() {
    assert(has_parent());
    bnode<value_type>* parent = find_parent(root, current);
    current = parent;
}

template <class value_type>
void binary_tree<value_type>::shift_left() {
    assert(has_left_child()); 
    current = current->left;
}

template <class value_type>
void binary_tree<value_type>::shift_right() {
    assert(has_right_child());
    current = current->right;
}

template <class value_type>
bool binary_tree<value_type>::has_parent() const {
    return (current != nullptr && find_parent(root, current) != nullptr);
}

template <class value_type>
bool binary_tree<value_type>::has_left_child() const {
    return (current != nullptr && current->left != nullptr);
}

template <class value_type>
bool binary_tree<value_type>::has_right_child() const {
    return (current != nullptr && current->right != nullptr);
}

template <class value_type>
value_type& binary_tree<value_type>::retrieve() {
    assert(current != nullptr);
    return current->data;
}

template <class value_type>
bnode<value_type>* binary_tree<value_type>::get_current() const{
    return current;
}

template <class value_type>
bnode<value_type>*& binary_tree<value_type>::get_root() const{
    return root;
}

template <class value_type>
std::size_t binary_tree<value_type>::size() const {
    return tree_size(root);
}