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
    
    arrPriorityQueue<int, int> a;
    a.enqueue(1, 1);
    a.print();
    a.enqueue(2, 1);
    a.print();
    a.enqueue(3, 1);
    a.print();
    a.enqueue(40, 2);
    a.print();
    a.enqueue(41, 2);
    a.print();
    cout << a.deque() << endl;
    a.print();
    cout << a.deque() << endl;
    a.print();

    return 0;
}


