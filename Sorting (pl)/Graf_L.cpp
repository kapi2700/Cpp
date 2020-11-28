#include "Graf_L.h"

Graf_L::Graf_L(int n):Graf(n)
{
	int i = 0;

	kopiec = new int*[n]; //kopiec[n][0] wartosc, kopiec[n][1] pozycja
	
	for (i = 0; i < n; i++)
		kopiec[i] = new int[2];

	for (i = 0; i < n; i++)
		kopiec[i][0] = kopiec[i][1] = i;
	dlugoscKopca = i;
}

void Graf_L::Dijk(int st)
{
	
	int u = 0, pom, rod, lew, pra, dmniejszy,pmniejszy,dziecko;
	dane* pw, * rw;

	odleglosc[st][0] = 0;
	cout << "tutaj!";

	pom = kopiec[0][0];
	kopiec[0][0] = kopiec[st][0];
	kopiec[st][0] = pom;

	kopiec[st][1] = 0;
	kopiec[0][1] = st;

	for (int i = 0; i < ilosc; i++)
	{
		u = kopiec[0][0];

		kopiec[0][0] = kopiec[--dlugoscKopca][0];
		kopiec[kopiec[0][0]][1] = rod = 0;
		while (1)
		{
			lew = rod + rod + 1;
			pra = lew + 1;
			if (lew >= dlugoscKopca)
				break;

			dmniejszy = odleglosc[kopiec[lew][0]][0];
			pmniejszy = lew;
			if ((pra < dlugoscKopca) && (dmniejszy > odleglosc[kopiec[pra][0]][0]))
			{
				dmniejszy = odleglosc[kopiec[pra][0]][0];
				pmniejszy = pra;
			}
			if (odleglosc[kopiec[rod][0]][0] <= dmniejszy)
				break;
			
			
			pom = kopiec[rod][0];
			kopiec[rod][0] = kopiec[pmniejszy][0];
			kopiec[pmniejszy][0] = pom;

			kopiec[kopiec[rod][0]][1] = rod;
			kopiec[kopiec[pmniejszy][0]][1] = pmniejszy;
			rod = pmniejszy;
		}
		przepisany[u] = true;

		for (pw = G[u]; pw; pw = pw->nast)
		{
			if (!przepisany[pw->cel] && (odleglosc[pw->cel][0] > (odleglosc[u][0] + pw->waga)))
			{
				odleglosc[pw->cel][0] = odleglosc[u][0] + pw->waga;
				odleglosc[pw->cel][1] = u;

				for (dziecko = kopiec[pw->cel][1]; dziecko; dziecko = rod)
				{
					rod = dziecko / 2;
					
					if (odleglosc[kopiec[rod][0]][0] <= odleglosc[kopiec[dziecko][0]][0])
						break;

					pom = kopiec[rod][0];
					kopiec[rod][0] = kopiec[dziecko][0];
					kopiec[dziecko][0] = pom;

					kopiec[kopiec[rod][0]][1] = rod;
					kopiec[kopiec[dziecko][0]][1] = dziecko;
				}
			}
		}
	}

	for (int i = 0; i < ilosc; i++)
	{
		pw = G[i];
		while (pw)
		{
			rw = pw;
			pw = pw->nast;
			delete rw;
		}
	}
}


void Graf_L::Dijk(int st,int ko)
{

	int u = 0, pom, rod, lew, pra, dmniejszy, pmniejszy, dziecko;
	dane* pw, * rw;

	odleglosc[st][0] = 0;

	pom = kopiec[0][0];
	kopiec[0][0] = kopiec[st][0];
	kopiec[st][0] = pom;

	kopiec[st][1] = 0;
	kopiec[0][1] = st;

	for (int i = 0; i < ilosc; i++)
	{
		u = kopiec[0][0];

		kopiec[0][0] = kopiec[--dlugoscKopca][0];
		kopiec[kopiec[0][0]][1] = rod = 0;
		while (1)
		{
			lew = rod + rod + 1;
			pra = lew + 1;
			if (lew >= dlugoscKopca)
				break;

			dmniejszy = odleglosc[kopiec[lew][0]][0];
			pmniejszy = lew;
			if ((pra < dlugoscKopca) && (dmniejszy > odleglosc[kopiec[pra][0]][0]))
			{
				dmniejszy = odleglosc[kopiec[pra][0]][0];
				pmniejszy = pra;
			}
			if (odleglosc[kopiec[rod][0]][0] <= dmniejszy)
				break;


			pom = kopiec[rod][0];
			kopiec[rod][0] = kopiec[pmniejszy][0];
			kopiec[pmniejszy][0] = pom;

			kopiec[kopiec[rod][0]][1] = rod;
			kopiec[kopiec[pmniejszy][0]][1] = pmniejszy;
			rod = pmniejszy;
		}
		przepisany[u] = true;

		for (pw = G[u]; pw; pw = pw->nast)
		{
			if (!przepisany[pw->cel] && (odleglosc[pw->cel][0] > odleglosc[u][0] + pw->waga))
			{
				odleglosc[pw->cel][0] = odleglosc[u][0] + pw->waga;
				odleglosc[pw->cel][1] = u;

				for (dziecko = kopiec[pw->cel][1]; dziecko; dziecko = rod)
				{
					rod = dziecko / 2;

					if (odleglosc[kopiec[rod][0]][0] <= odleglosc[kopiec[dziecko][0]][0])
						break;

					pom = kopiec[rod][0];
					kopiec[rod][0] = kopiec[dziecko][0];
					kopiec[dziecko][0] = pom;

					kopiec[kopiec[rod][0]][1] = rod;
					kopiec[kopiec[dziecko][0]][1] = dziecko;
				}
			}
			if (pw->cel == ko)
			{
				return;
			}
		}
	}

	for (int i = 0; i < ilosc; i++)
	{
		pw = G[i];
		while (pw)
		{
			rw = pw;
			pw = pw->nast;
			delete rw;
		}
	}
}


Graf_L::~Graf_L()
{
	for (int i = 0; i < ilosc; i++)
		delete kopiec[i];

	delete kopiec;
}
