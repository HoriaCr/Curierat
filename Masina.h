#include "Vehicul.h"

template<class PositionType>
class Masina : public Vehicul<PositionType>
{

public:

	Masina();

	int valoareCurenta();

	int consumCombustibil();
};


template<class PositionType = pair<int, int> >
Masina<PositionType>::Masina() : Vehicul({ 0, 0 },
	0,
	60,
	10000,
	24000,
	500,
	250,
	90000) {}


