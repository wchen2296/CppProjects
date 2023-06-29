//
//  Triangle.hpp
//  Project 3
//
//  Created by William Chen on 6/27/22.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Shape.hpp"
class Triangle:public Shape{
public:
    Triangle(const int& side);
    double get3DVolume(const double &depth) override;
    double getSurfaceArea() override;
};
#endif /* Triangle_hpp */
