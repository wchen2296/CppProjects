//
//  Motorcycle.hpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#ifndef Motorcycle_hpp
#define Motorcycle_hpp

#include "Vehicle.hpp"

class Motorcycle:public Vehicle{
private:
    bool sideMotorcycle_;
public:
    Motorcycle();
    Motorcycle(std::string name, std::string manufacturer);
    //sideMotor methods
    void toggleSideMotorcycle();
    bool getSideMotorcycle();
    
};

#endif /* Motorcycle_hpp */
