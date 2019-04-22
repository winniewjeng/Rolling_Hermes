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
    // Function: get move
    // Description: returns the number of move the game is on
    // Return type: unsigned int
    // Paramaters: none
    unsigned int getDiskNumber() {return diskNumber;};
    // Function: get disk number
    // Description: returns the number of disks the game uses
    // Return type: unsigned int
    // Paramaters: none
    arrPriorityQueue<disk*, int>& getSourcePeg() {return src;}
    // Function: get source peg
    // Description: returns the source peg
    // Return type: arrPriorityQueue
    // Paramaters: none
    arrPriorityQueue<disk*, int>& getAuxilaryPeg() {return aux;}
    // Function: get Auxilary peg
    // Description: returns the aux peg
    // Return type: arrPriorityQueue
    // Paramaters: none
    arrPriorityQueue<disk*, int>& getDestinationPeg() {return des;}
    // Function: get destination peg
    // Description: returns the des peg
    // Return type: arrPriorityQueue
    // Paramaters: none
    
    // Board Class Modifier
    void init();
<<<<<<< HEAD
    // Function: initalize board
    // Description: initializes stacks. Populates src stack with disks
    // Return type: void
    // Paramaters: none
    
    // Board initialize
    void changeDiskNumber(int newDisk);
    void printBoard();
    // Function: print board
    // Description: prints out the the disks in each stack peg
    // Return type: void
    // Paramaters: none
    void fromOneToAnother(arrPriorityQueue<disk*, int>& from, arrPriorityQueue<disk*, int>& to);
    // Function: from one to another
    // Description: moves disks from one peg to another peg
    // Return type: void
    // Paramaters: Stack&, Stack&
    void autoMove(bool finishTheGame = false);
    // Function: autoMove
    // Description: while game still runs, determines disk's next move
    // Return type: void
    // Paramaters: Boolean
    
    bool inProgress();
    // Function: in progress
    // Description: checks if the game still keeps going
    // Return type: boolean
    // Paramaters: none
=======
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
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
    
    void printBoard();
    /* Display the disks in all queues.
     *
     */
    
};
#endif /* board_hpp */
