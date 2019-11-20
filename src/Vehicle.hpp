// File Name: Vehicle.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <string>
#ifndef SRC_VEHICLE_HPP_
#define SRC_VEHICLE_HPP_

class Vehicle {
	std::string make;
	std::string model;
	double engine;
	double tankSize; //i had to unprivate this for some odd reason or else i would get an error
	int cylinders;
	int cityMPG;
	int highwayMPG;
	std::string type;

	public:
		Vehicle();
		Vehicle(std::string, std::string, double, double, int, int, int);
		std::string getMake();
		std::string getModel();
		double getEngine();
		double getTankSize();
		int getCylinders();
		int getCityMPG();
		int getHighwayMPG();

		// ASSIGNMENT 4
        // I'm just putting the comments for these here since I don't want to just say the same thing for each vehicle
        virtual Vehicle* clone() = 0;   // copy constructor for all types
		virtual std::string getType() = 0;  // returns type depending on the class a vehicle belongs to
		virtual const double getRefuelTime() = 0;   // different fuel times depending on class
		virtual std::string toString();     // combines this function with the same of the class to return a string with vehicle info
		virtual ~Vehicle();     // virtual destructor
};

#endif /* SRC_VEHICLE_HPP_ */
