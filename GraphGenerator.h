#include <iostream>
#include "Graph.h"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <functional>
#include <set>

using namespace std;


class GraphGenerator {
    
    public:
        
        GraphGenerator() {
             srand(static_cast<unsigned int>(time(0)));
        }

        tuple<int,int,vector< pair<int,int> > > UndirectedSparseGraph(int vertexNumber_ = 10) {
            int vertexNumber = vertexNumber_;
            int edgeNumber = min(vertexNumber * (vertexNumber - 1) / 2,2 * vertexNumber);
            set< pair<int,int> > edges_;
            for (int i = 0; i < edgeNumber; i++) {
                int a = rand() % vertexNumber;
                int b = rand() % vertexNumber;
				if (a == b) continue;
				if (a > b) swap(a, b);
				edges_.insert( {a, b} );
             
            }

            vector< pair<int,int> > edges(edges_.begin(),edges_.end());
            edgeNumber = static_cast<int>(edges.size());
            return make_tuple (vertexNumber,edgeNumber,edges); 
        }
        
        static void example() {
			GraphGenerator gen;
			for (int t = 1;t <= 5;t++) {
				int n, m;
				vector< pair<int,int> > e;
				tie(n, m, e) = gen.UndirectedSparseGraph();
				Graph graph(n, m, e);
				cout << graph.isConnected() << "\n";
			} 
		}

};
