#include "GrafOrientat.h"


template<class DataType>
class GrafOrientatCuCosturi : public GrafOrientat
{
	
	protected:
		vector< vector< int> > cost;


	public:

	
		GrafOrientatCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0,
			const vector< pair< pair<int, int>, DataType> >& muchii = {}) {
			numarNoduri = numarNoduri_;
			numarMuchii = numarMuchii_;
			for (const auto& muchie : muchii) {
				//adaugaMuchie(muchie.first.first, muchie.first.second, muchie.second);
			}
		}

		void adaugaMuchie(const int& x, const int& y, const DataType& costMuchie);

};