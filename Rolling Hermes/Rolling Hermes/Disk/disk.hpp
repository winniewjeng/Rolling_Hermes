//
//  disk.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef disk_hpp
#define disk_hpp
#include <iostream>
using namespace std;

class disk {
private:
    // Static number
    // Keeps the last issued disk size recorded.
    static int lastIssued;
    int number;
    
public:
    disk();
    ~disk();
    disk(const disk& other);
    disk& operator =(const disk& other);
    
    // accessor
    // Accessor
    int getNumber() {return number;}
    // Function: get disk number
    // Description: returns the disk number
    // Return type: int
    // Paramaters: none
    
    // overloaded operators
    friend ostream& operator<< (ostream& out, const disk& print);
    // Friend ostream
    // Print the disk
    friend
    ostream& operator<< (ostream& out, const disk& print);
    
    friend bool operator > (const disk& x, const disk& y);
    
    friend bool operator < (const disk& x, const disk& y);
    
};
#endif /* disk_hpp */
