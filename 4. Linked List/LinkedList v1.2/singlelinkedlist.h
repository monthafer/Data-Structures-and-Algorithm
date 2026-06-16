#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "node.cpp"
#include "linkedlisttoolkit.h"
#include <iostream>

class SingleLinkedList {
    private:
        node* headPtr;
        node* cursor;
        std::size_t size;

    public:
        SingleLinkedList();
        SingleLinkedList(const SingleLinkedList& other);
        ~SingleLinkedList();

        node* getCursor();
        node* getHeadPtr();
        std::size_t getSize();

        void nextCursor();
        void resetCursor();
        void prevCursor();
        bool findCursor(value_type value);

        void insertHead(value_type value);
        void insert(value_type value);

        void deleteHead();
        void removeData(value_type value);
        void deleteCurrent();
        void deleteAllNodes();

        void print_list() const;

        void reverseList();
        // void printSortList();
        void applySort();
};

#include "singlelinkedlist.cpp"
#endif
