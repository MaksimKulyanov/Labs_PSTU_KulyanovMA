#include <iostream>
using namespace std;

const int maks_razmer = 10;

bool podhodit_stolbec(const long long matrica[maks_razmer][maks_razmer],
                      int razmer, int nomer_stolbca)
{
    long long pervyy_element;
    int indeks;

    pervyy_element = matrica[0][nomer_stolbca];

    for (indeks = 0; indeks < razmer; indeks++)
    {
        if (pervyy_element <= matrica[indeks][indeks] ||
            pervyy_element <= matrica[indeks][razmer - 1 - indeks])
        {
            return false;
        }
    }

    return true;
}

long long proizvedenie_stolbca(const long long matrica[maks_razmer][maks_razmer],
                               int razmer, int nomer_stolbca)
{
    long long proizvedenie;
    int stroka;

    proizvedenie = 1;

    for (stroka = 0; stroka < razmer; stroka++)
    {
        proizvedenie *= matrica[stroka][nomer_stolbca];
    }

    return proizvedenie;
}

int main()
{
    long long matrica[maks_razmer][maks_razmer];
    long long rezultat;
    int razmer, stroka, stolbec;
    bool naydeno;

    cout << "Размер квадратной матрицы (от 1 до 10): ";
    if (!(cin >> razmer) || razmer < 1 || razmer > maks_razmer)
    {
        cerr << "Ошибка: размер должен быть от 1 до 10\n";
        return 1;
    }

    cout << "Элементы матрицы (целые числа от -10 до 10):\n";
    for (stroka = 0; stroka < razmer; stroka++)
    {
        for (stolbec = 0; stolbec < razmer; stolbec++)
        {
            if (!(cin >> matrica[stroka][stolbec]) ||
                matrica[stroka][stolbec] < -10 ||
                matrica[stroka][stolbec] > 10)
            {
                cerr << "Ошибка: некорректный элемент матрицы\n";
                return 1;
            }
        }
    }

    naydeno = false;
    for (stolbec = 0; stolbec < razmer; stolbec++)
    {
        if (podhodit_stolbec(matrica, razmer, stolbec))
        {
            rezultat = proizvedenie_stolbca(matrica, razmer, stolbec);
            cout << "Столбец " << stolbec + 1
                 << ": произведение = " << rezultat << "\n";
            naydeno = true;
        }
    }

    if (!naydeno)
    {
        cout << "Подходящих столбцов нет\n";
    }

    return 0;
}