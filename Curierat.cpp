#include <iostream>
#include "DeliveryFirm.h"
#include "WeightedGraph.h"
#include "OrderGenerator.h"

using namespace std;


class SimulatorCurierat
{
	int orase;
	DeliveryFirm<int> *deliveryFirm;
	OrderGenerator<int> *generator;
	Graph *graph;


public:

	SimulatorCurierat();

	~SimulatorCurierat();

	void start(const int& zile) {
		int secunde = zile * 24 * 3600;
		for (int s = 1; s <= secunde; s++) {
			if (rand() % 15 == 0) {
				Order<int> c = generator->nextOrder();
				deliveryFirm->receiveOrder(c);
			}

			if (s % 3600 == 0) {
				//DeliveryFirm->atribuieComenzi();
			}
		}
	}

};

SimulatorCurierat::SimulatorCurierat() {

	deliveryFirm = new DeliveryFirm<int>(0.0, 5.0, 3.0, 9.0, 50, 5, 300, 150, 250, 455, 500, 10);
	orase = 10000;
	generator = new OrderGenerator<int>(orase);
	graph = new WeightedGraph<int>(orase, orase * 2, {});
}


SimulatorCurierat::~SimulatorCurierat() {
	delete deliveryFirm;
	delete generator;
	delete graph;
}


int main()
{
	SimulatorCurierat S;
	S.start(30);
	Order<int> c;

	return 0;
}

