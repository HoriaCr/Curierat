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
		double valoareInitiala;

		int greutateCurenta;
		int volumCurent;
		int uzura;

		bool operational;


	public:

		Vehicul(PositionType pozitie_ = PositionType(),
			double kilometraj_ = 0.0,
			float vitezaMedie_ = 0.0,
			int volumMaxim_ = 0,
			int greutateMaxima_ = 0,
			int capacitateRezervor_ = 0,
			float combustibilCurent_ = 0.0,
			double valoareInitiala_ = 0.0
			);

		virtual double valoareCurenta() { return 0.0;  }

		virtual double consumCombustibil(const double& distanta) { return 0.0; }

		virtual void update() {}

		int getUzura();

};
template<class PositionType>
int Vehicul<PositionType>::getUzura() {
	return uzura;
}


template<class PositionType>
Vehicul<PositionType>::Vehicul(PositionType pozitie_,
	double kilometraj_,
	float vitezaMedie_,
	int volumMaxim_,
	int greutateMaxima_,
	int capacitateRezervor_,
	float combustibilCurent_,
	double valoareInitiala_
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