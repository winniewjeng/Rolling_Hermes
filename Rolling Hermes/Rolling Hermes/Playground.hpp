//
//  Playground.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef Playground_hpp
#define Playground_hpp

#include <SFML/Graphics.hpp>
using namespace sf;
class RollingHermes {
private:
    RenderWindow game;
    
public:
    RollingHermes();
    void init();
    void build();
};

#endif /* Playground_hpp */
