#include <iostream>
#include "Firma.h"
#include "GrafCuCosturi.h"
#include "GeneratorComenzi.h"

using namespace std;


class SimulatorCurierat
{
	int orase;
	Firma<int> *firma;
	GeneratorComenzi<int> *generator;
	Graf *graf;


public:

	SimulatorCurierat();

	~SimulatorCurierat();

	void start(const int& zile) {
		int secunde = zile * 24 * 360;

		for (int s = 1; s <= secunde; s++) {

		}
	}

};

SimulatorCurierat::SimulatorCurierat() {
	firma = new Firma<int>(0.0, 5.0, 3.0, 9.0, 50, 5, 300, 150, 250, 455, 500, 10);
	orase = 100000;
	generator = new GeneratorComenzi<int>(orase);
	graf = new GrafCuCosturi<int>(orase, orase * 2, {});
}


SimulatorCurierat::~SimulatorCurierat() {
	delete firma;
	delete generator;
	delete graf;
}



int main()
{

	return 0;
}

