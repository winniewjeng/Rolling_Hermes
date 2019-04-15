//
//  main.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng, Jack Zhao on 4/3/19.
//  Copyright © 2019 Winnie Jeng, Jack Zhao. All rights reserved.
//

#include <iostream>
#include "board.hpp"

using namespace std;

//void testStack();

int main(int argc, const char * argv[]) {
    
    arrPriorityQueue<disk*, int> qu;
    
    for (int i = 0; i < 5; ++i) {
        disk* temp = new disk();
        cout << "temp: " << temp -> getNumber() << " ";
        cout << "\npriority = " << -i << endl;
        qu.enqueue(temp, -i);
        qu.print();
        cout << endl;
    }
    
//    cout << endl;
//    cout << qu.getSize() << endl;
//    qu.print();
//    cout << *qu.deque() << endl;
//    cout << *qu.deque() << endl;
//    cout << *qu.deque() << endl; // nullptr dereferenced crash. 3rd disk is a nullptr. Check autoInsert algo
//
    
    
    //    for (int i = 0; i<5;++i) {
    //        cout << qu.deque() -> getNumber() << endl;
    //    }
    //    board(5);
}

