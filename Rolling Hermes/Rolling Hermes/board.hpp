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
    void adjustDiskNum(bool more);
    
public:
    board(unsigned int _diskNum = 4);
    ~board();
    board(const board& other);
    board& operator =(const board& other);
    
    // accessor
    unsigned int getMove() {return move;}
    unsigned int getDiskNumber() {return diskNumber;};
    arrPriorityQueue<disk*, int>& getSourcePeg() {return src;}
    arrPriorityQueue<disk*, int>& getAuxilaryPeg() {return aux;}
    arrPriorityQueue<disk*, int>& getDestinationPeg() {return des;}
    
    // Board Class Modifier
    void init();
    /* Board initialize
    *  Initialize new disks and push into source queue.
    *  Will resize the queue if needed.
    */

    void fromOneToAnother(arrPriorityQueue<disk*, int>& from, arrPriorityQueue<disk*, int>& to);
     /* Make move
     *  Pop a disk from one disk and push into another.
     *
     */
    
    void autoMove(bool finishTheGame = false, bool print = false);
    /* Automatically perform the next move.
     * Make the next move based on the current move number.
     * True - finish the entire game.
     * False - one step only.
     */
    
    bool inProgress();
    /* Boolean:
     * Tells if the game is in progress or finished
     * Return true if src and aux are empty.
     */
    
    void printBoard();
    /* Display the disks in all queues.
     *
     */
    
};
#endif /* board_hpp */
