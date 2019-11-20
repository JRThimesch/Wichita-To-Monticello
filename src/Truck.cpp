// File Name: Truck.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Truck.hpp"

Truck::Truck() : Vehicle()
{
}

Truck::Truck(std::string make, std::string model, double engine, double tankSize, int cylinders, int cityMPG, int highwayMPG) : Vehicle( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG )
{
}

Vehicle* Truck::clone()
{
	Truck* ptr = new Truck;
	*ptr = *this;
	return ptr;
}

std::string Truck::toString()
{
	std::string temp = "Type: " + getType();
	temp += Vehicle::toString();
	return temp;
}
