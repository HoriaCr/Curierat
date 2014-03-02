#include "Graf.h"

class GrafOrientat : public Graf
{

public:

	virtual	void adaugaMuchie(const int& x, const int& y);

};


void GrafOrientat::adaugaMuchie(const int& x, const int& y) {
	data[x].push_back(y);
}