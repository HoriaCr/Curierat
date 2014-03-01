#include "Vehicul.h"

template<class PositionType>
class Avion : public Vehicul<PositionType>
{

public:

	Avion();

	int valoareCurenta();

	int consumCombustibil();
};


template<class PositionType = pair<int, int> >
Avion<PositionType>::Avion() : Vehicul({ 0, 0 },
	0,
	60,
	10000,
	24000,
	500,
	250,
	90000) {}


