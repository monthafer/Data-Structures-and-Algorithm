#ifndef ARRAYSTACKDYNAMIC_H
#define ARRAYSTACKDYNAMIC_H

#include <iostream>
#include <stdexcept>

typedef std::size_t size_type;

template <class value_type>
class ArrayStack {
    private:
        // static const size_type MAX = 100;
        size_type capa;
        value_type *data;
        size_type current_size;

        void reserve(size_type new_cap);
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
    capa = 1;
    data = new value_type[capa];
}

template <class value_type>
ArrayStack<value_type>::~ArrayStack(){
    delete[] data;
    current_size = 0;
}

template <class value_type>
void ArrayStack<value_type>::reserve(size_type new_cap) {
    value_type* new_data = new value_type[new_cap];
    for (size_type i = 0; i < current_size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new value_type[new_cap];
    for (size_type i = 0; i < current_size; ++i) {
        data[i] = new_data[i];
    }
    // data = new_data;
    capa = new_cap;
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
    if (current_size == capa - 1) {
        reserve(capa*2);
    }
    // if(current_size == MAX){
    //     throw std::overflow_error("Stack is full:<");
    // } 
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