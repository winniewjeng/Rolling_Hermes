#ifndef BASESTACK_H
#define BASESTACK_H
#include "node.h"

enum BASESTACK_ERRORS{BASE_EMPTY, BASE_FULL, BAD_STACK_SIZE};

class baseStack
{
    public:
        baseStack(unsigned int cap = 5);
        ~baseStack();
        baseStack(const baseStack& other);
        baseStack& operator=(const baseStack& other);
        bool full();
        bool empty();
        unsigned int size();
        void resize(unsigned int newSize);

     protected:
        void push(node *ptr);
        node* pop();
        node* top();
        node* getHead() const;
        virtual void nukem() = 0;
        virtual void makeCopy(node* other) = 0;
    private:
        unsigned int capacity, mySize;
        node* tos;

};

#endif // BASESTACK_H
