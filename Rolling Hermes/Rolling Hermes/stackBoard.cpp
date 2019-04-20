//
//  stackBoard.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/20/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include <cmath>
#include <chrono>
#include "stackBoard.hpp"

using namespace std::chrono;

const int Inc = 1;

stackBoard::stackBoard(unsigned int _diskNum): diskNumber(_diskNum) {
    cout << diskNumber << endl;
    move = 0;
    preferOdd = diskNumber % 2;
    cout <<  preferOdd << " odd?" <<endl;
    init();
    cout << "finished\n";
}

stackBoard::~stackBoard() {
    if (!src.empty()) {
        src.clear();
    }
    if (!aux.empty()) {
        aux.clear();
    }
    if (!des.empty()) {
        des.clear();
    }
}

void stackBoard::init () {
    cout << "in init\n";
    // Enlarge the array first if diskNumber exceeds.
    if (diskNumber > 5) {
        cout << "before size: "<< src.getCap() << " "<< aux.getCap() << " "<< des.getCap() << endl;
        src.resize(diskNumber + Inc);
        aux.resize(diskNumber + Inc);
        des.resize(diskNumber + Inc);
        cout << "after size: "<< src.getCap() << " "<< aux.getCap() << " "<< des.getCap() << endl;
    }
    // Create disk pointers and push them into the stack.
    for (int i = 0; i < diskNumber; ++i) {
        node<disk>* temp = new node<disk>();
//        disk* temp = new disk();
        src.push(&temp->_item);
        cout << "printing source " << i << ": ";
        src.print();
    }
    cout << "exit init()\n";
}

void stackBoard::printBoard() {
    cout << "  Source Peg: ";
    src.print();
    cout << "\nAuxilary Peg: ";
    aux.print();
    cout << "\n    Dest Peg: ";
    des.print();
    cout << "\n        Move: " << move << endl;
}

void stackBoard::fromOneToAnother(Stack& from, Stack& to) {
    if (from.getTop()->_item < to.getTop()->_item)
        throw BAD_MOVE;
    if (from.empty())
        throw EMPTY_PEG;
    disk* tempD = new disk(from.pop());
    to.insert_top(tempD);
}

void stackBoard::autoMove(bool finishTheGame) {
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
        cout << endl;
        if (!inProgress())
            break;
        ++move;
        forLaterUse = 0;
        
        for (i = 0; i < diskNumber; ++ i) {
            forLaterUse = (move - initMove[i] + 1) % modNum[i];
            if (forLaterUse % interval[i] == 1)
                break;
        }
        
        // 然后判断i是单双数，是否preferred
        // 然后 step减去InitMove[i] + 1， 再Modulo modNum[i]
        // 然后divide interval[i]，
        // 看结果：
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
        printBoard();
    } while (finishTheGame);
}

bool stackBoard::inProgress() {
    return !(src.empty() && aux.empty());
}
