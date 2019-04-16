//
//  Stack.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack(unsigned int cap): _size(0), _cap(cap), head(nullptr) {}

Stack::~Stack() {
    clear(); // not yet implemented
}

Stack::Stack(const Stack& other) {
    clear();
    
    //copy other stack's disk into this stack ...
    
    _size = other._size;
    _cap = other._cap;
    
}

Stack& Stack::operator=(const Stack& other) {
    
    if (this == &other) {
        return *this;
    }
    
    clear();
    
    _cap = other._cap;
    _size = other._size;
    // copy the disks over - not yet implemented
    
    return *this;
}

void Stack::push(disk* d) {
    if (full()) {
        throw STACK_FULL;
    }
    
    disk* walker = head;
    
    while (walker != nullptr) {
        *walker = *(walker + 1);
        walker++;
    }
    
    walker = d;
    cout << "hi"<<endl;
    cout << *walker <<  endl;
    _size++;
}

disk& Stack::pop() {
    disk d;
    return d;
}

disk& Stack::peek() {
    disk d;
    return d;
}

void Stack::clear() {
    
}

void Stack::print() const {
    
}

void Stack::resize() {
    
}

bool Stack::empty() {
    return _size == 0;
}

bool Stack::full() {
    return _size == _cap;
}

int Stack::getSize() const {
    return _size;
}

// insertion/extraction optrs
Stack& Stack::operator>>(disk& disc) {
    
    return *this;
}

Stack& Stack::operator<<(const disk& d) {
    return *this;
}

// iostream
template<typename R>
std::ostream& operator<<(std::ostream &out, const Stack &s) {
    return out;
}

template<typename R>
std::istream& operator>>(std::istream &in, Stack &q) {
    return in;
}
