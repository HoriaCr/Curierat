#include <vector>
#include <queue>
#include "Airplane.h"
#include "Truck.h"
#include "Van.h"
#include "Automobile.h"
#include "Scooter.h"
#include "Order.h"
#include "WeightedGraph.h"


using namespace std;


template<class PositionType>
class DeliveryFirm
{
	private:

		vector< Vehicle<PositionType>*>  flotaVehiclee;
		queue< Order<PositionType> > *coada;
		Graph *graph;

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

		int drivers;
		int workers;
		int managers;

		int succeededOrders;
		int failedOrders;
		int employeesNumber;

		int strategyType;
	


	public:
	
	DeliveryFirm(
		Graph *graph_,
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

		void update();

		double costs();

		double venituri();

		void receiveOrder(const Order<PositionType>& order);

		void atribuieComenzi();

};



template<class PositionType>
DeliveryFirm<PositionType>::DeliveryFirm(Graph *graph_,
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
	graph = graph_;
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

	vehicleNumber = airplaneNumber + truckNumber + vanNumber + automobileNumber + scooterNumber;
	employeesNumber = drivers + workers + managers;
	flotaVehiclee.resize(vehicleNumber);
	coada = new queue< Order<PositionType> >[graph->getVertexNumber()];

	for (int i = 0; i < airplaneNumber; i++) {
		flotaVehiclee[i] = new Airplane<PositionType>();
	}

	for (int i = 0; i < truckNumber; i++) {
		flotaVehiclee[i + airplaneNumber] = new Truck<PositionType>();
	}

	for (int i = 0; i < vanNumber; i++ ) {
		flotaVehiclee[i + airplaneNumber + truckNumber] = new Van<PositionType>();
	}

	for (int i = 0; i < automobileNumber; i++) {
		flotaVehiclee[i + airplaneNumber + truckNumber + vanNumber] = new Automobile<PositionType>();
	}

	for (int i = 0; i < scooterNumber; i++) {
		flotaVehiclee[i + airplaneNumber + truckNumber + vanNumber + automobileNumber] = new Scooter<PositionType>();
	}
	
}


template<class PositionType>
DeliveryFirm<PositionType>::~DeliveryFirm() {
	delete graph;
	delete[] coada;
}


template<class PositionType>
void DeliveryFirm<PositionType>::receiveOrder(const Order<PositionType>& order) {
	coada[order.getSource()].push(order);
}

template<class PositionType>
void DeliveryFirm<PositionType>::atribuieComenzi() {

}