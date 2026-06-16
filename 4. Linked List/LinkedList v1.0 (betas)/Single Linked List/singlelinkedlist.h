#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include "node.h"
#include "linkedlisttoolkit.h"
#include <iostream>

class SingleLinkedList {
    public:
        typedef std::size_t size_type;

        SingleLinkedList();
        SingleLinkedList(const SingleLinkedList& other);
        ~SingleLinkedList();

        node::value_type get_cursor_data();
        node::value_type get_headPtr_data();

        node* get_cursor();
        node* get_headPtr();
        void nextcursor();
        void resetcursor();
        void prevcursor();

        void list_head_insert(node::value_type newdata);
        void list_head_remove();
        void list_insert(node::value_type newdata);
        void list_removedata(node::value_type olddata);
        void list_removenode();

        void list_print();

        node::value_type* list_to_array();

    private:
        node* headPtr;
        node* cursor;
        size_t size;
};

#include "singlelinkedlist.cpp"
#endif
