//
//  Peg.cpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Peg.hpp"

Peg::Peg() {
    length = 250;
    Base.setPosition(0, 0);
    Base.setFillColor(darkGreyDefault);
    Pole.setFillColor(darkGreyDefault);
    autoUpdate();
}

sf::Vector2f Peg::getMidPoint() {
    return (Base.getPosition() + sf::Vector2f(0.5 * length, 0));
}

float Peg::getLength() {
    return length;
}

void Peg::autoSetup(const UIView& safeArea, int index, float Gap) {
    setLength((safeArea.frame.width() - 4 * Gap) / 3.0);
    
    
    Base.setPosition(safeArea.frame.minX() + (index + 1) * Gap + index * length, safeArea.frame.maxY() - 0.5 * (safeArea.frame.height() - length - 10));
    autoUpdate();
    
    Base.setFillColor(lineBlue);
    Pole.setFillColor(lineGreen);
}

void Peg::autoUpdate() {
    Base.setSize(sf::Vector2f(length,10));
    
    Pole.setPosition(Base.getPosition().x+ 0.5*Base.getSize().x, Base.getPosition().y);
    Pole.rotate(-45);
    Pole.setSize(sf::Vector2f(length,10));
}

void Peg::setLength(const float& newLength) {
    length = newLength;
}

void Peg::draw(sf::RenderWindow& w) {
    w.draw(Pole);
    w.draw(Base);
}
