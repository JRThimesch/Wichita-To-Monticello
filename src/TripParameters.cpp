// File Name: TripParameters.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include "TripParameters.hpp"

TripParameters::TripParameters()
{
	cityMPH = 0;
	highwayMPH = 0;
	fuelPrice = 0;
	gasStopDistance = 0;
	timeBetweenNaps = 0;
//	refuelTime = 0;
	breakTime = 0;
	napLength = 0;
}

TripParameters::TripParameters(std::string inputfile)
{
	try {
    std::ifstream file(inputfile.c_str());

    if (!file.is_open()) {
    	throw("Error when opening " + inputfile); // throw error if file is open already
    }

    std::string str;
    std::vector<std::string>key;
    std::vector<std::string>value;

    while (std::getline(file, str)) {

   		if (file.bad()) {
   			throw("Error when reading from " + inputfile); // making sure file is read correctly
   		}

    	// completely removes any kind of white space & comments
    	str = str.substr(0, str.find("#", 0));
   		str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());

   		// I was having trouble with empty lines becoming strings but this fixes that
   		if (str == "") {
   			continue;
   		}

   		// separating the key from the value
    	key.push_back(str.substr(0, str.find("=")));
    	if(str.find("=") != std::string::npos) {
    		value.push_back(str.substr(str.find("=") + 1));
    	}
    }

    std::vector<std::string>temp;

    for (unsigned int i = 0; i < key.size(); i++) {

    	temp.push_back(key[i]); // holds a pre-uppercase copy of the key for throwing
    	transform(key[i].begin(), key[i].end(), key[i].begin(), ::toupper); // changes all keys to uppercase so it is no longer case sensitive
    	std::stringstream ss(value[i]); // used to input values as ints/doubles

    	// INVALID KEY BLOCK
    	try {
    		if (key[i] != "MPHCITY" && key[i] != "MPHHIGHWAY" && key[i] != "FUELPRICE" && key[i] != "DISTANCEBETWEENGASSTATIONS" && key[i] != "TIMEBETWEENNAPS" && key[i] != "REFUELTIME" && key[i] != "RESTROOMTIME" && key[i] != "NAPTIME" ) {
    			throw std::invalid_argument("EXCEPTION: Invalid key type! "); // Exception for invalid keys;
    		}
    	} catch(const std::invalid_argument& e) {
    		std::cerr << e.what() << std::endl << "Invalid key: " << temp[i] << std::endl << getValidKeys() << std::endl;
    		exit(1);
    	}

    	// MPHCITY BLOCK
        if (key[i] == "MPHCITY") {

        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> cityMPH;

        	try {
        		if ((ss >> cityMPH).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Value contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	std::cout << "Average speed in the city set to " << cityMPH << " MPH." << std::endl;
        }

        // MPHHIGHWAY BLOCK
        if (key[i] == "MPHHIGHWAY") {
        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> highwayMPH;

        	try {
        		if ((ss >> highwayMPH).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Average speed on the highway set to " << highwayMPH << " MPH." << std::endl;
        }

        // FUELPRICE BLOCK
        if (key[i] == "FUELPRICE") {
        	try {
        		if (std::count(value[i].begin(),value[i].end(), '.') > 1) {
        			throw std::invalid_argument("EXCEPTION: More than one decimal used in double value! "); // Exception for multiple decimals
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> fuelPrice;

        	try {
        		if ((ss >> fuelPrice).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Average fuel price per gallon set to $" << fuelPrice << std::endl;
        }

        // DISTANCEBETWEENGASSTATIONS BLOCK
        if (key[i] == "DISTANCEBETWEENGASSTATIONS") {
        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> gasStopDistance;

        	try {
        		if ((ss >> gasStopDistance).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Distance between gas stations set to " << gasStopDistance << " miles." << std::endl;
        }

        // TIMEBETWEENNAPS BLOCK
        if (key[i] == "TIMEBETWEENNAPS") {
        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> timeBetweenNaps;

        	try {
        		if ((ss >> timeBetweenNaps).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Time between taking naps set to " << timeBetweenNaps << " hours." << std::endl;
        }

        /*
        // REFUELTIME BLOCK
        if (key[i] == "REFUELTIME") {
        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> refuelTime;

        	try {
        		if ((ss >> refuelTime).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Time required to refuel set to " << refuelTime << " minutes." << std::endl;
        }
        */

        // RESTROOMTIME BLOCK
        if (key[i] == "RESTROOMTIME") {
        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> breakTime;

        	try {
        		if ((ss >> breakTime).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Time required to use the restroom set to " << breakTime << " minutes." << std::endl;
        }

        // NAPTIME BLOCK
        if (key[i] == "NAPTIME") {
        	try {
        		if (value[i].find('.') == 1) {
        			throw std::invalid_argument("EXCEPTION: Decimal used in an int value! "); // Exception for decimals in ints
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}

        	ss >> napLength;

        	try {
        		if ((ss >> napLength).fail() && !(ss >> std::ws).eof()) {
        			throw std::invalid_argument("EXCEPTION: Number contains illegal characters!" ); // Exception for invalid characters
        		}
        	} catch (const std::invalid_argument& e) {
        		std::cerr << e.what() << std::endl  << temp[i] << " = " << value[i] << std::endl;
        		exit(1);
        	}
        	std::cout << "Time required to take a nap set to " << napLength << " minutes." << std::endl << std::endl;
        }
    }
    file.close();
	} catch (std::exception const& e) {
		std::cerr << "EXCEPTION: " << e.what(); // exception for file i/o
	}
}

int TripParameters::getCityMPH()
{
	return cityMPH;
}

int TripParameters::getHighwayMPH()
{
	return highwayMPH;
}

double TripParameters::getFuelPrice()
{
	return fuelPrice;
}

int TripParameters::getGasStopDistance()
{
	return gasStopDistance;
}

int TripParameters::getTimeBetweenNaps()
{
	return timeBetweenNaps;
}

/*
int TripParameters::getRefuelTime()
{
	return refuelTime;
}
*/

int TripParameters::getBreakTime()
{
	return breakTime;
}

int TripParameters::getNapLength()
{
	return napLength;
}

std::string TripParameters::getValidKeys()
{
	return "  Valid Keys: MphCity, MphHighway, FuelPrice, DistanceBetweenGasStations, TimeBetweenNaps, RestroomTime, NapTime";
}

