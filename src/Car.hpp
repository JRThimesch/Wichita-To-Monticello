// File Name: Car.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <string>
#include "Vehicle.hpp"
#ifndef SRC_CAR_HPP_
#define SRC_CAR_HPP_

class Car : public Vehicle {
	public:
		Car();
		Car(std::string, std::string, double, double, int, int, int);
		std::string getType() { return "Car"; };
		Vehicle* clone();
		const double getRefuelTime() { return 8.0; };
		std::string toString();
};



#endif /* SRC_CAR_HPP_ */
