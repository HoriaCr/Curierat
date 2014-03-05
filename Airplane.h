#include "Vehicle.h"

template<class PositionType>
class Airplane : public Vehicle<PositionType>
{
	int fuelType;
		
	public:

		Airplane();

		double currentValue();

		double fuelConsumed(const double& distanta);
};


template<class PositionType>
Airplane<PositionType>::Airplane() : Vehicle(PositionType(),
	0,
	100,
	30,
	1000,
	500,
	250,
	200000) {
	fuelType = 2;
}

template<class PositionType>
double Airplane<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Airplane<PositionType>::fuelConsumed(const double& distanta) {
	return distanta * fuelType;
}


