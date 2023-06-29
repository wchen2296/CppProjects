//
//  Circle.hpp
//  Project 3
//
//  Created by William Chen on 6/25/22.
//

#ifndef Circle_hpp
#define Circle_hpp
#include "Shape.hpp"
#include <stdio.h>
class Circle : public Shape{
    //constructor
public:
    Circle(const int& diameter);
    //getters
    double getSurfaceArea() override;
    double get3DVolume(const double& depth) override;
    
};
#endif /* Circle_hpp */
