#include "GrafOrientatCuCosturi.h"


template<class DataType = int>
GrafOrientatCuCosturi<DataType>::GrafOrientatCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0, const vector< pair<int, DataType> >& muchii = {}) {
	numarNoduri = numarNoduri_;
	numarMuchii = numarMuchii_;

}


template<class DataType = int>
void GrafOrientatCuCosturi<DataType>::adaugaMuchie(const int& x, const int& y,const DataType& costMuchie) {
	data[x].push_back(y);
	cost[x].push_back(costMuchie);
}