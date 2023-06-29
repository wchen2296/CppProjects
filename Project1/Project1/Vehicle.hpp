//
//  Vehicle.hpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <iostream>
#include <string>
class Vehicle{
private:
    std::string name_;
    std::string manufacturer_;
    int wheels_;
    int gas_;
    int passengers_;
    int cargo_;
    
public:
    //default constuctor
    Vehicle();
    //parameterized constuctor
    Vehicle(std::string name, std::string manufacturer, int wheels, int gas, int passengers, int cargo);
    //Name methods
    std::string getName() const;
    void setName(std::string name);
    //manufacturer methods
    std::string getManufacturer() const;
    void setManufacturer(std::string manufacturer);
    //wheel methods
    int getWheels() const;
    void setWheels(int wheels);
    //gas methods
    int getGas()const;
    void setGas(int gas);
    //passengers methods
    int getPassengers()const;
    void setPassengers(int passengers);
    //cargo methods
    int getCargo()const;
    void setCargo(int cargo);
    
};
#endif /* Vehicle_hpp */
