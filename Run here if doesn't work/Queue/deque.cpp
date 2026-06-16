#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

typedef std::size_t size_type;

template <class value_type>
class Deque {
    private:
        static const size_type MAX = 100;
        value_type data[MAX];
        size_type front_index;
        size_type rear_index;
        size_type current_size;
    public:
        Deque();

        void push_front(const value_type& newData);
        void push_back(const value_type& newData);
        void pop_front();
        void pop_back();

        bool empty() const;
        size_type size() const;
        value_type front() const;
        value_type back() const;
};

template <class value_type>
Deque<value_type>::Deque(){
    front_index = 0;
    rear_index = 0;
    current_size = 0;
}

template <class value_type>
value_type Deque<value_type>::front() const{
    if(empty()){
        throw std::underflow_error("Deque is empty :>");
    } 
    return data[front_index];
}

template <class value_type>
value_type Deque<value_type>::back() const{
    if(empty()){
        throw std::underflow_error("Deque is empty :>");
    } 
    return data[(rear_index - 1 + MAX) % MAX];
}

template <class value_type>
void Deque<value_type>::push_front(const value_type& newData){
    if(current_size == MAX){
        throw std::overflow_error("Deque is full :>");
    } 
    front_index = (front_index - 1 + MAX) % MAX;
    data[front_index] = newData;
    ++current_size;
}

template <class value_type>
void Deque<value_type>::push_back(const value_type& newData){
    if(current_size == MAX){
        throw std::overflow_error("Deque is full :>");
    } 
    data[rear_index] = newData;
    rear_index = (rear_index + 1) % MAX;
    ++current_size;
}

template <class value_type>
void Deque<value_type>::pop_front(){
    if(empty()){
        throw std::underflow_error("Deque is empty :>");
    } 
    front_index = (front_index + 1) % MAX;
    --current_size;
}

template <class value_type>
void Deque<value_type>::pop_back(){
    if(empty()){
        throw std::underflow_error("Deque is empty :>");
    } 
    rear_index = (rear_index - 1 + MAX) % MAX;
    --current_size;
}

template <class value_type>
bool Deque<value_type>::empty() const{
    return current_size == 0;
}

template <class value_type>
size_type Deque<value_type>::size() const{
    return current_size;
}

#endif
