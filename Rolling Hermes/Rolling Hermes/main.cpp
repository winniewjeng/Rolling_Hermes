//
//  main.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng, Jack Zhao on 4/3/19.
//  Copyright © 2019 Winnie Jeng, Jack Zhao. All rights reserved.
//

#include <iostream>
#include "board.hpp"
#include "Stack.hpp"

using namespace std;

void testPQ();
void testStack();

int main(int argc, const char * argv[]) {
    
    testPQ();
    
    testStack();
    
}

void testPQ() {
    
    arrPriorityQueue<disk*, int> qu;
    for (int i = 0; i < 5; ++i) {
        disk* temp = new disk();  // mem leak
        cout << "temp: " << temp -> getNumber() << " ";
        cout << "\npriority = " << -i << endl;
        qu.enqueue(temp, -i);
        qu.print();
        cout << endl;
    }
    
    //    cout << qu.getSize() << endl;
    //    cout << *qu.deque() << endl;
    //    cout << *qu.deque() << endl;
    //    cout << *qu.deque() << endl;
    
    //3rd disk nullptr dereferenced. Check autoInsert()algo
    
    //    for (int i = 0; i<5;++i) {
    //        cout << qu.deque() -> getNumber() << endl;
    //    }
    //    board(5);
}

void testStack() {
    cout << "TEST STACK\n";
    Stack<int> src;
    
}
