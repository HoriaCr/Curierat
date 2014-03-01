#include "Vehicul.h"

template<class PositionType>
class Duba : public Vehicul<PositionType>
{

public:

	Duba();

	int valoareCurenta();

	int consumCombustibil();
};


template<class PositionType = pair<int, int> >
Duba<PositionType>::Duba() : Vehicul({ 0, 0 },
	0,
	60,
	10000,
	24000,
	500,
	250,
	90000) {}


