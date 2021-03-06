#include "Vehicle.h"

template<class PositionType>
class Automobile : public Vehicle<PositionType>
{
	int fuelType;

public:

	Automobile();

	double currentValue();

	double fuelConsumed(const double& distance);
};

template<class PositionType>
Automobile<PositionType>::Automobile() : Vehicle<PositionType>(PositionType(),
	0,
	20,
	100,
	250,
	3,
	30,
	15000) {
	fuelType = 1;
}


template<class PositionType>
double Automobile<PositionType>::currentValue() {
	return 0.0;
    //return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Automobile<PositionType>::fuelConsumed(const double& distance) {
	return distance * fuelType;
}

