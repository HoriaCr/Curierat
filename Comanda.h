#pragma once

template<class PositionType>
class Comanda
{
	protected:

		PositionType sursa;
		PositionType destinatie;

		double volum;
		double greutate;
		double valoare;

		int termenLivrareOre; 
		bool fragila;
		bool perisabila;

	public:

		Comanda(PositionType sursa_, PositionType destinatie_,double volum_, double greutate_, double valoare_, int termenLivrareOre_, bool fragila_, bool perisabila_);

		double costLivrare();
};

template<class PositionType>
Comanda<PositionType>::Comanda(PositionType sursa_, 
				 PositionType destinatie_, 
				 double volum_, 
				 double greutate_, 
				 double valoare_, 
				 int termenLivrareOre_, 
				 bool fragila_, 
				 bool perisabila_) {
	
	sursa = sursa_;
	destinatie = destinatie_;
	volum = volum_;
    greutate = greutate_;
	valoare = valoare_;
	termenLivrareOre = termenLivrareOre_;
	fragila = fragila_;
	perisabila = perisabila_;
}
