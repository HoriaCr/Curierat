#include "Vehicul.h"

template<class PositionType>
class Avion : public Vehicul<PositionType>
{
	int tipCombustibil;

	public:

		Avion();

		double valoareCurenta();

		double consumCombustibil(const double& distanta);
};


template<class PositionType>
Avion<PositionType>::Avion() : Vehicul(PositionType(),
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
double Avion<PositionType>::valoareCurenta() {
	return valoareInitiala - uzura / 100.0 * valoareInitiala;
}

template<class PositionType>
double Avion<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


