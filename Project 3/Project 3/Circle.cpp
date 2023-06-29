//
//  Circle.cpp
//  Project 3
//
//  Created by William Chen on 6/25/22.
//

#include "Circle.hpp"
#include <cmath>

Circle::Circle(const int &diameter) : Shape(diameter, diameter)
{
    setEdges(0);

    // Populate 2D array with empty chars
    //allocating array dyanmically
    char **arr = new char *[getHeight()];
    for (int row = 0; row < getHeight(); row++)
    {
        arr[row] = new char[getWidth()];
        for (int col = 0; col < getWidth(); col++)
        {
            arr[row][col] = ' ';
        }
    }

    // Populate the proper positions with *'s
    int x_radius = diameter / 2;
    int y_radius = (diameter / 2) - 1;
    float dist = 0;
    char ascii_counter = 48;

    for (int col = 0; col <= getWidth() + 1; col++)
    {
        for (int row = 0; row <= getHeight() + 5; row++)
        {
            dist = sqrt((row - y_radius) * (row - y_radius) +
                        (col - x_radius) * (col - x_radius));

            // dist in range: (radius - 0.5) to (radius + 0.5)
            if (dist > y_radius - 0.5 && dist < y_radius + 0.5)
            {
                arr[row][col] = ascii_counter;

                // fix ascii_counter to wrap around after
                ascii_counter++;
                if (ascii_counter > 126)
                {
                    ascii_counter = 48;
                }
            }
        }
    }
    setDisplayChars(arr);
}

double Circle::get3DVolume(const double &depth){
    
    return pow(depth/2.0,3.0)*M_PI*(4.0/3.0);
}

double Circle::getSurfaceArea(){
    return pow(getWidth()/2,2)*M_PI;
}
