#include <iostream>
#include "singlelinkedlist.h"

int main(){
    SingleLinkedList list;

    list.insertHead(3);
    list.insert(4);
    list.insert(1);
    list.insert(2);

    list.printSortList();

    return 0;
}


