//
//  stackBoard.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/20/19.
//  Copyright © 2019 Winnie Jeng. All rights reserved.
//

#include <cmath>
#include <chrono>
#include "stackBoard.hpp"

using namespace std::chrono;

const int Inc = 1;

stackBoard::stackBoard(unsigned int _diskNum): diskNumber(_diskNum) {
    move = 0;
    preferOdd = diskNumber % 2;
    init();
}

stackBoard::~stackBoard() {
    src.clear();
    aux.clear();
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
        disk* temp = new disk();
        src.push(temp);
    }
}

void stackBoard::printBoard() {
    cout << "  Source Peg: ";
    for (int i = 0; i < src.getSize(); ++ i)
        std::cout << "(" << (src.at(i) -> getNumber()) <<") ";
    cout << "\nAuxilary Peg: ";
    for (int i = 0; i < aux.getSize(); ++ i)
        std::cout << "(" << (aux.at(i) -> getNumber()) <<") ";
    cout << "\n    Dest Peg: ";
    for (int i = 0; i < des.getSize(); ++ i)
        std::cout << "(" << (des.at(i) -> getNumber()) <<") ";
    cout << "\n        Move: " << move << endl;
}

void stackBoard::fromOneToAnother(Stack<disk*>& from, Stack<disk*>& to) {
    if (from.empty())
        throw EMPTY_PEG;
    disk* tempD = new disk(*from.peek());
    from.pop();
    to.push(tempD);
}

void stackBoard::autoMove(bool finishTheGame, bool print) {
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
        if (!inProgress())
            break;
        ++move;
        forLaterUse = 0;
        
        for (i = 0; i < diskNumber; ++ i) {
            forLaterUse = (move - initMove[i] + 1) % modNum[i];
            if (forLaterUse % interval[i] == 1)
                break;
        }

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
        (print)? printBoard():void();
    } while (finishTheGame);
}

bool stackBoard::inProgress() {
    return !(src.empty() && aux.empty());
}
