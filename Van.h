#include "Vehicle.h"

template<class PositionType>
class Van : public Vehicle<PositionType>
{
	
	int fuelType;
public:

	Van();

	double currentValue();

	double fuelConsumed(const double& distance);
};


template<class PositionType>
Van<PositionType>::Van() : Vehicle<PositionType>(PositionType(),
	0,
	17,
	1,
	2000,
	150,
	90,
	25000) {
	fuelType = 1;
}



template<class PositionType>
double Van<PositionType>::currentValue() {
	return 0.0;
    //return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Van<PositionType>::fuelConsumed(const double& distance) {
	return distance * fuelType;
}


