#ifndef RING_H
#define RING_H

#include <iostream>

class Ring {
    public:
        int size;

        Ring(int s = 0);
        void print() const;
};

Ring::Ring(int s){
    size = s;
}

void Ring::print() const{
    std::cout << "Ring size: " << size << std::endl;
}

#endif