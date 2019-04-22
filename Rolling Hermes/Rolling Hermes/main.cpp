//
//  main.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng, Jack Zhao on 4/3/19.
//  Copyright © 2019 Winnie Jeng, Jack Zhao. All rights reserved.
//

#include <iostream>
#include <string>
#include <chrono>
#include "Stack.hpp"
#include "Playground.hpp"
#include "stackBoard.hpp"
using namespace std;

void testPQS();
void testSB();

int main(int argc, const char * argv[]) {

<<<<<<< HEAD
    UIDelegate ui(7);
    ui.build();
    
=======
//    UIDelegate ui(8);
//    ui.build();
//
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
//    board a(6);
//    auto start_PQ = chrono::high_resolution_clock::now();
//    a.autoMove(true,true);
//    auto stop_PQ = chrono::high_resolution_clock::now();
//    auto PQDuration = std::chrono::duration_cast<chrono::microseconds>(stop_PQ - start_PQ);

////
    auto start_ST = chrono::high_resolution_clock::now();
    testSB();
    auto stop_ST = chrono::high_resolution_clock::now();
    auto STDuration = std::chrono::duration_cast<chrono::microseconds>(stop_ST - start_ST);
//
//    cout  << "Priority Queue took " << PQDuration.count()  << "ms. " << endl;
    cout  << "Stack took " << STDuration.count()  << "ms. " << endl;

    
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

<<<<<<< HEAD
//void testSB() {
//    stackBoard(6);
//    Stack s(6);
//    node<disk>* hi = new node<disk>;
//
//    s.push(&(hi->_item));
//}
//
//void testPQS() {
//
//    arrPriorityQueue<disk*, int> qu(10);
//    for (int i = 0; i < 4; ++i) {
//        disk* temp = new disk();  //
//        cout << "temp: " << temp -> getNumber() << " ";
//        cout << "\npriority = " << i << endl;
//        qu.enqueue(temp, i);
//        //        qu.print();
//        cout << endl;
//    }
//
//    qu.print();
//
//    // board(5);
//
//    int s = qu.getSize();
//    Stack src(s);
//    while (!qu.empty()) {
//        src.push(qu.deque());
//    }
//    cout << "\nsize "<< src.getSize() <<endl;
//    while (!src.empty()) {
//        cout << "Bye " << src.peek() <<endl;
//        src.pop();
//    }
//    cout << "size "<< src.getSize() << endl;
//}
=======
void testSB() {
    stackBoard(10);
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
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
