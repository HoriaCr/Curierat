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

		void update();

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

	currentLoad = 0;
	currentVolume = 0;
	wear = 0;
	operational = true;
}