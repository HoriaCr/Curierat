#include "Graph.h"

class GraphOrientat : public Graph
{

public:

	virtual	void adaugaMuchie(const int& x, const int& y);

};


void GraphOrientat::adaugaMuchie(const int& x, const int& y) {
	data[x].push_back(y);
}