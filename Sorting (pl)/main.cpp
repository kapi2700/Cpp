#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <ratio>
#include <chrono>
#include <iomanip>

#include "Graf_L.h"
#include "Graf_M.h"



using namespace std::chrono;
using namespace std;



void SprawdzCzas_L(int wielkosc, int gestosc, int st, int ko, ofstream& zapisCzasu, bool doPliku) //Funkcja do zapisu czasu do pliku dla Graf_L
{
    high_resolution_clock::time_point t1, t2;
    ofstream czas;
    Graf_L sprawdzany(wielkosc);
    sprawdzany.generuj(gestosc);

    if (ko == -1)
    {
        t1 = high_resolution_clock::now();
        sprawdzany.Dijk(st);
        t2 = high_resolution_clock::now();
    }
    else
    {
        t1 = high_resolution_clock::now();
        sprawdzany.Dijk(st, ko);
        t2 = high_resolution_clock::now();
    }

    duration<double, std::milli> time_span = t2 - t1;
    zapisCzasu << time_span.count() << std::endl;


    if (doPliku)
    {
        ofstream zapis;
        zapis.open("Graf.txt");
    }
}

void SprawdzCzas_M(int wielkosc, int gestosc, int st, int ko, ofstream& zapisCzasu, bool doPliku)  //Funkcja do zapisu czasu do pliku dla Graf_M
{
    high_resolution_clock::time_point t1, t2;
    ofstream czas;
    Graf_M sprawdzany(wielkosc);
    sprawdzany.generuj(gestosc);

    if (ko == -1)
    {
        t1 = high_resolution_clock::now();
        sprawdzany.Dijk(st);
        t2 = high_resolution_clock::now();
    }
    else
    {
        t1 = high_resolution_clock::now();
        sprawdzany.Dijk(st, ko);
        t2 = high_resolution_clock::now();
    }

    duration<double, std::milli> time_span = t2 - t1;
    zapisCzasu << time_span.count() << std::endl;


    if (doPliku)
    {
        ofstream zapis;
        zapis.open("Graf.txt");
    }
}


int main()
{
    ofstream zapisCzasu_L, zapisCzasu_M;
    int gest[] = { 25, 50, 75, 100 };
    int liczba[] = { 100,200,500,1000,2000 };
    int postep = 0;
    int j = 0, i = 0;
    string doWczytania, doZapisu;
    int menu1, menu2, menu3;
    int kr, wi, st;
    ifstream plikWczytywany;
    Graf* jeden;


    std::cout << "Menu: \n" <<
        "1- Podstawowe dzialanie programu, losowe zestawy danych i zapisywanie do plikow\n" <<
        "o nazwie Wyniki_L.txt oraz Wyniki_M.txt.\n" <<
        "2- Wczytanie danych z pliku oraz dzialanie na nich\n" <<
        "3- Jeden losowy graf o wielkosci 100 oraz gestosci 50 rozwiazany za pomoca wybranego\n"<<
        "algorytmu i wyswietlony\n";
    std::cin >> menu1;


    switch (menu1)
    {
    case 1:
        zapisCzasu_L.open("Wyniki_L.txt");
        zapisCzasu_M.open("Wyniki_M.txt");

        while (i < 4)
        {
            j = 0;
            while (j < 5)
            {
                zapisCzasu_L << "Liczba: " << liczba[j] << " Gestosc: " << gest[i] << endl;
                for (int k = 0; k < 100; k++)
                    SprawdzCzas_L(liczba[j], gest[i], 0, -1, zapisCzasu_L, 0);
                zapisCzasu_M << "Liczba: " << liczba[j] << " Gestosc: " << gest[i] << endl;
                for (int k = 0; k < 100; k++)
                    SprawdzCzas_M(liczba[j], gest[i], 0, -1, zapisCzasu_M, 0);
                postep = ((((i * 5) + (j + 1)) * 100) / (4 * 5));
                std::cout << "Postep: " << postep << "%" << endl;
                j++;
            }
            zapisCzasu_L << endl;
            zapisCzasu_M << endl;
            i++;
        }
        return 0;
        break;

    case 2:
        std::cout << "Podaj plik z ktorego wczytac dane: ";
        std::cin >> doWczytania;
        std::cout << "Algorytm z wykorzystaniem: 1- Listy, 2- Macierzy: ";
        std::cin >> menu2;
        std::cout << "Wynik: 1- wyswietl, 2- zapisz do pliku";
        std::cin >> menu3;
        plikWczytywany.open(doWczytania);
        
        plikWczytywany >> kr >> wi >> st;
        switch (menu2)
        {
        case 1:
            jeden = new Graf_L(wi);
            jeden->wczytaj(plikWczytywany);
            break;
        case 2:
            jeden = new Graf_M(wi);
            jeden->wczytaj(plikWczytywany);
            break;
        default:
            return 1;
        }
        
        switch (menu3)
        {
        case 1:
            jeden->Dijk(0);
            jeden->wypisz();
            break;
            return 0;
        case 2:
            jeden->Dijk(0);
            jeden->zapisz();
            cout << "Zapisano w Graf_gotowy.txt";
            break;
            return 0;
        default:
            return 1;
        }
        break;
    case 3:
        cout << "Ktory algorytm wykorzystac: 1- Lista, 2-Macierz: ";
        cin >> menu2;
        switch (menu2)
        {
        case 1:
            jeden = new Graf_L(100);
            break;
        case 2:
            jeden = new Graf_M(100);
            break;
        default:
            return 1;
        }
        jeden->generuj(50);
        jeden->Dijk(0);
        jeden->wypisz();
        break;
    default:
        return 1;
    }
    return 0;
}
