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

struct node {
    disk _item;
    node* _next;
    // ctor
    node(disk d = disk(), node* n = nullptr): _item(d), _next(n) {}
};


class Stack {
private:
    node* _top;
    int _size;
    int _cap;
    
public:
    Stack(unsigned int cap = 10);
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    
    void push(disk* d);
    disk* pop();
    disk* peek();
    void clear();
    void print() const;
    void resize();
    
    bool empty();
    bool full();
    
    int getSize() const;
    
    Stack& operator>>(disk& d);
    Stack& operator<<(const disk& d);
    
    // iostream
    template<typename R>
    friend std::ostream& operator<<(std::ostream &out, const Stack &s);
    template<typename R>
    friend std::istream& operator>>(std::istream &in, Stack &q);
    
};


#endif /* Stack_hpp */
