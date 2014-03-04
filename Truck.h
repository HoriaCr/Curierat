#include "Vehicle.h"


template<class PositionType>
class Truck : public Vehicle<PositionType>
{
	int fuelType;

	public:
	
		Truck();

		double currentValue();

		double fuelConsumed(const double& distanta);

		void update(PositionType& nextLocatie);
};


template<class PositionType = pair<int,int> >
Truck<PositionType>::Truck() : Vehicle(PositionType(),
			0,
			50,
			100,
			24000,
		   	500,
			250,
			90000) {
	fuelType = 1;
}


template<class PositionType>
double Truck<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Truck<PositionType>::fuelConsumed(const double& distanta) {
	return distanta * fuelType;
}



