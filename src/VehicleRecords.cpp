// File Name: VehicleRecords.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "VehicleRecords.hpp"
#include "VehicleTrip.hpp"
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Van.hpp"
#include "Minivan.hpp"
#include "Truck.hpp"
#include "Suv.hpp"


std::string VehicleRecords::make;
std::string VehicleRecords::model;
double VehicleRecords::engine;
double VehicleRecords::tankSize;
int VehicleRecords::cylinders;
int VehicleRecords::cityMPG;
int VehicleRecords::highwayMPG;
std::string VehicleRecords::type;
int VehicleRecords::size;
std::vector<Vehicle*> VehicleRecords::temp;

VehicleRecords::VehicleRecords()
{
	make = "Make";
	model = "Model";
	engine = 0;
	tankSize = 0;
	cylinders = 0;
	cityMPG = 0;
	highwayMPG = 0;
}

std::string VehicleRecords::trimWhiteSpace(std::string& str) //gets rid of trailing and leading whitespace but keeps spaces in between words
{
	size_t i;
	i = str.find_first_not_of(" \t\n\r");
	str.erase(0, i);

	i = str.find_last_not_of(" \t\n\r");
	if (std::string::npos != i) {
		str.erase(i+1);
	}

	return str;
}

VehicleRecords::VehicleRecords(std::string inputfile)
{
    std::fstream file(inputfile.c_str());
    int i = 0; // main loop counter
    int g = 0; // loop counter (negative for assignment 4 with addition of type)


    std::string str;
    std::string line;
    std::stringstream ss; // used to input values as ints/doubles
    std::stringstream inputstreamEngine(str); // the only way i could figure out how to reliably put strings into ints was to create several inputstreams, instead of using just one
    std::stringstream inputstreamCylinders(str);
    std::stringstream inputstreamTankSize(str);
    std::stringstream inputstreamCityMPG(str);
    std::stringstream inputstreamHighwayMPG(str);

    try {
    while (std::getline(file, line)) {
    	VehicleRecords::trimWhiteSpace(line);
    	line = line.substr(0, line.find("#", 0));
    	ss.clear();
    	ss.str("");
        ss << line;

        while (getline(ss, str, '|'))
        {

        	VehicleRecords::trimWhiteSpace(str);
        	str = str.substr(0, str.find("#", 0));
        	//std::cout << str << std::endl << "\t Loop: " << g << std::endl;

        	if (g == 0) {
        		type = str;
        	}

        	// MAKE BLOCK
        	if (g == 1) {
        		make = str;
        	}

        	// MODEL BLOCK
        	if (g == 2) {
        		model = str;
        	}

        	// ENGINE BLOCK
        	if (g == 3) {
        		if (std::count(str.begin(),str.end(), '.') > 1) {
        			throw std::invalid_argument("EXCEPTION: More than one decimal used in double value! \n"  + make + " " + model + " = " + str); // Exception for multiple decimals
        		}
        		inputstreamEngine << str;
        		inputstreamEngine >> engine;
           		if ((inputstreamEngine >> engine).fail() && !(inputstreamEngine >> std::ws).eof()) {
           			throw std::invalid_argument("EXCEPTION: Number contains illegal characters! \n"  + make + " " + model + " = " + str); // Exception for invalid characters
           		}
        	}

        	// CYLINDER BLOCK
        	if (g == 4) {
        		if (str.find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! \n"  + make + " " + model + " = " + str); // Exception for decimals in ints
        		}
        		inputstreamCylinders << str;
        		inputstreamCylinders >> cylinders;
           		if ((inputstreamCylinders >> cylinders).fail() && !(inputstreamCylinders >> std::ws).eof()) {
           			throw std::invalid_argument("EXCEPTION: Number contains illegal characters! \n"  + make + " " + model + " = " + str); // Exception for invalid characters
           		}
        	}

        	// TANKSIZE BLOCK
        	if (g == 5) {
        		if (std::count(str.begin(),str.end(), '.') > 1) {
        			throw std::invalid_argument("EXCEPTION: More than one decimal used in double value! \n"  + make + " " + model + " = " + str); // Exception for multiple decimals
        		}
        		inputstreamTankSize << str;
        		inputstreamTankSize >> tankSize;
           		if ((inputstreamTankSize >> tankSize).fail() && !(inputstreamTankSize >> std::ws).eof()) {
           			throw std::invalid_argument("EXCEPTION: Number contains illegal characters! \n"  + make + " " + model + " = " + str); // Exception for invalid characters
           		}
        	}

        	// CITYMPG BLOCK
        	if (g == 6) {
        		if (str.find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! \n"  + make + " " + model + " = " + str); // Exception for decimals in ints
        		}
        		inputstreamCityMPG << str;
        		inputstreamCityMPG >> cityMPG;
           		if ((inputstreamCityMPG >> cityMPG).fail() && !(inputstreamCityMPG >> std::ws).eof()) {
           			throw std::invalid_argument("EXCEPTION: Number contains illegal characters! \n"  + make + " " + model + " = " + str); // Exception for invalid characters
           		}
        	}

        	// HIGHWAYMPG BLOCK
        	if (g == 7) {
        		if (str.find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! \n"  + make + " " + model + " = " + str); // Exception for decimals in ints
        		}
        		inputstreamHighwayMPG << str;
        		inputstreamHighwayMPG >> highwayMPG;
           		if ((inputstreamHighwayMPG >> highwayMPG).fail() && !(inputstreamHighwayMPG >> std::ws).eof()) {
           			throw std::invalid_argument("EXCEPTION: Number contains illegal characters! \n"  + make + " " + model + " = " + str); // Exception for invalid characters
           		}
        	}
        	g++;
        }
        g = 0; // reset loop counter

        // stops any empty strings
        if (line == "") {
        	continue;
        }

		//std::cout << "make: " << make << std::endl;
		//std::cout << "model: " << model << std::endl;
		//std::cout << "engine: " << engine << std::endl;
		//std::cout << "cylinders: " << cylinders << std::endl;
        //std::cout << "tankSize: " << tankSize << std::endl;
		//std::cout << "cityMPG: " << cityMPG << std::endl;
        //std::cout << "highwayMPG: " << highwayMPG << std::endl << std::endl;

        //std::cout << "	END OF LOOP" << std::endl;

        if (type == "Car") {
            temp.push_back(new Car( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG ) );
        } else if (type == "Van") {
        	temp.push_back(new Van( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG ) );
        } else if (type == "Minivan") {
        	temp.push_back(new Minivan( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG ) );
        } else if (type == "Suv") {
        	temp.push_back(new Suv( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG ) );
        } else if (type == "Truck") {
        	temp.push_back(new Truck( make, model, engine, tankSize, cylinders, cityMPG, highwayMPG ) );
        }

        // this block makes everything work, don't know completely why but it does
        inputstreamEngine.clear();
        inputstreamCylinders.clear();
        inputstreamTankSize.clear();
        inputstreamCityMPG.clear();
        inputstreamHighwayMPG.clear();
        inputstreamEngine.str("");
        inputstreamCylinders.str("");
        inputstreamTankSize.str("");
        inputstreamCityMPG.str("");
        inputstreamHighwayMPG.str("");

    	i++; // increment main loop counter
    }
    file.close();
    } catch (const std::invalid_argument& e) {
    	std::cerr << e.what()  << std::endl;
    	file.close();
    	exit(1);
    }
}

// for returning a list of vehicles
std::string VehicleRecords::getList()
{
	std::ostringstream toString;
	for (int i = 0; i < VehicleRecords::vehicleListSize(); i++) {
		toString << temp[i]->toString() << std::endl;
	}

	return toString.str();
}

int VehicleRecords::vehicleListSize()
{
	return temp.size();
}

VehicleRecords::~VehicleRecords()
{
}
