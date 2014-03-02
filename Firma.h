#include <vector>
#include "Vehicul.h"

using namespace std;


template<class PositionType>
class Firma
{
	Vehicul< PositionType > *flotaVehicule;
	double balantaBani;
	double salariuOraSofer;
	double salariuOraMuncitor;
	double salariuOraManager;
	double comenziPeZi;

	int comenziReusite;
	int comenziEsuate;
	int totalAngajati;
	
	int soferi;
	int muncitori;
	int manageri;




public:

	double costuri();

	double venituri();

};