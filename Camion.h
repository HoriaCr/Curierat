#include "Vehicul.h"

template<class PositionType>
class Camion : public Vehicul<PositionType>
{
	public:
	
		Camion();

		int valoareCurenta();

		int consumCombustibil();
};


template<class PositionType = pair<int,int> >
Camion<PositionType>::Camion() : Vehicul({ 0, 0 },
			0,
			60,
			10000,
			24000,
		   	500,
			250,
			90000) {}


