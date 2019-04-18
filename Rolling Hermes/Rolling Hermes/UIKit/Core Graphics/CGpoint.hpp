//
//  CGpoint.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef CGpoint_hpp
#define CGpoint_hpp

struct CGPoint {
    
    double x;
    double y;
    CGPoint(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
    void init() {
        x = 0;
        y = 0;
    }
};

#endif /* CGpoint_hpp */
