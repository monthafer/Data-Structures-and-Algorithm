// #include "liststack.h"
#include "arraystack.cpp"
#include "../Linked List/doublelinkedlist.h"

int main() {
    ArrayStack<DoubleLinkedList> stack;

    DoubleLinkedList list1;
    list1.insertHead(10);
    list1.insertTail(20);

    DoubleLinkedList list2;
    list2.insertHead(30);
    list2.insertTail(40);
    list2.resetCursor();
    list2.insert(7);

    DoubleLinkedList list3;
    list3.insertHead(50);
    list3.insert(37);
    list3.insertTail(60);

    stack.push(list1);
    stack.push(list2);
    stack.push(list3);
    

    stack.peek().print_list();

    std::cout << "Orig Stack size: " << stack.size() << std::endl;
    stack.pop();

    DoubleLinkedList poppedList = stack.peek();
    poppedList.nextCursor();
    poppedList.print_list();

    std::cout << "1: Stack size: " << stack.size() << std::endl;
    stack.pop();

    DoubleLinkedList poppedList2 = stack.pop();
    poppedList2.print_list();

    std::cout << "2: Stack size: " << stack.size() << std::endl;

    std::cout << "Is Empty: " << stack.empty() << std::endl;

    return 0;
}
