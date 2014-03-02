#pragma once

template<class PositionType>
class Vehicul
{
	protected:


		PositionType pozitie;

		double kilometraj;
		float vitezaMedie;
		int volumMaxim;
		int greutateMaxima;
		int capacitateRezervor;
		float combustibilCurent;
		int valoareInitiala;

		int greutateCurenta;
		int volumCurent;
		int uzura;

		bool operational;


	public:

		Vehicul(PositionType pozitie_,
			double kilometraj_,
			float vitezaMedie_,
			int volumMaxim_,
			int greutateMaxima_,
			int capacitateRezervor_,
			float combustibilCurent_,
			int valoareInitiala_
			);

		virtual double valoareCurenta() = 0;

		virtual double consumCombustibil(const double& distanta) = 0;

		virtual void update() = 0;


};



template<class PositionType>
Vehicul<PositionType>::Vehicul(PositionType pozitie_,
	double kilometraj_,
	float vitezaMedie_,
	int volumMaxim_,
	int greutateMaxima_,
	int capacitateRezervor_,
	float combustibilCurent_,
	int valoareInitiala_
	) {
	pozitie = pozitie_;
	kilometraj = kilometraj_;
	vitezaMedie = vitezaMedie_;
	volumMaxim = volumMaxim_;
	greutateMaxima = greutateMaxima_;
	capacitateRezervor = capacitateRezervor_;
	combustibilCurent = combustibilCurent_;
	valoareInitiala = valoareInitiala_;

	greutateCurenta = 0;
	volumCurent = 0;
	uzura = 0;
	operational = true;


}