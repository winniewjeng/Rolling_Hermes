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
    
    T& front() const { return head -> _item; }
    // Function: front
    // Description: Returns the front item of the linked list
    
    node<T>* begin() const { return head; }
    // Function: front
    // Description: Returns the front node of the linked list
    
    node<T>* end() const { end(head); }
    // Function: end
    // Description: Returns the end node of the linked list
    
    node<T>* insertHead(const T& item) { return InsertHead(head, item); }
    // Function: insert head
    // Description: adds a new node to the front of linked list
    // Return: node<T>*
    // Parameter: T&
    
    bool isEmpty() const { return !head; }
    // Function: is empty
    // Description: checks if linked list is empty of nodes
    // Return: bool
    // Parameter: none
  
    T removeNode(node<T>* mark) { return DeleteNode(head, mark); }
    // Function: remove node
    // Description: adds a new node to the front of linked list
    // Return: node<T>*
    // Parameter: T&
    
    void clear() { ClearList(head);}
    // Function: clear
    // Description: deletes all nodes in  the linked list
    // Return: void
    // Parameter: none
    
    const T& at(unsigned int i) { return At(head, i); }
    // Function: at
    // Description: finds the node at a specific location and returns its item
    // Return: T&
    // Parameter: unsigned int
    
    std::ostream& print(std::ostream& outs, const LinkedList& print_me) const{
        return PrintList(outs, print_me.head); }
    // Function: print
    // Description: prints out the items in the  linked list
    // Return: ostream&
    // Parameter: ostream&, const LinkedList&
    
};


#endif /* Linked_List_hpp */
