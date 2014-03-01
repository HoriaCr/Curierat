#include "GrafNeorientat.h"

void GrafNeorientat::adaugaMuchie(const int& x, const int& y) {
	data[x].push_back(y);
	data[y].push_back(x);
}