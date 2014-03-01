#include "Graf.h"

template<class DataType>
class GrafCuCosturi : public Graf
{
	protected:
	vector< vector< int> > cost;


	GrafCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0,
		const vector< pair< pair<int, int>, DataType> >& muchii = {});

	void adaugaMuchie(const int& x, const int& y, const DataType& costMuchie);
};

template<class DataType>
GrafCuCosturi<DataType>::GrafOCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0, const vector< pair< pair<int, int>, DataType> >& muchii = {}) {
	numarNoduri = numarNoduri_;
	numarMuchii = numarMuchii_;
	for (const auto& muchie : muchii) {
		adaugaMuchie(muchie.first.first, muchie.first.second, muchie.second);
	}
}

template<class DataType>
void GrafCuCosturi<DataType>::adaugaMuchie(const int& x, const int& y, const DataType& costMuchie) {
	data[x].push_back(y);
	data[y].push_baack(x);
	cost[x].push_back(costMuchie);
	cost[y].push_back(costMuchie);
}