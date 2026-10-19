#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double tochnost = 0.0001;
    double tekushiy_chlen, summa_ryada;
    int nomer_chlena, kolichestvo_chlenov;

    nomer_chlena = 1;
    tekushiy_chlen = 1.0 / 3.0;
    summa_ryada = 0.0;

    while (fabs(tekushiy_chlen) >= tochnost)
    {
        summa_ryada += tekushiy_chlen;
        tekushiy_chlen *= pow((double)nomer_chlena / (nomer_chlena + 1),
                           nomer_chlena);
        nomer_chlena++;
    }

    kolichestvo_chlenov = nomer_chlena - 1;
    cout << "Сумма ряда n!/(3*n^n), точность: " << tochnost << endl;
    cout << "Сумма = " << summa_ryada << endl;
    cout << "Количество членов: " << kolichestvo_chlenov << endl;

    return 0;
}
