//
//  Node.hpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/22/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
// Node struct
template <typename T>
struct node {
    T _item;
    node* _next;
    node* _prev;
    // ctor
    node(T item = T()): _item(item), _next(nullptr),  _prev(nullptr) {}
};


#endif /* Node_hpp */
