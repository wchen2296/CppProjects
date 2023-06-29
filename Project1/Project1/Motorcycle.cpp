//
//  Motorcycle.cpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#include "Motorcycle.hpp"
//constuctors
Motorcycle::Motorcycle(){
    setName("");
    setManufacturer("");
    setWheels(2);
    setPassengers(2);
    setGas(1);
    setCargo(0);
}
Motorcycle::Motorcycle(std::string name, std::string manufacturer){
    setName(name);
    setManufacturer(manufacturer);
    setWheels(2);
    setPassengers(2);
    setGas(1);
    setCargo(0);
}
//sidemotor methods
void Motorcycle::toggleSideMotorcycle(){
    if (sideMotorcycle_==false){
        sideMotorcycle_=true;
        setWheels(4);
        setPassengers(3);
    }
    else{
        sideMotorcycle_=false;
        setWheels(2);
        setPassengers(2);
    }
}
bool Motorcycle::getSideMotorcycle(){
 
    return sideMotorcycle_;
}


