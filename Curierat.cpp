#include <iostream>
#include <string>
#include <fstream>
#include "DeliveryFirm.h"
#include "WeightedGraph.h"
#include "OrderGenerator.h"

using namespace std;


class DeliverySimulator
{
	int orase;
	DeliveryFirm *deliveryFirm;
	OrderGenerator<unsigned int> *generator;

public:

	DeliverySimulator();

	~DeliverySimulator();

	void start(const int& days) {
		int seconds = days * 24 * 3600;
		for (int s = 1; s <= seconds; s++) {
			if (rand() % 15 == 0) {
				Order<unsigned int> c = generator->nextOrder(s);
				deliveryFirm->receiveOrder(c);
			}

			if (s % 3600 == 0) {
				//DeliveryFirm->atribuieComenzi();
			}
		}
	}

};

DeliverySimulator::DeliverySimulator() {
	int cities = 1000;
	deliveryFirm = new DeliveryFirm(new WeightedGraph<int>(cities,cities << 1, {}), 0.0, 5.0, 3.0, 9.0, 10, 2, 30, 20, 15, 77, 500, 10);
	generator = new OrderGenerator<unsigned int>(orase);
}


DeliverySimulator::~DeliverySimulator() {
	delete deliveryFirm;
	delete generator;
}


int main()
{
	DeliverySimulator S;
//	S.start(1);

	return 0;
}

