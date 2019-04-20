//
//  Playground.cpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Playground.hpp"

UIDelegate::UIDelegate(unsigned int _diskNum): board(_diskNum) {
    init();
}

void UIDelegate::init() {
    
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    window.create(sf::VideoMode(DEFAULT_W, DEFAULT_H), TITLE);
    window.setFramerateLimit(FrameRate);
    window.setVerticalSyncEnabled(true);
    
    appView.setPosition(CGPoint(0,0));
    appView.backgroundColor(sf::Color::White);
    appView.setSize(CGSize(DEFAULT_W, DEFAULT_H));
    
    SafeArea.setPosition(CGPoint(0.1*DEFAULT_W, 0.25*DEFAULT_H));
    SafeArea.setSize(CGSize(0.8*DEFAULT_W, 0.5*DEFAULT_H));
    SafeArea.backgroundColor(sf::Color::White);
    
}

void UIDelegate::initLabel() {
    sf::Font font;
    if (!font.loadFromFile(regularFont))
        cout << "Error! Font loading failed!\n";
    
}

void UIDelegate::build() {
    while (window.isOpen()) {
        // Process event
        EventDelegate();
        render();
    }
}

void UIDelegate::EventDelegate() {
    Event event;
    mousePos = Mouse::getPosition(window);
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
                
            default:
                break;
        }
    }
}



void UIDelegate::render() {
    window.clear();
    window.draw(appView.getView());
    // Draw buttons here.
    drawLabels();
    window.draw(SafeArea.getView());
    // Draw pegs here.
    // Draw disks here.
    window.display();
    // Draw views, Pegs, disks here
}


void UIDelegate::drawLabels() {
    
}
