#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "dnode.h"
#include <iostream>

class DoubleLinkedList{
    public:
        typedef std::size_t size_type;

        DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList& other);
        ~DoubleLinkedList();

        DNode::value_type get_cursor_data();
        DNode::value_type get_headPtr_data();
        DNode::value_type get_tailPtr_data();

        DNode* get_cursor();
        DNode* get_headPtr();
        DNode* get_tailPtr();
        void nextcursor();
        void resetcursor();
        void prevcursor();

        void list_head_insert(DNode::value_type newdata);
        void list_head_remove();
        void list_insert(DNode::value_type newdata);
        void list_removedata(DNode::value_type olddata);
        void list_removenode();

        void head_insert(DNode*& headPtr, DNode::value_type newdata);
        void head_remove(DNode*& headPtr);
        void insert(DNode*& headPtr, DNode::value_type newdata);
        void removedata(DNode*& headPtr, DNode::value_type olddata);
        void removenode(DNode*& headPtr)

        void reverse(DNode*& headPtr);

    private:
        DNode* headPtr;
        DNode* tailPtr;
        DNode* cursor;
        size_t size;

}

#include "doublelinkedlist.cpp"
#endif
