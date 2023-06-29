//
//  Car.hpp
//  Project1
//
//  Created by William Chen on 6/4/22.
//

#ifndef Car_hpp
#define Car_hpp

#include "Vehicle.hpp"
#include "vector"

class Car : public Vehicle{
private:
    std::vector<std::string> list_of_bumper_stickers_;
    
public:
    //constuctors
    Car();
    Car(std::string name,std::string manufacturer);
    //sticker methods
    void addBumperStickers(std::string sticker);
    void getBumperStickers();
    
};

#endif /* Car_hpp */
