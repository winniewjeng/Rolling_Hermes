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
enum BOARD_ERROR {
    ILLEGAL_MOVE,
    PEG_EMPTY
};

class board {
    
private:
    arrPriorityQueue<disk*, int> src;
    arrPriorityQueue<disk*, int> aux;
    arrPriorityQueue<disk*, int> des;
    unsigned int diskNumber;
    bool preferOdd;
    
protected:
    unsigned int move;
    unsigned int minMove;
    
public:
    board(unsigned int _diskNum = 4);
    ~board();
    board(const board& other);
    board& operator =(const board& other);
    
    // accessor
    unsigned int getMove();
    unsigned int getDiskNumber();
    arrPriorityQueue<disk*, int>& getSourcePeg() {return src;}
    arrPriorityQueue<disk*, int>& getAuxilaryPeg() {return aux;}
    arrPriorityQueue<disk*, int>& getDestinationPeg() {return des;}
    
    // Board Class Delegate
    void init();
    // Board initialize
    void printBoard();
    void fromOneToAnother(arrPriorityQueue<disk*, int>& from, arrPriorityQueue<disk*, int>& to);
    void autoMove(bool finishTheGame = false);
    
    bool inProgress();
    
    
    
};
#endif /* board_hpp */
