// File Name: WichitaToMonticello.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Assignment Number: 4

/*
 *
 *  I know I said I was using your program for this but Eclipse decided to not compile anything, even using C++11, so I just went back to my code
 *  I did not take any code from your program and put it into mine but it definitely did help me put some of this together
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Vehicle.hpp"
#include "TripParameters.hpp"
#include "VehicleRecords.hpp"
#include "VehicleTrip.hpp"
#include "TripLeg.hpp"
using namespace std;

const int HOUR = 60;

int main() {

	TripParameters parameters("WichitaToMonticello-Input.ini");
	VehicleRecords("WichitaToMonticello-Vehicles2.txt");
	VehicleTrip vehicleTrip[VehicleRecords::vehicleListSize()]; // initializing vehicleTrip array
	vector<TripLeg> tripLeg;

	cout << VehicleRecords::getList(); // outputs list of vehicles to console using the toString function for Assignment 4

	double temp = 0; // used throughout program

	//initializing TripLeg
	tripLeg.push_back(TripLeg( 3.3, CITY ));
	tripLeg.push_back(TripLeg( 23.2, HIGHWAY ));
	tripLeg.push_back(TripLeg( 0.05, CITY ));
	tripLeg.push_back(TripLeg( 0.2, CITY ));
	tripLeg.push_back(TripLeg( 56.2, HIGHWAY ));
	tripLeg.push_back(TripLeg( 50.3, HIGHWAY ));
	tripLeg.push_back(TripLeg( 6.8, HIGHWAY ));
	tripLeg.push_back(TripLeg( 53.5, HIGHWAY ));
	tripLeg.push_back(TripLeg( 21.3, CITY ));
	tripLeg.push_back(TripLeg( 229.0, HIGHWAY ));
	tripLeg.push_back(TripLeg( 2.8, CITY ));
	tripLeg.push_back(TripLeg( 74.7, HIGHWAY ));
	tripLeg.push_back(TripLeg( 47.3, HIGHWAY ));
	tripLeg.push_back(TripLeg( 69.3, HIGHWAY ));
	tripLeg.push_back(TripLeg( 0.2, HIGHWAY ));
	tripLeg.push_back(TripLeg( 24.3, CITY ));
	tripLeg.push_back(TripLeg( 21.2, CITY ));
	tripLeg.push_back(TripLeg( 79.2, HIGHWAY ));
	tripLeg.push_back(TripLeg( 208, HIGHWAY ));
	tripLeg.push_back(TripLeg( 181.3, HIGHWAY ));
	tripLeg.push_back(TripLeg( 86.6, HIGHWAY ));
	tripLeg.push_back(TripLeg( 106.7, HIGHWAY ));
	tripLeg.push_back(TripLeg( 8.0, HIGHWAY ));
	tripLeg.push_back(TripLeg( 45.6, CITY ));
	tripLeg.push_back(TripLeg( 0.1, CITY ));
	tripLeg.push_back(TripLeg( 0.5, CITY ));
	tripLeg.push_back(TripLeg( 22.7, HIGHWAY ));
	tripLeg.push_back(TripLeg( 0.6, CITY ));
	tripLeg.push_back(TripLeg( 1.7, CITY ));

	// TRIP START
	// WELCOME TO FUNCTION CITY
	for (int i = 0; i < VehicleRecords::vehicleListSize(); i++) {

		//cout << vehicleTrip[i].returnMake(i);
		vehicleTrip[i].startingGas(VehicleRecords::temp[i]->getTankSize()); // sets the starting gas for each vehicle since they all start with a full tank
		//cout << "Starting gas for " << vehicleTrip[i].returnMake(i) << " " << vehicleTrip[i].returnModel(i) << " = " << vehicleTrip[i].getGas() << " gallons."<< endl;

		vehicleTrip[i].setGasDistanceRemaining(parameters.getGasStopDistance());

		for (unsigned int j = 0; j < tripLeg.size(); j++){
			//cout << "Starting leg #" << j + 1  << "  [" << vehicleTrip[i].returnMake(i) << " " << vehicleTrip[i].returnModel(i) << "]" << endl;
			//cout << "    Distance: " << tripLeg[j].getDistance() << "; TYPE: " << tripLeg[j].printRoad() << endl;

			if (tripLeg[j].getRoad() == CITY) {
				if (parameters.getGasStopDistance() - (VehicleRecords::temp[i]->getCityMPG() * vehicleTrip[i].getGas()) < 0 && vehicleTrip[i].getGas() * VehicleRecords::temp[i]->getCityMPG() > tripLeg[j].getDistance()) { // miles i can go
					//cout.unsetf(ios_base::fixed);

					temp = tripLeg[j].getDistance() / VehicleRecords::temp[i]->getCityMPG(); // gas used in leg
					//cout << "    (" << temp << ") gallons used;    " << (vehicleTrip[i].getGas() - temp) << " gallons remaining." << endl << endl;
					vehicleTrip[i].setGas(vehicleTrip[i].getGas() - temp); // subtracts gas used
					vehicleTrip[i].addGasUsed(temp); // used to calculate total fuel used

					temp = tripLeg[j].getDistance() / parameters.getCityMPH() * HOUR;
					vehicleTrip[i].addTime(temp); // used to calculate total time

					//NAP CHECK
					temp = vehicleTrip[i].getTime() - (vehicleTrip[i].getNaps() * (parameters.getTimeBetweenNaps() * HOUR));

					if (temp >= parameters.getTimeBetweenNaps() * HOUR) {
						vehicleTrip[i].addNaps();
						//cout << "    Taking nap #" << vehicleTrip[i].getNaps() << endl;
					}
					vehicleTrip[i].setCityDriven(tripLeg[j].getDistance() + vehicleTrip[i].getCityDriven()); // total City miles calculation
				} else {
					//cout << "    Getting gas...\t (" << vehicleTrip[i].getGas() << ") remaining." << endl;

					temp = VehicleRecords::temp[i]->getTankSize() - vehicleTrip[i].getGas();
					//cout << "    Filling up tank... (" << temp << " gallons added!)" << endl;
					vehicleTrip[i].setGasAdded(vehicleTrip[i].getGasAdded() + temp);
					vehicleTrip[i].setGas(VehicleRecords::temp[i]->getTankSize());
					vehicleTrip[i].addGasStop();
					vehicleTrip[i].checkBreaks();
					vehicleTrip[i].setGasDistanceRemaining(parameters.getGasStopDistance());

					temp = tripLeg[j].getDistance() / VehicleRecords::temp[i]->getCityMPG(); // gas used in leg
					//cout << "    (" << temp << ") gallons used;    " << (vehicleTrip[i].getGas() - temp) << " gallons remaining." << endl << endl;
					vehicleTrip[i].setGas(vehicleTrip[i].getGas() - temp); // subtracts gas used
					vehicleTrip[i].addGasUsed(temp); // used to calculate total fuel used

					temp = tripLeg[j].getDistance() / parameters.getCityMPH() * HOUR;
					vehicleTrip[i].addTime( temp); // used to calculate total time

					//NAP CHECK
					temp = vehicleTrip[i].getTime() - (vehicleTrip[i].getNaps() * (parameters.getTimeBetweenNaps() * HOUR));

					if (temp >= parameters.getTimeBetweenNaps() * HOUR) {
						vehicleTrip[i].addNaps();
						//cout << "    Taking nap #" << vehicleTrip[i].getNaps() << endl;
					}
					vehicleTrip[i].setCityDriven(tripLeg[j].getDistance() + vehicleTrip[i].getCityDriven()); // total City miles calculation
				}
			}

			if (tripLeg[j].getRoad() == HIGHWAY) {
				if (parameters.getGasStopDistance() - (VehicleRecords::temp[i]->getHighwayMPG() * vehicleTrip[i].getGas()) < 0 && vehicleTrip[i].getGas() * VehicleRecords::temp[i]->getHighwayMPG() > tripLeg[j].getDistance()) { // miles i can go
					//cout.unsetf(ios_base::fixed);

					temp = tripLeg[j].getDistance() / VehicleRecords::temp[i]->getHighwayMPG(); // gas used in leg
					//cout << "    (" << temp << ") gallons used;    " << (vehicleTrip[i].getGas() - temp) << " gallons remaining." << endl << endl;
					vehicleTrip[i].setGas(vehicleTrip[i].getGas() - temp); // subtracts gas used
					vehicleTrip[i].addGasUsed(temp); // used to calculate total fuel used

					temp = tripLeg[j].getDistance() / parameters.getHighwayMPH() * HOUR;
					vehicleTrip[i].addTime( temp); // used to calculate total time

					//NAP CHECK
					temp = vehicleTrip[i].getTime() - (vehicleTrip[i].getNaps() * (parameters.getTimeBetweenNaps() * HOUR));

					if (temp >= parameters.getTimeBetweenNaps() * HOUR) {
						vehicleTrip[i].addNaps();
						//cout << "    Taking nap #" << vehicleTrip[i].getNaps() << endl;
					}
					vehicleTrip[i].setHighwayDriven(tripLeg[j].getDistance() + vehicleTrip[i].getHighwayDriven()); // total highway miles calculation
				} else {
					//cout << "    Getting gas...\t (" << vehicleTrip[i].getGas() << ") remaining." << endl;

					temp = VehicleRecords::temp[i]->getTankSize() - vehicleTrip[i].getGas();
					//cout << "    Filling up tank... (" << temp << " gallons added!)" << endl;
					vehicleTrip[i].setGasAdded(vehicleTrip[i].getGasAdded() + temp);
					vehicleTrip[i].setGas(VehicleRecords::temp[i]->getTankSize());
					vehicleTrip[i].addGasStop();
					vehicleTrip[i].checkBreaks();
					vehicleTrip[i].setGasDistanceRemaining(parameters.getGasStopDistance());

					temp = tripLeg[j].getDistance() / VehicleRecords::temp[i]->getHighwayMPG(); // gas used in leg
					//cout << "    (" << temp << ") gallons used;    " << (vehicleTrip[i].getGas() - temp) << " gallons remaining." << endl << endl;
					vehicleTrip[i].setGas(vehicleTrip[i].getGas() - temp); // subtracts gas used
					vehicleTrip[i].addGasUsed(temp); // used to calculate total fuel used

					temp = tripLeg[j].getDistance() / parameters.getHighwayMPH() * HOUR;
					vehicleTrip[i].addTime( temp); // used to calculate total time

					//NAP CHECK
					temp = vehicleTrip[i].getTime() - (vehicleTrip[i].getNaps() * (parameters.getTimeBetweenNaps() * HOUR));

					if (temp >= parameters.getTimeBetweenNaps() * HOUR) {
						vehicleTrip[i].addNaps();
						//cout << "    Taking nap #" << vehicleTrip[i].getNaps() << endl;
					}
					vehicleTrip[i].setHighwayDriven(tripLeg[j].getDistance() + vehicleTrip[i].getHighwayDriven()); // total highway miles calculation
				}
			}
		}

		// ENDING SECTION FOR EACH VEHICLE DISPLAYING STATS

		//cout << "TOTAL DRIVING TIME: " << vehicleTrip[i].getTime() << endl;

		// NAP ADDITION
		//cout << "  Adding " << parameters.getNapLength() << " minutes for each nap * (" << vehicleTrip[i].getNaps() << ")" << endl;
		for (int m = 0; m < vehicleTrip[i].getNaps(); m++) { // adding time for naps after so that way it doesn't interfere with other calculations involving driving time
			vehicleTrip[i].addTime(parameters.getNapLength());
		}

		// BREAK ADDITION
		//cout << "  Adding " << parameters.getBreakTime() << " minutes for each break * (" << vehicleTrip[i].getBreaks() << ")" << endl;
		for (int n = 0; n < vehicleTrip[i].getBreaks(); n++) { // adding time for breaks after so that way it doesn't interfere with other calculations involving driving time
			vehicleTrip[i].addTime(parameters.getBreakTime());
		}

		// REFUEL ADDITION
		//cout << "  Adding " << parameters.getRefuelTime() << " minutes for each refuel * (" << vehicleTrip[i].getGasStops() << ")" << endl;
		for (int o = 0; o < vehicleTrip[i].getGasStops(); o++) { // adding time for refueling after so that way it doesn't interfere with other calculations involving driving time
			vehicleTrip[i].addTime(VehicleRecords::temp[i]->getRefuelTime());
		}

		//cout << "TOTAL TRIP LENGTH: " << vehicleTrip[i].getTime() << endl;
		vehicleTrip[i].setCostGasAdded(vehicleTrip[i].getGasAdded() * parameters.getFuelPrice()); // calculating total fuel added cost
		//cout << "TOTAL FUEL ADDED COST: $" << vehicleTrip[i].getCostGasAdded() << endl;
		vehicleTrip[i].setCostGasUsed(vehicleTrip[i].getGasUsed() * parameters.getFuelPrice()); // calculating total fuel used cost
		//cout << "TOTAL FUEL USED COST: $" << vehicleTrip[i].getCostGasUsed() << endl;
		//cout << "TOTAL NAPS: " << vehicleTrip[i].getNaps() << endl;
		//cout << "TOTAL BREAKS: " << vehicleTrip[i].getBreaks() << endl;
		//cout << "TOTAL REFUELS: " << vehicleTrip[i].getGasStops() << endl << endl;
	}

	//cout << endl << endl << endl;
	temp = vehicleTrip[0].getCityDriven() + vehicleTrip[0].getHighwayDriven();
	cout << setprecision(2) << fixed << "Total miles driven: " << temp << " [city: " << vehicleTrip[0].getCityDriven() << "; highway: " << vehicleTrip[0].getHighwayDriven() << "]" << endl << endl;

	ofstream output("WichitaToMonticello-Results2.txt");
	output.exceptions (ofstream::failbit | ofstream::badbit);

	try {
	output << "Type|Make|Model|EngineSize|EngineCylinders|TankSize|MpgCity|MpgHighway|Time(minutes)|Time(d.hh:mm)|CostFuelAdded|CostFuelUsed|FuelAdded|FuelUsed|FuelRemaining|FuelStops" << endl;


	// SORTING BY FUEL REMAINING FOR ASSIGNMENT 4
	vector<double> sortList;
	for (int k = 0; k < VehicleRecords::vehicleListSize(); k++) {
		sortList.push_back(vehicleTrip[k].getGas());
	}

	sort(sortList.begin(), sortList.end()); // sorting the list for comparison purposes

	for (int m = 0; m < VehicleRecords::vehicleListSize(); m++) {
		for (int n = 0; n < VehicleRecords::vehicleListSize(); n++)
			if (sortList[m] == vehicleTrip[n].getGas()) {
				output << VehicleRecords::temp[n]->getType() << "|"   << VehicleRecords::temp[n]->getMake() << "|" << VehicleRecords::temp[n]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[n]->getEngine() << "|" << VehicleRecords::temp[n]->getCylinders() << "|" << VehicleRecords::temp[n]->getTankSize() << "|" << VehicleRecords::temp[n]->getCityMPG() << "|" << VehicleRecords::temp[n]->getHighwayMPG();
				output << "|" << setprecision(0) << fixed << vehicleTrip[n].getTime() << "|" << vehicleTrip[n].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[n].getCostGasAdded() << "|" << vehicleTrip[n].getCostGasUsed();
				output << "|" << setprecision(4) << fixed << vehicleTrip[n].getGasAdded() << "|" << vehicleTrip[n].getGasUsed() << "|" << vehicleTrip[n].getGas() << "|" << vehicleTrip[n].getGasStops() << endl;
			}
		}

	output << endl; // extra blank line

	// VEHICLE ARRIVING FIRST
	int z = 9999999; // used in loops to determine least/most of a category
	for (int p = 0; p < VehicleRecords::vehicleListSize(); p++) {
		if (vehicleTrip[p].getTime() < z) {
			z = vehicleTrip[p].getTime();
			temp = p;
		}
	}
	int a;
	a = temp;
	vehicleTrip[a].returnArrivingFirst(a);

	// writing it to output
	output << VehicleRecords::temp[a]->getType() << "|" << VehicleRecords::temp[a]->getMake() << "|" << VehicleRecords::temp[a]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[a]->getEngine() << "|" << VehicleRecords::temp[a]->getCylinders() << "|" << VehicleRecords::temp[a]->getTankSize() << "|" << VehicleRecords::temp[a]->getCityMPG() << "|" << VehicleRecords::temp[a]->getHighwayMPG();
	output << "|" << setprecision(0) << fixed << vehicleTrip[a].getTime() << "|" << vehicleTrip[a].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[a].getCostGasAdded() << "|" << vehicleTrip[a].getCostGasUsed();
	output << "|" << setprecision(4) << fixed << vehicleTrip[a].getGasAdded() << "|" << vehicleTrip[a].getGasUsed() << "|" << vehicleTrip[a].getGas() << "|" << vehicleTrip[a].getGasStops();
	output << "    #Vehicle arriving first" << endl;

	// VEHICLE ARRIVING LAST
	z = 0; // used in loops to determine least/most of a category
	for (int r = 0; r < VehicleRecords::vehicleListSize(); r++) {
		if (vehicleTrip[r].getTime() > z) {
			z = vehicleTrip[r].getTime();
			temp = r;
		}
	}
	a = temp;
	vehicleTrip[a].returnArrivingLast(a);

	// writing it to output
	output << VehicleRecords::temp[a]->getType() << "|" << VehicleRecords::temp[a]->getMake() << "|" << VehicleRecords::temp[a]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[a]->getEngine() << "|" << VehicleRecords::temp[a]->getCylinders() << "|" << VehicleRecords::temp[a]->getTankSize() << "|" << VehicleRecords::temp[a]->getCityMPG() << "|" << VehicleRecords::temp[a]->getHighwayMPG();
	output << "|" << setprecision(0) << fixed << vehicleTrip[a].getTime() << "|" << vehicleTrip[a].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[a].getCostGasAdded() << "|" << vehicleTrip[a].getCostGasUsed();
	output << "|" << setprecision(4) << fixed << vehicleTrip[a].getGasAdded() << "|" << vehicleTrip[a].getGasUsed() << "|" << vehicleTrip[a].getGas() << "|" << vehicleTrip[a].getGasStops();
	output << "    #Vehicle arriving last" << endl;

	// VEHICLE COST LEAST BASED ON FUEL ADDED
	z = 9999999; // used in loops to determine least/most of a category
	for (int s = 0; s < VehicleRecords::vehicleListSize(); s++) {
		if (vehicleTrip[s].getCostGasAdded() < z) {
			z = vehicleTrip[s].getCostGasAdded();
			temp = s;
		}
	}
	a = temp;
	vehicleTrip[a].returnCostFuelAddedLeast(a);

	// writing it to output
	output << VehicleRecords::temp[a]->getType() << "|" << VehicleRecords::temp[a]->getMake() << "|" << VehicleRecords::temp[a]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[a]->getEngine() << "|" << VehicleRecords::temp[a]->getCylinders() << "|" << VehicleRecords::temp[a]->getTankSize() << "|" << VehicleRecords::temp[a]->getCityMPG() << "|" << VehicleRecords::temp[a]->getHighwayMPG();
	output << "|" << setprecision(0) << fixed << vehicleTrip[a].getTime() << "|" << vehicleTrip[a].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[a].getCostGasAdded() << "|" << vehicleTrip[a].getCostGasUsed();
	output << "|" << setprecision(4) << fixed << vehicleTrip[a].getGasAdded() << "|" << vehicleTrip[a].getGasUsed() << "|" << vehicleTrip[a].getGas() << "|" << vehicleTrip[a].getGasStops();
	output << "    #Vehicle costing least (fuel added)" << endl;

	// VEHICLE COST MOST BASED ON FUEL ADDED
	z = 0; // used in loops to determine least/most of a category
	for (int t = 0; t < VehicleRecords::vehicleListSize(); t++) {
		if (vehicleTrip[t].getCostGasAdded() > z) {
			z = vehicleTrip[t].getCostGasAdded();
			temp = t;
		}
	}
	a = temp;
	vehicleTrip[a].returnCostFuelAddedMost(a);

	// writing it to output
	output << VehicleRecords::temp[a]->getType() << "|" << VehicleRecords::temp[a]->getMake() << "|" << VehicleRecords::temp[a]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[a]->getEngine() << "|" << VehicleRecords::temp[a]->getCylinders() << "|" << VehicleRecords::temp[a]->getTankSize() << "|" << VehicleRecords::temp[a]->getCityMPG() << "|" << VehicleRecords::temp[a]->getHighwayMPG();
	output << "|" << setprecision(0) << fixed << vehicleTrip[a].getTime() << "|" << vehicleTrip[a].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[a].getCostGasAdded() << "|" << vehicleTrip[a].getCostGasUsed();
	output << "|" << setprecision(4) << fixed << vehicleTrip[a].getGasAdded() << "|" << vehicleTrip[a].getGasUsed() << "|" << vehicleTrip[a].getGas() << "|" << vehicleTrip[a].getGasStops();
	output << "    #Vehicle costing most (fuel added)" << endl;

	// VEHICLE COST LEAST BASED ON FUEL USED
	z = 9999999; // used in loops to determine least/most of a category
	for (int u = 0; u < VehicleRecords::vehicleListSize(); u++) {
		if (vehicleTrip[u].getCostGasUsed() < z) {
			z = vehicleTrip[u].getCostGasUsed();
			temp = u;
		}
	}
	a = temp;
	vehicleTrip[a].returnCostFuelUsedLeast(a);

	// writing it to output
	output << VehicleRecords::temp[a]->getType() << "|" << VehicleRecords::temp[a]->getMake() << "|" << VehicleRecords::temp[a]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[a]->getEngine() << "|" << VehicleRecords::temp[a]->getCylinders() << "|" << VehicleRecords::temp[a]->getTankSize() << "|" << VehicleRecords::temp[a]->getCityMPG() << "|" << VehicleRecords::temp[a]->getHighwayMPG();
	output << "|" << setprecision(0) << fixed << vehicleTrip[a].getTime() << "|" << vehicleTrip[a].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[a].getCostGasAdded() << "|" << vehicleTrip[a].getCostGasUsed();
	output << "|" << setprecision(4) << fixed << vehicleTrip[a].getGasAdded() << "|" << vehicleTrip[a].getGasUsed() << "|" << vehicleTrip[a].getGas() << "|" << vehicleTrip[a].getGasStops();
	output << "    #Vehicle costing least (fuel used)" << endl;

	// VEHICLE COST MOST BASED ON FUEL USED
	z = 0; // used in loops to determine least/most of a category
	for (int v = 0; v < VehicleRecords::vehicleListSize(); v++) {
		if (vehicleTrip[v].getCostGasUsed() > z) {
			z = vehicleTrip[v].getCostGasUsed();
			temp = v;
		}
	}
	a = temp;
	vehicleTrip[a].returnCostFuelUsedMost(a);

	// writing it to output
	output << VehicleRecords::temp[a]->getType() << "|" << VehicleRecords::temp[a]->getMake() << "|" << VehicleRecords::temp[a]->getModel() << setprecision(1) << fixed << "|" << VehicleRecords::temp[a]->getEngine() << "|" << VehicleRecords::temp[a]->getCylinders() << "|" << VehicleRecords::temp[a]->getTankSize() << "|" << VehicleRecords::temp[a]->getCityMPG() << "|" << VehicleRecords::temp[a]->getHighwayMPG();
	output << "|" << setprecision(0) << fixed << vehicleTrip[a].getTime() << "|" << vehicleTrip[a].getTimeRefined() << "|" << setprecision(2) << fixed << vehicleTrip[a].getCostGasAdded() << "|" << vehicleTrip[a].getCostGasUsed();
	output << "|" << setprecision(4) << fixed << vehicleTrip[a].getGasAdded() << "|" << vehicleTrip[a].getGasUsed() << "|" << vehicleTrip[a].getGas() << "|" << vehicleTrip[a].getGasStops();
	output << "    #Vehicle costing most (fuel used)" << endl;

	output.close();
	} catch (std::exception const& e) {
		std::cerr << "EXCEPTION: " << e.what(); // exception for file i/o
		output.close();
		exit(1);
	}
}
