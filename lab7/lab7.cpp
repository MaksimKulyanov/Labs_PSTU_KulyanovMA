#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdarg>
#include <climits>
using namespace std;

double logarifm(double x)
{
    return log(x);
}

double logarifm(double x, int osnovanie)
{
    return log(x) / log((double)osnovanie);
}

bool perevesti_v_troichnuyu(const char* dvoichnoe, char troichnoe[], int razmer_bufera)
{
    unsigned long long znachenie;
    unsigned int cifra;
    int indeks, dlina, levyy, pravyy;
    char vremennyy_simvol;

    if (dvoichnoe == NULL || dvoichnoe[0] == '\0')
    {
        strcpy(troichnoe, "ошибка");
        return false;
    }

    znachenie = 0;
    for (indeks = 0; dvoichnoe[indeks] != '\0'; indeks++)
    {
        if (dvoichnoe[indeks] != '0' && dvoichnoe[indeks] != '1')
        {
            strcpy(troichnoe, "ошибка");
            return false;
        }

        cifra = (unsigned int)(dvoichnoe[indeks] - '0');
        if (znachenie > (ULLONG_MAX - cifra) / 2)
        {
            strcpy(troichnoe, "переполнение");
            return false;
        }

        znachenie = znachenie * 2 + cifra;
    }

    if (znachenie == 0)
    {
        strcpy(troichnoe, "0");
        return true;
    }

    dlina = 0;
    while (znachenie > 0 && dlina < razmer_bufera - 1)
    {
        troichnoe[dlina] = (char)('0' + (znachenie % 3));
        znachenie /= 3;
        dlina++;
    }
    troichnoe[dlina] = '\0';

    levyy = 0;
    pravyy = dlina - 1;
    while (levyy < pravyy)
    {
        vremennyy_simvol = troichnoe[levyy];
        troichnoe[levyy] = troichnoe[pravyy];
        troichnoe[pravyy] = vremennyy_simvol;
        levyy++;
        pravyy--;
    }

    return true;
}

void perevesti_chisla(int kolichestvo, ...)
{
    va_list spisok_argumentov;
    const char* tekushee_chislo;
    char troichnyy_vid[64];
    int nomer;

    va_start(spisok_argumentov, kolichestvo);
    for (nomer = 0; nomer < kolichestvo; nomer++)
    {
        tekushee_chislo = va_arg(spisok_argumentov, const char*);
        perevesti_v_troichnuyu(tekushee_chislo, troichnyy_vid, 64);
        cout << tekushee_chislo << "(2) = " << troichnyy_vid << "(3)\n";
    }
    va_end(spisok_argumentov);
}

int main()
{
    int vybor;
    double x, naturalnyy, desyatichnyy;

    cout << "Выберите режим (1 - логарифмы, 2 - перевод чисел): ";
    if (!(cin >> vybor) || (vybor != 1 && vybor != 2))
    {
        cerr << "Ошибка: неверный выбор режима\n";
        return 1;
    }

    if (vybor == 1)
    {
        cout << "Введите положительное число: ";
        if (!(cin >> x) || !isfinite(x) || x <= 0.0)
        {
            cerr << "Ошибка: число должно быть положительным и конечным\n";
            return 1;
        }

        naturalnyy = logarifm(x);
        desyatichnyy = logarifm(x, 10);

        cout << fixed << setprecision(8);
        cout << "ln(" << x << ") = " << naturalnyy << "\n";
        cout << "lg(" << x << ") = " << desyatichnyy << "\n";
    }
    else
    {
        cout << "Перевод 3 чисел:\n";
        perevesti_chisla(3, "0", "10", "101");

        cout << "Перевод 6 чисел:\n";
        perevesti_chisla(6, "1", "11", "100", "110", "111", "1000");

        cout << "Перевод 7 чисел:\n";
        perevesti_chisla(7, "1001", "1010", "1011", "1100", "1101", "1110", "1111");
    }

    return 0;
}