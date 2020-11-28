#pragma once
#include "Graf.h"

class Graf_M :
	public Graf					//Klasu grafu, dzialajaca na podstawie macierzy
{
public:
	Graf_M(int n);				//Konstruktor, n-ilosc wierzcholkow
	virtual void Dijk(int st);	//Algorytm Dijkstry st- poczatek grafu
	void Dijk(int st, int ko);	//Algorytm Dijkstry st- poczatek grafu ko- koniec grafu
	~Graf_M();
};

