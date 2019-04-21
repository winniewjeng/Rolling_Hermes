//
//  Peg.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef Peg_hpp
#define Peg_hpp

#include "SFML/Graphics.hpp"
#include "UIKit/UIKit.hpp"
class Peg {
private:
    sf::RectangleShape Base;
    sf::RectangleShape Pole;
    float length;
    
public:
    Peg();
    
    void setPosition(const sf::Vector2f& pos);
    void setLength(const float& newLength);
    void setWidth();
    
    // Accessor:
    sf::Vector2f getMidPoint();
    float getLength();
    
    void autoSetup(const UIView& safeArea, int index, float Gap);
    void autoUpdate();
    void draw(sf::RenderWindow& w);
};

#endif /* Peg_hpp */
