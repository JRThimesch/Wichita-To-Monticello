// File Name: VehicleTrip.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

#include <string>
#include <vector>

#include "Vehicle.hpp"
#include "TripParameters.hpp"
#include "VehicleRecords.hpp"
#include "TripLeg.hpp"


#ifndef SRC_VEHICLETRIP_HPP_
#define SRC_VEHICLETRIP_HPP_

class VehicleTrip {
	double time;
	int breaks;
	int breakTime;
	int totalBreaks;
	int gasDistance;
	int gasStops;
	int speedCity;
	int speedHighway;
	int naps;
	int napLength;
	int fuelTime;
	double gasDistanceRemaining;
	double legDistance;
	double napTime;
	double gasPrice;
	double gas;
	double gasNeeded;
	double gasUsed;
	double gasAdded;
	double totalDistance;
	double costGasAdded;
	double costGasUsed;
	double cityDriven;
	double highwayDriven;

	//incoming mess of functions
	public:
		VehicleTrip();
		std::string getTimeRefined();
		double getGasDistanceRemaining();
		void setGasDistanceRemaining(double);
		void startingGas(double);
		void setGasAdded(double);
		void setCityDriven(double);
		void setHighwayDriven(double);
		double getCityDriven();
		double getHighwayDriven();
		double getCostGasUsed();
		void setCostGasUsed(double);
		double getCostGasAdded();
		void setCostGasAdded(double);
		double getGasAdded();
		int getFuelTime();
		void setFuelTime(int);
		double getTime();
		void setTime(double);
		int getBreakTime();
		void setBreakTime(int);
		int getBreaks();
		void addBreak();
		void setGasDistance(int);
		int getGasDistance();
		int getGasStops();
		void addGasStop();
		void checkBreaks();
		void setSpeedCity(int);
		int getSpeedCity();
		void setSpeedHighway(int);
		int getSpeedHighway();
		int getNapLength();
		void setNapLength(int);
		double getNapTime();
		void addNaps();
		void setNapTime(double);
		int getNaps();
		void addNap();
		double getGasPrice();
		void setGasPrice(double);
		double getGas();
		void setGas(double);
		void setGasUsed(double);
		double getGasUsed();

		// ASSIGNMENT 2 FUNCTIONS
		void addTime(double);
		void addGasUsed(double);

		// ASSIGNMENT 3 STUFF
		std::string returnMake(int);
		std::string returnModel(int);
		double returnEngine(int);
		double returnTankSize(int);
		int returnCylinders(int);
		int returnCityMPG(int);
		int returnHighwayMPG(int);

		void returnArrivingFirst(int);
		void returnArrivingLast(int);
		void returnCostFuelAddedMost(int);
		void returnCostFuelAddedLeast(int);
		void returnCostFuelUsedMost(int);
		void returnCostFuelUsedLeast(int);

		~VehicleTrip(); //destructor
};

#endif /* SRC_VEHICLETRIP_HPP_ */
