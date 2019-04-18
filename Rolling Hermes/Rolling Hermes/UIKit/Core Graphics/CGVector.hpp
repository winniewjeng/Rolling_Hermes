//
//  CGVector.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef CGVector_hpp
#define CGVector_hpp

struct CGVector {
    double dx;
    double dy;
    
    CGVector(double x = 0, double y = 0): dx(x), dy(y) {}
};
#endif /* CGVector_hpp */
