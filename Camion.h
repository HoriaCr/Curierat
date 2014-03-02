#include "Vehicul.h"


template<class PositionType>
class Camion : public Vehicul<PositionType>
{
	int tipCombustibil;

	public:
	
		Camion();

		double valoareCurenta();

		double consumCombustibil(const double& distanta);

		void update(PositionType& urmatoareaLocatie);
};


template<class PositionType = pair<int,int> >
Camion<PositionType>::Camion() : Vehicul(PositionType(),
			0,
			50,
			100,
			24000,
		   	500,
			250,
			90000) {
	tipCombustibil = 1;
}


template<class PositionType>
double Camion<PositionType>::valoareCurenta() {
	return valoareInitiala - uzura / 100.0 * valoareInitiala;
}

template<class PositionType>
double Camion<PositionType>::consumCombustibil(const double& distanta) {
	return distanta * tipCombustibil;
}



