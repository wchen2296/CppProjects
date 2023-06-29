//
//  Truck.cpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#include "Truck.hpp"
//constructor
Truck::Truck(){
    setName("");
    setManufacturer("");
    setWheels(16);
    setPassengers(3);
    setGas(125);
    setCargo(8000);
    
}
Truck::Truck(std::string name, std::string manufacturer){
    setName(name);
    setManufacturer(manufacturer);
    setWheels(16);
    setPassengers(3);
    setGas(125);
    setCargo(8000);
}
//trailer method
void Truck::toggleTrailer(){
    if(hasTrailer_==false){
        setWheels(26);
        setCargo(16000);
        hasTrailer_=true;
    }
    else{
        setWheels(16);
        setCargo(8000);
        hasTrailer_=false;
    }
}

bool Truck::getTrailer(){
    return hasTrailer_;
}
