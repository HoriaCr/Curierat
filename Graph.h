#include <vector>
#include <queue>

#pragma once

using namespace std;

class Graph
{

	protected:
	
		int vertexNumber;
		int edgeNumber;
		vector< vector<int> > data;

		void dfs(const int& v, const int& parent, vector<bool>& visited, vector<int>& ret);
	

	
	public:

		Graph(int vertexNumber_);

		int getVertexNumber() const;

		virtual void addEdge(const int&x, const int& y);

		friend istream& operator >> (istream& in, Graph& G);
	
		vector<int> dfs(const int& root);

		vector<int> bfs(const int& root);

};

Graph::Graph(int vertexNumber_ = 0) {
	vertexNumber = vertexNumber_;
	data.resize(vertexNumber);
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
	data[x].push_back(y);
	data[y].push_back(x);
}