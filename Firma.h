#include <vector>
#include "Vehicul.h"

using namespace std;

class Firma
{
	Vehicul< pair<int,int> > *flotaVehicule;
	double balantaBani;
	int comenziReusite;
	int comenziEsuate;
	int totalAngajati;
	
	int soferi;
	int muncitori;
	int manageri;

	int salariuOraSofer;
	int salariuOraMuncitor;
	int salariuOraManager;

	double comenziPeZi;

public:
	int costuri();

	int venituri();

};