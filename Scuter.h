#include "Vehicul.h"

#pragma once

template<class PositionType>
class Scuter : public Vehicul<PositionType>
{
	int tipCombustibil;

	public:

		Scuter();

		double valoareCurenta();

		double consumCombustibil(const double& distanta);
};


template<class PositionType = pair<int, int> >
Scuter<PositionType>::Scuter() : Vehicul(PositionType(),
	0,
	40,
	1,
	30,
	10,
	5,
	1000) {
	tipCombustibil = 1;
}


template<class PositionType>
double Scuter<PositionType>::valoareCurenta() {
	return valoareInitiala - uzura / 100.0 * valoareInitiala;
}

template<class PositionType>
double Scuter<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


