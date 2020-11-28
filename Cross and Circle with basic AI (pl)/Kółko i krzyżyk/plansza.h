#pragma once
#include <iostream>

using namespace std;

class plansza
{
	int** pola;

public:
	plansza(int wlk,int wym);
	~plansza();
	void operator =(plansza przepisywana);
	int wygrana();
	void wyswietl();
	void dodaj(int znak, int wiersz, int kolumna);
	
	bool czypuste(int w, int k);

	int wielkosc;
	int wymog;
};

