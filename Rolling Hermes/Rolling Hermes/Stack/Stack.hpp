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

template <class D>

class Stack {
private:
    disk disc;
    int size;
    
public:
    Stack();
    ~Stack();
    
    void push(D dis);
    void pop();
    int StackSize();
    
};
template <class D>
Stack<D>::Stack() {}

template <class D>
Stack<D>::~Stack() {}

template <class D>
void Stack<D>::push(D dis) {}

template <class D>
void Stack<D>::pop() {}

template <class D>
int Stack<D>::StackSize() {}



#endif /* Stack_hpp */
