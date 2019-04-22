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
    init();
}

stackBoard::~stackBoard() {
    if (!src.empty())
        src.clear();
    if (!aux.empty())
        aux.clear();
    if (!des.empty())
        des.clear();
}

void stackBoard::init () {
    // Enlarge the array first if diskNumber exceeds.
    if (diskNumber > 5) {
        src.resize(diskNumber + Inc);
        aux.resize(diskNumber + Inc);
        des.resize(diskNumber + Inc);
    }
    // Create disk pointers and push them into the stack.
    for (int i = 0; i < diskNumber; ++i) {
        node<disk>* temp = new node<disk>();
        src.push(&temp->_item);
        src.print();
    }
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
<<<<<<< HEAD
=======

>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
        
        int operationIndex = forLaterUse / interval[i];

        i++;
        switch (operationIndex) {
            case 0:
                if ((i%2) == preferOdd) {
                    fromOneToAnother(src, des);
                } else {
                    fromOneToAnother(src, aux);
                }
                break;
            case 1:
                if ((i%2) == preferOdd) {
                    fromOneToAnother(des, aux);
                } else {
                    fromOneToAnother(aux, des);
                }
                break;
            case 2:
                if ((i%2) == preferOdd) {
                    fromOneToAnother(aux, src);
                } else {
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
