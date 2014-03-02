#include "Vehicul.h"

#pragma once

template<class PositionType>
class Scuter : public Vehicul<PositionType>
{
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
	1000) {}
