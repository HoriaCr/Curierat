#include "Vehicul.h"

template<class PositionType>
class Scuter : public Vehicul<PositionType>
{
	public:

		Scuter();

		int valoareCurenta();

		int consumCombustibil();
};


template<class PositionType = pair<int, int> >
Scuter<PositionType>::Scuter() : Vehicul({ 0, 0 },
	0,
	60,
	10000,
	24000,
	500,
	250,
	90000) {}
