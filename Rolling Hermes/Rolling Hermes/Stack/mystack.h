#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "basestack.h"
#include "mynode.h"

using namespace std;

template<typename T>
class myStack : public baseStack
{
    public:
        myStack(int cap = 5);
        ~myStack();
        myStack(const myStack<T> &other);
        myStack<T>& operator=(const myStack<T>& other);
        T pop();
        void push(const T& data);
        T top();

        template<typename U>
        friend
        ostream& operator<<(ostream& out,const myStack<U> &theStack);

        template<typename U>
        friend
        istream& operator>>(istream& in,myStack<U> &theStack);

    protected:
        void nukem();

    private:
        void copy(const myStack& other);
        void makeCopy(node* ptr);

};


template<typename T>
myStack<T>::myStack(int cap) : baseStack(cap)
{}

template<typename T>
myStack<T>::~myStack()
{
    while(!empty())
        nukem();
}

template<typename T>
myStack<T>::myStack(const myStack<T> &other): baseStack(other)
{
    copy(other);
}

template<typename T>
myStack<T>& myStack<T>::operator=(const myStack<T>& other)
{
    if (this != &other) {
        while (!empty()) nukem();
        baseStack::operator =(other);
        copy(other);
    }
    return *this;
}

template<typename T>
T myStack<T>::pop()
{
    try
    {
        //Should myStack do this??? Or, how about myNode???
        node* temp = baseStack::pop();
        T data = *(static_cast<T*>(temp->access()));
        delete (static_cast<T*>(temp->edit()));
        delete temp;
        return data;
    }
    catch(BASESTACK_ERRORS e)
    {
        cout<<"Stack empty!! Cannot pop data!"<<endl;
    }
    catch(...)
    {
        cout<<"An unknown error occurred. Program terminating."<<endl;
        exit(1);
    }
}

template<typename T>
void myStack<T>::push(const T& data)
{
    try
    {
        if (full()) throw BASE_FULL;
        myNode<T> *newNode = new myNode<T>(data);
        baseStack::push(newNode);
    }
    catch(BASESTACK_ERRORS e)
    {
        cout<<"Stack full!! Cannot push data!"<<endl;
    }
    catch(...)
    {
        cout<<"An unknown error occurred. Program terminating."<<endl;
        exit(1);
    }
}

template<typename T>
T myStack<T>::top()
{
    try
    {
        return *(static_cast<T*>(baseStack::top()->access()));
    }
    catch(BASESTACK_ERRORS e)
    {
        cout<<"Stack empty!! Cannot pop data!"<<endl;
    }
    catch(...)
    {
        cout<<"An unknown error occurred. Program terminating."<<endl;
        exit(1);
    }
}

template<typename T>
void myStack<T>::nukem()
{
    node* toBeDeleted = baseStack::pop();
    delete toBeDeleted;
}

template<typename T>
void myStack<T>::copy(const myStack& other)
{
    try
    {
       node* ptr = other.getHead();
       makeCopy(ptr);
    }
    catch (BASESTACK_ERRORS e)
    {
        cout << "Unexpected Errors Occurred!\n";
    }
}

template<typename T>
void myStack<T>::makeCopy(node* ptr)
{
    if(!ptr -> getNext())   // If ptr is not the last node,
                            // go to next recursion.
        makeCopy(ptr->getNext());
    push(*(static_cast<T*>(ptr->access())));
}

template<typename U>
ostream& operator<<(ostream& out,const myStack<U> &theStack)
{
    node* head = theStack.getHead();
    while (!head) {
        out << *(static_cast<U*>(head -> access())) << " ";
        head = head -> getNext();
    }
    return out;
}

template<typename U>
istream& operator>>(istream& in,myStack<U> &theStack)
{
    U temp;
    in >> temp;
    theStack.push(temp);
    return in;
}

#endif // MYSTACK_H
