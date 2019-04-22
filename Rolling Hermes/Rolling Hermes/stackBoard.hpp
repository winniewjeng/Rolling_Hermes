//
//  stackBoard.hpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/20/19.
//  Copyright © 2019 Winnie Jeng. All rights reserved.
//

#ifndef stackBoard_hpp
#define stackBoard_hpp

#include "disk.hpp"
#include "Stack.hpp"

enum STACK_BOARD_ERROR {BAD_MOVE, EMPTY_PEG};

class stackBoard {
    
private:
    Stack<disk*> src;
    Stack<disk*> aux;
    Stack<disk*> des;
    unsigned int diskNumber;
    unsigned int move;
    bool preferOdd;
    
public:
    stackBoard(unsigned int _diskNum = 4);
    ~stackBoard();
    stackBoard(const stackBoard& other);
    stackBoard& operator =(const stackBoard& other);
    
    // Board Class Delegate
    void init();
    // Function: initalize board
    // Description: initializes stacks. Populates src stack with disks
    // Return type: void
    // Paramaters: none
    
    // Board initialize
    void printBoard();
    // Function: print board
    // Description: prints out the the disks in each stack peg
    // Return type: void
    // Paramaters: none
    void fromOneToAnother(Stack<disk*>& from, Stack<disk*>& to);
    // Function: from one to another
    // Description: moves disks from one peg to another peg
    // Return type: void
    // Paramaters: Stack&, Stack&
    void autoMove(bool finishTheGame = false, bool print = false);
    // Function: autoMove
    // Description: while game still runs, determines disk's next move
    // Return type: void
    // Paramaters: Boolean
    bool inProgress();
    // Function: in progress
    // Description: checks if the game still keeps going
    // Return type: boolean
    // Paramaters: none
    
};
#endif /* stackBoard_hpp */
