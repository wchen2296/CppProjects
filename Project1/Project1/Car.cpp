//
//  Car.cpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#include "Car.hpp"
//constuctors

Car::Car(){
    setName("");
    setManufacturer("");
    setWheels(4);
    setGas(12);
    setCargo(850);
    setPassengers(5);
}
Car::Car(std::string name, std::string manufacturer){
    setName(name);
    setManufacturer(manufacturer);
    setWheels(4);
    setGas(12);
    setCargo(850);
    setPassengers(5);
}
//bumpersticker methods
void Car::addBumperStickers(std::string sticker){
    list_of_bumper_stickers_.push_back(sticker);
}
void Car::getBumperStickers(){
    for (int i=0;i<list_of_bumper_stickers_.size();i++){
        std::cout<<list_of_bumper_stickers_[i]<<"\n";
    }
}
