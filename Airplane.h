#include "Vehicle.h"

template<class PositionType>
class Airplane : public Vehicle<PositionType>
{
	int fuelType;
		
	public:

		Airplane();

		double currentValue();

		double fuelConsumed(const double& distance);
};


template<class PositionType>
Airplane<PositionType>::Airplane() : Vehicle<PositionType>(PositionType(),
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
	return 0.0;
	//return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Airplane<PositionType>::fuelConsumed(const double& distance) {
	return distance * fuelType;
}
