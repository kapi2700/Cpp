#pragma once
#include <iostream>
#include "dane.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>

using namespace std;

#define MAXINT 2147483647;

class Graf
{
public:
	dane** G; //Graf z danymi wejsciowymi
	int** odleglosc; //tabela odleglosci z poprzednikami
	int* stos; //stos
	bool* przepisany; //czy zostalo juz przepisane z G
	int ilosc; //ilosc danych
	int gestosc; //gestosc
	Graf(int n); //ustawia wielkosc grafu
	void generuj(int gest); //generuje G
	void wypisz(); //wypisuje gotowy Graf
	void zapisz(); //Zapisuje gotowy Graf do pliku "Graf_gotowy.txt"
	void wczytaj(ifstream& plik); //Wczytuje krawedzie z pliku
	virtual void Dijk(int st) {}
	~Graf();
};

