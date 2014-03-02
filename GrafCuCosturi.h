#include "Graf.h"
#include <ctime>
#include <cstdlib>
#pragma once

template<class DataType>
class GrafCuCosturi : public Graf
{
	protected:
	vector< vector< int> > cost;


	public:

	GrafCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0,
		const vector< pair< pair<int, int>, DataType> >& muchii = {});

	
	void adaugaMuchie(const int& x, const int& y, const DataType& costMuchie);

};

template<class DataType>
GrafCuCosturi<DataType>::GrafCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0, const vector< pair< pair<int, int>, DataType> >& muchii = {}) {
	numarNoduri = numarNoduri_;
	numarMuchii = numarMuchii_;
	data.resize(numarNoduri);
	cost.resize(numarNoduri);
	for (const auto& muchie : muchii) {
		adaugaMuchie(muchie.first.first, muchie.first.second, muchie.second);
	}
}

template<>
GrafCuCosturi<int>::GrafCuCosturi(const int& numarNoduri_, const int& numarMuchii_, const vector< pair< pair<int, int>, int> >& muchii) {
	numarNoduri = numarNoduri_;
	numarMuchii = numarMuchii_;
	data.resize(numarNoduri);
	cost.resize(numarNoduri);
	for (int i = 0; i <= numarMuchii; i++) {
		int v = rand() % numarNoduri;
		int w = rand() % numarNoduri;
		int c = rand() % 666013 + 1;
		if (numarNoduri > 1 && v == w) {
			while (v == w) {
				w = rand() % numarNoduri;
			}
		}
		adaugaMuchie(v, w, c);
	}
}



template<class DataType>
void GrafCuCosturi<DataType>::adaugaMuchie(const int& x, const int& y, const DataType& costMuchie) {
	data[x].push_back(y);
	data[y].push_back(x);
	cost[x].push_back(costMuchie);
	cost[y].push_back(costMuchie);
}