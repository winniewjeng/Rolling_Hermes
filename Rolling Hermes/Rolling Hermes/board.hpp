//
//  board.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/14/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include "disk.hpp"
#include "ArrayBasedPriorityQueue.hpp"
#include "Stack.hpp"

class board {
    
private:
    arrPriorityQueue<disk*, int> src;
    arrPriorityQueue<disk*, int> aux;
    arrPriorityQueue<disk*, int> des;
    unsigned int diskNumber;
    unsigned int move;
    bool preferOdd;
    
public:
    board(unsigned int _diskNum = 4);
    ~board();
    board(const board& other);
    board& operator =(const board& other);
    
    // accessor
    unsigned int getMove();
    unsigned int getDiskNumber();
    
    // Board Class Delegate
    void init();
    void moveToSrc();
    void moveToAux();
    void moveToDes();
    void autoMove(bool finishTheGame = false);
    
    bool inProgress();
    
    
    
};
#endif /* board_hpp */
