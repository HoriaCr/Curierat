#include <complex>

using namespace std;

class Vehicul
{
	protected:

		int kilometraj;
		int vitezaMedie;
		int volumMaxima;
		int greutateMaxima;
		int capacitateRezervor;

		int greutateCurenta;
		int volumCurent;
		int combustibilCurent;
		int valoareInitiala;

		int uzura;
		bool operational;


	public:


		virtual int valoareCurenta();

		virtual int costCombustibil();
	


};