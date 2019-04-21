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
    SafeArea.backgroundColor(orangePressed);
    
    initPeg();
    initButton();
    initDisk();
}

void UIDelegate::initLabel() {
    sf::Font font;
    if (!font.loadFromFile(regularFont))
        cout << "Error! Font loading failed!\n";
    
}

void UIDelegate::initButton() {
    displayMove.setPosition(Vector2f(0.05*DEFAULT_W, 0.05*DEFAULT_H));
    displayMove.setTitle("Move: " + to_string(board::getMove()));
    displayMove.setTitleSize(30);
    displayMove.setHeight(75);
    displayMove.setLength(200);

    
    
    displayDiskNumber.setPosition(Vector2f(0.8*DEFAULT_W, 0.05*DEFAULT_H));
    displayDiskNumber.setTitle("Disk: " + to_string(getDiskNumber()));
    displayDiskNumber.setHeight(75);
    displayDiskNumber.setLength(200);
    displayDiskNumber.setTitleSize(30);
    displayDiskNumber.setBackGroundColor(orangeDefault);

    
    
    diskNumberIncr.setPosition(sf::Vector2f(displayDiskNumber.getLength() + 0.4*diskNumberIncr.getRadius(),0) + displayDiskNumber.origin());
    diskNumberIncr.setTitle("U");
    diskNumberIncr.setHeight(75);
    diskNumberIncr.setTitleSize(30);
    diskNumberIncr.setBackGroundColor(orangeHighlighted);
    
    diskNumberDecr.setPosition(sf::Vector2f(- 0.4*diskNumberIncr.getRadius() - diskNumberIncr.getLength(),0) + displayDiskNumber.origin());
    diskNumberDecr.setTitle("D");
    diskNumberDecr.setHeight(75);
    diskNumberDecr.setTitleSize(30);
    diskNumberDecr.setBackGroundColor(orangeHighlighted);
    
    
    // Align all text to the middle of the button.
    displayMove.textAlignToCenter();
    displayDiskNumber.textAlignToCenter();
    diskNumberIncr.textAlignToCenter();
    diskNumberDecr.textAlignToCenter();
}

void UIDelegate::initPeg() {
    source.autoSetup(SafeArea, 0, 0.05*DEFAULT_W);
    aux.autoSetup(SafeArea, 1, 0.05*DEFAULT_W);
    dest.autoSetup(SafeArea, 2, 0.05*DEFAULT_W);
}

void UIDelegate::initDisk() {
    for (int i = 0; i < getDiskNumber(); ++ i) {
        UIButton* tempDisk = new UIButton();
        tempDisk -> setLength((i+1) * 0.128 * source.getLength());
        tempDisk -> setHeight(15);
        disks.push_back(tempDisk);
    }
}

// Put disks on the correct peg.
void UIDelegate::updateDisks() {
    for (int i = 0; i < getSourcePeg().getSize(); ++i) {
        
    }
    for (int i = 0; i < getAuxilaryPeg().getSize(); ++i) {
        
    }
    for (int i = 0; i < getDestinationPeg().getSize(); ++i) {
        
    }
}

void UIDelegate::drawDisks() {
    
}

void UIDelegate::drawPeg() {
    source.draw(window);
    aux.draw(window);
    dest.draw(window);
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
    drawPeg();
    // Draw disks here.
    displayMove.placeButton(window);
    displayDiskNumber.placeButton(window);
    diskNumberIncr.placeButton(window);
    diskNumberDecr.placeButton(window);
    
    window.display();
    // Draw views, Pegs, disks here
}


void UIDelegate::drawLabels() {
    
}
