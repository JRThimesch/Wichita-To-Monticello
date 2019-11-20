// File Name: VehicleRecords.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include "Vehicle.hpp"
#ifndef SRC_VEHICLERECORDS_HPP_
#define SRC_VEHICLERECORDS_HPP_

const int NUMVEHICLES = 33;

class VehicleRecords {
	private:
		static std::string make;
		static std::string model;
		static double engine;
		static double tankSize;
		static int cylinders;
		static int cityMPG;
		static int highwayMPG;
		static std::string type;
		static int size;


	public:
		VehicleRecords();
		~VehicleRecords();
		VehicleRecords(std::string);
		static std::string trimWhiteSpace(std::string&);
		static std::string getList();
		static std::string getMake();
		static std::string getModel();
		static double getEngine();
		static double getTankSize();
		static int getCylinders();
		static int getCityMPG();
		static int getHighwayMPG();
		static std::vector<Vehicle*> temp;

		// ASSIGNMENT 3
		static int vehicleListSize();
};



#endif /* SRC_VEHICLERECORDS_HPP_ */
