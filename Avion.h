#include "Vehicul.h"

template<class PositionType>
class Avion : public Vehicul<PositionType>
{

public:

	Avion();

	double valoareCurenta();

	double consumCombustibil(const double& distanta);
};


template<class PositionType = pair<int, int> >
Avion<PositionType>::Avion() : Vehicul(PositionType(),
	0,
	60,
	30,
	1000,
	500,
	250,
	200000) {}


