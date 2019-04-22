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
    minMove = static_cast<int>(pow(2, diskNumber)) - 1;
    preferOdd = diskNumber % Even;
    
    init();
}

board::~board() {
    if (!src.empty()) {
        for (int i = src.getSize(); i > 0; -- i) {
            delete src.at(i - 1) -> data;
        }
    }
    if (!aux.empty()) {
        for (int i = aux.getSize(); i > 0; -- i) {
            delete aux.at(i - 1) -> data;
//            src.deque();
        }
    }
    if (!des.empty()) {
        for (int i = des.getSize(); i > 0; -- i) {
            delete des.at(i - 1) -> data;
        }
    }
}

board::board(const board& other) {
    diskNumber = other.diskNumber;
    preferOdd = other.preferOdd;
    src = other.src;
    aux = other.aux;
    des = other.des;
    move = other.move;
    minMove = other.minMove;
}

board& board::operator =(const board& other) {
    if (this == &other)
        return *this;
    diskNumber = other.diskNumber;
    preferOdd = other.preferOdd;
    src = other.src;
    aux = other.aux;
    des = other.des;
    move = other.move;
    minMove = other.minMove;
    return *this;
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

void board::fromOneToAnother(arrPriorityQueue<disk*, int>& from, arrPriorityQueue<disk*, int>& to) {
    if (from.peekPriority() < to.peekPriority())
        throw ILLEGAL_MOVE;
    if (from.empty())
        throw PEG_EMPTY;
    int tempP = from.peekPriority();
    disk* tempD = new disk(*from.peek());
    from.deque();
    to.enqueue(tempD, tempP);
}

void board::autoMove(bool finishTheGame, bool print) {
    int i = 0;
    int forLaterUse = 0;
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
    
    do {
        if (!inProgress())
            break;
        ++move;
        forLaterUse = 0;
        
        for (i = 0; i < diskNumber; ++ i) {
            forLaterUse = (move - initMove[i] + 1) % modNum[i];
            if (forLaterUse % interval[i] == 1)
                break;
        }
        
        // Then tell if i is odd or even，preferred (odd) or not
        // step - InitMove[i] + 1， Modulo modNum[i]
        // then divide interval[i]，
        // Look at the result：
        // Preferred：SD DA AS
        // Unpreferred：SA AD DS
        
        int operationIndex = forLaterUse / interval[i];
        // Increment i in order to correct the index number to the disk number
        // in for loop, i starts at 0; in disk world, i starts at 1.
        i ++;
        switch (operationIndex) {
            case 0:
                if ((i%2) == preferOdd) {
                   // SD
                    fromOneToAnother(src, des);
                } else {
                    // SA
                    fromOneToAnother(src, aux);
                }
                break;
            case 1:
                if ((i%2) == preferOdd) {
                    // DA
                    fromOneToAnother(des, aux);
                } else {
                    // AD
                    fromOneToAnother(aux, des);
                }
                break;
            case 2:
                if ((i%2) == preferOdd) {
                    // AS
                    fromOneToAnother(aux, src);
                } else {
                    // DS
                    fromOneToAnother(des, src);
                }
                break;
            default:
                break;
        }
        if (print)
            printBoard();

    } while (finishTheGame);
    cout << "Expect minimum move: " << pow(2, diskNumber) - 1 << endl;
}

bool board::inProgress() {
    return !(src.empty() && aux.empty());
}

void board::printBoard() {
    cout << "  Source Peg: ";
    for (int i = 0; i < src.getSize(); ++ i)
        std::cout << "(" << *(src.at(i) -> data) <<") ";
    cout << "\nAuxiliary Peg: ";
    for (int i = 0; i < aux.getSize(); ++ i)
        std::cout << "(" << *(aux.at(i) -> data) <<") ";
    cout << "\n    Dest Peg: ";
    for (int i = 0; i < des.getSize(); ++ i)
        std::cout << "(" << *(des.at(i) -> data) <<") ";
    cout << "\n        Move: " << move << endl;
}

