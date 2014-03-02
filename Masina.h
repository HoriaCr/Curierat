#include "Vehicul.h"

template<class PositionType>
class Masina : public Vehicul<PositionType>
{
	int tipCombustibil;

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
	15000) {
	tipCombustibil = 1;
}


template<class PositionType>
double Masina<PositionType>::valoareCurenta() {
	return valoareInitiala - uzura / 100.0 * valoareInitiala;
}

template<class PositionType>
double Masina<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}


