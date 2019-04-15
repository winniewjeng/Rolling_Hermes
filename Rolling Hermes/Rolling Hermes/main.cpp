//
//  main.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng, Jack Zhao on 4/3/19.
//  Copyright © 2019 Winnie Jeng, Jack Zhao. All rights reserved.
//

#include <iostream>
#include "board.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    arrPriorityQueue<disk*, int> src;
    for (int i = 0; i < 5; ++i) {
        disk* temp = new disk();
        cout << "temp: " << temp -> getNumber() << " ";
        cout << "\ni = " << -i << endl;
        src.enqueue(temp, -i);
    }

    for (int i = 0; i<5;++i) {
        cout << src.deque() -> getNumber() << endl;
    }
    cout << endl;
//    board(5);
}


