//
//  CGRect.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/17/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef CGRect_hpp
#define CGRect_hpp

#include "CGpoint.hpp"
#include "CGSize.hpp"
#include "CGVector.hpp"
struct CGRect {
    CGPoint origin;
    CGSize size;
    
    CGRect(CGPoint _origin, CGSize _size);
    CGRect(double x = 0, double y = 0, double width = 0, double height = 0);
    
    double height() const;
    double width() const;
    double minX() const;
    double midX() const;
    double maxX() const;
    double minY() const;
    double midY() const;
    double maxY() const;
    
    CGPoint midPoint() const;
    void setOrigin(const CGPoint& point);
    void setSize(const CGSize& _size);
    bool contains(CGPoint aPoint) const;
    bool contains(CGRect aRect) const;
    
};
#endif /* CGRect_hpp */
