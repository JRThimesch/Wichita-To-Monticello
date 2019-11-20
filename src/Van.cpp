// File Name: Van.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Van.hpp"

Van::Van() : Vehicle()
{
}

Van::Van(std::string make, std::string model, double engine, double tankSize, int cylinders, int cityMPG, int highwayMPG) : Vehicle( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG )
{
}

Vehicle* Van::clone()
{
	Van* ptr = new Van;
	*ptr = *this;
	return ptr;
}

std::string Van::toString()
{
	std::string temp = "Type: " + getType();
	temp += Vehicle::toString();
	return temp;
}
