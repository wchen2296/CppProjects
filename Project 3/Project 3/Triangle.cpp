//
//  Triangle.cpp
//  Project 3
//
//  Created by William Chen on 6/27/22.
//

#include "Triangle.hpp"

Triangle::Triangle(const int& side):Shape(side, side){
    setWidth(side);
    setHeight(side);
    setEdges(3);
    //allocating array and populating with ""
    char **arr = new char *[getHeight()];
    for (int row = 0; row < getHeight(); row++)
    {
        arr[row] = new char[getWidth()];
        for (int col = 0; col < getWidth(); col++)
        {
            arr[row][col] = ' ';
        }
    }
    //populating with asci
    char asci=47;
    int hypo=0; //hypotnuse of triagnle
    for(int row=0;row<getHeight();row++){
        if(row<getHeight()-1){
            arr[row][0]=asci;
            asci++;
            
            if(asci>126){
                asci=48;
            }
            arr[row][hypo]=asci;
            hypo++;
            asci++;
            if(asci>126){
                asci=48;
            }
        }
        else{
            for(int col=0;col<getWidth();col++){
                arr[row][col]=asci;
                asci++;
                if(asci>126){
                    asci=48;
                }
            }
        }
    }
    setDisplayChars(arr);
    
}

double Triangle::get3DVolume(const double &depth){
    return 0.5*getWidth()*getHeight()*depth;
}

double Triangle::getSurfaceArea(){
    return getWidth()*getHeight()*0.5;
}
