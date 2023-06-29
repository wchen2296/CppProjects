//
//  main.cpp
//  Project 4
//
//  Created by William Chen on 6/30/22.
//

#include <iostream>
#include "Sorter.hpp"

int main(int argc, const char * argv[]) {
    Sorter a(RANDOM, 10);
    a.runSorts(INCREASING);
    return 0;
}
