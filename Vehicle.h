#include "Order.h"
#include <list>

using namespace std;

#pragma once

template<class PositionType>
class Vehicle
{
	protected:

		list< Order< PositionType> > orders;

		PositionType destination;
		double buyValue;
		double mileage;
		double distanceToDestination;
		double kilometersPerLiter;
		float averageSpeed;
		float maximumVolume;
		float maximumWeight;
		int tankCapacity;
		double fuel;


		float currentLoad;
		float currentVolume;
		float wear;

		bool operational;
		bool parked;


	public:

		Vehicle(PositionType position_ = PositionType(),
			double mileage_ = 0.0,
			float averageSpeed_ = 0.0,
			float maximumVolume_ = 0,
			float maximumWeight_ = 0,
			int tankCapacity_ = 0,
			double fuel_ = 0.0,
			double buyValue_ = 0.0
			);

		virtual double currentValue() { return 0.0;  }

		virtual double fuelConsumed(const double& distance) { return 0.0; }

		bool update(double seconds);

		void updateDestination(const PositionType& nextDestination,double distance_);

		pair< pair<int, int>, double> deliverOrders(int currentTime);

		bool receiveOrder(const Order<PositionType>& order);

		int getOrderCount();

		bool isParked() const;

};

template<class PositionType>
bool Vehicle<PositionType>::receiveOrder(const Order<PositionType>& order) {
	if (currentVolume + order.getVolume() < maximumVolume && currentLoad + order.getWeight() < maximumWeight) {
		orders.push_back(order);
		currentVolume += order.getVolume();
		currentLoad += order.getWeight();
		return true;
	}

	return false;
}

template<class PositionType>
bool Vehicle<PositionType>::isParked() const {
	return parked;
}

template<class PositionType>
bool Vehicle<PositionType>::update(double seconds) {
	if (distanceToDestination < 1e-4) return false;
	double timeLeft = distanceToDestination / averageSpeed;
	double dist;
	bool reachedDestination = false;
	if (timeLeft <= seconds) {
		reachedDestination = true;
		parked = true;
		dist = distanceToDestination;
	} else {
		dist = averageSpeed * seconds;
	}

	fuel = fuel - dist * kilometersPerLiter;
	distanceToDestination -= dist;
	mileage += dist;

	return reachedDestination;
}


template<class PositionType>
pair< pair<int,int> , double> Vehicle<PositionType>::deliverOrders(int currentTime) {
	vector<list< Order<PositionType> >::iterator > ordersToBeErased;
	pair< pair<int, int>, double> ret = { { 0, 0 }, 0.0 };
	for (list< Order<PositionType> >::iterator it = orders.begin();it != orders.end(); ++it) {
		Order<PositionType> &currentOrder = *it;
		if (currentOrder.getDestination() == destination) {
			ordersToBeErased.push_back(it);
			currentLoad -= currentOrder.getWeight();
			currentVolume -= currentOrder.getVolume();
			if (currentTime <= currentOrder.getTimelimit()) {
				ret.first.first++;
				ret.second += currentOrder.computePrice();
			} else {
				ret.first.second++;
			}
		}
	}

	for (auto& it : ordersToBeErased) {
		orders.erase(it);
	}

	return ret;
}


template<class PositionType>
Vehicle<PositionType>::Vehicle(PositionType position_,
	double mileage_,
	float averageSpeed_,
	float maximumVolume_,
	float maximumWeight_,
	int tankCapacity_,
	double fuel_,
	double buyValue_
	) {
	destination = position_;
	mileage = mileage_;
	averageSpeed = averageSpeed_;
	maximumVolume = maximumVolume_;
	maximumWeight = maximumWeight_;
	tankCapacity = tankCapacity_;
	fuel = fuel_;
	buyValue = buyValue_;


	distanceToDestination = 0.0;
	kilometersPerLiter = 20.0;

	currentLoad = 0.0;
	currentVolume = 0.0;
	wear = 0;
	operational = true;
	parked = true;
}


template<class PositionType>
int Vehicle<PositionType>::getOrderCount() {
	return static_cast<int>(orders.size());
}


template<class PositionType>
void Vehicle<PositionType>::updateDestination(const PositionType& nextDestination,double distance_) {
	destination = nextDestination;
	distanceToDestination = distance_;
	parked = false;
}