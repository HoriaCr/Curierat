#include <vector>
#include "Avion.h"
#include "Camion.h"
#include "Duba.h"
#include "Masina.h"
#include "Scuter.h"


using namespace std;


template<class PositionType>
class Firma
{
	private:

		Vehicul< PositionType > *flotaVehicule;

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
	
	flotaVehicule<PositionType> = new Vehicul<PositionType>[numarVehicule];

	for (int i = 0; i < numarAvioane; i++) {
		flotaVehicule[i] = new Avion<int>();
	}

	for (int i = 0; i < numarCamioane; i++ + ) {
		flotaVehicule[i + numarAvioane] = new Camion<int>();
	}

	for (int i = 0; i < numarDube; i++ + ) {
		flotaVehicule[i + numarAvioane + numarCamioane] = new Duba<int>();
	}

	for (int i = 0; i < numarMasini; i++ + ) {
		flotaVehicule[i + numarAvioane + numarCamioane + numarDube] = new Masina<int>();
	}

	for (int i = 0; i < numarScutere; i++ + ) {
		flotaVehicule[i + numarAvioane + numarCamioane + numarDube + numarMasini] = new Masina<int>();
	}

}


template<class PositionType>
Firma<PositionType>::~Firma() {
	delete[] flotaVehicule;

}