#include "SI.h"


int z = 0;

ruch SI::najlepszyRuch(plansza& gra,int gracz)
{
	int win = gra.wygrana();

	if (win == 1)
		return ruch(10);
	else if (win == 2)
		return ruch(-10);
	else if (win == -1)
		return ruch(0);

	std::vector<ruch> mozliwosci;

	for (int i = 0; i < gra.wielkosc; i++)
	{
		for (int j = 0; j < gra.wielkosc; j++)
		{
			if (gra.czypuste(i, j))
			{
				ruch ruch;
				ruch.wiersz = i;
				ruch.kolumna = j;

				gra.dodaj(gracz, i, j);

				if (gracz == 1)
				{
					ruch.pkt = najlepszyRuch(gra, 2).pkt;
				}
				else
				{
					ruch.pkt = najlepszyRuch(gra, 1).pkt;
				}

				mozliwosci.push_back(ruch);
				gra.dodaj(0, i, j);
			}
		}
	}
	int naj = 0;


	if (gracz == 1)
	{
		int najP = -10000;
		for (int i = 0; i < mozliwosci.size(); i++)
		{
			if (mozliwosci[i].pkt > najP)
			{
				naj = i;
				najP = mozliwosci[i].pkt;
			}
		}
	}
	else
	{
		int najP = 10000;
		for (int i = 0; i < mozliwosci.size(); i++)
		{
			if (mozliwosci[i].pkt < najP)
			{
				naj = i;
				najP = mozliwosci[i].pkt;
			}
		}
	}

	return mozliwosci[naj];

}

void SI::mv(plansza& gra)
{
	ruch najlepszy = najlepszyRuch(gra, 1);

	gra.dodaj(1, najlepszy.wiersz, najlepszy.kolumna);
}

void SI::mvOpt(plansza& gra)
{
	ruch najlepszy = najlepszyRuchOpt(gra, 1, -1000);

	gra.dodaj(1, najlepszy.wiersz, najlepszy.kolumna);
}

ruch SI::najlepszyRuchOpt(plansza& gra, int gracz,int max)
{
	if (max == 0)
		return ruch(0);


	int win = gra.wygrana();
	if (win == 1)
		return ruch(10);
	else if (win == 2)
		return ruch(-10);
	else if (win == -1)
		return ruch(0);

	std::vector<ruch> mozliwosci;

	for (int i = 0; i < gra.wielkosc; i++)
	{
		for (int j = 0; j < gra.wielkosc; j++)
		{
			if (gra.czypuste(i, j))
			{
				ruch ruch;
				ruch.wiersz = i;
				ruch.kolumna = j;

				gra.dodaj(gracz, i, j);

				if (gracz == 1)
				{
					ruch.pkt = najlepszyRuchOpt(gra, 2,max-1).pkt;
				}
				else
				{
					ruch.pkt = najlepszyRuchOpt(gra, 1,max-1).pkt;
				}

				mozliwosci.push_back(ruch);
				gra.dodaj(0, i, j);
			}
		}
	}
	int naj = 0;


	if (gracz == 1)
	{
		int najP = -10000;
		for (int i = 0; i < mozliwosci.size(); i++)
		{
			if (mozliwosci[i].pkt > najP)
			{
				naj = i;
				najP = mozliwosci[i].pkt;
			}
		}
	}
	else
	{
		int najP = 10000;
		for (int i = 0; i < mozliwosci.size(); i++)
		{
			if (mozliwosci[i].pkt < najP)
			{
				naj = i;
				najP = mozliwosci[i].pkt;
			}
		}
	}

	return mozliwosci[naj];

}