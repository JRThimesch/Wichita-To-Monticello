// File Name: TripLeg.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4
#include <string>
#ifndef SRC_TRIPLEG_HPP_
#define SRC_TRIPLEG_HPP_

enum roadType{CITY, HIGHWAY};

class TripLeg {
	double distance;
	roadType road;

	public:
		TripLeg();
		TripLeg(double, roadType);
		double getDistance();
		roadType getRoad();
		std::string printRoad();
};

#endif /* SRC_TRIPLEG_HPP_ */
