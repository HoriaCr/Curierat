#include "Graph.h"
#include <queue>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <limits>

#pragma once

class DisjointSet {
	vector<int> parent;

public:

	DisjointSet() {

	}


	DisjointSet(DisjointSet& S) {
		parent = S.parent;
	}

	DisjointSet(int Size) {
		parent.resize(Size);
		for (int i = 0; i < Size; i++) {
			parent[i] = i;
		}
	}

	int getRoot(const int& x) {
		int ret = x;
		while (ret != parent[ret]) {
			ret = parent[ret];
		}
		int v = x;
		while (v != parent[v]) {
			int aux = parent[v];
			parent[v] = ret;
			v = aux;
		}

		return ret;
	}

	bool merge(const int& x, const int& y) {
		int rootX = getRoot(x);
		int rootY = getRoot(y);
		if (rootX != rootY) {
			parent[rootX] = rootY;
			return true;
		}

		return false;
	}
};

template<class DataType>
class WeightedGraph : public Graph
{
protected:

	vector< vector<DataType> > cost;

	void readData(istream& in);

	void writeData(ostream& out);

public:

	WeightedGraph(const int& vertexNumber_ = 0, const int& edgeCount_ = 0);

	WeightedGraph(const int& vertexNumber_,
		const int& edgeNumber_,
		const vector< pair< pair<int, int>, DataType> >& edges);

	~WeightedGraph();

	virtual void addEdge(const int& x, const int& y, const DataType& edgeCost);

	vector<DataType> djikstra(const unsigned int& source);

	WeightedGraph<DataType> MinimumSpanningTree();

	WeightedGraph<DataType> MinimumSpanningTreeKruskal();
};

template<class DataType>
WeightedGraph<DataType>::WeightedGraph(const int& vertexNumber_ , const int& edgeNumber_ , const vector< pair< pair<int, int>, DataType> >& edges) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
	for (const auto& edge : edges) {
		addEdge(edge.first.first, edge.first.second, edge.second);
	}

}

template<class DataType>
WeightedGraph<DataType>::WeightedGraph(const int& vertexNumber_ , const int& edgeCount_) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeCount_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
}

template<class DataType>
WeightedGraph<DataType>::~WeightedGraph() {
	vertexNumber = 0;
	edgeNumber = 0;
}

template<>
WeightedGraph<int>::WeightedGraph(const int& vertexNumber_, const int& edgeNumber_, const vector< pair< pair<int, int>, int> >& edges) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);

	for (const auto& edge : edges) {
		addEdge(edge.first.first, edge.first.second, edge.second);
	}

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
		cout << exception.what() << " " << x << " " << y << " " << "\n";
	}
}

template<class DataType>
vector<DataType> WeightedGraph<DataType>::djikstra(const unsigned int& source) {

	auto comp = [](const pair< DataType, int >& a, const pair< DataType, int >& b) {
		return a.first > b.first;
	};

	priority_queue < pair< DataType, int>, vector< pair<DataType, int> >, decltype(comp) > myHeap(comp);
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
	WeightedGraph<DataType> ret(vertexNumber, vertexNumber - 1);

	vector<bool> used(vertexNumber, false);
	vector<int> who(vertexNumber);
	vector<DataType> best(vertexNumber, numeric_limits<DataType>::max());
	priority_queue < pair< DataType, int>, vector< pair<DataType, int> > > myHeap;
	int v;
	DataType edgeCost;
	best[0] = DataType();
	myHeap.push({ DataType(), 0 });

	for (int step = 1; step <= vertexNumber; step++) {
		if (myHeap.empty()) {
			//not connected;
			return ret;
		}

		do {
			tie(edgeCost, v) = myHeap.top();
			myHeap.pop();
		} while (!myHeap.empty() && used[v]);

		if (step > 1) {
			ret.addEdge(v, who[v], -edgeCost);
		}

		used[v] = true;
		for (int i = 0; i < (int)data[v].size(); i++) {
			int& w = data[v][i];
			DataType& edgeCost = cost[v][i];
			if (!used[w] && best[w] > edgeCost) {
				best[w] = edgeCost;
				who[w] = v;
				myHeap.push({ -best[w], w });
			}
		}
	}
	return ret;
}

template<class DataType>
WeightedGraph<DataType> WeightedGraph<DataType>::MinimumSpanningTreeKruskal() {
	WeightedGraph<DataType> ret(vertexNumber, vertexNumber - 1);
	vector< tuple<DataType, int, int> > edges;
	for (int i = 0; i < vertexNumber; i++) {
		for (int j = 0; j < (int)data[i].size(); j++) {
			if (i < data[i][j]) {
				edges.push_back(make_tuple(cost[i][j], i, data[i][j]));
			}
		}
	}

	sort(edges.begin(), edges.end());
	int edgeCount = 0;

	DisjointSet forest(vertexNumber);

	for (auto& edge : edges) {
		DataType& c = get<0>(edge);
		int& x = get<1>(edge);
		int& y = get<2>(edge);
		if (forest.merge(x, y)) {
			edgeCount++;
			ret.addEdge(x, y, c);
			if (edgeCount == vertexNumber - 1) {
				break;
			}
		}
	}
	return ret;
}

template<class DataType>
void WeightedGraph<DataType>::readData(istream& in) {
	in >> vertexNumber >> edgeNumber;
	data.resize(vertexNumber);
	cost.resize(vertexNumber);
	int a, b;
	DataType c;

	for (int i = 0; i < edgeNumber; i++) {
		in >> a >> b >> c;
		a--, b--;
		addEdge(a, b, c);
	}
}

template<class DataType>
void WeightedGraph<DataType>::writeData(ostream& out) {

	out << vertexNumber << " " << edgeNumber << "\n";
	for (int v = 0; v < vertexNumber; v++) {
		for (int i = 0; i < (int)data[v].size(); i++) {
			if (v < data[v][i]) {
				out << v + 1 << " " << data[v][i] + 1 << " " << cost[v][i] << "\n";
			}
		}
	}
}