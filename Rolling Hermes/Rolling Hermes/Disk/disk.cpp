//
//  disk.cpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//
#include <iostream>
#include "disk.hpp"

int disk::lastIssued = 0;

disk::disk()  {
    number = ++lastIssued;
    cout << "Disk #" << number << " was created!" << endl;
}
disk::~disk() {
    --lastIssued;
    cout << "Disk #" << number << " was destroyed!" << endl;
}
disk::disk(const disk& other) {
    number = other.number;
}
disk& disk::operator =(const disk& other) {
    if (this == &other)
        return *this;
    number = other.number;
    return *this;
}


ostream& operator<< (ostream& out, const disk& print) {
    out << "Disk: " << print.number;
    return out;
}


bool operator > (const disk& x, const disk& y) {
    return (x.number > y.number);
}

bool operator < (const disk& x, const disk& y) {
    return (x.number < y.number);
}
