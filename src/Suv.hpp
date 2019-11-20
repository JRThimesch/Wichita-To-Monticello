// File Name: Suv.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Vehicle.hpp"
#ifndef SRC_SUV_HPP_
#define SRC_SUV_HPP_

class Suv : public Vehicle {
	public:
		Suv();
		Suv(std::string, std::string, double, double, int, int, int);
		std::string getType() { return "Suv"; };
		Vehicle* clone();
		const double getRefuelTime() { return 10.0; };
		std::string toString();
};



#endif /* SRC_SUV_HPP_ */
