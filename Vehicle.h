#include "Order.h"
#include <list>

using namespace std;

#pragma once

template<class PositionType>
class Vehicle
{
	protected:
		list< Order< PositionType> > orders;

		PositionType position;
		double buyValue;
		double mileage;
		double distanceToDestination;
		double kilometersPerLiter;
		float averageSpeed;
		int maximumVolume;
		int maximumWeight;
		int tankCapacity;
		float fuel;


		int currentLoad;
		int currentVolume;
		int wear;

		bool operational;


	public:

		Vehicle(PositionType position_ = PositionType(),
			double mileage_ = 0.0,
			float averageSpeed_ = 0.0,
			int maximumVolume_ = 0,
			int maximumWeight_ = 0,
			int tankCapacity_ = 0,
			float fuel_ = 0.0,
			double buyValue_ = 0.0
			);

		virtual double currentValue() { return 0.0;  }

		virtual double fuelConsumed(const double& distanta) { return 0.0; }

		void update(double seconds);

		pair< pair<int, int>, double> deliverOrders(int currentTime);

		int getWear();

		void receiveOrder(const Order<PositionType>& Order);

};
template<class PositionType>
int Vehicle<PositionType>::getWear() {
	return wear;
}

template<class PositionType>
void Vehicle<PositionType>::receiveOrder(const Order<PositionType>& Order) {
	orders.push_back(Order);
}

template<class PositionType>
void Vehicle<PositionType>::update(double seconds) {
	double timeLeft = distanceToDestination / averageSpeed;
	double dist;
	if (timeLeft <= seconds) {
		dist = distanceToDestination;
	} else {
		dist = averageSpeed * seconds;
	}

	fuel -= dist * kilometersPerLiter;
	distanceToDestination -= dist;
	mileage += dist;
}


template<class PositionType>
pair< pair<int,int> , double> Vehicle<PositionType>::deliverOrders(int currentTime) {
	vector<auto> ordersToBeErased;
	pair< pair<int, int>, double> ret = { { 0, 0 }, 0.0 };
	for (list< Order<PositionType> >::iterator it = orders.begin();it != orders.end(); ++it) {
		Order<PositionType> &currentOrder = *it;
		if (currentOrder.getDestination() == position) {
			if (currentTime <= currentOrder.getTimelimit()) {
				ret.first.first++;
				ret.second += currentOrder.getPrice();
			} else {
				ret.first.second++;
			}
		}
	}

	return ret;
}


template<class PositionType>
Vehicle<PositionType>::Vehicle(PositionType position_,
	double mileage_,
	float averageSpeed_,
	int maximumVolume_,
	int maximumWeight_,
	int tankCapacity_,
	float fuel_,
	double buyValue_
	) {
	position = position_;
	mileage = mileage_;
	averageSpeed = averageSpeed_;
	maximumVolume = maximumVolume_;
	maximumWeight = maximumWeight_;
	tankCapacity = tankCapacity_;
	fuel = fuel_;
	buyValue = buyValue_;


	distanceToDestination = 0.0;
	kilometersPerLiter = 20.0;

	currentLoad = 0;
	currentVolume = 0;
	wear = 0;
	operational = true;
}