#include "Graph.h"
#include <queue>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <cassert>

#pragma once

template<class DataType>
class WeightedGraph : public Graph
{
	protected:

	vector< vector<DataType> > cost;


	public:

	WeightedGraph(const int& vertexNumber_ = 0, const int& edgeNumber_ = 0,
		const vector< pair< pair<int, int>, DataType> >& edges = {});

	
	virtual void addEdge(const int& x, const int& y, const DataType& edgeCost);

	vector<DataType> djikstra(const int& source);

};

template<class DataType>
WeightedGraph<DataType>::WeightedGraph(const int& vertexNumber_ = 0, const int& edgeNumber_ = 0, const vector< pair< pair<int, int>, DataType> >& edges = {}) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
	for (const auto& edge : edges) {
		addEdge(edge.first.first, edge.first.second, edge.second);
	}
}

template<>
WeightedGraph<int>::WeightedGraph(const int& vertexNumber_, const int& edgeNumber_, const vector< pair< pair<int, int>, int> >& edges) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
	for (int i = 0; i < edgeNumber; i++) {
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
void WeightedGraph<DataType>::addEdge(const int& x, const int& y, const DataType& edgeCost) {
	data[x].push_back(y);
	data[y].push_back(x);
	cost[x].push_back(edgeCost);
	cost[y].push_back(edgeCost);
}

template<class DataType>
vector<DataType> WeightedGraph<DataType>::djikstra(const int& source) {

	auto comp = [](pair< DataType, int >& a, pair< DataType, int >& b) {
		return a.first < b.first;
	};

	priority_queue < pair< DataType,int>, vector< pair<DataType,int> > ,decltype(comp) > myHeap(comp);
	vector<DataType> distance(vertexNumber, numeric_limits<DataType>::max());
	int v;
	DataType priority;
	distance[source] = DataType();
	myHeap.push({ distance[source], source });
	while (!myHeap.empty()) {
		tie(priority, v) = myHeap.top();
		myHeap.pop();

		if (distance[v] != priority) continue;
		for (int i = 0; i < (int)data[v].size(); i++) {
			int w = data[v][i];
			int c = cost[v][i];
			if (distance[w] > distance[v] + c) {
				distance[w] = distance[v] + c;
				myHeap.push({ distance[w], w });
			}
		}
	}

	return distance;
}