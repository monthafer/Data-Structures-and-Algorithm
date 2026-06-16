#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "dnode.cpp"
#include "linkedlisttoolkit.cpp"
#include <iostream>

class DoubleLinkedList 
{
    public:
        DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList& other);
        ~DoubleLinkedList();

        dnode* get_cursor();
        dnode* get_headPtr();
        dnode* get_tailPtr();

        void c_next();
        void c_reset();
        void c_prev();
        bool c_find(dnode::value_type data);

        void insert_head(dnode::value_type newdata);
        void remove_head();
        void insert_tail(dnode::value_type newdata);
        void remove_tail();
        void insert_after(dnode::value_type newdata);
        void remove_data(dnode::value_type olddata);
        void remove_current();

        void print_list();

    private:
        dnode* headPtr;
        dnode* tailPtr;
        dnode* cursor;
        std::size_t size;
};

#include "doublelinkedlist.cpp"
#endif
