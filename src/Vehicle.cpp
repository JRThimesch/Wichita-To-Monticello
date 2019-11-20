// File Name: Vehicle.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <sstream>
#include "Vehicle.hpp"

Vehicle::Vehicle()
{
	make = "Make";
	model = "Model";
	engine = 0;
	tankSize = 0;
	cylinders = 0;
	cityMPG = 0;
	highwayMPG = 0;
	type = "NULL";
}

Vehicle::Vehicle(std::string tempMake, std::string tempModel, double tempEngine, double tempTankSize, int tempCylinders, int tempCityMPG, int tempHighwayMPG)
{
	make = tempMake;
	model = tempModel;
	engine = tempEngine;
	tankSize = tempTankSize;
	cylinders = tempCylinders;
	cityMPG = tempCityMPG;
	highwayMPG = tempHighwayMPG;
	type = "NULL";
}

std::string Vehicle::getMake()
{
	return make;
}

std::string Vehicle::getModel()
{
	return model;
}

double Vehicle::getEngine()
{
	return engine;
}

double Vehicle::getTankSize()
{
	return tankSize;
}

int Vehicle::getCylinders()
{
	return cylinders;
}

int Vehicle::getCityMPG()
{
	return cityMPG;
}

int Vehicle::getHighwayMPG()
{
	return highwayMPG;
}

std::string Vehicle::toString()
{
	std::ostringstream ss;
	ss << "  Make: " << make << "  Model: " << model << "  Tank Size: " << tankSize << "  Cylinders: " << cylinders << std::endl;
	ss << "  City MPG: " << cityMPG << "  Highway MPG: " << highwayMPG << std::endl;
	return ss.str();
}

Vehicle::~Vehicle()
{
}
