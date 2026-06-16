#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "node.cpp"
#include "linkedlisttoolkit.cpp"
#include <iostream>

class SingleLinkedList{
    public:
        SingleLinkedList();
        SingleLinkedList(const SingleLinkedList& other);
        ~SingleLinkedList();

        node* get_cursor();
        node* get_headPtr();

        void c_next();
        void c_reset();
        void c_prev();
        bool c_find(node::value_type data);

        void insert_head(node::value_type newdata);
        void remove_head();
        void insert_after(node::value_type newdata);
        void remove_data(node::value_type olddata);
        void remove_current();

        void print_list();
        void reverse();

    private:
        node* headPtr;
        node* cursor;
        std::size_t size;
};

#include "singlelinkedlist.cpp"
#endif