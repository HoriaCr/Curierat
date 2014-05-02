#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include <stack>

#pragma once

using namespace std;

class Graph
{
protected:

	int vertexNumber;
	int edgeNumber;
	vector< vector<int> > data;

	void dfs(const int& v, const int& parent, vector<bool>& visited, vector<int>& ret);

	virtual void readData(istream& in);

	virtual void writeData(ostream& out);

public:

	Graph(int vertexNumber_);

	Graph(int vertexNumber_, int edgeNumber, const vector< pair<int, int> >& edges);

	virtual ~Graph();

	int getVertexNumber() const;

	virtual void addEdge(const int&x, const int& y);

	vector<int> dfs(const int& root);

	vector<int> bfs(const int& root);

	vector<int> getCriticalNodes();

	vector< vector<int> > getBiconnectedComponents();

	bool isConnected();

	friend istream& operator >> (istream& in, Graph& graph);

	friend ostream& operator << (ostream& out, Graph& graph);

};

Graph::Graph(int vertexNumber_ = 0) {
	vertexNumber = vertexNumber_;
	data.resize(vertexNumber);
}

Graph::Graph(int vertexNumber_, int edgeNumber_, const vector< pair<int, int> >& edges) {
	vertexNumber = vertexNumber_;
	edgeNumber = edgeNumber_;
	data.resize(vertexNumber);
	for (const auto& edge : edges) {
		addEdge(edge.first, edge.second);
	}
}

Graph::~Graph() {
	vertexNumber = 0;
}

int Graph::getVertexNumber() const {
	return vertexNumber;
}

void Graph::dfs(const int& v, const int& parent, vector<bool>& visited, vector<int>& ret) {
	visited[v] = true;
	for (const int& w : data[v]) {
		if (w != parent) {
			dfs(w, v, visited, ret);
		}
	}

	ret.push_back(v);
}

vector<int> Graph::dfs(const int& root) {
	vector<int> ret;
	vector<bool> visited(vertexNumber, false);
	dfs(root, -1, visited, ret);
	return ret;
}

vector<int> Graph::bfs(const int& root) {
	vector<bool> visited(vertexNumber, false);
	vector<int> ret;
	queue<int> Q;
	Q.push(root);
	visited[root] = true;
	while (!Q.empty()) {
		int v = Q.front();
		ret.push_back(v);
		Q.pop();
		for (const int& w : data[v]) {
			if (!visited[w]) {
				visited[w] = true;
				Q.push(w);
			}
		}
	}

	return ret;
}

void Graph::addEdge(const int& x, const int& y) {
	try {
		if (x < 0 || x >= vertexNumber || y < 0 || y >= vertexNumber) {
			out_of_range outException("Node index out of bounds!");
			throw outException;
		}
		data[x].push_back(y);
		data[y].push_back(x);
	}

	catch (out_of_range& exception) {
		cout << exception.what() << "\n";
	}
}

void Graph::readData(istream& in) {
	in >> vertexNumber >> edgeNumber;
	data.clear();
	data.resize(vertexNumber);
	int a, b;
	for (int i = 0; i < edgeNumber; i++) {
		in >> a >> b;
		a--, b--;
		addEdge(a, b);
	}
}

void Graph::writeData(ostream& out) {
	out << vertexNumber << " " << edgeNumber << "\n";
	for (int v = 0; v < vertexNumber; v++) {
		for (const int& w : data[v]) {
			if (v < w) {
				out << v << " " << w << "\n";
			}
		}
	}
}

bool Graph::isConnected() {
	vector<int> nodes = bfs(0);
	return (int)nodes.size() == vertexNumber;
}

istream& operator >> (istream& in, Graph& graph) {
	graph.readData(in);
	return in;
}

ostream& operator << (ostream& out, Graph& graph) {
	graph.writeData(out);
	return out;
}


vector<int> Graph::getCriticalNodes() {
	vector<int> criticalNodes;
	if (vertexNumber == 0)
		return criticalNodes;

	vector<bool> visited(vertexNumber, false), isCriticalNode(vertexNumber, false);
	vector<int> parent(vertexNumber, -1),
		depth(vertexNumber, numeric_limits<int>::max()),
		minSDepth(vertexNumber, numeric_limits<int>::max());

	vector< vector<int>::iterator > nextNode(vertexNumber);
	const int root = 0;
	stack<int> s;
	s.push(root);
	depth[root] = 0;

	while (!s.empty()){
		int x = s.top();
		s.pop();
		if (!visited[x]){
			visited[x] = true;
			minSDepth[x] = depth[x];
			nextNode[x] = begin(data[x]);
		} else {
			auto y = *(nextNode[x]++);
			if (minSDepth[y] >= depth[x] && !isCriticalNode[x]){
				isCriticalNode[x] = true;
			}
			minSDepth[x] = min(minSDepth[x], minSDepth[y]);
		}

		for (auto& it = nextNode[x]; it != end(data[x]); it++) {
			auto& y = *it;
			if (visited[y]) {
				if (parent[x] != y)
					minSDepth[x] = min(minSDepth[x], depth[y]);
			} else {
				s.push(x);
				s.push(y);
				parent[y] = x;
				depth[y] = depth[x] + 1;
				break;
			}
		}
	}

	int rootSons = 0;
	for (auto& y : data[root]) {
		if (parent[y] == root) {
			++rootSons;
		}
	}

	if (rootSons >= 2)
		isCriticalNode[root] = 1;

	for (int v = 0; v < vertexNumber; v++) {
		if (isCriticalNode[v]) {
			criticalNodes.push_back(v);
		}
	}

	return criticalNodes;
}

vector< vector<int> > Graph::getBiconnectedComponents() {
	vector<vector<int> > components;
	if (vertexNumber == 0)
		return components;

	vector<bool> visited(vertexNumber, false);
	vector<int> parent(vertexNumber, -1),
		depth(vertexNumber, numeric_limits<int>::max()),
		minSDepth(vertexNumber, numeric_limits<int>::max());

	vector< vector<int>::iterator > nextNode(vertexNumber);
	const int root = 0;
	stack<int> s;
	stack< pair<int, int> > edgeStack;
	s.push(root);
	depth[root] = 0;

	while (!s.empty()){
		int x = s.top();
		s.pop();
		if (!visited[x]){
			visited[x] = true;
			minSDepth[x] = depth[x];
			nextNode[x] = begin(data[x]);
		} else {
			auto y = *(nextNode[x]++);
			pair<int, int> edge;
			minSDepth[x] = min(minSDepth[x], minSDepth[y]);
			if (minSDepth[y] >= depth[x]) {
				components.push_back(vector<int>());
				do {
					edge = edgeStack.top();
					edgeStack.pop();
					components.back().push_back(edge.first);
					components.back().push_back(edge.second);
				} while (x != edge.first || y != edge.second);
			}
		}

		for (auto& it = nextNode[x]; it != end(data[x]); it++) {
			auto& y = *it;
			if (visited[y]) {
				if (parent[x] != y)
					minSDepth[x] = min(minSDepth[x], depth[y]);
			} else {
				s.push(x);
				s.push(y);
				edgeStack.push({ x, y });
				parent[y] = x;
				depth[y] = depth[x] + 1;
				break;
			}
		}
	}

	for (auto& component : components) {
		sort(component.begin(), component.end());
		component.erase(unique(component.begin(), component.end()), component.end());
	}

	return components;
}