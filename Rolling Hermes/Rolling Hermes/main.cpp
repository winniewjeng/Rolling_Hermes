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

void testSB();

int main(int argc, const char * argv[]) {


//    UIDelegate ui(7);
//    ui.build();

//    UIDelegate ui(8);
//    ui.build();
//
    board a(6);
    auto start_PQ = chrono::high_resolution_clock::now();
    a.autoMove(true, true);
    auto stop_PQ = chrono::high_resolution_clock::now();
    auto PQDuration = std::chrono::duration_cast<chrono::microseconds>(stop_PQ - start_PQ);

////
//    auto start_ST = chrono::high_resolution_clock::now();
//    testSB();
//    auto stop_ST = chrono::high_resolution_clock::now();
//    auto STDuration = std::chrono::duration_cast<chrono::microseconds>(stop_ST - start_ST);
//
    cout  << "Priority Queue took " << PQDuration.count()  << "ms. " << endl;
//    cout  << "Stack took " << STDuration.count()  << "ms. " << endl;

    
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


void testSB() {
    stackBoard s(6);
    s.autoMove(true);
}

