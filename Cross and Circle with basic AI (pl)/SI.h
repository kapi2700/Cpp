#pragma once

#include "plansza.h"
#include <vector>


struct ruch
{
	ruch() {};
	ruch(int p) :pkt(p) {};

	int wiersz;
	int kolumna;
	int pkt;
};


class SI
{
	ruch najlepszyRuch(plansza& gra, int gracz);
public:
	void mv(plansza& gra);
	ruch najlepszyRuchOpt(plansza& gra, int gracz,int max);
	void mvOpt(plansza& gra);
};

