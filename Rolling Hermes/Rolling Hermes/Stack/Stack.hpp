//
//  Stack.hpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "disk.hpp"

enum STACK_ERRORS{STACK_EMPTY, STACK_FULL, STACK_BAD_SIZE};

template <typename T>
struct node {
    T _item;
    node* _next;
    node* _prev;
    // ctor
    node(T item = T()): _item(item), _next(nullptr),  _prev(nullptr) {}
};

class Stack {
private:
    node<disk>* _top;
    unsigned int _size;
    unsigned int _cap;
    
public:
    Stack(unsigned int cap = 5);
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    
    node<disk>* copy(const Stack& other);

    void push(disk* d);
    void insert_top(disk* d);
    void insert_bottom(disk* d);
    disk pop();
    disk peek();
    void clear();
    void print() const;
    void resize(unsigned int cap);
    
    bool empty();
    bool full();
    
    unsigned int getSize() const;
    unsigned int getCap() const;
    node<disk>* getTop() const;
    
    Stack& operator>>(disk& d);
    Stack& operator<<(const disk& d);
    
    // iostream
    friend std::ostream& operator<<(std::ostream &out, Stack &s);
    friend std::istream& operator>>(std::istream &in, Stack &q);
    
};



#endif /* Stack_hpp */
