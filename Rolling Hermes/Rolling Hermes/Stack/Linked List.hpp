//
//  Linked List.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/22/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef Linked_List_hpp
#define Linked_List_hpp
#include <iostream>
#include "Node.hpp"

template <class T>
class LinkedList {
private:
    node<T>* head;
    
public:
    LinkedList(node<T>* _head = nullptr): head(_head) {}
    ~LinkedList() {ClearList(head);}
    LinkedList(const LinkedList<T> &other) {
        head = CopyList(other.head);
    }
    LinkedList& operator =(const LinkedList& RHS) {
        return (this == &RHS)? *this:(head = CopyList(RHS.head), *this);
    }
    T& front() const {
        return head -> _item;
    }
    node<T>* begin() const {
        return head;
    }
    node<T>* end() const {
        end(head);
    }
    
    node<T>* insertHead(const T& item) {
        return InsertHead(head, item);
    }
    
    bool isEmpty() const {
        return head == nullptr;
    }
  
    T removeNode(node<T>* mark) {
        return DeleteNode(head, mark);
    }
    
    void clear() {
        ClearList(head);
    }
    const T& at(unsigned int i) {
        return At(head, i);
    }
    
    std::ostream& print(std::ostream& outs, const LinkedList& print_me) const{
        return PrintList(outs, print_me.head);
    }
    
};


#endif /* Linked_List_hpp */
