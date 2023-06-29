//
//  Truck.hpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#ifndef Truck_hpp
#define Truck_hpp

#include "Vehicle.hpp"

class Truck:public Vehicle{
private:
    bool hasTrailer_{false};
    
public:
    //constructors
    Truck();
    Truck(std::string name, std::string manufacturer);
    //trailer methods
    void toggleTrailer();
    bool getTrailer();
    
    
};

#endif /* Truck_hpp */
