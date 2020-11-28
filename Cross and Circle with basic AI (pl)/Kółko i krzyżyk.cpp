// Kółko i krzyżyk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "plansza.h"
#include "SI.h"



int main()
{
    int rozmiar = 0;
    int w = -1;
    int k = -1;
    int wymog = 0;
    int menu = 0;
    bool tura = false;
    bool pierwszy = false;
    plansza* gra;
    char dalej = 0;

    SI AI;

    cout << "  _________         \n";
    cout << " /:::::::::\\         \n";
    cout << "|:::Gra w:::|       \n";
    cout << "|:::Kolko:::|        \n";
    cout << "|:::::i:::::|        \n";
    cout << "|::Krzyzyk::|        \n";
    cout << " \\_________/        \n";

    cout << "\nPodaj wielkosc planszy: ";
    cin >> rozmiar;

    while (rozmiar < 3)
    {
        cout << "Nieprawidlowy rozmiar planszy, wybierz inny: ";
        cin >> rozmiar;
    }

    cout << "\nPodaj wymog do wygranej: ";
    cin >> wymog;

    while (wymog < 2 || wymog>rozmiar)
    {
        cout << "Nieprawidlowy wymog do wygranej, wybierz inny: ";
        cin >> wymog;
    }

    gra = new plansza(rozmiar, wymog);

    cout << "1- Gra jednoosobwa przeciwko SI \n2- Gra dwuosobowa\n3- Gra jednoosobowa optymalizowana\n Wybor: ";
    cin >> menu;

    while (1)
    {
        switch (menu)
        {
        case 1:
            cout << "Czy chcesz zaczac pierwszy? 1- tak 0- nie: ";
            cin >> pierwszy;
            if (pierwszy)
            {
                cout << "Kolej na gracza 1.\n";
                tura = 1;
            }
            gra->wyswietl();
            while (1)
            {
                if (tura)
                    cout << "Kolej na gracza 1.\n";
                while (tura)
                {
                    cout << "Podaj wiersz gdzie wpisac znak: ";
                    cin >> w;
                    w--;
                    cout << "Podaj kolumne gdzie wpisac znak: ";
                    cin >> k;
                    k--;
                    if (!gra->czypuste(w, k))
                        cout << "Blad!!!\n";
                    else
                    {
                        gra->dodaj(2, w, k);
                        tura = 0;
                    }
                    gra->wyswietl();

                    switch (gra->wygrana())
                    {
                    case 1:
                        cout << "AI wygrywa!!!\n";
                        cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                        cin >> dalej;
                        return 0;
                        break;
                    case 2:
                        cout << "Gracz 1 wygrywa!!!\n";
                        cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                        cin >> dalej;
                        return 0;
                        break;
                    case -1:
                        cout << "Remis\n!";
                        cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                        cin >> dalej;
                        return 0;

                        break;
                    }
                    
                }
                cout << "Tura SI!\n";
                AI.mv(*gra);
                gra->wyswietl();

                switch (gra->wygrana())
                {
                case 1:
                    cout << "AI wygrywa!!!\n";
                    cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                    cin >> dalej;
                    return 0;
                    break;
                case 2:
                    cout << "Gracz 1 wygrywa!!!\n";
                    cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                    cin >> dalej;
                    return 0;
                    break;
                case -1:
                    cout << "Remis!\n";
                    cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                    cin >> dalej;
                    return 0;

                    break;
                }
                tura = 1;
            }
            break;

        case 2:
            gra->wyswietl();
            while (1)
            {
                cout << " Kolej na gracza 1.\n";
                tura = 1;
                while (tura)
                {
                    cout << "Podaj wiersz gdzie wpisac znak: ";
                    cin >> w;
                    w--;
                    cout << "Podaj kolumne gdzie wpisac znak: ";
                    cin >> k;
                    k--;
                    if (!gra->czypuste(w, k))
                        cout << "Blad!!!\n";
                    else
                    {
                        gra->dodaj(1, w, k);
                        tura = 0;
                    }
                    gra->wyswietl();
                    switch (gra->wygrana())
                    {
                    case 1:
                        cout << "Gracz 1 wygrywa!!!";
                        return 0;
                        break;
                    case 2:
                        cout << "Gracz 2 wygrywa!!!";
                        return 0;
                        break;
                    case -1:
                        cout << "Remis!";
                        return 0;
                        break;
                    }
                }

                cout << " Kolej na gracza 2.\n";
                tura = 1;
                while (tura)
                {
                    cout << "Podaj wiersz gdzie wpisac znak: ";
                    cin >> w;
                    w--;
                    cout << "Podaj kolumne gdzie wpisac znak: ";
                    cin >> k;
                    k--;
                    if (!gra->czypuste(w, k))
                        cout << "Blad!!!\n";
                    else
                    {
                        gra->dodaj(2, w, k);
                        tura = 0;
                    }
                    gra->wyswietl();
                    switch (gra->wygrana())
                    {
                    case 1:
                        cout << "Gracz 1 wygrywa!!!";
                        return 0;
                        break;
                    case 2:
                        cout << "Gracz 2 wygrywa!!!";
                        return 0;
                        break;
                    case -1:
                        cout << "Remis!";
                        return 0;
                        break;
                    }
                }
            }
            break;

        case 3:
            cout << "Czy chcesz zaczac pierwszy? 1- tak 0- nie: ";
            cin >> pierwszy;
            if (pierwszy)
            {
                cout << "Kolej na gracza 1.\n";
                tura = 1;
            }
            gra->wyswietl();
            while (1)
            {
                if (tura)
                    cout << "Kolej na gracza 1.\n";
                while (tura)
                {
                    cout << "Podaj wiersz gdzie wpisac znak: ";
                    cin >> w;
                    w--;
                    cout << "Podaj kolumne gdzie wpisac znak: ";
                    cin >> k;
                    k--;
                    if (!gra->czypuste(w, k))
                        cout << "Blad!!!\n";
                    else
                    {
                        gra->dodaj(2, w, k);
                        tura = 0;
                    }
                    gra->wyswietl();

                    switch (gra->wygrana())
                    {
                    case 1:
                        cout << "AI wygrywa!!!\n";
                        cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                        cin >> dalej;
                        return 0;
                        break;
                    case 2:
                        cout << "Gracz 1 wygrywa!!!\n";
                        cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                        cin >> dalej;
                        return 0;
                        break;
                    case -1:
                        cout << "Remis\n!";
                        cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                        cin >> dalej;
                        return 0;

                        break;
                    }

                }
                cout << "Tura SI!\n";
                AI.mv(*gra);
                gra->wyswietl();

                switch (gra->wygrana())
                {
                case 1:
                    cout << "AI wygrywa!!!\n";
                    cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                    cin >> dalej;
                    return 0;
                    break;
                case 2:
                    cout << "Gracz 1 wygrywa!!!\n";
                    cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                    cin >> dalej;
                    return 0;
                    break;
                case -1:
                    cout << "Remis!\n";
                    cout << "Podaj dowolny znak aby zakonczyc dzialanie";
                    cin >> dalej;
                    return 0;

                    break;
                }
                tura = 1;
            }
            break;


        default:
            cout << "Wybrano nie poprawna opcje.\n";
            cout << "1- Gra jednoosobwa przeciwko SI \n2- Gra dwuosobowa\n Wybor: ";
            cin >> menu;
        }
    }
}

