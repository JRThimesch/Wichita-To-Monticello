// File Name: Minivan.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Vehicle.hpp"
#ifndef SRC_MINIVAN_HPP_
#define SRC_MINIVAN_HPP_

class Minivan : public Vehicle {
	public:
		Minivan();
		Minivan(std::string, std::string, double, double, int, int, int);
		std::string getType() { return "Minivan"; };
		Vehicle* clone();
		const double getRefuelTime() { return 14.0; };
		std::string toString();
};



#endif /* SRC_MINIVAN_HPP_ */
