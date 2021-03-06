#include "Vehicle.h"


template<class PositionType>
class Truck : public Vehicle<PositionType>
{
	int fuelType;

	public:
	
		Truck();

		double currentValue();

		double fuelConsumed(const double& distance);
};


template<class PositionType>
Truck<PositionType>::Truck() : Vehicle<PositionType>(PositionType(),
			0,
			12,
			100,
			24000,
		   	500,
			250,
			90000) {
	fuelType = 1;
}


template<class PositionType>
double Truck<PositionType>::currentValue() {
    return 0.5;
//	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Truck<PositionType>::fuelConsumed(const double& distance) {
	return distance * fuelType;
}



