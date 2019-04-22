//
//  Playground.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef Playground_hpp
#define Playground_hpp
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "board.hpp"
#include "Peg.hpp"
#include "UIKit/UIKit.hpp"

using namespace sf;
using namespace std;
class UIDelegate: public board {
private:
    RenderWindow window;
    Vector2i mousePos;
    
    Peg source;
    Peg aux;
    Peg dest;
    
    UIView SafeArea;
    UIView appView;
    UIButton displayMove;
    UIButton displayDiskNumber;
    UIButton minMove;
    
    UILabel title;
    vector<UIButton*> disks;
    
public:
    UIDelegate(unsigned int _diskNum = 4);
    void init();
    // Function: init
    // Description: initializes the UI window
    // Return type: void
    // Paramaters: none
    void initLabel();
    // Function: init label
    // Description: initializes the labels in UI
    // Return type: void
    // Paramaters: none
    void initButton();
    // Function: init button
    // Description: initializes the buttons in UI
    // Return type: void
    // Paramaters: none
    void initPeg();
    // Function: init peg
    // Description: initializes the pegs
    // Return type: void
    // Paramaters: none
    void initDisk();
    // Function: init disk
    // Description: initializes the disks
    // Return type: void
    // Paramaters: none
    
    void updateDisks();
    // Function: update disks
    // Description: puts disks on correct peg
    // Return type: void
    // Paramaters: none
    void drawDisks();
    // Function: draw disks
    // Description: draws the disks on peg
    // Return type: void
    // Paramaters: none
    void drawPeg();
    // Function: draw peg
    // Description: draws the three pegs in UI
    // Return type: void
    // Paramaters: none
    void drawButtons();
    // Function: draw buttons
    // Description: draws the buttons in UI
    // Return type: boolean
    // Paramaters: none
    void drawLabels();
    // Function: draw labels
    // Description: draws the labels in UI
    // Return type: void
    // Paramaters: none
    
    // SFML UI Delegate
    void build();
    // Function: build
    // Description: builds and process the game
    // Return type: void
    // Paramaters: none
    void EventDelegate();
    // Function: event delegate
    // Description: enables user interaction
    // Return type: void
    // Paramaters: none
    void render();
    // Function: render
    // Description: render the UI of processing game
    // Return type: void
    // Paramaters: none
    
    // Draw here.
//    void buildPegs();
//    void drawBackGround();
    
};

#endif /* Playground_hpp */
