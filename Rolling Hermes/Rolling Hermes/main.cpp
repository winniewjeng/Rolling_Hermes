//
//  main.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng, Jack Zhao on 4/3/19.
//  Copyright © 2019 Winnie Jeng, Jack Zhao. All rights reserved.
//

#include <iostream>
#include "ArrayBasedPriorityQueue.hpp"
using namespace std;
int* func(int* head, int p, int size);
static int con = 0;
int main(int argc, const char * argv[]) {
    
    arrPriorityQueue<int, int> a;
    a.enqueue(1, 1);
    a.print();
    a.enqueue(2, 1);
    a.print();
    a.enqueue(3, 1);
    a.print();
    a.enqueue(40, 2);
    a.print();
    a.enqueue(41, 2);
    a.print();
    cout << a.deque() << endl;
    a.print();
    cout << a.deque() << endl;
    a.print();

    return 0;
}



int* func(int* head, int p, int size) {
    cout << "Run: " << ++con << endl;
    if (size == 1)
        return (*head > p)? (head+1):(head);
    
    if (*(head + size/2) > p)
        head = func(head + size/2 + 1, p, size/2);
    else if (*(head + size/2) < p)
        head = func(head, p, size/2);
    else {
        while (*(head++ + size/2) == p)
            return head + size/2;
    }
    
    return head;
}
