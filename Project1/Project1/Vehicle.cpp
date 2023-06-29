//
//  Vehicle.cpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#include "Vehicle.hpp"
//default constructor
Vehicle::Vehicle():name_(""),manufacturer_(""),wheels_(0),gas_(0),passengers_(0),cargo_(0){}
//parametermized constuctor
Vehicle::Vehicle(std::string name, std::string manufacturer, int wheels, int gas, int passengers, int cargo):name_(name), manufacturer_(manufacturer),wheels_(wheels),gas_(gas), passengers_(passengers),cargo_(cargo){}
//name methods
std::string Vehicle::getName() const{
    
    return name_;
}
void Vehicle::setName(std::string name){
    name_=name;
}
//manufacturer methods
std::string Vehicle::getManufacturer()const{
    
    return manufacturer_;
}
void Vehicle::setManufacturer(std::string manufacturer){
    manufacturer_=manufacturer;
}
//wheels methods
int Vehicle::getWheels()const{
   
    return wheels_;
}
void Vehicle::setWheels(int wheels){
    wheels_=wheels;
}
//gas methods
int Vehicle::getGas()const{
    
    return gas_;
}
void Vehicle::setGas(int gas){
    gas_=gas;
}
//passenger methods
int Vehicle::getPassengers()const{
        return passengers_;
}
void Vehicle::setPassengers(int passengers){
    passengers_=passengers;
}
//cargo methods
int Vehicle::getCargo()const{
    
    return cargo_;
}
void Vehicle::setCargo(int cargo){
    cargo_=cargo;
}
