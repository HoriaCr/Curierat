#include "Graf.h"


void Graf::dfs(const int& v, const int& parent, vector<bool>& visited, vector<int>& ret) {
	visited[v] = true;
	for (const int& w : data[v]) {
		if (w != parent) {
			dfs(w, v, visited, ret);
		}
	}

	ret.push_back(v);
}

vector<int> Graf::dfs(const int& root) {
	vector<int> ret;
	vector<bool> visited(numarNoduri, false);
	dfs(root, -1, visited, ret);
	return ret;
}


vector<int> Graf::bfs(const int& root) {
	vector<bool> visited(numarNoduri, false);
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