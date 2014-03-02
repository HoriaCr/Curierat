#include "Vehicul.h"

template<class PositionType>
class Masina : public Vehicul<PositionType>
{

public:

	Masina();

	double valoareCurenta();

	double consumCombustibil(const double& distanta);
};


template<class PositionType = pair<int, int> >
Masina<PositionType>::Masina() : Vehicul(PositionType(),
	0,
	70,
	100,
	250,
	3,
	30,
	15000) {}


