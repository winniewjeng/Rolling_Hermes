//
//  board.cpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "board.hpp"
const int AReallyBigNumber = 100;
const int Increment = 1;
const int Even = 2;

board::board(unsigned int _diskNum): diskNumber(_diskNum) {
    move = 0;
    preferOdd = diskNumber % Even;
    if (diskNumber > 5) {
        src.resize(diskNumber + Increment);
        aux.resize(diskNumber + Increment);
        des.resize(diskNumber + Increment);
    }
    for (int i = 0; i < diskNumber; ++ i) {
        disk* temp = new disk();
        src.enqueue(temp, AReallyBigNumber - temp->getNumber());
    }
}

board::~board() {
    if (!src.empty()) {
        for (int i = src.getSize(); i > 0; -- i) {
            delete src.peek();
            src.deque();
        }
    }
    if (!aux.empty()) {
        for (int i = aux.getSize(); i > 0; -- i) {
            delete aux.peek();
            src.deque();
        }
    }
    if (!des.empty()) {
        for (int i = des.getSize(); i > 0; -- i) {
            delete des.peek();
            des.deque();
        }
    }
}

void board::fromOneToOther(arrPriorityQueue<disk*, int>& from, arrPriorityQueue<disk*, int>& to) {
    int tempP = from.peekPriority();
    disk* tempD = from.deque();
    to.enqueue(tempD, tempP);
}
