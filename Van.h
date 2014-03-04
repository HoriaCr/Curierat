#include "Vehicle.h"

template<class PositionType>
class Van : public Vehicle<PositionType>
{
	
	int tipCombustibil;
public:

	Van();

	double currentValue();

	double consumCombustibil(const double& distanta);
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
	tipCombustibil = 1;
}



template<class PositionType>
double Van<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Van<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


