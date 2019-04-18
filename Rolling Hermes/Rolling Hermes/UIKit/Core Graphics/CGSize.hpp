//
//  CGSize.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef CGSize_hpp
#define CGSize_hpp

struct CGSize {
    double width;
    double height;
    
    CGSize(double _width = 0, double _height = 0) {
        width = _width;
        height = _height;
    }
    void init(double w = 0, double h = 0) {
        width = w;
        height = h;
    }
    
};

#endif /* CGSize_hpp */
