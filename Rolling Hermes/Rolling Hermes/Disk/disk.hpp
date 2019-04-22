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
    
<<<<<<< HEAD
    // accessor
=======
    // Accessor
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
    int getNumber() {return number;}
    // Function: get disk number
    // Description: returns the disk number
    // Return type: int
    // Paramaters: none
    
<<<<<<< HEAD
    // overloaded operators
    friend ostream& operator<< (ostream& out, const disk& print);
=======
    // Friend ostream
    // Print the disk
    friend
    ostream& operator<< (ostream& out, const disk& print);
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
    
    friend bool operator > (const disk& x, const disk& y);
    
    friend bool operator < (const disk& x, const disk& y);
    
};
#endif /* disk_hpp */
