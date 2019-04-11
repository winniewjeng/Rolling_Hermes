#include "node.h"

node::node()
{ 
    dataPtr = next = nullptr;
}

node::node(void *ptr)
{
    dataPtr = ptr;
    next = nullptr;
}

node::~node()
{
   dataPtr = next = nullptr;
}

node::node(const node &other)
{
    copy(other);
}

node& node::operator=(const node&other)
{
   if(this != &other)
       copy(other);
   return *this;
}

void* node::access() const
{
    return dataPtr;
}

node* node::getNext()
{
    return next;
}

void node::setNext(node *ptr)
{
    next = ptr;
}

void node::copy(const node &other)
{
    makeCopy(other);
}

void*& node::edit() {
    return dataPtr;
}
