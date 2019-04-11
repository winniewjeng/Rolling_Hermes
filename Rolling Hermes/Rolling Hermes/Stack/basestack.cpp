#include "basestack.h"

baseStack::baseStack(unsigned int cap):
    capacity(0),
    mySize(0),
    tos(nullptr)
{
    resize(cap);
}

baseStack::~baseStack()
{
    tos = nullptr;
    mySize = capacity = 0;
}

baseStack::baseStack(const baseStack& other)
{
    tos = nullptr;
    mySize = 0;
    capacity = other.capacity;
}

baseStack& baseStack::operator=(const baseStack& other)
{
    if (this != &other) {
        capacity = other.capacity;
        tos = nullptr;
        mySize = 0;
    }
    return *this;
}

bool baseStack::full()
{
    return mySize == capacity;
}

bool baseStack::empty()
{
    return !tos;
}

unsigned int baseStack::size()
{
    return mySize;
}

void baseStack::resize(unsigned int newSize)
{
    if(newSize < 1)
        throw BAD_STACK_SIZE;
    if(!tos || newSize >= capacity)
        capacity = newSize;
    else
    {
        while(mySize > newSize)
            nukem();
        capacity = newSize;
    }
}



void baseStack::push(node *ptr)
{
    if(full())
        throw BASE_FULL;
    ptr->setNext(tos);
    tos = ptr;
    ++mySize;
}

node* baseStack::pop()
{
    node* toGoBack = top();
    tos->setNext(tos->getNext()); // Essentially tos = tos->next;
    --mySize;
    return toGoBack;
}

node* baseStack::top()
{
    if(empty())
        throw BASE_EMPTY;
    return tos;
}

node* baseStack::getHead() const {
    if (empty())
        throw BASE_EMPTY;
    return tos;
}
