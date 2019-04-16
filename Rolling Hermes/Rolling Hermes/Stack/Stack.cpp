//
//  Stack.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack(unsigned int cap): _size(0), _cap(cap) {
    _top = new node[_cap]();
}

Stack::~Stack() {
    clear(); // not yet implemented
}

Stack::Stack(const Stack& other) {
    clear();
    
    //copy other stack's disk into this stack - not yet imp
    
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
    
    if (full())
        throw STACK_FULL;
    
//    cout << *d << " - " << d <<endl;
    
    node n = node(*d, nullptr);
    (_top+_size)->_item = *d;
//    cout  << (_top+_size)->_item <<  endl;
    _size++;
}

disk* Stack::pop() {
    if (empty())
        throw STACK_EMPTY;
    
    node* temp = _top;
    _top = _top->_next;
    _size--;
    
    return &temp->_item;
}

disk* Stack::peek() {

    disk* e;
    return e;
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
