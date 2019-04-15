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

class board {
    arrPriorityQueue<disk, int> src;
    arrPriorityQueue<disk, int> aux;
    arrPriorityQueue<disk, int> des;
    unsigned int move;
public:
    board();
    ~board();
    board(const board& other);
    board& operator =(const board& other);
    
    // accessor
    unsigned int getMove();
    
    
    
};
#endif /* board_hpp */
