// File Name: Minivan.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Minivan.hpp"

Minivan::Minivan() : Vehicle()
{
}

Minivan::Minivan(std::string make, std::string model, double engine, double tankSize, int cylinders, int cityMPG, int highwayMPG) : Vehicle( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG )
{
}

Vehicle* Minivan::clone()
{
	Minivan* ptr = new Minivan;
	*ptr = *this;
	return ptr;
}

std::string Minivan::toString()
{
	std::string temp = "Type: " + getType();
	temp += Vehicle::toString();
	return temp;
}
