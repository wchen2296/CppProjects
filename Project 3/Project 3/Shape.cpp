//
//  Shape.cpp
//  Project 3
//
//  Created by William Chen on 6/23/22.
//

#include "Shape.hpp"
//construtor
Shape::Shape(const int& width, const int& height):Width_(width),Height_(height){}
//getters
int Shape::getEdges(){
    return Edges_;
}
int Shape::getWidth(){
    return Width_;
}
int Shape::getHeight(){
    return Height_;
}
char** Shape::getDisplayChars(){
    return DisplayChars_;
}
//setters
void Shape::setEdges(const int &edges){
    Edges_=edges;
}
void Shape::setWidth(const int &width){
    Width_=width;
}
void Shape::setHeight(const int &height){
    Height_=height;
}
void Shape::setDisplayChars(char **display){
    DisplayChars_=display;
}
void Shape::display(){
    char** display=getDisplayChars();
    for(int i=0;i<getHeight();i++){
        for(int j=0;j<getWidth();j++){
            std::cout<<display[i][j]<<' ';
        }
        std::cout<<"\n";
    }
}
//Mutators
//counterclockwise
void Shape::rotateLeft(){
    //dynamically allocating temp array to store rotated shape
    char** original=getDisplayChars();
    char** temp= new char*[getWidth()];
    for(int i=0;i<getWidth();i++){
        temp[i]=new char[getHeight()];
        for(int j=0;j<getHeight();j++){
            temp[i][j]=' ' ;
        }
    }
    //rotating 90 and storing in temp
    for(int i=0;i<getHeight();i++){
        for(int j=0;j<getWidth();j++){
            temp[getWidth()-1-j][i]=original[i][j];
        }
    }
    setDisplayChars(temp);
}
//clockwise
void Shape::rotateRight(){
    //dynamically allocating temp array to store rotated shape
    char** original=getDisplayChars();
    char** temp= new char*[getWidth()];
    for(int i=0;i<getWidth();i++){
        temp[i]=new char[getHeight()];
        for(int j=0;j<getHeight();j++){
            temp[i][j]=' ' ;
        }
    }
    //rotating 90 and storing in temp
    for(int i=0;i<getHeight();i++){
        for(int j=0;j<getWidth();j++){
            temp[j][getHeight()-1-i]=original[i][j];
        }
    }
    setDisplayChars(temp);
}
