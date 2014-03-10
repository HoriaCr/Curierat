#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_set>
#include "Airplane.h"
#include "Truck.h"
#include "Van.h"
#include "Automobile.h"
#include "Scooter.h"
#include "Order.h"
#include "WeightedGraph.h"


using namespace std;

class DeliveryFirm
{
	private:

		vector< Vehicle<unsigned int>*>  vehicleFleet;
		queue< Order<unsigned int> > *cityOrders;
		unordered_set<unsigned int> unassignedCities;
		WeightedGraph<int> *graph;
		vector< vector<int> > distances;

		double balance;
		double driverSlarary;
		double wokerSalary;
		double managerSalary;

		int truckNumber;
		int airplaneNumber;
		int scooterNumber;
		int vanNumber;
		int automobileNumber;
		int vehicleNumber;

		int ordersInQueue;

		int drivers;
		int workers;
		int managers;

		int succeededOrders;
		int failedOrders;
		int employeesNumber;

		int strategyType;
	


	public:
	
	DeliveryFirm(
		WeightedGraph<int>*graph_,
		double balance_,
		double driverSlarary_,
		double wokerSalary_,
		double managerSalary_,
		int truckNumber_,
		int airplaneNumber_,
		int scooterNumber_,
		int vanNumber_,
		int automobileNumber_,
		int drivers_,
		int workers_,
		int managers_);


		~DeliveryFirm();

		void update(const int& currentTime, double seconds);

		void computeDistances();

		double getCosts();

		double getIncome();

		void receiveOrder(const Order<unsigned int>& order);

		string getLog();
};


DeliveryFirm::DeliveryFirm(WeightedGraph<int> *graph_,
	double balance_,
	double driverSlarary_,
	double wokerSalary_,
	double managerSalary_,
	int truckNumber_,
	int airplaneNumber_,
	int scooterNumber_,
	int vanNumber_,
	int automobileNumber_,
	int drivers_,
	int workers_,
	int managers_
	) {
	graph  = graph_;
	balance = balance_;
	driverSlarary = driverSlarary_;
	wokerSalary = wokerSalary_;
	managerSalary = managerSalary_;
	truckNumber = truckNumber_;
	airplaneNumber = airplaneNumber_;
	scooterNumber = scooterNumber_;
	vanNumber = vanNumber_;
	automobileNumber = automobileNumber_;
	drivers = drivers_;
	workers = workers_;
	managers = managers_;

	ordersInQueue = 0;
	succeededOrders = 0;
	failedOrders = 0;

	vehicleNumber = airplaneNumber + truckNumber + vanNumber + automobileNumber + scooterNumber;
	employeesNumber = drivers + workers + managers;
	vehicleFleet.resize(vehicleNumber);
	cityOrders = new queue< Order<unsigned int> >[graph->getVertexNumber()];

	for (int i = 0; i < airplaneNumber; i++) {
		vehicleFleet[i] = new Airplane<unsigned int>();
	}

	for (int i = 0; i < truckNumber; i++) {
		vehicleFleet[i + airplaneNumber] = new Truck<unsigned int>();
	}

	for (int i = 0; i < vanNumber; i++ ) {
		vehicleFleet[i + airplaneNumber + truckNumber] = new Van<unsigned int>();
	}

	for (int i = 0; i < automobileNumber; i++) {
		vehicleFleet[i + airplaneNumber + truckNumber + vanNumber] = new Automobile<unsigned int>();
	}

	for (int i = 0; i < scooterNumber; i++) {
		vehicleFleet[i + airplaneNumber + truckNumber + vanNumber + automobileNumber] = new Scooter<unsigned int>();
	}
	
}

DeliveryFirm::~DeliveryFirm() {
	delete graph;
	delete[] cityOrders;
}


void DeliveryFirm::receiveOrder(const Order<unsigned int>& order) {
	cityOrders[order.getSource()].push(order);
	unassignedCities.insert(order.getSource());
}

void DeliveryFirm::computeDistances() {
	int V = graph->getVertexNumber();
	distances.resize(V);
	for (int i = 0; i < V; i++) {
		distances[i] = graph->djikstra(i);
	}
}

void DeliveryFirm::update(const int& currentTime,double seconds) {

	for (int i = 0; i < vehicleNumber; i++) {
		if (vehicleFleet[i]->isParked()) {
			unsigned int currentDestination = vehicleFleet[i]->getDestination();
			if (vehicleFleet[i]->getOrderCount() > 0) {
				unsigned int nextDestination = vehicleFleet[i]->getNextDestination();
				vehicleFleet[i]->updateDestination(nextDestination, 1.0 * distances[currentDestination][nextDestination]);

			} else
			if (unassignedCities.empty() == false) {
				 unsigned int nextDestination = *unassignedCities.begin();
				 unassignedCities.erase(unassignedCities.begin());
				 vehicleFleet[i]->updateDestination(nextDestination, 1.0 * distances[currentDestination][nextDestination]);
			} else
			if (cityOrders[currentDestination].empty() == false) {
				while (cityOrders[currentDestination].empty() == false) {
					Order<unsigned int> order = cityOrders[currentDestination].front();
					if (vehicleFleet[i]->receiveOrder(order) == false) {
						break;
					} else {
						cityOrders[currentDestination].pop();
					}
				}
			}
		} 

		if (vehicleFleet[i]->update(seconds)) {
			pair < pair<int,int>,double> ret = vehicleFleet[i]->deliverOrders(currentTime);
			succeededOrders += ret.first.first;
			failedOrders += ret.first.second;
			balance += ret.second;
		}
		
	}
}

string DeliveryFirm::getLog() {
	ostringstream out;
	out << "Balance : " << fixed << balance << "\n";
	out << "Succeded Orders : " << succeededOrders << "\n";
	out << "Failed Orders : " << failedOrders << "\n";
	return out.str();
}
