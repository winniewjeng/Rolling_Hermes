//
//  board.cpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//
#include <cmath>
#include <chrono>
#include "board.hpp"
using namespace std::chrono;
const int AReallyBigNumber = 100;
const int Increment = 1;
const int Even = 2;

board::board(unsigned int _diskNum): diskNumber(_diskNum) {
    move = 0;
    preferOdd = diskNumber % Even;
    init();
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

void board::init () {
    // Enlarge the array first if diskNumber exceeds.
    if (diskNumber > 5) {
        src.resize(diskNumber + Increment);
        aux.resize(diskNumber + Increment);
        des.resize(diskNumber + Increment);
    }
    // Create disk pointers and priority for each disk
    // Push them into the queue.
    for (int i = 0; i < diskNumber; ++ i) {
        disk* temp = new disk();
        src.enqueue(temp, AReallyBigNumber - temp->getNumber());
    }
}

void board::printBoard() {
    cout << "Source Peg: ";
    for (int i = 0; i < src.getSize(); ++ i)
        std::cout << "(" << *(src.at(i) -> data) <<") ";
    cout << "\nAuxilary Peg:";
    for (int i = 0; i < aux.getSize(); ++ i)
        std::cout << "(" << *(aux.at(i) -> data) <<") ";
    cout << "\nDest Peg: ";
    for (int i = 0; i < des.getSize(); ++ i)
        std::cout << "(" << *(des.at(i) -> data) <<") ";
    cout << "\n\n";
}

void board::fromOneToOther(arrPriorityQueue<disk*, int>& from, arrPriorityQueue<disk*, int>& to) {
    int tempP = from.peekPriority();
    disk* tempD = from.deque();
    to.enqueue(tempD, tempP);
}

void board::autoMove(bool finishTheGame) {
    int modNum[diskNumber];
    int initMove[diskNumber];
    int interval[diskNumber];
    // For disk# 1 to n,
    // Init Step: (2^(n - 1))
    // Modulo = 3*(2^n)
    for (int i = 1; i <= diskNumber; ++ i) {
        modNum[i - 1] = 3 * pow(2, i);
        initMove[i - 1] = pow(2, (i - 1));
        interval[i - 1] = pow(2, i);
    }
    for (int i = 0; i < diskNumber; ++ i) {
        cout << "Mod Num: " << modNum[i] << endl;
        cout << "init Move: " << initMove[i] << endl;
        cout << "interval: " << interval[i] << endl;
    }
    do {
        if (!inProgress())
            break;
        ++move;
        int i = 0;
        int forLaterUse = 0;
        for (i = 0; i < diskNumber; ++ i) {
            forLaterUse = (move - initMove[i] + 1) % modNum[i];
            if (forLaterUse % interval[i] == 1)
                break;
        }
        
//        i --; // Decr from the for loop in order to have the right number of Peg.
        
        // 然后判断i是单双数，是否preferred
        // 然后 step减去InitMove[i] + 1， 再Modulo modNum[i]
        // 然后divide interval[i]，
        // 看结果：
        // Preferred：SD DA AS
        // Unpreferred：SA AD DS
        
        int operationIndex = forLaterUse / interval[i];
        i ++;
        switch (operationIndex) {
            case 0:
                if ((i%2) == preferOdd) {
                   // SD
                    fromOneToOther(src, des);
                } else {
                    // SA
                    fromOneToOther(src, aux);
                }
                break;
            case 1:
                if ((i%2) == preferOdd) {
                    // DA
                    fromOneToOther(des, aux);
                } else {
                    // AD
                    fromOneToOther(aux, des);
                }
                break;
            case 2:
                if ((i%2) == preferOdd) {
                    // AS
                    fromOneToOther(aux, src);
                } else {
                    // DS
                    fromOneToOther(des, src);
                }
                break;
            default:
                break;
        }
        printBoard();
        cout << endl;
    } while (finishTheGame);
    cout << "total move:" << move;
}

bool board::inProgress() {
    return !(src.empty() && aux.empty());
}
