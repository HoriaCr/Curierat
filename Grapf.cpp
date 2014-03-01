#include "Graf.h"




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