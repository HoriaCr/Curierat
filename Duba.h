#include "Vehicul.h"

template<class PositionType>
class Duba : public Vehicul<PositionType>
{

public:

	Duba();

	double valoareCurenta();

	double consumCombustibil(const double& distanta);
};


template<class PositionType = pair<int, int> >
Duba<PositionType>::Duba() : Vehicul(PositionType(),
	0,
	60,
	1,
	2000,
	150,
	90,
	25000) {}


