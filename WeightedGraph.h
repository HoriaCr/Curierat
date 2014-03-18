#include "Graph.h"
#include <queue>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <limits>

#pragma once

template<class DataType>
class WeightedGraph : public Graph
{
	protected:

	vector< vector<DataType> > cost;
	
	void readData(istream& in);

	void writeData(ostream& out);

	public:

	WeightedGraph(const int& vertexNumber_,
                  const int& edgeNumber_,
		          const vector< pair< pair<int, int>, DataType> >& edges);

	virtual void addEdge(const int& x, const int& y, const DataType& edgeCost);

	vector<DataType> djikstra(const unsigned int& source);
	
	WeightedGraph<DataType> MinimumSpanningTree();
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
		int c = rand() % 113 + 1;
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
	
	try {
		if (x < 0 || x >= vertexNumber || y < 0 || y >= vertexNumber) {
			out_of_range outException("Node index out of bounds!");
			throw outException;
		}
		data[x].push_back(y);
		data[y].push_back(x);
		cost[x].push_back(edgeCost);
		cost[y].push_back(edgeCost);
	}
	
	catch (out_of_range& exception) {
		cout << exception.what() << "\n";
	}
}

template<class DataType>
vector<DataType> WeightedGraph<DataType>::djikstra(const unsigned int& source) {

	auto comp = [](const pair< DataType, int >& a,const pair< DataType, int >& b) {
		return a.first > b.first;
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
			DataType c = cost[v][i];
			if (distance[w] > distance[v] + c) {
				distance[w] = distance[v] + c;
				myHeap.push({ distance[w], w });
			}
		}
	}

	return distance;
}

template<class DataType> 
WeightedGraph<DataType> WeightedGraph<DataType>::MinimumSpanningTree() {
	WeightedGraph<DataType> ret(vertexNumber, 0, {});

	auto comp = [](const pair< DataType, int >& a, const pair< DataType, int >& b) {
		return a.first > b.first;
	};
	
	vector<bool> used(vertexNumber,false);
	vector<int> who(vertexNumber);
	vector<DataType> best(vertexNumber, numeric_limits<DataType>::max());
	priority_queue < pair< DataType, int>, vector< pair<DataType, int> >, decltype(comp) > myHeap(comp);
	int treeEdges = 0;
	best[0] = DataType();
	myHeap.push({ DataType(), 0 });
	while (treeEdges != vertexNumber - 1){
		int v;
		DataType edgeCost;
	
		do {
			tie(edgeCost, v) = myHeap.top();
			myHeap.pop();
		} while (!myHeap.empty() && !used[v]);
		if (v != who[v]) {
			treeEdges++;
			ret.addEdge(v, who[v], edgeCost);
		}
		used[v] = true;
		for (int i = 0; i < (int)data[v].size(); i++) {
			int w = data[v][i];
			edgeCost = cost[v][i];
			if (best[w] > edgeCost) {
				best[w] = edgeCost;
				who[w] = v;
				myHeap.push({ best[w], w });
			}
		}
		
	}
	return ret;
}

template<class DataType>
void WeightedGraph<DataType>::readData(istream& in) {	
	in >> vertexNumber >> edgeNumber;
	int a, b;
	DataType c;
	for (int i = 0; i < edgeNumber; i++) {
		cin >> a >> b >> c;
		addEdge(a, b, c);
	}
}

template<class DataType>
void WeightedGraph<DataType>::writeData(ostream& out) {
	out << vertexNumber << " " << edgeNumber << "\n";
	for (int v = 0; v < vertexNumber; v++) {
		for (int i = 0; i < (int)data[v].size(); i++) {
			if (v < data[v][i]) {
				out << v << " " << data[v][i] << cost[v][i] << "\n";
			}
		}
	}
}
