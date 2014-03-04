#include "Graph.h"

class DirectedGraph : public Graph
{

	public:

		virtual	void addEdge(const int& x, const int& y);

};


void  DirectedGraph::addEdge(const int& x, const int& y) {
	data[x].push_back(y);
}