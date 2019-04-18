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
#include "UIKit Ripoff/UIButton.hpp"
#include "board.hpp"

using namespace sf;
class RollingHermes: public board {
private:
    RenderWindow game;
    Vector2i mousePos;
    UIButton srcPeg;
    UIButton auxPeg;
    UIButton desPeg;
    vector<UIButton> disks;
public:
    RollingHermes();
    void init();
    void build();
    void EventDelegate();
    void render();
    
    void buildPegs();
    
    
};

#endif /* Playground_hpp */