//
//  Stack.hpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "Linked List.hpp"
#include "disk.hpp"
#include "Node.hpp"

enum STACK_ERRORS{STACK_EMPTY, STACK_FULL, STACK_BAD_SIZE};

template <class T>
class Stack {
private:
    LinkedList<T> _head;
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
    
    void push(const T& item);
    // Function: push
    // Description: Accessor, see if the array is full.
    // Return type: void
    // Paramaters: const T& item
    const T pop();
    // Function: pop
    // Description: take the top of stack out
    // Return type: const T
    // Paramaters: none
    const T& peek();
    // Function: peek
    // Description: checks the disk at top of stack
    // Return type: T&
    // Paramaters: none
    
    void clear();
    // Function: clear
    // Description: clears the stack of nodes
    // Return type: void
    // Paramaters: none
    std::ostream& print(std::ostream& outs) const;
    // Function: print stack
    // Description: prints out all nodes in stack
    // Return type: std::ostream&
    // Paramaters: std::ostream& outs
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
    
    unsigned int getSize() const {return _size;}
    // Function: get size
    // Description: returns the size of stack
    // Return type: unsigned int
    // Paramaters: none
    unsigned int getCap() const {return _cap;}
    // Function: get capacity
    // Description: returns the capacity of stack
    // Return type: unsigned int
    // Paramaters: none
    const T& at(unsigned int i) {return _head.at(i);}
};


template <class T>
Stack<T>::Stack(unsigned int cap): _cap(cap), _size(0), _head() {}

template <class T>
Stack<T>::~Stack() {
    _head.clear();
}

template <class T>
Stack<T>::Stack(const Stack& other) {
    _head = other._head;
    _size = other._size;
    _cap = other._cap;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    return (this == &other)? (*this):(_head = other._head, *this);
}

template <class T>
void Stack<T>::push(const T& item) {
    if (_size >= _cap)
        throw STACK_FULL;
    ++_size;
    _head.insertHead(item);
}

template <class T>
const T Stack<T>::pop() {
    if (empty())
        throw STACK_EMPTY;
    -- _size;
    return _head.removeNode(_head.begin());
}

template <class T>
const T& Stack<T>::peek() {
    return (_head.front());
}

template <class T>
void Stack<T>::clear() {
    _head.clear();
    _size = 0;
}

template <class T>
std::ostream& Stack<T>::print(std::ostream& outs) const {
    return _head.print(outs, _head);
}

template <class T>
void Stack<T>::resize(unsigned int cap) {
    _cap = cap;
}

template <class T>
bool Stack<T>::empty() {
    return _size == 0;
}

template <class T>
bool Stack<T>::full() {
    return _size == _cap;
}






#endif /* Stack_hpp */
