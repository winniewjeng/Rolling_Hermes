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
    void update();
    void draw(sf::RenderWindow& w);
};

Peg::Peg() {}

void Peg::setPosition(const sf::Vector2f& pos) {
    
}
void Peg::setLength(const float& newLength) {
    length = newLength;
}
void Peg::setWidth() {
    
}
void Peg::draw(sf::RenderWindow& w) {
    
}

#endif /* Peg_hpp */
