//
//  Rectangle.hpp
//  Project 3
//
//  Created by William Chen on 6/27/22.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include "Shape.hpp"

class Rectangle: public Shape{
public:
    Rectangle(const int& width, const int& height);
    double get3DVolume(const double &depth) override;
    double getSurfaceArea() override;
    
};

#endif /* Rectangle_hpp */
