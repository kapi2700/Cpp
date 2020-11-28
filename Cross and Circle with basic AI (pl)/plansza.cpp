#include "plansza.h"


plansza::plansza(int wlk, int wym)
{
	wielkosc = wlk;
	wymog = wym;
	pola = new int*[wlk];
	for (int i = 0; i < wlk; i++)
	{
		pola[i] = new int[wlk];
	}

	for (int i = 0; i < wlk; i++)
		for (int j = 0; j < wlk; j++)
			pola[i][j] = 0;
}

plansza::~plansza()
{
	for (int i = 0; i < wielkosc; i++)
	{
		delete[] pola[i];
	}
	delete[] pola;
}

void plansza::operator =(plansza przepisywana)
{	
	wymog = przepisywana.wymog;
	wielkosc = przepisywana.wielkosc;
	for (int i = 0; i < wielkosc; i++)
	{
		for (int j = 0; j < wielkosc; j++)
		{
			pola[i][j] = przepisywana.pola[i][j];
		}
	}
}



/*
int plansza::wygrana()
{
	int ktory = 0;
	int w = 0;

	for (int i = 0; i < wielkosc; i++) //Sprawdzanie zwyciestwa w pionie
	{
		if (pola[0][i] == 1 || pola[0][i] == 2) {
			ktory = pola[0][i];
			w = 1;
			for (int j = 1; j < wielkosc; j++)
			{
				if (pola[j][i] != ktory)
					break;
				else
					w++;
			}
			if (w == wielkosc)
				return ktory;
		}
	}
	
	for (int i = 0; i < wielkosc; i++) //Sprawdzanie zwyciestwa w poziomie
	{
		if (pola[i][0] == 1 || pola[i][0] == 2)
		{
			ktory = pola[i][0];
			w = 1;
			for (int j = 1; j < wielkosc; j++)
			{
				if (pola[i][j] != ktory)
					break;
				else
					w++;
			}
			if (w == wielkosc)
				return ktory;
		}
	}
	if (pola[0][0] == 1 || pola[0][0] == 2)
	{
		w = 1;
		for (int j = 1; j < wielkosc; j++)
		{
			if (pola[j][j] != ktory)
				break;
			else
				w++;
		}
		if (w == wielkosc)
			return ktory;
	}
	if (pola[wielkosc-1][0] == 1 || pola[wielkosc-1][0] == 2)
	{
		w = 1;
		for (int j = 1; j < wielkosc; j++)
		{
			if (pola[wielkosc-j-1][j] != ktory)
				break;
			else
				w++;
		}
		if (w == wielkosc)
			return ktory;
	}
	return 0;
}
*/


void plansza::wyswietl()
{
	int linia = 0;
	int j = 0;

	cout << "  ";
	for (int i = 0; i < wielkosc; i++)
	{
		if (i >= 10)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << "   ";
	}
	cout << endl;

	for (linia = 1; linia < (wielkosc * 2); linia++)
	{
		if (linia % 2)
		{
			j++;
			if (j >= 10)
				cout << j;
			else
				cout << j << " ";
			for (int k = 0; k < wielkosc; k++)
			{
				cout << " ";
				if (k == (wielkosc - 1))
				{
					switch (pola[j-1][k])
					{
					case 0:
						cout << " ";
						break;
					case 1:
						cout << 'o';
						break;
					case 2:
						cout << 'x';
break;
					}
				}
				else
				{
				switch (pola[j - 1][k])
				{
				case 0:
					cout << " ";
					break;
				case 1:
					cout << 'o';
					break;
				case 2:
					cout << 'x';
					break;
				}
				cout << " |";
				}
			}
		}
		else
		{
		cout << "   ";
		for (int i = 0; i < ((wielkosc - 1) * 2 + 1); i++)
		{
			if (i % 2)
			{
				cout << "+ ";
			}
			else
			{
				cout << "- ";
			}
		}
		}
		cout << endl;
	}
}

void plansza::dodaj(int znak, int wiersz, int kolumna)
{
	pola[wiersz][kolumna] = znak;
}

bool plansza::czypuste(int w, int k)
{
	if (pola[w][k] == 0)
		return true;
	else
		return false;
}


int plansza::wygrana()
{
	int ktory = 0;
	int w = 0;
	
	bool wolne = false;

	for(int i=0; i<wielkosc; i++)
		for (int j = 0; j < wielkosc; j++)
		{
			if (czypuste(i, j))
			{
				wolne = true;
				i = wielkosc;
				j = wielkosc;
			}
		}

	if (!wolne) //remis
		return -1;


	for (int i = 0; i < ((wielkosc - wymog) +1 ); i++)		//Sprawdzanie zwyciestwa w pionie
	{
		for (int j = 0; j < wielkosc; j++)
		{
			if (pola[i][j] == 1 || pola[i][j] == 2)
			{
				ktory = pola[i][j];
				w = 1;
				for (int k = 1 + i; k < wymog; k++)
				{
					if (pola[k][j] != ktory)
						break;
					else
						w++;
				}
				if (w >= wymog)
					return ktory;
			}
		}
	}
	for (int i = 0; i < (wielkosc - wymog+1); i++)		//Sprawdzanie zwyciestwa w poziomie
	{
		for (int j = 0; j < wielkosc; j++)
		{
			if (pola[j][i] == 1 || pola[j][i] == 2)
			{
				ktory = pola[j][i];
				w = 1;
				for (int k = 1 + i; k < wymog; k++)
				{
					if (pola[j][k] != ktory)
						break;
					else
						w++;
				}
				if (w >= wymog)
					return ktory;
			}
		}
	}

	for (int i = 0; i < (wielkosc - wymog+1); i++) //sprawdzanie zwyciestwa na skos w dol
	{
		for (int j = 0; j < (wielkosc - wymog+1); j++)
		{
			if (pola[i][j] == 1 || pola[i][j] == 2)
			{
				ktory = pola[i][j];
				w = 1;
				for (int k = 1; k < wymog; k++)
				{
					if (pola[i + k][j + k] != ktory)
						break;
					else
						w++;
				}
				if (w >= wymog)
					return ktory;
			}
		}
	}

	for (int i = wymog - 1; i < wielkosc; i++) //sprawdzanie zwyciestwa na skos w gore
	{
		for (int j = 0; j < (wielkosc - wymog+1); j++)
		{
			if (pola[i][j] == 1 || pola[i][j] == 2)
			{
				ktory = pola[i][j];
				w = 1;
				for (int k = 1; k < wymog; k++)
				{
					if (pola[i - k][j + k] != ktory)
						break;
					else
						w++;
				}
				if (w >= wymog)
					return ktory;
			}
		}
	}
	return 0;
}