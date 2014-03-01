

template<class PositionType>
class Vehicul
{
	protected:


		PositionType pozitie;

		int kilometraj;
		int vitezaMedie;
		int volumMaxima;
		int greutateMaxima;
		int capacitateRezervor;
		int combustibilCurent;
		int valoareInitiala;

		int greutateCurenta;
		int volumCurent;
		int uzura;

		bool operational;


	public:

		Vehicul(PositionType pozitie_,
			int kilometraj_,
			int vitezaMedie_,
			int volumMaxima_,
			int greutateMaxima_,
			int capacitateRezervor_,
			int combustibilCurent_,
			int valoareInitiala_
			);

		virtual int valoareCurenta() = 0;

		virtual int consumCombustibil() = 0;


};



template<class PositionType>
Vehicul<PositionType>::Vehicul(PositionType pozitie_,
	int kilometraj_,
	int vitezaMedie_,
	int volumMaxima_,
	int greutateMaxima_,
	int capacitateRezervor_,
	int combustibilCurent_,
	int valoareInitiala_
	) {
	pozitie = pozitie_;
	kilometraj = kilometraj_;
	vitezaMedie = vitezaMedie_;
	volumMaxima = volumMaxima_;
	greutateMaxima = greutateMaxima_;
	capacitateRezervor = capacitateRezervor_;
	combustibilCurent = combustibilCurent_;
	valoareInitiala = valoareInitiala_;

	greutateCurenta = 0;
	volumCurent = 0;
	uzura = 0;
	operational = true;


}