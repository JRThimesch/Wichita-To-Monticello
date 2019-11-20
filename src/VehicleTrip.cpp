// File Name: VehicleTrip.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
#include "VehicleTrip.hpp"
#include "Vehicle.hpp"
#include "VehicleRecords.hpp"


VehicleTrip::VehicleTrip() {
	time = 0;
	breaks = 0;
	breakTime = 10;
	totalBreaks = 0;
	gasDistance = 80;
	gasDistanceRemaining = 0;
	gasStops = 0;
	speedCity = 25;
	speedHighway = 70;
	napTime = 8.0;
	napLength = 15;
	naps = 0;
	legDistance = 0;
	gas = 0;
	gasPrice = 2.19;
	gasUsed = 0;
	fuelTime = 20;
	totalDistance = 0;
	gasNeeded = 0;
	gasAdded = 0;
	costGasUsed = 0;
	costGasAdded = 0;
	cityDriven = 0;
	highwayDriven = 0;
}

double VehicleTrip::getCityDriven()
{
	return cityDriven;
}

double VehicleTrip::getHighwayDriven()
{
	return highwayDriven;
}

void VehicleTrip::setCityDriven(double x)
{
	cityDriven = x;
}

void VehicleTrip::setHighwayDriven(double x)
{
	highwayDriven = x;
}

double VehicleTrip::getGasDistanceRemaining()
{
	return gasDistanceRemaining;
}

void VehicleTrip::setGasDistanceRemaining(double x)
{
	gasDistanceRemaining = x;
}

double VehicleTrip::getGasAdded()
{
	return gasAdded;
}

double VehicleTrip::getCostGasUsed()
{
	return costGasUsed;
}

double VehicleTrip::getCostGasAdded()
{
	return costGasAdded;
}

void VehicleTrip::setCostGasUsed(double x)
{
	costGasUsed = x;
}

void VehicleTrip::setCostGasAdded(double x)
{
	costGasAdded = x;
}

std::string VehicleTrip::getTimeRefined()
{
	std::stringstream toString;
	int days, hours, minutes;

	std::cout << std::setprecision(0) << std::fixed;
	days = getTime() / 60 / 24;

	hours = (getTime() / 60) - (days * 24);

	minutes = getTime() - (days * 24 * 60) - (hours * 60) + 1; //need to add 1 to the result because it was off by 1 minute in the display

	// I know there is probably a better way to do this but it works
	if (hours >= 10 && minutes >= 10) {
		toString << days << "." << hours << ":" << minutes;
	} else if (hours <= 9 && minutes >= 10) {
		toString << days << ".0" << hours << ":" << minutes;
	} else if (hours <= 9 && minutes <= 9) {
		toString << days << ".0" << hours << ":0" << minutes;
	} else if (hours >= 10 && minutes <= 9) {
		toString << days << "." << hours << ":0" << minutes;
	}

	return toString.str();
}

int VehicleTrip::getGasStops()
{
	return gasStops;
}

void VehicleTrip::setGasUsed(double x)
{
	gasUsed = x;
}

void VehicleTrip::setGasAdded(double x)
{
	gasAdded = x;
}

void VehicleTrip::setFuelTime(int x)
{
	fuelTime = x;
}

int VehicleTrip::getFuelTime()
{
	return fuelTime;
}

void VehicleTrip::startingGas(double x) {
	gas = x;
}

double VehicleTrip::getTime()
{
	return time;
}

void VehicleTrip::setTime(double x)
{
	time = x;
}

void VehicleTrip::setBreakTime(int x)
{
	breakTime = x;
}

int VehicleTrip::getBreakTime()
{
	return breakTime;
}

int VehicleTrip::getBreaks()
{
	return breaks;
}

void VehicleTrip::addGasStop()
{
	gasStops++;
}

void VehicleTrip::checkBreaks()
{
	if ( gasStops != 0 && gasStops % 2 == 0) {
		addBreak();
		//std::cout << "    Taking a break! " << "Break #" << getBreaks() << std::endl;
	} else {
		//std::cout << "    No need to take a break!" << std::endl;
	}
}

void VehicleTrip::addBreak()
{
	breaks++;
	//checkBreaks();
}

void VehicleTrip::setGasDistance(int x)
{
	gasDistance = x;
}

int VehicleTrip::getGasDistance()
{
	return gasDistance;
}

void VehicleTrip::setSpeedCity(int x)
{
	speedCity = x;
}

int VehicleTrip::getSpeedCity()
{
	return speedCity;
}

void VehicleTrip::setSpeedHighway(int x)
{
	speedHighway = x;
}

int VehicleTrip::getSpeedHighway()
{
	return speedHighway;
}

void VehicleTrip::setNapTime(double x)
{
	napTime = x;
}

double VehicleTrip::getNapTime()
{
	return napTime;
}

void VehicleTrip::setNapLength(int x)
{
	napLength = x;
}

int VehicleTrip::getNapLength()
{
	return napLength;
}

int VehicleTrip::getNaps()
{
	return naps;
}

void VehicleTrip::addNaps()
{
	naps++;
}

double VehicleTrip::getGasPrice()
{
	return gasPrice;
}

void VehicleTrip::setGasPrice(double x)
{
	gasPrice = x;
}

void VehicleTrip::setGas(double x)
{
	gas = x;
}

double VehicleTrip::getGas()
{
	return gas;
}

double VehicleTrip::getGasUsed()
{
	return gasUsed;
}

// ASSIGNMENT 2 FUNCTIONS
void VehicleTrip::addTime(double x)
{
	setTime(getTime() + x);
}

void VehicleTrip::addGasUsed(double x)
{
	setGasUsed(getGasUsed() + x);
}

// ASSIGNMENT 3 FUNCTIONS

VehicleTrip::~VehicleTrip()
{
}

void VehicleTrip::returnArrivingFirst(int a)
{
	std::cout << "Vehicle arriving first at Jefferson’s Monticello: " << std::endl;
	std::cout << VehicleRecords::temp[a]->getType() << ": " << VehicleRecords::temp[a]->getMake() << " " << VehicleRecords::temp[a]->getModel() << std::endl;
	std::cout << "  Tank Size: " << std::setprecision(1) << std::fixed << VehicleRecords::temp[a]->getTankSize() << "    " << "City MPG: " << VehicleRecords::temp[a]->getCityMPG() << "    " << "Highway MPG: " << VehicleRecords::temp[a]->getHighwayMPG() << std::endl;
	std::cout << "  Engine Size: " << VehicleRecords::temp[a]->getEngine() << "L    " << "Cylinders: " << VehicleRecords::temp[a]->getCylinders() << std::endl;
	std::cout << "  Trip Time [minutes]: " << std::setprecision(0) << std::fixed << getTime() << "    " << "Trip Time [d.hh:mm]: " << getTimeRefined() << std::endl;
	std::cout << "  Trip cost based on fuel added: $" << std::setprecision(2) << std::fixed << getCostGasAdded() << "    " << "Trip cost based on fuel used: $" << getCostGasUsed() << std::endl;
	std::cout << "  Fuel added: " << std::setprecision(4) << std::fixed << getGasAdded() << " gallons" << "    " << "Fuel used: " << getGasUsed() << std::endl;
	std::cout << "  Fuel remaining: " << getGas() << "    " << "Fuel Stops: ";
	std::cout.unsetf(std::ios_base::fixed);
	std::cout << getGasStops() << std::endl << std::endl;
}

void VehicleTrip::returnArrivingLast(int a)
{
	std::cout << "Vehicle arriving last at Jefferson’s Monticello: " << std::endl;
	std::cout << VehicleRecords::temp[a]->getType() << ": "<< VehicleRecords::temp[a]->getMake() << " " << VehicleRecords::temp[a]->getModel() << std::endl;
	std::cout << "  Tank Size: " << std::setprecision(1) << std::fixed << VehicleRecords::temp[a]->getTankSize() << "    " << "City MPG: " << VehicleRecords::temp[a]->getCityMPG() << "    " << "Highway MPG: " << VehicleRecords::temp[a]->getHighwayMPG() << std::endl;
	std::cout << "  Engine Size: " << VehicleRecords::temp[a]->getEngine() << "L    " << "Cylinders: " << VehicleRecords::temp[a]->getCylinders() << std::endl;
	std::cout << "  Trip Time [minutes]: " << std::setprecision(0) << std::fixed << getTime() << "    " << "Trip Time [d.hh:mm]: " << getTimeRefined() << std::endl;
	std::cout << "  Trip cost based on fuel added: $" << std::setprecision(2) << std::fixed << getCostGasAdded() << "    " << "Trip cost based on fuel used: $" << getCostGasUsed() << std::endl;
	std::cout << "  Fuel added: " << std::setprecision(4) << std::fixed << getGasAdded() << " gallons" << "    " << "Fuel used: " << getGasUsed() << std::endl;
	std::cout << "  Fuel remaining: " << getGas() << "    " << "Fuel Stops: ";
	std::cout.unsetf(std::ios_base::fixed);
	std::cout << getGasStops() << std::endl << std::endl;
}

void VehicleTrip::returnCostFuelAddedMost(int a)
{
	std::cout << "Vehicle costing the most to reach Jefferson’s Monticello based on fuel added to tank: " << std::endl;
	std::cout << VehicleRecords::temp[a]->getType() << ": "<< VehicleRecords::temp[a]->getMake() << " " << VehicleRecords::temp[a]->getModel() << std::endl;
	std::cout << "  Tank Size: " << std::setprecision(1) << std::fixed << VehicleRecords::temp[a]->getTankSize() << "    " << "City MPG: " << VehicleRecords::temp[a]->getCityMPG() << "    " << "Highway MPG: " << VehicleRecords::temp[a]->getHighwayMPG() << std::endl;
	std::cout << "  Engine Size: " << VehicleRecords::temp[a]->getEngine() << "L    " << "Cylinders: " << VehicleRecords::temp[a]->getCylinders() << std::endl;
	std::cout << "  Trip Time [minutes]: " << std::setprecision(0) << std::fixed << getTime() << "    " << "Trip Time [d.hh:mm]: " << getTimeRefined() << std::endl;
	std::cout << "  Trip cost based on fuel added: $" << std::setprecision(2) << std::fixed << getCostGasAdded() << "    " << "Trip cost based on fuel used: $" << getCostGasUsed() << std::endl;
	std::cout << "  Fuel added: " << std::setprecision(4) << std::fixed << getGasAdded() << " gallons" << "    " << "Fuel used: " << getGasUsed() << std::endl;
	std::cout << "  Fuel remaining: " << getGas() << "    " << "Fuel Stops: ";
	std::cout.unsetf(std::ios_base::fixed);
	std::cout << getGasStops() << std::endl << std::endl;
}

void VehicleTrip::returnCostFuelAddedLeast(int a)
{
	std::cout << "Vehicle costing the least to reach Jefferson’s Monticello based on fuel added to tank: " << std::endl;
	std::cout << VehicleRecords::temp[a]->getType() << ": "<< VehicleRecords::temp[a]->getMake() << " " << VehicleRecords::temp[a]->getModel() << std::endl;
	std::cout << "  Tank Size: " << std::setprecision(1) << std::fixed << VehicleRecords::temp[a]->getTankSize() << "    " << "City MPG: " << VehicleRecords::temp[a]->getCityMPG() << "    " << "Highway MPG: " << VehicleRecords::temp[a]->getHighwayMPG() << std::endl;
	std::cout << "  Engine Size: " << VehicleRecords::temp[a]->getEngine() << "L    " << "Cylinders: " << VehicleRecords::temp[a]->getCylinders() << std::endl;
	std::cout << "  Trip Time [minutes]: " << std::setprecision(0) << std::fixed << getTime() << "    " << "Trip Time [d.hh:mm]: " << getTimeRefined() << std::endl;
	std::cout << "  Trip cost based on fuel added: $" << std::setprecision(2) << std::fixed << getCostGasAdded() << "    " << "Trip cost based on fuel used: $" << getCostGasUsed() << std::endl;
	std::cout << "  Fuel added: " << std::setprecision(4) << std::fixed << getGasAdded() << " gallons" << "    " << "Fuel used: " << getGasUsed() << std::endl;
	std::cout << "  Fuel remaining: " << getGas() << "    " << "Fuel Stops: ";
	std::cout.unsetf(std::ios_base::fixed);
	std::cout << getGasStops() << std::endl << std::endl;
}

void VehicleTrip::returnCostFuelUsedMost(int a)
{
	std::cout << "Vehicle costing the most to reach Jefferson’s Monticello based on actual fuel used: " << std::endl;
	std::cout << VehicleRecords::temp[a]->getType() << ": "<< VehicleRecords::temp[a]->getMake() << " " << VehicleRecords::temp[a]->getModel() << std::endl;
	std::cout << "  Tank Size: " << std::setprecision(1) << std::fixed << VehicleRecords::temp[a]->getTankSize() << "    " << "City MPG: " << VehicleRecords::temp[a]->getCityMPG() << "    " << "Highway MPG: " << VehicleRecords::temp[a]->getHighwayMPG() << std::endl;
	std::cout << "  Engine Size: " << VehicleRecords::temp[a]->getEngine() << "L    " << "Cylinders: " << VehicleRecords::temp[a]->getCylinders() << std::endl;
	std::cout << "  Trip Time [minutes]: " << std::setprecision(0) << std::fixed << getTime() << "    " << "Trip Time [d.hh:mm]: " << getTimeRefined() << std::endl;
	std::cout << "  Trip cost based on fuel added: $" << std::setprecision(2) << std::fixed << getCostGasAdded() << "    " << "Trip cost based on fuel used: $" << getCostGasUsed() << std::endl;
	std::cout << "  Fuel added: " << std::setprecision(4) << std::fixed << getGasAdded() << " gallons" << "    " << "Fuel used: " << getGasUsed() << std::endl;
	std::cout << "  Fuel remaining: " << getGas() << "    " << "Fuel Stops: ";
	std::cout.unsetf(std::ios_base::fixed);
	std::cout << getGasStops() << std::endl << std::endl;
}

void VehicleTrip::returnCostFuelUsedLeast(int a)
{
	std::cout << "Vehicle costing the least to reach Jefferson’s Monticello based on actual fuel used: " << std::endl;
	std::cout << VehicleRecords::temp[a]->getType() << ": "<< VehicleRecords::temp[a]->getMake() << " " << VehicleRecords::temp[a]->getModel() << std::endl;
	std::cout << "  Tank Size: " << std::setprecision(1) << std::fixed << VehicleRecords::temp[a]->getTankSize() << "    " << "City MPG: " << VehicleRecords::temp[a]->getCityMPG() << "    " << "Highway MPG: " << VehicleRecords::temp[a]->getHighwayMPG() << std::endl;
	std::cout << "  Engine Size: " << VehicleRecords::temp[a]->getEngine() << "L    " << "Cylinders: " << VehicleRecords::temp[a]->getCylinders() << std::endl;
	std::cout << "  Trip Time [minutes]: " << std::setprecision(0) << std::fixed << getTime() << "    " << "Trip Time [d.hh:mm]: " << getTimeRefined() << std::endl;
	std::cout << "  Trip cost based on fuel added: $" << std::setprecision(2) << std::fixed << getCostGasAdded() << "    " << "Trip cost based on fuel used: $" << getCostGasUsed() << std::endl;
	std::cout << "  Fuel added: " << std::setprecision(4) << std::fixed << getGasAdded() << " gallons" << "    " << "Fuel used: " << getGasUsed() << std::endl;
	std::cout << "  Fuel remaining: " << getGas() << "    " << "Fuel Stops: ";
	std::cout.unsetf(std::ios_base::fixed);
	std::cout << getGasStops() << std::endl << std::endl;
}
