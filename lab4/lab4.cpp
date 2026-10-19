#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int vmestimost = 100;
    int massiv[vmestimost], novye_elementy[3];
    int razmer, indeks, leviy_indeks, praviy_indeks;
    int vremennoe_znachenie, seredina;

    cout << "Введите размер массива от 14 до 97: ";
    cin >> razmer;

    if (!cin || razmer < 14 || razmer > vmestimost - 3)
    {
        cout << "Ошибка: нужен целый размер от 14 до 97." << endl;
        return 1;
    }

    srand(time(0));
    for (indeks = 0; indeks < razmer; indeks++)
        massiv[indeks] = rand() % 41 - 20;

    cout << "Исходный массив:" << endl;
    for (indeks = 0; indeks < razmer; indeks++)
        cout << massiv[indeks] << " ";
    cout << endl;

    leviy_indeks = 0;
    praviy_indeks = razmer - 1;
    while (leviy_indeks < praviy_indeks)
    {
        vremennoe_znachenie = massiv[leviy_indeks];
        massiv[leviy_indeks] = massiv[praviy_indeks];
        massiv[praviy_indeks] = vremennoe_znachenie;
        leviy_indeks++;
        praviy_indeks--;
    }

    if (razmer % 2 != 0)
    {
        seredina = razmer / 2;
        for (indeks = seredina; indeks < razmer - 1; indeks++)
            massiv[indeks] = massiv[indeks + 1];
        razmer--;
    }

    cout << "После переворота и удаления середины:" << endl;
    for (indeks = 0; indeks < razmer; indeks++)
        cout << massiv[indeks] << " ";
    cout << endl;

    for (indeks = 0; indeks < 3; indeks++)
        novye_elementy[indeks] = massiv[indeks + 10] - 2;

    for (indeks = razmer - 1; indeks >= 0; indeks--)
        massiv[indeks + 3] = massiv[indeks];

    for (indeks = 0; indeks < 3; indeks++)
        massiv[indeks] = novye_elementy[indeks];
    razmer += 3;

    cout << "Итоговый массив:" << endl;
    for (indeks = 0; indeks < razmer; indeks++)
        cout << massiv[indeks] << " ";
    cout << endl;
    cout << "Количество элементов: " << razmer << endl;

    return 0;
}
