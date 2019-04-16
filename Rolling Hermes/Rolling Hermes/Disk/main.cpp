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

void testPQS();

int main(int argc, const char * argv[]) {
    
    testPQS();
    
}

void testPQS() {
    
    arrPriorityQueue<disk*, int> qu(10);
    for (int i = 0; i < 4; ++i) {
        disk* temp = new disk();  //
        cout << "temp: " << temp -> getNumber() << " ";
        cout << "\npriority = " << i << endl;
        qu.enqueue(temp, i);
        //        qu.print();
        cout << endl;
    }
    // why some disks end up being nullptrs when doing -i
    // so going counterintuitively, greater number = greater priority ie priority 4 > priority 1
    
    qu.print();
    
    // board(5);
    
    int s = qu.getSize();
    Stack src(s);
    while (!qu.empty()) {
        src.push(qu.deque());
    }
    cout << "\nsize "<< src.getSize() <<endl;
    while (!src.empty()) {
        cout << "Bye " << src.peek() <<endl;
        src.pop();
        // why is everything destroyed twice?
    }
    cout << "size "<< src.getSize() << endl;
}
