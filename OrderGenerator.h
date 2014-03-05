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
class OrderGenerator<unsigned int>
{
	private:
		int vertexNumber;


	public:
	
		OrderGenerator(int vertexNumber_ = 1) {
			vertexNumber = vertexNumber_;
			srand(static_cast<unsigned int> (time(0)));
		}

		Order<unsigned int> nextOrder(const int& sendingTime_) {
			unsigned int source = rand() % vertexNumber;
			unsigned int destination = rand() % vertexNumber;
			if (vertexNumber > 1 && source == destination) {
				while (source == destination) {
					destination = rand() % vertexNumber;
				}
			}

			float volume = (rand() % 10) + 0.1f + (rand() % 10) / 100.0f;
			float weight = (rand() % 100) + 0.1f + (rand() % 10) / 100.0f;
			double value = (rand() % 10000) + 0.1 + (rand() % 10) / 100.0f;
			int deliveryTime = rand() % 48 + 1;
			bool fragile = static_cast<bool> (rand() & 1);
			bool perishable = static_cast<bool> (rand() & 1);

			return Order<unsigned int>(source, destination, volume, weight, value, deliveryTime, sendingTime_, fragile, perishable);
		}
};