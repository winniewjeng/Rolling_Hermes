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
    cout << "~Stack() called\n";
    clear();
}

Stack::Stack(const Stack& other) {
    
    //copy other - not yet imp
    _size = other._size;
    _cap = other._cap;
    
}

Stack& Stack::operator=(const Stack& other) {
    
    if (this != &other)  {
        clear();
        _cap = other._cap;
        _size = other._size;
        _top = copy(other);
    }
    
    return *this;
}

node<disk>* Stack::copy(const Stack& other) {
    disk item;
    node<disk>* walker = other.getTop();
    while (_size!= other.getSize()) {
        item = walker->_item;
        insert_top(&item);
        walker = walker->_prev;
    }
    return _top;
}

void Stack::insert_top(disk* d) {
    node<disk>* new_node = new node<disk>(*d);
    new_node->_prev = _top;
    _top = new_node;
    if (_top->_prev && _size != 0)
        (_top->_prev)->_next = _top;
    _size++;
}

void Stack::insert_bottom(disk* d) {
    if (!_top)
        insert_top(d);
    else {
        node<disk>* walker = _top;
        node<disk>* new_node = new node<disk>(*d);
        while(walker->_prev)
            walker =  walker->_prev;
        walker->_prev = new_node;
        new_node->_next = walker;
        _size++;
    }
}

void Stack::push(disk* d) {
    
    if (full())
        throw STACK_FULL;
    insert_top(d);
}

disk Stack::pop() {
    if (empty())
        throw STACK_EMPTY;
    
    disk item = _top->_item;
    _size--;
    if (_top->_prev)
        _top = _top->_prev;
    
    return item;
}

disk Stack::peek() {
    if (empty())
        throw STACK_EMPTY;
    return _top->_item;
}

void Stack::clear() {
    while (!empty()) {
        pop();
    }
    delete _top;
    _top = nullptr;
    _size = 0;
    _cap = 5;
    
}

void Stack::print() const {
    if (_size) {
        node<disk>* walker = _top;
        while(walker) {
            cout << "["<< walker->_item << "] ";
            walker = walker->_prev;
        }
        cout << endl;
    }
}

void Stack::resize(unsigned int cap) {
    if (cap < 2)
        throw STACK_BAD_SIZE;
    Stack s(cap);
    disk temp;
    while (!empty() && s.getSize() != cap ) {
        temp = pop();
        s.insert_bottom(&temp);
    }
    clear();
    *this = s;
}

bool Stack::empty() {
    return _size == 0;
}

bool Stack::full() {
    return _size == _cap;
}

unsigned int Stack::getSize() const {
    return _size;
}

unsigned int Stack::getCap() const {
    return _cap;
}

node<disk>* Stack::getTop() const {
    return _top;
}

// extraction optr
Stack& Stack::operator>>(disk& d) {
    d = pop();
    return *this;
}

// insertion optr
Stack& Stack::operator<<(const disk& d) {
    disk item = d;
    push(&item);
    return *this;
}

// ostream
std::ostream& operator<<(std::ostream &out, const Stack &s) {
    if (&std::cout != &out) {
        out << "Capacity: " << s.getCap() << std::endl;
        node<disk>* walker = s.getTop();
        while(walker) {
            out << " [" << walker->_item << "]";
            walker = walker->_next;
        }
    }
    
    return out;
}

// istream
std::istream& operator>>(std::istream &in, Stack &s) {
    node<disk>* temp;
    s.clear();
    std::string junk;
        if(&std::cin == &in)
            in >> junk >> s._cap;
        else
            in >> s._cap;
//        while (in >> temp) {
//            disk hold = s.pop();
//            insert_bottom(&hold);
//        }
    return in;
    
}
