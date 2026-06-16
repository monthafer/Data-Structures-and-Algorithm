#include "node.cpp"
#include "linkedlisttoolkit.h"
#include <iostream>

// ---Single Linked List-------------------------------------------------------------
std::size_t list_length(const node* headPtr){
    std::size_t count = 0;
    while (headPtr != nullptr){
        count++;
        headPtr = headPtr -> next;
    }
    return count;
}

void printReverse(node* headPtr){
    if(headPtr == nullptr){
        return;
    }
    printReverse(headPtr -> next);
    std::cout << headPtr -> data << " -> ";
}

// node* reverse(node* headPtr){
//     if(headPtr == nullptr || headPtr -> next == nullptr){
//         return headPtr;
//     }

//     node* rest = reverse(headPtr->next);
//     headPtr -> next -> next = headPtr;
//     headPtr -> next = nullptr;
//     return rest;
// }

// node* merge(node* headPtr1, node* headPtr2){
//     if(headPtr1 == nullptr){
//         return headPtr2;
//     } else if(headPtr2 == nullptr){
//         return headPtr1;
//     }

//     node* temp = headPtr1;
//     while(temp -> next != nullptr){
//         temp = temp -> next;
//     }
//     temp -> next = headPtr2;

//     return headPtr1;
// }

node* sort(node* headPtr){
    node* current = headPtr;
    while(current -> next != nullptr){
        node* min = current;
        node* temp = current -> next;
        while(temp != nullptr){
            if(temp -> data < min -> data){
                min = temp;
            }
            temp = temp -> next;
        }
        if (min != current) {
            value_type temp_data = current -> data;
            current -> data = min -> data;
            min -> data = temp_data;
        }
        current = current -> next;
    }
    return headPtr;
}

// node* sortnode(node* headPtr){
//     std::size_t len = list_length(headPtr);
//     node* current = headPtr;
//     node* headmin = current;
//     int found = 0;

//     // for(std::size_t i = 1; i <= list_length(headcopy); ++i){
//     //     node* min = locate(headcopy, i);
//     //     node* prev, nex;

//     //     for(std::size_t j = i; j <= list_length(headcopy); ++j){
//     //         if(min > locate(headcopy, j)){
//     //             min = locate(headcopy, j);
//     //             prev = locate(headcopy, j-1);
//     //             nex = locate(headcopy, j+1);
//     //         }
//     //     }

//     //     if(min != locate(headcopy, i)){
//     //         prev -> next = nex;
//     //         min -> next = locate(headcopy, i);
//     //     }
//     // }

//     for(std::size_t i = 1; i <= len; ++i){
//         node* min = current;
//         node* nex;
//         if(current -> next != nullptr) {
//             nex = current -> next;
//         }

//         std::cout << "1. Debug: current=" << current->data << " min=" << min->data << std::endl;

//         for(std::size_t j = i; j <= len - 1; ++j){
//             if(nex != nullptr) {

//                 if(min -> data > nex -> data){
//                     min = nex;
//                     found++;
//                 }
                
//                 nex = nex -> next;
//             }
//         }
        

//         std::cout << "inside for done, found=" << found << " min=" << min->data << " current=" << current->data << std::endl;

//         if(found > 0){
//             node* prev;
//             for(prev = headmin; prev -> next -> data != min -> data; prev = prev -> next);

//             std::cout << "there's found, prev=" << prev->next->data << " min=" << min->data << " current=" << current->data << std::endl;

//             if(min -> data == locate(headmin, len) -> data){
//                 std::cout << "Works, locatedata=" << locate(headmin, len) -> data << std::endl;
//                 prev -> next = nullptr;
//                 std::cout << "there's found, prev=" << prev->next << " min=" << min->next << " current=" << current->data << std::endl;
//                 min -> next = new node();
//                 min -> next = current;
//             } else{
//                 prev -> next = min -> next;
//                 min -> next = current;
//             }

//             // std::cout << "Works, locatedata=" << locate(headmin, len) -> data << std::endl;
//             // prev -> next = min -> next;
//             // min -> next = current;
        
//             std::cout << "there's found, prevnext=" << prev->next->data << " min=" << min->next->data << " current=" << current->data << std::endl;
//             current = min;
//             std::cout << "there's found, minnext=" << min->next->data << " current=" << current->data << std::endl;
//             found = 0;
//         }

//         if(headmin -> data > current -> data){
//             std::cout << "before headmin=" << headmin->data << std::endl; 
//             headmin = current;
//             std::cout << "after headmin=" << headmin->data << std::endl;
//         }

//         current = current -> next;
//     }

//     return headmin;
// }

void sortnode(node*& headPtr) {
    if (headPtr == nullptr || headPtr -> next == nullptr) {
        // return headPtr;
        return;
    }

    node* headmin = nullptr;
    node* tail = nullptr;

    while (headPtr != nullptr) {

        node* minPrev = nullptr;
        node* minNode = headPtr;
        node* prev = headPtr;
        node* current = headPtr -> next;

        while (current != nullptr) {
            if (current -> data < minNode -> data) {
                minPrev = prev;
                minNode = current;
            }
            prev = current;
            current = current -> next;
        }

        if (minPrev != nullptr) {
            minPrev -> next = minNode -> next;
        } else {
            headPtr = minNode -> next;
        }

        if (headmin == nullptr) {
            headmin = minNode;
            tail = headmin;
        } else {
            tail -> next = minNode;
            tail = minNode;
        }

        // minNode->next = headmin;
        // headmin = minNode;

        tail -> next = nullptr;
    }

    // return headmin;
    headPtr = headmin;
}


// void printSortedList(node* headPtr){
//     node* sorted = new node();
//     sorted = sortnode(headPtr);
//     while(sorted != nullptr){
//         std::cout << sorted -> data << " -> ";
        
//         sorted = sorted -> next;
//     }
//     std::cout << "nullptr" << std::endl;
// }

node* search(node* headPtr, value_type target){
    node* current = headPtr;
    
    if(current == nullptr){
        return nullptr;
    }
        
    while(current != nullptr){
        if(current -> data == target){
            return current;
        }
        current = current -> next;
    }
    

    // for(current = headPtr; current -> next != nullptr; current = current -> next){
    //     if(current -> data == target){
    //         found = true;
    //         break;
    //     }
    // }
    return nullptr;
}

// node* locate(node* headPtr, std::size_t position){
//     if(headPtr == nullptr || position == 0){
//         return nullptr;
//     } else{
//         bool found = false;
//         node* current = headPtr;
//         for(std::size_t i = 1; i < position; ++i){
//             if(current == nullptr){
//                 return nullptr;
//             }
//             current = current -> next;
//         }
//         return current;
//     }
// }

void copy(const node* source, node*& headPtr) {
    headPtr = nullptr;

    if (source == nullptr){
        return;
    } 

    headPtr = new node();
    headPtr -> data = source -> data;

    source = source -> next;
    while (source != nullptr){
        node* newNode = new node();
        newNode -> data = source -> data;
        
        source = source -> next;
    }
}


void headInsert(node*& headPtr, value_type value){
    node* newNode = new node();
    newNode -> data = value;
    newNode -> next = headPtr;
    headPtr = newNode;
}

bool headRemove(node*& headPtr){
    if (headPtr == nullptr) {
        return false;
    } else{
        node* temp = headPtr;
        headPtr = headPtr -> next;
        delete temp;
        return true;
    }
}

bool insert(node*& headPtr, node*& cursor, value_type value){
    if(cursor == nullptr){
        return false;
    } else if(headPtr == nullptr){
        headInsert(headPtr, value);
        cursor = headPtr;
        return true;
    } else{
        node* newNode = new node();
        newNode -> data = value;
        newNode -> next = cursor -> next;
        cursor -> next = newNode;
        cursor = newNode;
        return true;
    }
}

bool removeCurrent(node*& headPtr, node*& cursor){
    if(cursor == nullptr){
        return false;
    }

    if(cursor == headPtr){
        headRemove(headPtr);
        cursor = headPtr;
    } else{
        node* prev = nullptr;
        for(prev = headPtr; prev -> next != cursor; prev = prev -> next);
        prev -> next = cursor -> next;
        if(cursor -> next != nullptr){
            cursor = cursor -> next;
        } else{
            cursor = prev;
        }
    }
    return true;
}

bool removeData(node*& headPtr, value_type target){
    node* prev = nullptr;
    node* current = headPtr;

    while(current != nullptr && current -> data != target){
        prev = current;
        current = current -> next;
    }

    if(current == nullptr){
        return false;
    }

    if(prev == nullptr){
        headPtr = headPtr -> next;
    } else{
        prev -> next = current -> next;
    }

    delete current;
    return true;
}

void clear(node*& headPtr){
    while (headPtr != nullptr) {
        node* temp = headPtr;
        headPtr = headPtr->next;
        delete temp;
    }
}

void printList(const node* headPtr, const node* cursor){
    while(headPtr != nullptr){
        if(headPtr == cursor){
            std::cout << "[" << headPtr -> data << "] -> ";
        } else{
            std::cout << headPtr -> data << " -> ";
        }
        headPtr = headPtr -> next;
    }
    std::cout << "nullptr" << std::endl;
}




// ---Double Linked List-------------------------------------------------------------
std::size_t list_length(const dnode* headPtr){
    std::size_t count = 0;
    while (headPtr != nullptr){
        count++;
        headPtr = headPtr -> flink;
    }
    return count;
}

void printReverse(dnode* headPtr){
    if(headPtr == nullptr){
        return;
    }
    printReverse(headPtr -> flink);
    std::cout << headPtr -> data << " <=> ";
}

// dnode* reverse(dnode* headPtr) {
//     if(headPtr == nullptr || headPtr -> flink == nullptr){
//         return headPtr;
//     }
//     dnode* rest = reverse(headPtr->flink);
//     headPtr -> flink -> flink = headPtr;
//     headPtr -> blink = headPtr -> flink;
//     headPtr -> flink = nullptr;
//     return rest;
// }

// dnode* merge(dnode* headPtr1, dnode* headPtr2){
//     if(headPtr1 == nullptr){
//         return headPtr2;
//     } else if(headPtr2 == nullptr){
//         return headPtr1;
//     }

//     dnode* temp = headPtr1;
//     while(temp -> flink != nullptr){
//         temp = temp -> flink;
//     }
//     temp -> flink = headPtr2;
//     headPtr2 -> blink = temp;

//     return headPtr1;
// }

dnode* sort(dnode* headPtr){
    dnode* current = headPtr;
    while(current != nullptr){
        dnode* min = current;
        dnode* temp = current -> flink;
        while(temp != nullptr){
            if(temp -> data < min -> data){
                min = temp;
            }
            temp = temp -> flink;
        }

        if (min != current) {
            value_type temp_data = current -> data;
            current -> data = min -> data;
            min -> data = temp_data;
        }
        current = current -> flink;
    }
    return headPtr;
}

dnode* search(dnode* headPtr, value_type target){
    if(headPtr == nullptr){
        return nullptr;
    } else {
        dnode* current;
        bool found = false;
        for(current = headPtr; current != nullptr; current = current -> flink){
            if(current -> data == target){
                found = true;
                break;
            }
        }
        if(found){
            return current;
        } else{
            return nullptr;
        }
    }
}

// dnode* locate(dnode* headPtr, std::size_t position){
//     if(headPtr == nullptr || position == 0){
//         return nullptr;
//     } else{
//         bool found = false;
//         dnode* current = headPtr;
//         for(std::size_t i = 1; i < position; ++i){
//             if(current == nullptr){
//                 return nullptr;
//             }
//             current = current -> flink;
//         }
//         return current;
//     }
// }

void copy(const dnode* source, dnode*& headPtr, dnode*& tailPtr) {
    headPtr = nullptr;
    tailPtr = nullptr;

    if (source == nullptr){
        return;
    } 

    headPtr = new dnode();
    headPtr -> data = source -> data;
    tailPtr = headPtr;

    source = source -> flink;
    while (source != nullptr){
        dnode* newNode = new dnode();
        newNode -> data = source -> data;
        if(tailPtr != nullptr){
            tailPtr -> flink = newNode;
            newNode -> blink = tailPtr;
        }
        tailPtr = newNode;
        source = source -> flink;
    }
}


void headInsert(dnode*& headPtr, value_type value){
    dnode* newNode = new dnode();
    newNode -> data = value;
    newNode -> flink = headPtr;
    newNode -> blink = nullptr;
    headPtr = newNode;
}

bool headRemove(dnode*& headPtr){
    if(headPtr == nullptr){
        return false;
    }

    dnode* temp = headPtr;
    if(headPtr -> flink == nullptr){
        headPtr = nullptr;
    } else{
        headPtr = headPtr -> flink;
        headPtr -> blink = nullptr;
    }

    delete temp;
    return true;
}

// void tailInsert(dnode*& headPtr, value_type value){ //this func will not implement the tail "tailPtr"
//     if(headPtr == nullptr){
//         headInsert(headPtr, value);
//     } else if(headPtr -> flink == nullptr){
//         dnode* newNode = new dnode();
//         newNode -> data = value;
//         headPtr -> flink = newNode;
//         newNode -> blink = headPtr;
//         newNode -> flink = nullptr;
//     } else{
//         dnode* tail;
//         for(tail = headPtr; tail -> flink != nullptr; tail = tail -> flink);
//         dnode* newNode = new dnode();
//         newNode -> data = value;
//         tail -> flink = newNode;
//         newNode -> blink = tail;
//         newNode -> flink = nullptr;
//     }
// }

void tailInsert(dnode*& tailPtr, dnode*& headPtr, value_type value){
    dnode* newNode = new dnode();
    newNode -> data = value;

    if (tailPtr == nullptr) {
        headPtr = tailPtr = newNode;
    } else {
        tailPtr -> flink = newNode;
        newNode -> blink = tailPtr;
        tailPtr = newNode;
    }
}

bool tailRemove(dnode*& tailPtr){
    if(tailPtr == nullptr){
        return false;
    } else{
        if(tailPtr -> blink == nullptr){
            // headRemove(tailPtr);
            // tailPtr = nullptr;
            return true;
        } else{
            dnode* newNode = tailPtr -> blink;
            newNode -> flink = nullptr;
            tailPtr -> blink = nullptr;
            tailPtr = newNode;
            return true;
        }
    }
}

bool insert(dnode*& headPtr, dnode*& cursor, value_type value){
    if(cursor == nullptr){
        return false;
    } 
    // else if(cursor == headPtr){
    //     headInsert(headPtr, value);
    //     return true;
    // } 
    else{
        dnode* newNode = new dnode();
        newNode -> data = value;
        if(cursor -> flink != nullptr){
            cursor -> flink -> blink = newNode;
        }
        newNode -> flink = cursor -> flink;
        newNode -> blink = cursor;
        cursor -> flink = newNode;
        return true;
    }
}

bool removeCurrent(dnode*& headPtr, dnode*& cursor){
    if(cursor == nullptr){
        return false;
    }

    if(cursor == headPtr){
        headRemove(headPtr);
        cursor = headPtr;
    } else{
        dnode* current;
        for(current = headPtr; current != cursor; current = current -> flink);
        if(current -> flink != nullptr){
            current -> flink -> blink = current -> blink;
        }
        current -> blink -> flink = current -> flink;
        current -> flink = nullptr;
        current -> blink = nullptr;
        delete current;
    }
    return true;
}

bool removeData(dnode*& headPtr, value_type target){
    dnode* current = search(headPtr, target);
    if(current == nullptr){
        return false;
    }

    if(current == headPtr){
        headRemove(headPtr);
        return true;
    }

    if(current -> flink != nullptr){
        current -> flink -> blink = current -> blink;
    }
    if(current -> blink != nullptr){
        current -> blink -> flink = current -> flink;
    }
    delete current;

    return true;
}

void clear(dnode*& headPtr){
    while (headPtr != nullptr) {
        dnode* temp = headPtr;
        headPtr = headPtr->flink;
        delete temp;
    }
}

void printList(const dnode* headPtr, const dnode* cursor){
    if(headPtr == nullptr){
        std::cout << nullptr << std::endl;
        return;
    }

    std::cout << "nullptr <- ";
    while(headPtr != nullptr){
        if(headPtr == cursor && headPtr -> flink == nullptr){
            std::cout << "[" << headPtr -> data << "] -> ";
        } else if(headPtr == cursor){
            std::cout << "[" << headPtr -> data << "] <=> ";
        } else if(headPtr -> flink == nullptr){
            std::cout << headPtr -> data << " -> ";
        }
        else{
            std::cout << headPtr -> data << " <=> ";
        }
        headPtr = headPtr -> flink;
    }
    std::cout << "nullptr" << std::endl;
}

void sortnode(dnode*& headPtr, dnode*& tailPtr) {
    if (headPtr == nullptr || headPtr -> flink == nullptr) {
        // return headPtr;
        return;
    }

    dnode* headmin = nullptr;
    dnode* tail = nullptr;

    while (headPtr != nullptr) {

        // dnode* minPrev = nullptr;
        dnode* minNode = headPtr;
        dnode* current = headPtr -> flink;

        while (current != nullptr) {
            if (current -> data < minNode -> data) {
                minNode = current;
            }
            current = current -> flink;
        }

        if (minNode != headPtr) {
            if(minNode -> flink != nullptr){
                minNode -> flink -> blink = minNode -> blink;
            }
            minNode -> blink -> flink = minNode -> flink;
        } else {
            headPtr = minNode -> flink;
        }

        if (headmin == nullptr) {
            headmin = minNode;
            tail = headmin;
        } else {
            tail -> flink = minNode;
            minNode -> blink = tail;
            tail = minNode;
        }

        // minNode->next = headmin;
        // headmin = minNode;

        tail -> flink = nullptr;
    }

    // return headmin;
    headPtr = headmin;
    tailPtr = tail;
}
