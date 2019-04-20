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
#include "UIKit/UIKit.hpp"

using namespace sf;

class UIDelegate: public board {
private:
    RenderWindow window;
    Vector2i mousePos;
//    Text minMove;
//    UILabel totalMove;
//    UILabel DiskNumDiaplay;
    UIView SafeArea;
    UIView appView;
    

    
public:
    UIDelegate(unsigned int _diskNum = 4);
    void init();
    void initLabel();
    // SFML UI Delegate
    void build();
    void EventDelegate();
    void render();
    
    // Draw here.
    void buildPegs();
    void drawBackGround();
    void drawLabels();
    
};

#endif /* Playground_hpp */
