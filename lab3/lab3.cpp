#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    const double pi = acos(-1.0);
    const double tochnost = 0.0001;
    const int chislo_razbieniy = 10;
    const int chislo_chlenov = 20;
    double nachalo, konec, shag, x;
    double summa_20, summa_po_tochnosti, tekushiy_chlen;
    double znachenie_funkcii, granica_ostatka, oshibka;
    int nomer_tochki, nomer_chlena, znak, dobavleno_chlenov;

    nachalo = pi / 5.0;
    konec = pi;
    shag = (konec - nachalo) / chislo_razbieniy;

    cout << fixed << setprecision(8);
    for (nomer_tochki = 0;
         nomer_tochki <= chislo_razbieniy; nomer_tochki++)
    {
        x = nachalo + nomer_tochki * shag;
        summa_20 = 0.0;
        znak = -1;

        for (nomer_chlena = 1;
             nomer_chlena <= chislo_chlenov; nomer_chlena++)
        {
            tekushiy_chlen = znak * cos(nomer_chlena * x)
                             / (nomer_chlena * nomer_chlena);
            summa_20 += tekushiy_chlen;
            znak = -znak;
        }

        summa_po_tochnosti = 0.0;
        nomer_chlena = 1;
        znak = -1;
        granica_ostatka = 1.0;

        while (granica_ostatka >= tochnost)
        {
            tekushiy_chlen = znak * cos(nomer_chlena * x)
                             / (nomer_chlena * nomer_chlena);
            summa_po_tochnosti += tekushiy_chlen;
            granica_ostatka = 1.0 / nomer_chlena;
            znak = -znak;
            nomer_chlena++;
        }

        dobavleno_chlenov = nomer_chlena - 1;
        znachenie_funkcii = (x * x - pi * pi / 3.0) / 4.0;
        oshibka = fabs(summa_po_tochnosti - znachenie_funkcii);

        cout << "X=" << x << " SN=" << summa_20;
        cout << " SE=" << summa_po_tochnosti;
        cout << " Y=" << znachenie_funkcii;
        cout << " ERR=" << oshibka;
        cout << " N_E=" << dobavleno_chlenov << endl;
    }

    return 0;
}
