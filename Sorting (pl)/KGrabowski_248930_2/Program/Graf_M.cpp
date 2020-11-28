#include "Graf_M.h"

Graf_M::Graf_M(int n) :Graf(n)
{

}

void Graf_M::Dijk(int st)
{
	dane* pw, *rw;
	int j, u;

	pw = new dane;

	odleglosc[st][0] = 0;

	for (int i = 0; i < ilosc; i++)
	{
		for (j = 0; przepisany[j]; j++);
		for (u = j++; j < ilosc; j++)
			if (!przepisany[j] && (odleglosc[j][0] < odleglosc[u][0]))
				u = j;
		przepisany[u] = true;
		for (pw = G[u]; pw; pw = pw->nast)
		{
			if (!przepisany[pw->cel] && (odleglosc[pw->cel][0] > odleglosc[u][0] + pw->waga))
			{
				odleglosc[pw->cel][0] = odleglosc[u][0] + pw->waga;
				odleglosc[pw->cel][1] = u;
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



void Graf_M::Dijk(int st,int ko)
{
	dane* pw, *rw;
	int j, u;

	pw = new dane;

	odleglosc[st][0] = 0;

	for (int i = 0; i < ilosc; i++)
	{
		if (odleglosc[ko][0] < 2147483647)
		{
			return;
		}

		for (j = 0; przepisany[j]; j++);
		for (u = j++; j < ilosc; j++)
			if (!przepisany[j] && (odleglosc[j][0] < odleglosc[u][0]))
				u = j;
		przepisany[u] = true;

		for (pw = G[u]; pw; pw = pw->nast)
		{
			if (!przepisany[pw->cel] && (odleglosc[pw->cel][0] > odleglosc[u][0] + pw->waga))
			{
				odleglosc[pw->cel][0] = odleglosc[u][0] + pw->waga;
				odleglosc[pw->cel][1] = u;
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


Graf_M::~Graf_M()
{

}