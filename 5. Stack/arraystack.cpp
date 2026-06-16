#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include <stdexcept>

// #ifndef VALUE_TYPE
// #define VALUE_TYPE int
// #endif

// typedef VALUE_TYPE value_type;
typedef std::size_t size_type;

template <class value_type>
class ArrayStack {
    private:
        static const size_type MAX = 100;
        value_type data[MAX];
        size_type current_size;
    public:
        ArrayStack();
        ~ArrayStack();

        value_type peek() const;
        value_type pop();
        void push(const value_type& newData);

        bool empty() const;
        size_type size() const;
        value_type top() const;
};

template <class value_type>
ArrayStack<value_type>::ArrayStack(){
    current_size = 0;
}

template <class value_type>
ArrayStack<value_type>::~ArrayStack(){
    current_size = 0;
}

template <class value_type>
value_type ArrayStack<value_type>::peek() const{
    if(empty()){
        throw std::underflow_error("Stack is empty:>");
    } 
    return data[current_size - 1];
}

template <class value_type>
value_type ArrayStack<value_type>::pop(){
    if(empty()){
        throw std::underflow_error("Stack is empty:>");
    } 
    return data[--current_size];
}

template <class value_type>
void ArrayStack<value_type>::push(const value_type& newData){
    if(current_size == MAX){
        throw std::overflow_error("Stack is full:<");
    } 
    data[current_size++] = newData;
}

template <class value_type>
bool ArrayStack<value_type>::empty() const{
    return current_size == 0;
}

template <class value_type>
size_type ArrayStack<value_type>::size() const{
    return current_size;
}

template <class value_type>
value_type ArrayStack<value_type>::top() const{
    return peek();
}

#endif