#include "Graph.h"

class GraphOrientat : public Graph
{

public:

	virtual	void addEdge(const int& x, const int& y);

};


void GraphOrientat::addEdge(const int& x, const int& y) {
	data[x].push_back(y);
}