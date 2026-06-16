#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "node.cpp"
#include "linkedlisttoolkit.h"
#include <iostream>

class DoubleLinkedList 
{
    public:
        DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList& other);
        ~DoubleLinkedList();

        dnode* getCursor();
        dnode* getHeadPtr();
        dnode* getTailPtr();
        std::size_t getSize();

        void nextCursor();
        void resetCursor();
        void prevCursor();
        bool findCursor(value_type data);

        void insertHead(value_type newdata);
        void insertTail(value_type newdata);
        void insert(value_type newdata);
        
        void deleteHead();
        void deleteTail();
        bool removeData(value_type olddata);
        void deleteCurrent();

        void print_list();
        void reverseList();
        void sortList();

    private:
        dnode* headPtr;
        dnode* tailPtr;
        dnode* cursor;
        std::size_t size;
};

#include "doublelinkedlist.cpp"
#endif
