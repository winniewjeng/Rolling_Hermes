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

class Stack {
private:
    disk _disk;
    int _size;
    int _cap;
    
public:
    Stack(disk d = disk());
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    
    void push(disk disc);
    disk& pop();
    disk& peek();
    void clear();
    void print() const;
    void resize();
    
    bool empty();
    bool full();
    
    Stack& operator>>(disk& d);
    Stack&  operator<<(const disk& d);
    
    // iostream
    friend std::ostream& operator<<(std::ostream &out, const Stack &s);
    friend std::istream& operator>>(std::istream &in, Stack &q);
    
    int getSize() const;
};


#endif /* Stack_hpp */
