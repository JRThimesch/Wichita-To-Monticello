// File Name: Car.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "Car.hpp"

Car::Car() : Vehicle()
{
}

Car::Car(std::string make, std::string model, double engine, double tankSize, int cylinders, int cityMPG, int highwayMPG) : Vehicle( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG )
{
}

Vehicle* Car::clone()
{
	Car* ptr = new Car;
	*ptr = *this;
	return ptr;
}

std::string Car::toString()
{
	std::string temp = "Type: " + getType();
	temp += Vehicle::toString();
	return temp;
}
