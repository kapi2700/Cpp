#pragma once
#include "Graf.h"


class Graf_L :
	public Graf						//Klasa grafu dzialajaca na podstawie listy
{
	int** kopiec;					
	int dlugoscKopca;				
public:
	Graf_L(int n);					//Konstruktor, n-ilosc wierzcholkow
	virtual void Dijk(int st);		//Algorytm Dijkstry st- poczatek grafu
	void Dijk(int st, int ko);		//Algorytm Dijkstry st- poczatek grafu ko- koniec grafu
	~Graf_L();
};

