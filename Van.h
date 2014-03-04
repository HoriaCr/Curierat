#include "Vehicle.h"

template<class PositionType>
class Van : public Vehicle<PositionType>
{
	
	int fuelType;
public:

	Van();

	double currentValue();

	double fuelConsumed(const double& distanta);
};


template<class PositionType = pair<int, int> >
Van<PositionType>::Van() : Vehicle(PositionType(),
	0,
	60,
	1,
	2000,
	150,
	90,
	25000) {
	fuelType = 1;
}



template<class PositionType>
double Van<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Van<PositionType>::fuelConsumed(const double& distanta) {
	return distanta * fuelType;
}


