#ifndef MYNODE_H
#define MYNODE_H
#include "node.h"

template <typename T>
class myNode : node
{
    public:
        myNode(const T& data = T());
        ~myNode();
        myNode(const myNode<T>& other);
        myNode<T>& operator=(const myNode<T>& other);

    protected:
        void makeCopy(const node& other);
    private:

};

template <typename T>
myNode<T>::myNode(const T& data)
{
    node::access() = new T(data);
}

template <typename T>
myNode<T>::~myNode()
{
    if (!node::edit()) {
        delete static_cast<T*>(node::access());
        node::edit() = nullptr;
    }
}

template <typename T>
myNode<T>::myNode(const myNode<T>& other)
{
    makeCopy();
}

template <typename T>
myNode<T>& myNode<T>::operator=(const myNode<T>& other)
{
    if(this != &other)
        makeCopy(other);
    return *this;
}

template <typename T>
void myNode<T>::makeCopy(const node& other)
{
    if (!node::access())
        delete static_cast<T*>(node::edit());
    node::edit() = new T(*(T*)(other.access()));
}
#endif // MYNODE_H
