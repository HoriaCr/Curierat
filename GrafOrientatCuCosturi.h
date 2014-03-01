#include "GrafOrientat.h"

template<class DataType = int>
class GrafOrientatCuCosturi : public GrafOrientat
{
	
	protected:
		vector< vector< DataType> > cost;


	public:

		//GrafOrientatCuCosturi();

		GrafOrientatCuCosturi(const int& numarNoduri_ = 0, const int& numarMuchii_ = 0, const vector< pair<int, DataType> >& muchii = {});

		void adaugaMuchie(const int& x, const int& y, const DataType& costMuchie);

};