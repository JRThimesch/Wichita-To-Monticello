// File Name: TripParameters.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#ifndef SRC_TRIPPARAMETERS_HPP_
#define SRC_TRIPPARAMETERS_HPP_

class TripParameters {
	private:
		int cityMPH;
		int highwayMPH;
		double fuelPrice;
		int gasStopDistance;
		int timeBetweenNaps;
		//int refuelTime;
		int breakTime;
		int napLength;
	public:
		TripParameters();
		TripParameters(std::string);
		void loadParameters(std::string);
		std::string getValidKeys();
		int getCityMPH();
		int getHighwayMPH();
		double getFuelPrice();
		int getGasStopDistance();
		int getTimeBetweenNaps();
		//int getRefuelTime(); taken out for assignment 4
		int getBreakTime();
		int getNapLength();
};



#endif /* SRC_TRIPPARAMETERS_HPP_ */
