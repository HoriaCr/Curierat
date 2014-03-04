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
	DeliveryFirm<int> *deliveryFirm;
	OrderGenerator<int> *generator;
	Graph *graph;


public:

	DeliverySimulator();

	~DeliverySimulator();

	void start(const int& days) {
		int seconds = days * 24 * 3600;
		for (int s = 1; s <= seconds; s++) {
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

DeliverySimulator::DeliverySimulator() {

	deliveryFirm = new DeliveryFirm<int>(0.0, 5.0, 3.0, 9.0, 50, 5, 300, 150, 250, 455, 500, 10);
	orase = 10000;
	generator = new OrderGenerator<int>(orase);
	graph = new WeightedGraph<int>(orase, orase * 2, {});
}


DeliverySimulator::~DeliverySimulator() {
	delete deliveryFirm;
	delete generator;
	delete graph;
}



int main()
{
	DeliverySimulator S;
	const string files[] = {
		"Airplane",
		"Automobile",
		"DeliveryFirm",
		"DirectedGraph",
		"Graph",
		"Order",
		"OrderGenerator",
		"Scooter",
		"Truck",
		"Van",
		"Vehicle",
		"WeightedDirectedGraph",
		"WeightedGraph"
	};

	for (string file : files) {
		ifstream ifs(file + ".h");
		ofstream f2(file + ".cpp");
		string content((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));

		f2 << content;
	}
	return 0;
}

