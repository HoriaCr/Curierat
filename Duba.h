#include "Vehicul.h"

template<class PositionType>
class Duba : public Vehicul<PositionType>
{
	
	int tipCombustibil;
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
	25000) {
	tipCombustibil = 1;
}



template<class PositionType>
double Duba<PositionType>::valoareCurenta() {
	return valoareInitiala - uzura / 100.0 * valoareInitiala;
}

template<class PositionType>
double Duba<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


