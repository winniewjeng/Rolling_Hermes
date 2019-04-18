//
//  Playground.cpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#include "Playground.hpp"

RollingHermes::RollingHermes() {
    
}

void RollingHermes::init() {
    game.create(sf::VideoMode(1080, 720), "Title");
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    game.create(VideoMode(1080,720), "Tower of Hanoi",sf::Style::Close | sf::Style::Resize, settings);
    game.setFramerateLimit(30);
    game.setVerticalSyncEnabled(true);
    
    
}

void RollingHermes::build() {
    while (game.isOpen()) {
        // Process event
        EventDelegate();
        render();
    }
}

void RollingHermes::EventDelegate() {
    Event event;
    mousePos = Mouse::getPosition(game);
    
}

void RollingHermes::render() {
    game.clear();
    // Draw views, Pegs, disks here
//    game.draw();
}
