#include "Graph.h"

class DirectedGraph : public Graph
{

	public:

		virtual	void addEdge(const int& x, const int& y);

		vector<int> getTopologicalSort();
		
		vector< vector<int> > getSCC();
};

vector<int> DirectedGraph::getTopologicalSort() {
	vector<int> sortedOrder;

	vector <bool> visited(vertexNumber, false);

	vector< vector<int>::iterator > nextNode(vertexNumber);

	stack<int> s;
	

	for (int i = 0; i < vertexNumber; i++) {
		if (!visited[i]) {
			int v = i;
			s.push(v);
			while (!s.empty()) {
				v = s.top();
				if (!visited[v]) {
					visited[v] = true;
					nextNode[v] = begin(data[v]);
				}
			
				bool allDone = true;

				while (allDone && nextNode[v] != end(data[v])) {
					auto w = *(nextNode[v]++);
					if (!visited[w]) {
						s.push(w);
						allDone = false;
					} 
				}

				if (allDone) {
					sortedOrder.push_back(v);
					s.pop();
				} 
			}
		}
	}

	reverse(begin(sortedOrder), end(sortedOrder));
	return sortedOrder;
}


vector< vector<int> > DirectedGraph::getSCC() {
	vector<vector<int> > components;
	if (vertexNumber == 0)
		return components;

	vector<bool> inStack(vertexNumber, false);
	vector< vector<int>::iterator > nextNode(vertexNumber);

	vector<int> inTime(vertexNumber, -1),
		lowlink(vertexNumber, -1), 
		who(vertexNumber, -1);


	stack<int> dfsStack, S;

	int indexCount = 0;
	for (int i = 0; i < vertexNumber; i++) {
		if (inTime[i] != -1) continue;
		dfsStack.push(i);
		while (!dfsStack.empty()) {
			int v = dfsStack.top();
			if (inTime[v] == -1) {
				S.push(v);
				inStack[v] = true;
				inTime[v] = lowlink[v] = indexCount++;
				nextNode[v] = begin(data[v]);
			} else 
			if (who[v] != -1) {
				auto& w = who[v];
				if (inStack[w])
					lowlink[v] = min(lowlink[v], lowlink[w]);
			}

			bool allDone = true;

			while (allDone && nextNode[v] != end(data[v])) {
				auto w = *(nextNode[v]++);
				if (inStack[w])
					lowlink[v] = min(lowlink[v], lowlink[w]);
				else
				if (allDone && inTime[w] == -1) {
					dfsStack.push(w);
					who[v] = w;
					allDone = false;
				}
			}


			if (allDone) {
				if (inTime[v] == lowlink[v]) {
					components.push_back(vector<int>());
					int w;
					do {
						w = S.top();
						inStack[w] = false;
						components.back().push_back(w);
						S.pop();
					} while (w != v);
				}
				dfsStack.pop();
			}
		}
	}

	return components;
}




void  DirectedGraph::addEdge(const int& x, const int& y) {
	data[x].push_back(y);
}
