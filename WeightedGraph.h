#include "Graph.h"
#include <ctime>
#include <cstdlib>
#pragma once

template<class DataType>
class WeightedGraph : public Graph
{
	protected:
	vector< vector< int> > cost;


	public:

	WeightedGraph(const int& vertexNumber_ = 0, const int& edgeNumber_ = 0,
		const vector< pair< pair<int, int>, DataType> >& muchii = {});

	
	void addEdge(const int& x, const int& y, const DataType& costMuchie);

};

template<class DataType>
WeightedGraph<DataType>::WeightedGraph(const int& vertexNumber_ = 0, const int& edgeNumber_ = 0, const vector< pair< pair<int, int>, DataType> >& muchii = {}) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
	for (const auto& muchie : muchii) {
		addEdge(muchie.first.first, muchie.first.second, muchie.second);
	}
}

template<>
WeightedGraph<int>::WeightedGraph(const int& vertexNumber_, const int& edgeNumber_, const vector< pair< pair<int, int>, int> >& muchii) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
	for (int i = 0; i <= edgeNumber; i++) {
		int v = rand() % vertexNumber;
		int w = rand() % vertexNumber;
		int c = rand() % 666013 + 1;
		if (vertexNumber > 1 && v == w) {
			while (v == w) {
				w = rand() % vertexNumber;
			}
		}
		addEdge(v, w, c);
	}
}



template<class DataType>
void WeightedGraph<DataType>::addEdge(const int& x, const int& y, const DataType& costMuchie) {
	data[x].push_back(y);
	data[y].push_back(x);
	cost[x].push_back(costMuchie);
	cost[y].push_back(costMuchie);
}