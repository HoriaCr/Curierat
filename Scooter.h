#include "Vehicle.h"

#pragma once

template<class PositionType>
class Scooter : public Vehicle<PositionType>
{
	int fuelType;

	public:

		Scooter();

		double currentValue();

		double fuelConsumed(const double& distanta);
};


template<class PositionType = pair<int, int> >
Scooter<PositionType>::Scooter() : Vehicle(PositionType(),
	0,
	40,
	1,
	30,
	10,
	5,
	1000) {
	fuelType = 1;
}


template<class PositionType>
double Scooter<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Scooter<PositionType>::fuelConsumed(const double& distanta) {
	return distanta * fuelType;
}


