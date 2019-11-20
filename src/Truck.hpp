// File Name: Truck.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Vehicle.hpp"
#ifndef SRC_TRUCK_HPP_
#define SRC_TRUCK_HPP_

class Truck : public Vehicle {
    public:
        Truck();
        Truck(std::string, std::string, double, double, int, int, int);
        std::string getType() { return "Truck"; };
        Vehicle* clone();
        const double getRefuelTime() { return 16.0; };
        std::string toString();
};



#endif /* SRC_TRUCK_HPP_ */
