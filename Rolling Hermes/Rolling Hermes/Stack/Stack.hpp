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
#include "Node.hpp"

enum STACK_ERRORS{STACK_EMPTY, STACK_FULL, STACK_BAD_SIZE};

// Linked-list stack
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
    // Function: copy stack
    // Description: copy other's stack to this stack
    // Return type: node<disk>*
    // Paramaters: const Stack&
    
    void push(disk* d);
    // Function: push
    // Description: Accessor, see if the array is full.
    // Return type: void
    // Paramaters: disk*
    void insert_top(disk* d);
    // Function: insert top
    // Description: insert node at top of stack
    // Return type: void
    // Paramaters: disk*
    void insert_bottom(disk* d);
    // Function: insert bottom
    // Description: insert node at bottom of stack
    // Return type: void
    // Paramaters: disk*
    disk pop();
    // Function: pop
    // Description: take the top of stack out
    // Return type: disk
    // Paramaters: none
    disk peek();
    // Function: peek
    // Description: checks the disk at top of stack
    // Return type: checks the top of stack
    // Paramaters: none
    
    void clear();
    // Function: clear
    // Description: clears the stack of nodes
    // Return type: void
    // Paramaters: none
    void print() const;
    // Function: print stack
    // Description: prints out all nodes in stack
    // Return type: void
    // Paramaters: none
    void resize(unsigned int cap);
    // Function: resize
    // Description: enlarges or shrinks stack capacity
    // Return type: void
    // Paramaters: unsigned int
    
    //
    bool empty();
    // Function: empty
    // Description: checks if stack is empty
    // Return type: boolean
    // Paramaters: none
    bool full();
    // Function: full
    // Description: checks if stack is full
    // Return type: boolean
    // Paramaters: none
    
    unsigned int getSize() const;
    // Function: get size
    // Description: returns the size of stack
    // Return type: unsigned int
    // Paramaters: none
    unsigned int getCap() const;
    // Function: get capacity
    // Description: returns the capacity of stack
    // Return type: unsigned int
    // Paramaters: none
    node<disk>* getTop() const;
    // Function: get top
    // Description: returns the top node of stack
    // Return type: node<disk>*
    // Paramaters: none
    
    // overloaded operators
    Stack& operator>>(disk& d);
    Stack& operator<<(const disk& d);
    
    // iostream
    friend std::ostream& operator<<(std::ostream &out, Stack &s);
    friend std::istream& operator>>(std::istream &in, Stack &q);
    
};



#endif /* Stack_hpp */
