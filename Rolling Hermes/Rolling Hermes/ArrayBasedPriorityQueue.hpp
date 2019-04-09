//
//  ArrayBasedPriorityQueue.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/8/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef ArrayBasedPriorityQueue_hpp
#define ArrayBasedPriorityQueue_hpp

enum PRIORITY_QUEUE_ERRORS{PQ_EMPTY, PQ_FULL, PQ_BAD_SIZE};

template <class Data, class Priority>
struct element {
    Data data;
    Priority priority;
};

template <class Data, class Priority>
element<Data, Priority>* copyOther(element<Data, Priority>* other, unsigned int capacity);


template <class Data, class Priority>
class arrPriorityQueue {
private:
    element<Data, Priority>* head;
    unsigned int size;
    unsigned int capacity;
    
public:
    arrPriorityQueue(unsigned int _cap = 5);
    ~arrPriorityQueue();
    arrPriorityQueue(const arrPriorityQueue<Data, Priority>& other);
    arrPriorityQueue<Data, Priority>& operator= (const arrPriorityQueue<Data, Priority>& other);
    
    // Booleans
    bool full() const {return size == capacity;};
    bool empty() const {return size == 0;};
    
    // Accessors
    unsigned int getSize() const {return size;};
    unsigned int getCapacity() const {return capacity;};
    const Data& peek() const {return head[size-1].data;};
    
    // Mutators
    void clear();
    void resize(unsigned int s);
    void push(Data d, Priority p);
    Data& pop();
    
    
//    arrPriorityQueue<Data,Priority>& operator>>(Data &d);
//    arrPriorityQueue<Data,Priority>& operator<<(const node<Data,Priority> &n);
//
};

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>::arrPriorityQueue(unsigned int _cap): capacity(_cap) {
    head = new element<Data, Priority>[capacity]();
    size = 0;
}

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>::~arrPriorityQueue() {
    clear();
}

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>::arrPriorityQueue(const arrPriorityQueue<Data, Priority>& other) {
    clear();
    capacity = other.capacity;
    size = other.size;
    head = copyOther(other.head, capacity);
}

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>& arrPriorityQueue<Data, Priority>::operator= (const arrPriorityQueue<Data, Priority>& other) {
    if (this == &other)
        return *this;
    clear();
    capacity = other.capacity;
    size = other.size;
    head = copyOther(other.head, capacity);
    return *this;
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::clear() {
    delete [] head;
    head = nullptr;
    size = 0;
    capacity = 5;
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::resize(unsigned int s) {
    
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::push(Data d, Priority p) {
    
}

template <class Data, class Priority>
Data& arrPriorityQueue<Data, Priority>::pop() {
    if (empty())
        throw PQ_EMPTY;
    size --;
    element<Data, Priority>* walker = head;
    element<Data, Priority>* end = head + size - 1;
    Data temp = head -> data;
    
    while (walker < end) *walker = *(++walker);
    
    return temp;
}




template <class Data, class Priority>
element<Data, Priority>* copyOther(element<Data, Priority>* other, unsigned int capacity) {
    
    element<Data, Priority>* temp = new element<Data, Priority>[capacity]();
    element<Data, Priority>* walker = temp;
    for (int i = 0; i < capacity; ++ i) {
        *walker = *other;
        walker ++;
        other ++;
    }
    return temp;
}



#endif /* ArrayBasedPriorityQueue_hpp */
