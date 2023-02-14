#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

int nakljucno();
int poisciNajmanseD(int tab[][5]);
void urediVrstico(int tab[][5], int n);
int poisciStVVrstici(int tab[][5], int n, int iskano, int vrsta);
void izpisi(int tab[][5], int n);
void napolni(int tab[][5], int n);
int main()
{
    int tab[5][5];
    napolni(tab, 5);
    izpisi(tab, 5);
    std::cout << '\n';
    int vrsta = poisciNajmanseD(tab);
    std::cout << vrsta;
    std::cout << '\n';
    urediVrstico(tab, vrsta);
    izpisi(tab, 5);
    std::cout << '\n';
    int a = poisciStVVrstici(tab, 5, 111, vrsta);
    std::cout << a;
}
void napolni(int tab[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            tab[i][j] = nakljucno();
    }
}
int nakljucno()
{
    return rand() % (127 - 30) + 30;
}
void izpisi(int tab[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            std::cout << std::setw(4) << tab[i][j];
        std::cout << '\n';
    }
}
int poisciNajmanseD(int tab[][5])
{
    int najmansiI = 0;
    for (int i = 1; i < 5; i++)
    {
        if (tab[najmansiI][najmansiI] > tab[i][i])
            najmansiI = i;
    }
    return najmansiI;
}

void urediVrstico(int tab[][5], int n)
{
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (tab[n][j] > tab[n][j + 1])
            {
                int tamp = tab[n][j];
                tab[n][j] = tab[n][j + 1];
                tab[n][j + 1] = tamp;
            }
        }
    }
}
int poisciStVVrstici(int tab[][5], int n, int iskano, int vrsta)
{
    int zac = 0;
    int kon = n - 1;

    int sre;
    do
    {
        sre = (zac + kon) / 2;
        if (tab[vrsta][sre] == iskano)
        {
            return sre;
            std::cout << "==" << '\n';
        }
        if (tab[vrsta][sre] < iskano)
        {
            kon = sre + 1;
            std::cout << "<" << '\n';
        }
        if (tab[vrsta][sre] > iskano)
        {
            zac = sre - 1;
            std::cout << ">" << '\n';
        }
    } while (zac <= kon);
    return -1;
}