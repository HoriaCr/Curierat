#include "Vehicle.h"

#pragma once

template<class PositionType>
class Scooter : public Vehicle<PositionType>
{
	int fuelType;

	public:

		Scooter();

		double currentValue();

		double fuelConsumed(const double& distance);
};


template<class PositionType>
Scooter<PositionType>::Scooter() : Vehicle<PositionType>(PositionType(),
	0,
	15,
	1,
	30,
	10,
	5,
	1000) {
	fuelType = 1;
}


template<class PositionType>		
double Scooter<PositionType>::currentValue() {
	return 0.0;
    //return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Scooter<PositionType>::fuelConsumed(const double& distance) {
	return distance * fuelType;
}


