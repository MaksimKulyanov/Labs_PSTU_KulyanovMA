#include <iostream>
#include <cstring>
using namespace std;

const int maks_dlina = 256;

int main()
{
    char stroka[maks_dlina];
    char cifry[maks_dlina];
    char vremennyy_simvol;
    int dlina, nachalo_slova, konec_slova;
    int kolichestvo_cifr, indeks, nomer_cifry, i, j;

    cout << "Введите строку с точкой в конце (до 255 символов):\n";
    cin.getline(stroka, maks_dlina);

    if (cin.fail())
    {
        cerr << "Ошибка: длина строки превышает 255 символов\n";
        return 1;
    }

    dlina = (int)strlen(stroka);
    if (dlina == 0 || stroka[dlina - 1] != '.')
    {
        cerr << "Ошибка: строка должна завершаться точкой\n";
        return 1;
    }

    nachalo_slova = 0;
    while (nachalo_slova < dlina - 1)
    {
        if (stroka[nachalo_slova] == ' ')
        {
            nachalo_slova++;
            continue;
        }

        konec_slova = nachalo_slova;
        while (konec_slova < dlina - 1 && stroka[konec_slova] != ' ')
        {
            konec_slova++;
        }

        kolichestvo_cifr = 0;
        for (indeks = nachalo_slova; indeks < konec_slova; indeks++)
        {
            if (stroka[indeks] >= '0' && stroka[indeks] <= '9')
            {
                cifry[kolichestvo_cifr] = stroka[indeks];
                kolichestvo_cifr++;
            }
        }

        for (i = 0; i < kolichestvo_cifr - 1; i++)
        {
            for (j = 0; j < kolichestvo_cifr - 1 - i; j++)
            {
                if (cifry[j] < cifry[j + 1])
                {
                    vremennyy_simvol = cifry[j];
                    cifry[j] = cifry[j + 1];
                    cifry[j + 1] = vremennyy_simvol;
                }
            }
        }

        nomer_cifry = 0;
        for (indeks = nachalo_slova; indeks < konec_slova; indeks++)
        {
            if (stroka[indeks] >= '0' && stroka[indeks] <= '9')
            {
                stroka[indeks] = cifry[nomer_cifry];
                nomer_cifry++;
            }
        }

        nachalo_slova = konec_slova;
    }

    cout << "Результат: " << stroka << "\n";

    return 0;
}