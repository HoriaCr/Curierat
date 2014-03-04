#include "WeightedGraph.h"
#include "DirectedGraph.h"


template<class DataType>
class WeightedDirectedGraph : public WeightedGraph
{
	public:

		WeightedDirectedGraph(const int& vertexNumber_ = 0, const int& edgeNumber_ = 0,
						      const vector< pair< pair<int, int>, DataType> >& muchii = {});

		void addEdge(const int& x, const int& y, const DataType& costMuchie);

};


template<class DataType>
WeightedDirectedGraph<DataType>::WeightedDirectedGraph(const int& vertexNumber_ = 0, const int& edgeNumber_ = 0,const vector< pair< pair<int, int>, DataType> >& muchii = {}) {
		vertexNumber = vertexNumber_;
		edgeNumber = edgeNumber_;
		for (const auto& muchie : muchii) {
			addEdge(muchie.first.first, muchie.first.second, muchie.second);
		}
}

template<class DataType>
void WeightedDirectedGraph<DataType>::addEdge(const int& x, const int& y, const DataType& costMuchie) {
	data[x].push_back(y);
	cost[x].push_back(costMuchie);
}