// File Name: Suv.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Suv.hpp"

Suv::Suv() : Vehicle()
{
}

Suv::Suv(std::string make, std::string model, double engine, double tankSize, int cylinders, int cityMPG, int highwayMPG) : Vehicle( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG )
{
}

Vehicle* Suv::clone()
{
	Suv* ptr = new Suv;
	*ptr = *this;
	return ptr;
}

std::string Suv::toString()
{
	std::string temp = "Type: " + getType();
	temp += Vehicle::toString();
	return temp;
}
