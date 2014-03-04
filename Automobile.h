#include "Vehicle.h"

template<class PositionType>
class Automobile : public Vehicle<PositionType>
{
	int tipCombustibil;

public:

	Automobile();

	double currentValue();

	double consumCombustibil(const double& distanta);
};


template<class PositionType = pair<int, int> >
Automobile<PositionType>::Automobile() : Vehicle(PositionType(),
	0,
	70,
	100,
	250,
	3,
	30,
	15000) {
	tipCombustibil = 1;
}


template<class PositionType>
double Automobile<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Automobile<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


