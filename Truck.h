#include "Vehicle.h"


template<class PositionType>
class Truck : public Vehicle<PositionType>
{
	int tipCombustibil;

	public:
	
		Truck();

		double currentValue();

		double consumCombustibil(const double& distanta);

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
	tipCombustibil = 1;
}


template<class PositionType>
double Truck<PositionType>::currentValue() {
	return buyValue - wear / 100.0 * buyValue;
}

template<class PositionType>
double Truck<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}



