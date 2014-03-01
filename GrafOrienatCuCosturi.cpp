#include "GrafOrientatCuCosturi.h"



template<class DataType>
void GrafOrientatCuCosturi<DataType>::adaugaMuchie(const int& x, const int& y, const DataType& costMuchie) {
	data[x].push_back(y);
	cost[x].push_back(costMuchie);
}