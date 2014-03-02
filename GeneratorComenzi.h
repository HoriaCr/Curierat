#include "Comanda.h"
#include <cstdlib>
#include <ctime>

#pragma once

using namespace std;


template<class PositionType>
class GeneratorComenzi
{

};



//Generator pentru grafuri - specializare template
template<>
class GeneratorComenzi<int>
{
	private:
		int numarNoduri;


	public:

		GeneratorComenzi(int numarNoduri_ = 1) {
			numarNoduri = numarNoduri_;
			srand(static_cast<unsigned int> (time(0)));
		}

		Comanda<int> urmatoareaComanda() {
			int sursa = rand() % numarNoduri;
			int destinatie = rand() % numarNoduri;
			if (numarNoduri > 1 && sursa == destinatie) {
				while (sursa == destinatie) {
					destinatie = rand() % numarNoduri;
				}
			}

			double volum = (rand() % 10) + 0.1 + (rand() % 10) / 100.0;
			double greutate = (rand() % 100) + 0.1 + (rand() % 10) / 100.0;
			double valoare = (rand() % 10000) + 0.1 + (rand() % 10) / 100.0;
			int termenLivrare = rand() % 48 + 1;
			bool fragila = static_cast<bool> (rand() & 1);
			bool perisabila = static_cast<bool> (rand() & 1);

			return Comanda<int>(sursa, destinatie, volum, greutate, valoare, termenLivrare, fragila, perisabila);
		}
};