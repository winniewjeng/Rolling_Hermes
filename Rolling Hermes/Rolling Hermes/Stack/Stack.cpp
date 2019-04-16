//
//  Stack.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack(unsigned int cap): _size(0), _cap(cap), _top(nullptr) {}

Stack::~Stack() {
    clear();
}

Stack::Stack(const Stack& other) {
    clear();
    
    //copy other - not yet imp
    _size = other._size;
    _cap = other._cap;
    
}

Stack& Stack::operator=(const Stack& other) {
    
    if (this == &other)
        return *this;
    
    clear();
    _cap = other._cap;
    _size = other._size;
    
    // copy the disks over - not yet implemented
    
    return *this;
}

void Stack::push(disk* d) {
    
    if (full())
        throw STACK_FULL;
    
    node<disk>* new_node = new node<disk>(*d);
    new_node->_next = _top;
    _top = new_node;
    _size++;
}

// hi jack mind checking my pop()?
disk Stack::pop() {
    if (empty())
        throw STACK_EMPTY;
    
    disk item = _top->_item;
    _size--;
    // welp im creating mem leak here
    // only move next if next is not nullptr
    if (_top->_next)
        _top = _top->_next;
    
    return item;
}

disk Stack::peek() {
    if (empty())
        throw STACK_EMPTY;
    return _top->_item;
}

void Stack::clear() {
    // delete each and every single node
    while (_top->_next) {
        node<disk>*temp = _top;
        _top = _top->_next;
        delete temp;
    }
    _top = nullptr; // delete head node
    _size = 0;
    _cap = 5;
}

void Stack::print() const {
    
}

void Stack::resize(unsigned int cap) {
    if (cap < 2)
        throw STACK_BAD_SIZE;
    
    _cap = cap;
    // node<disk>* temp =  copy(_top, cap) - not yet  implemented
    //    delete[] _top;
    // _top = temp
    
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
