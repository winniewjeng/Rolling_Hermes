//
//  Stack.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack(disk d):_disk(d), _size(0), _cap(0) {}

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

void Stack::push(disk disc) {
    
}

disk& Stack::pop() {
    return _disk;
}

disk& Stack::peek() {
    return _disk;
}

void Stack::clear() {
    
}

void Stack::print() const {
    
}
void Stack::resize() {
    
}

bool Stack::empty() {
    return 0;
}

bool Stack::full() {
    return 0;
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
std::ostream& operator<<(std::ostream &out, const Stack &s) {
    return out;
}
std::istream& operator>>(std::istream &in, Stack &q) {
    return in;
}
