//
//  stackBoard.hpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/20/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef stackBoard_hpp
#define stackBoard_hpp

#include "disk.hpp"
#include "Stack.hpp"

enum BOARD_ERROR {
    ILLEGAL_MOVE,
    PEG_EMPTY
};

class stackBoard {
    
private:
    Stack src;
    Stack aux;
    Stack des;
    unsigned int diskNumber;
    unsigned int move;
    bool preferOdd;
    
public:
    stackBoard(unsigned int _diskNum = 4);
    ~stackBoard();
    stackBoard(const stackBoard& other);
    stackBoard& operator =(const stackBoard& other);
    
    // accessor
    unsigned int getMove();
    unsigned int getDiskNumber();
    Stack& getSourcePeg() {return src;}
    Stack& getAuxilaryPeg() {return aux;}
    Stack& getDestinationPeg() {return des;}
    
    // Board Class Delegate
    void init();
    // Board initialize
    void printBoard();
    void fromOneToAnother(Stack& from, Stack& to);
    void autoMove(bool finishTheGame = false);
    
    bool inProgress();
    
};
#endif /* stackBoard_hpp */
