#include "Graf.h"



Graf::Graf(int n)
{
	ilosc = n;
	gestosc = 0;

	G = new dane * [n];
	odleglosc = new int*[n]; //odleglosc[n][0] odleglosc, odleglosc[n][1] poprzednik


	for (int i = 0; i < n; i++)
	{
		odleglosc[i] = new int[2];
	}
	
	stos = new int[n];
	
	przepisany = new bool[n];

	for (int i = 0; i < n; i++)
	{
		odleglosc[i][0] = MAXINT;
		odleglosc[i][1] = -1;
		przepisany[i] = false;
		G[i] = NULL;
	}

}

void Graf::generuj(int gest)
{
	int o = 0, k;
	dane *pw;

	srand((int)time(0));
	while (o < (ilosc * (ilosc - 1) * gest / 100))
	{
		int l = rand() % ilosc;
		pw = new dane;
		k = rand() % ilosc;
		if (k != l)
		{
			pw->cel = l;
			pw->waga = rand() % 100 + 1;
			pw->nast = G[k];
			G[k] = pw;
			o++;
		}
	}
}


void Graf::wypisz()
{
	int wskStos=0;

	for (int i = 0; i < ilosc; i++)
	{
		cout << i << ": ";
		for (int j = i; j > -1; j = odleglosc[j][1])
			stos[wskStos++] = j;
		while (wskStos)
			cout << stos[--wskStos] << " ";
		cout << "$" << odleglosc[i][0] << endl;
	}
}

void Graf::zapisz()
{
	ofstream zapis;
	zapis.open("Graf_gotowy.txt");
	int wskStos = 0;

	for (int i = 0; i < ilosc; i++)
	{
		zapis << i << ": ";
		for (int j = i; j > -1; j = odleglosc[j][1])
			stos[wskStos++] = j;
		while (wskStos)
			zapis << stos[--wskStos] << " ";
		zapis << "$" << odleglosc[i][0] << endl;
	}
}

void Graf::wczytaj(ifstream& plik)
{
	int x, y, z;
	dane* wsk;
	for (int i = 0; i < ilosc; i++)
	{
		plik >> x >> y >> z;
		wsk = new dane;
		wsk->cel = y;
		wsk->waga = z;
		wsk->nast = G[x];
		G[x] = wsk;
	}
}

Graf::~Graf()
{

}

/*void Graf::Dijk()
{

}*/