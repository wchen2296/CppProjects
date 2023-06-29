//
//  Rectangle.cpp
//  Project 3
//
//  Created by William Chen on 6/27/22.
//

#include "Rectangle.hpp"
//constructor
Rectangle::Rectangle(const int& width,const int& height): Shape(width, height){
    setWidth(width);
    setHeight(height);
    setEdges(4);
  //allocate array dynamically and populate with " "
    char **arr = new char *[getHeight()];
    for (int row = 0; row < getHeight(); row++)
    {
        arr[row] = new char[getWidth()];
        for (int col = 0; col < getWidth(); col++)
        {
            arr[row][col] = ' ';
        }
    }
    //populating with ascI
    char asci=48;
    
    for(int col=0;col<getWidth();col++){
        
            arr[0][col]=asci;
            asci++;
            if(asci>126){
                asci=48;
            }
    }
    for(int row=1;row<getHeight();row++){
        arr[row][0]=asci;
        asci++;
        if(asci>126){
            asci=48;
        }
        arr[row][getWidth()-1]=asci;
        asci++;
        if(asci>126){
            asci=48;
        }
        
        if(row==getHeight()-1){
            --asci;
            --asci;
            for(int bRow=0;bRow<getWidth();bRow++){
                arr[getHeight()-1][bRow]=asci;
                asci++;
                if(asci>126){
                    asci=48;
                }
            }
        }
    }
    setDisplayChars(arr);
    
}

double Rectangle::get3DVolume(const double &depth){
    return getWidth()*getHeight()*depth;
}

double Rectangle::getSurfaceArea(){
    return getWidth()*getHeight();
}
