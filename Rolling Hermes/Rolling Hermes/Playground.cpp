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
    SafeArea.backgroundColor(sf::Color::Transparent);
    initLabel();
    initPeg();
    initDisk();
}

void UIDelegate::initLabel() {
    sf::Font font;
    if (!font.loadFromFile(regularFont))
        cout << "Error! Font loading failed!\n";
    title.setTitleFont(font);
    title.setTitle("TOWER OF HANOI");
    title.setCharacterSize(100);
    title.setFillColor(lightGreyPressed);
    title.setPosition(sf::Vector2f(SafeArea.frame.midX() - 0.5*title.getBoundary().width, 0.8*DEFAULT_H));
}

void UIDelegate::initButton() {
    displayMove.setPosition(Vector2f(0.05*DEFAULT_W, 0.05*DEFAULT_H));
    displayMove.setTitle("Move: " + to_string(board::move));
    displayMove.setTitleSize(35);
    displayMove.setHeight(75);
    displayMove.setLength(550);
    if (board::inProgress())
        displayMove.setBackGroundColor(darkGreyHighlighted);
    else
        displayMove.setBackGroundColor(lineGreen);
    
    minMove.setPosition(Vector2f(0.05*DEFAULT_W, 0.05*DEFAULT_H + displayMove.getHeight() + 20));
    minMove.setTitle("Expected Minimum Move: " + to_string(board::minMove));
    minMove.setTitleSize(35);
    minMove.setHeight(75);
    minMove.setLength(550);
    minMove.setBackGroundColor(lineOrange);

    displayDiskNumber.setPosition(Vector2f(0.8*DEFAULT_W, 0.05*DEFAULT_H));
    displayDiskNumber.setTitle("Disk: " + to_string(getDiskNumber()));
    displayDiskNumber.setHeight(75);
    displayDiskNumber.setLength(200);
    displayDiskNumber.setTitleSize(35);
    displayDiskNumber.setBackGroundColor(lineRed);

    
    
    // Align all text to the middle of the button.
    displayMove.textAlignToCenter();
    displayDiskNumber.textAlignToCenter();
    minMove.textAlignToCenter();
}

void UIDelegate::initPeg() {
    source.autoSetup(SafeArea, 0, 0.05*DEFAULT_W);
    aux.autoSetup(SafeArea, 1, 0.05*DEFAULT_W);
    dest.autoSetup(SafeArea, 2, 0.05*DEFAULT_W);
}

void UIDelegate::initDisk() {
    for (int i = 0; i < getDiskNumber(); ++ i) {
        UIButton* tempDisk = new UIButton();
        tempDisk -> setLength((i+1) * 0.13 * source.getLength());
        tempDisk -> setHeight(20);
        tempDisk -> setBackGroundColor(lineBlue);
        disks.push_back(tempDisk);
    }
}

// Put disks on the correct peg.
void UIDelegate::updateDisks() {
    for (int i = getSourcePeg().getSize(); i > 0; --i) {
        UIButton* tempDisk = disks[getSourcePeg().at(i - 1) -> data ->getNumber() -1];
        tempDisk -> setPosition(source.getMidPoint() + sf::Vector2f(5-0.5*tempDisk->getLength(),-tempDisk->getHeight() -(getSourcePeg().getSize() - i)*25));
    }
    for (int i = getAuxilaryPeg().getSize(); i > 0; --i) {
        UIButton* tempDisk = disks[getAuxilaryPeg().at(i - 1) -> data ->getNumber() -1];
        tempDisk -> setPosition(source.getMidPoint() + sf::Vector2f(5-0.5*tempDisk->getLength() + source.getLength() + 0.05*DEFAULT_W,-tempDisk->getHeight() -(getAuxilaryPeg().getSize() - i)*25));
    }
    for (int i = getDestinationPeg().getSize(); i > 0; --i) {
        UIButton* tempDisk = disks[getDestinationPeg().at(i - 1) -> data ->getNumber() -1];
        tempDisk -> setPosition(source.getMidPoint() + sf::Vector2f(5-0.5*tempDisk->getLength()+2* source.getLength()+0.1*DEFAULT_W,-tempDisk->getHeight() -(getDestinationPeg().getSize() - i)*25));
    }
}

void UIDelegate::drawDisks() {
    for (int i = 0; i < disks.size(); ++ i) {
        disks[i] -> placeButton(window);
    }
}

void UIDelegate::drawPeg() {
    source.draw(window);
    aux.draw(window);
    dest.draw(window);
}

void UIDelegate::drawButtons() {
    displayMove.placeButton(window);
    displayDiskNumber.placeButton(window);
    minMove.placeButton(window);
}

void UIDelegate::drawLabels() {
    title.drawLabel(window);
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
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Enter:
                    case sf::Keyboard::Space:
                    case sf::Keyboard::Right:
                        if (inProgress()) {
                            autoMove();
                            updateDisks();
                        }
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}




void UIDelegate::render() {
    window.clear();
    // Draw base views here.
    window.draw(appView.getView());
    window.draw(SafeArea.getView());
    drawLabels();
    // Draw pegs here.
    drawPeg();

    // Update and Draw buttons here.
    initButton();
    drawButtons();
    // Draw disks here.
    updateDisks();
    drawDisks();
    
    window.display();
    
}
