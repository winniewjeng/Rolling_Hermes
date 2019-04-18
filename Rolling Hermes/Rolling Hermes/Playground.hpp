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
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "UIKit/UIButton.hpp"
using namespace sf;
class RollingHermes: public board {
private:
    RenderWindow game;
    Vector2i mousePos;
    
public:
    RollingHermes();
    void init();
    void drawBackGround();
    void build();
    void EventDelegate();
    void render();
    
    void buildPegs();
    
    
};

#endif /* Playground_hpp */
