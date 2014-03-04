#include "Vehicle.h"

#pragma once

template<class PositionType>
class Scooter : public Vehicle<PositionType>
{
	int tipCombustibil;

	public:

		Scooter();

		double currentValue();

		double consumCombustibil(const double& distanta);
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
	tipCombustibil = 1;
}


template<class PositionType>
double Scooter<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Scooter<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


