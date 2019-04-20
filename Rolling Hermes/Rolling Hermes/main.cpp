//
//  main.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng, Jack Zhao on 4/3/19.
//  Copyright © 2019 Winnie Jeng, Jack Zhao. All rights reserved.
//

#include <iostream>
#include <string>
#include "Stack.hpp"
#include "Playground.hpp"

using namespace std;

void testPQS();

int main(int argc, const char * argv[]) {
    
    board(6).autoMove(true);
   
//    testPQS();
}
/*
 Board Test run:
 Disk #1 was created!
 Disk #2 was created!
 Disk #3 was created!
 Disk #4 was created!
 Disk #5 was created!
 i = 5
 src size = 5
 Disk #1 was destroyed!
 i = 4
 src size = 4
 Disk #2 was destroyed!
 i = 3
 src size = 3
 Disk #3 was destroyed!
 i = 2
 src size = 2
 Disk #4 was destroyed!
 i = 1
 src size = 1
 Disk #5 was destroyed!
 
 Disk #1 was created!
 Disk #2 was created!
 Disk #3 was created!
 Disk #4 was created!
 Disk #5 was created!
 Disk #6 was created!
 i = 6
 src size = 6
 Disk #1 was destroyed!
 i = 5
 src size = 5
 Disk #2 was destroyed!
 i = 4
 src size = 4
 Disk #3 was destroyed!
 i = 3
 src size = 3
 Disk #4 was destroyed!
 i = 2
 src size = 2
 Disk #5 was destroyed!
 i = 1
 src size = 1
 Disk #6 was destroyed!
 */



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
