// File Name: TripLeg.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "TripLeg.hpp"

TripLeg::TripLeg()
{
	distance = 0;
	road = CITY;
}

TripLeg::TripLeg(double tempDistance, roadType tempRoad)
{
	distance = tempDistance;
	road = tempRoad;
}

double TripLeg::getDistance()
{
	return distance;
}

roadType TripLeg::getRoad()
{
	return road;
}

std::string TripLeg::printRoad()
{
	std::string x = "NULL";
	getRoad();
	if ( road == CITY ) {
		x = "CITY";
		return x;
	} else if ( road == HIGHWAY ) {
		x = "HIGHWAY";
		return x;
	} else {
		return x;
	}
}
