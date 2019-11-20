// File Name: Van.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Vehicle.hpp"
#ifndef SRC_VAN_HPP_
#define SRC_VAN_HPP_

class Van : public Vehicle {
    public:
        Van();
        Van(std::string, std::string, double, double, int, int, int);
        std::string getType() { return "Van"; };
        Vehicle* clone();
        const double getRefuelTime() { return 12.0; };
        std::string toString();
};



#endif /* SRC_VAN_HPP_ */
