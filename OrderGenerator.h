#include "Order.h"
#include <cstdlib>
#include <ctime>

#pragma once

using namespace std;


template<class PositionType>
class OrderGenerator
{

};



//Generator pentru Graphuri - specializare template
template<>
class OrderGenerator<int>
{
	private:
		int vertexNumber;


	public:

		OrderGenerator(int vertexNumber_ = 1) {
			vertexNumber = vertexNumber_;
			srand(static_cast<unsigned int> (time(0)));
		}

		Order<int> nextOrder() {
			int source = rand() % vertexNumber;
			int destination = rand() % vertexNumber;
			if (vertexNumber > 1 && source == destination) {
				while (source == destination) {
					destination = rand() % vertexNumber;
				}
			}

			double volume = (rand() % 10) + 0.1 + (rand() % 10) / 100.0;
			double weight = (rand() % 100) + 0.1 + (rand() % 10) / 100.0;
			double value = (rand() % 10000) + 0.1 + (rand() % 10) / 100.0;
			int deliveryTime = rand() % 48 + 1;
			bool fragile = static_cast<bool> (rand() & 1);
			bool perishable = static_cast<bool> (rand() & 1);

			return Order<int>(source, destination, volume, weight, value, deliveryTime, fragile, perishable);
		}
};