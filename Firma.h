#include <vector>
#include <queue>
#include "Avion.h"
#include "Camion.h"
#include "Duba.h"
#include "Masina.h"
#include "Scuter.h"
#include "Comanda.h"


using namespace std;


template<class PositionType>
class Firma
{
	private:

		vector< Vehicul<PositionType>*>  flotaVehicule;
		queue< Comanda<PositionType> > coada;

		double balantaBani;
		double salariuOraSofer;
		double salariuOraMuncitor;
		double salariuOraManager;

		int numarCamioane;
		int numarAvioane;
		int numarScutere;
		int numarDube;
		int numarMasini;
		int numarVehicule;

		int soferi;
		int muncitori;
		int manageri;

		int comenziReusite;
		int comenziEsuate;
		int totalAngajati;

		int tipStrategie;
	


	public:
	
	Firma(
		double balantaBani_,
		double salariuOraSofer_,
		double salariuOraMuncitor_,
		double salariuOraManager_,
		int numarCamioane_,
		int numarAvioane_,
		int numarScutere_,
		int numarDube_,
		int numarMasini_,
		int soferi_,
		int muncitori_,
		int manageri_);


		~Firma();

		double costuri();

		double venituri();

		void primesteComanda(const Comanda<PositionType>& comanda);

		void atribuieComenzi();

};



template<class PositionType>
Firma<PositionType>::Firma(double balantaBani_,
	double salariuOraSofer_,
	double salariuOraMuncitor_,
	double salariuOraManager_,
	int numarCamioane_,
	int numarAvioane_,
	int numarScutere_,
	int numarDube_,
	int numarMasini_,
	int soferi_,
	int muncitori_,
	int manageri_
	) {
	balantaBani = balantaBani_;
	salariuOraSofer = salariuOraSofer_;
	salariuOraMuncitor = salariuOraMuncitor_;
	salariuOraManager = salariuOraManager_;
	numarCamioane = numarCamioane_;
	numarAvioane = numarAvioane_;
	numarScutere = numarScutere_;
	numarDube = numarDube_;
	numarMasini = numarMasini_;
	soferi = soferi_;
	muncitori = muncitori_;
	manageri = manageri_;

	numarVehicule = numarAvioane + numarCamioane + numarDube + numarMasini + numarScutere;
	totalAngajati = soferi + muncitori + manageri;
	flotaVehicule.resize(numarVehicule);
	for (int i = 0; i < numarAvioane; i++) {
		flotaVehicule[i] = new Avion<PositionType>();
	}

	for (int i = 0; i < numarCamioane; i++) {
		flotaVehicule[i + numarAvioane] = new Camion<PositionType>();
	}

	for (int i = 0; i < numarDube; i++ ) {
		flotaVehicule[i + numarAvioane + numarCamioane] = new Duba<PositionType>();
	}

	for (int i = 0; i < numarMasini; i++) {
		flotaVehicule[i + numarAvioane + numarCamioane + numarDube] = new Masina<PositionType>();
	}

	for (int i = 0; i < numarScutere; i++) {
		flotaVehicule[i + numarAvioane + numarCamioane + numarDube + numarMasini] = new Scuter<PositionType>();
	}
	
}


template<class PositionType>
Firma<PositionType>::~Firma() {

}


template<class PositionType>
void Firma<PositionType>::primesteComanda(const Comanda<PositionType>& comanda) {
	coada.push(comanda);
}

template<class PositionType>
void Firma<PositionType>::atribuieComenzi() {

}