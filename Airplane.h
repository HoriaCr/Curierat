#include "Vehicle.h"

template<class PositionType>
class Airplane : public Vehicle<PositionType>
{
	int tipCombustibil;

	public:

		Airplane();

		double currentValue();

		double consumCombustibil(const double& distanta);
};


template<class PositionType>
Airplane<PositionType>::Airplane() : Vehicle(PositionType(),
	0,
	60,
	30,
	1000,
	500,
	250,
	200000) {
	tipCombustibil = 2;
}

template<class PositionType>
double Airplane<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Airplane<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


