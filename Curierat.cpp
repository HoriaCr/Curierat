#include <iostream>
#include "Firma.h"
#include "GrafOrientatCuCosturi.h"
#include "GeneratorComenzi.h"

using namespace std;


class SimulatorCurierat
{
	Firma<int> *firma;
	GeneratorComenzi<int> G;


public:

	SimulatorCurierat();

	void start(const int& zile) {
		int secunde = zile * 24 * 360;

		for (int s = 1; s <= secunde; s++) {

		}
	}

};


int main()
{

	return 0;
}

