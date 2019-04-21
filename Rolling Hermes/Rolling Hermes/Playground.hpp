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
    void initLabel();
    void initButton();
    void initPeg();
    void initDisk();
    
    void updateDisks();
    void drawDisks();
    void drawPeg();
    void drawButtons();
    void drawLabels();
    // SFML UI Delegate
    void build();
    void EventDelegate();
    void render();
    
    // Draw here.
    void buildPegs();
    void drawBackGround();
    
};

#endif /* Playground_hpp */
