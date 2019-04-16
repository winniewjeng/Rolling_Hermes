//
//  Stack.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack(unsigned int cap): _size(0), _cap(cap) {
    _top = nullptr;
    //    _top = new node<disk>();
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
    // cout << *d << " - " << d <<endl;
    // insert head function
    // create a new node storing item *d and next* nullptr
    node<disk>* new_node = new node<disk>(*d);
    new_node->_next = _top;
    _top = new_node;
    _size++;
}

disk* Stack::pop() {
    if (empty())
        throw STACK_EMPTY;
    
    disk item = _top->_item;
    
    _size--;
    node<disk>* temp = _top;
    if (_top->_next) {
        _top = _top->_next;
    }
    delete temp;
    cout  << "new top is "<< _top->_item << " " << _top <<endl<<endl;
    
    return &item;
}

disk* Stack::peek() {
    if (empty())
        throw STACK_EMPTY;
    //    node<disk>* walker = _top;
    return &_top->_item;
    //    return &(walker+_size-1)->_item;
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
