//
//  Shape.hpp
//  Project 3
//
//  Created by William Chen on 6/23/22.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <iostream>

class Shape{
private:
    int Edges_;
    int Width_;
    int Height_;
    char** DisplayChars_;//pointer to array
    
public:
    //constructor
    Shape(const int& width, const int& height);
    //getters
    int getEdges();
    int getWidth();
    int getHeight();
    char **getDisplayChars();
    //setters
    void setEdges(const int& edges);
    void setWidth(const int& width);
    void setHeight(const int& height);
    void setDisplayChars(char **display);
    //mutators (rotate 90 degrees)
    void rotateRight();
    void rotateLeft();
    //virtual methods
    virtual double getSurfaceArea() = 0;
    virtual double get3DVolume(const double& depth) = 0;
    void display();

};

#endif /* Shape_hpp */
