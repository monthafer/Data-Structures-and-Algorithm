#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <stdexcept>

// #ifndef VALUE_TYPE
// #define VALUE_TYPE int
// #endif

// typedef VALUE_TYPE value_type;
typedef std::size_t size_type;

template <class value_type>
class Queue {
    private:
        static const size_type MAX = 100;
        value_type data[MAX];
        size_type front_index;
        size_type rear_index;
        size_type current_size;
    public:
        Queue();

        void pop();
        void push(const value_type& newData);
        void push_priority(const value_type& newData);

        bool empty() const;
        size_type size() const;
        value_type front() const;
};

template <class value_type>
Queue<value_type>::Queue(){
    front_index = 0;
    rear_index = 0;
    current_size = 0;
}

template <class value_type>
value_type Queue<value_type>::front() const{
    if(empty()){
        throw std::underflow_error("There's nothing in the queue :>");
    } 
    return data[front_index];
}

template <class value_type>
void Queue<value_type>::pop(){
    if(empty()){
        throw std::underflow_error("There's nothing in the queue :>");
    } 
    front_index = (front_index + 1) % MAX;
    --current_size;
}

template <class value_type>
void Queue<value_type>::push(const value_type& newData){
    if(current_size == MAX){
        throw std::overflow_error("The queue is in max occupancy :>");
    } 
    data[rear_index] = newData;
    rear_index = (rear_index + 1) % MAX;
    ++current_size;
}

template <class value_type>
void Queue<value_type>::push_priority(const value_type& newData){
    if (current_size == MAX) {
        throw std::overflow_error("The queue is in max occupancy :>");
    }

    size_type pos = rear_index;
    for (size_type i = 0; i < current_size; ++i) {
        size_type index = (front_index + i) % MAX;
        if (newData < data[index]) {
            pos = index;
            break;
        }
    }

    for (size_type i = current_size; i > 0; --i) {
        size_type src = (front_index + i - 1) % MAX;
        size_type dest = (src + 1) % MAX;
        data[dest] = data[src];
        if (src == pos) break;
    }

    data[pos] = newData;
    rear_index = (rear_index + 1) % MAX;
    ++current_size;
}

template <class value_type>
bool Queue<value_type>::empty() const{
    return current_size == 0;
}

template <class value_type>
size_type Queue<value_type>::size() const{
    return current_size;
}

#endif