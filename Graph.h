#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

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
        
        virtual ~Graph();

		int getVertexNumber() const;

		virtual void addEdge(const int&x, const int& y);

		vector<int> dfs(const int& root);

		vector<int> bfs(const int& root);

		friend istream& operator >> (istream& in, Graph& graph);

		friend ostream& operator << (ostream& out, Graph& graph);

};

Graph::Graph(int vertexNumber_ = 0) {
	vertexNumber = vertexNumber_;
	data.resize(vertexNumber);
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
	int a, b;
	for (int i = 0; i < edgeNumber; i++) {
		cin >> a >> b;
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

istream& operator >> (istream& in, Graph& graph) {
	graph.readData(in);
	return in;
}

ostream& operator << (ostream& out, Graph& graph) {
	graph.writeData(out);
	return out;
}
