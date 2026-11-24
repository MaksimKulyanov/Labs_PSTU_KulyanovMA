#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int razmer_polya = 128;

struct Stadion
{
    char nazvanie[razmer_polya];
    char adres[razmer_polya];
    int vmestimost;
    char vidy_sporta[razmer_polya];
};

bool schitat_stroku(const char* priglashenie, char* bufer, int razmer)
{
    cout << priglashenie;
    cin.getline(bufer, razmer);

    if (cin.fail() || bufer[0] == '\0')
    {
        cin.clear();
        return false;
    }

    return true;
}

bool vvesti_stadion(Stadion& zapis)
{
    if (!schitat_stroku("Название: ", zapis.nazvanie, razmer_polya) ||
        !schitat_stroku("Адрес: ", zapis.adres, razmer_polya))
    {
        return false;
    }

    cout << "Вместимость: ";
    if (!(cin >> zapis.vmestimost) || zapis.vmestimost < 0)
    {
        return false;
    }
    cin.ignore(10000, '\n');

    return schitat_stroku("Виды спорта: ", zapis.vidy_sporta, razmer_polya);
}

bool zapisat_blok(FILE* potok, const Stadion& zapis)
{
    return fwrite(&zapis, sizeof(Stadion), 1, potok) == 1;
}

bool sozdat_fayl(const char* imya_fayla)
{
    FILE* potok;
    Stadion zapis;
    int kolichestvo, indeks;
    bool uspeshno;

    cout << "Количество стадионов (не менее 5): ";
    if (!(cin >> kolichestvo) || kolichestvo < 5 || kolichestvo > 1000)
    {
        return false;
    }
    cin.ignore(10000, '\n');

    potok = fopen(imya_fayla, "wb");
    if (potok == NULL)
    {
        return false;
    }

    uspeshno = true;
    for (indeks = 0; indeks < kolichestvo && uspeshno; indeks++)
    {
        memset(&zapis, 0, sizeof(Stadion));
        cout << "Стадион " << indeks + 1 << "\n";
        uspeshno = vvesti_stadion(zapis) && zapisat_blok(potok, zapis);
    }

    if (fclose(potok) != 0)
    {
        uspeshno = false;
    }

    return uspeshno;
}

bool pechatat_fayl(const char* imya_fayla)
{
    FILE* potok;
    Stadion zapis;
    int nomer;
    bool uspeshno;

    potok = fopen(imya_fayla, "rb");
    if (potok == NULL)
    {
        return false;
    }

    nomer = 0;
    while (fread(&zapis, sizeof(Stadion), 1, potok) == 1)
    {
        nomer++;
        cout << nomer << ". " << zapis.nazvanie
             << " | " << zapis.adres
             << " | " << zapis.vmestimost
             << " | " << zapis.vidy_sporta << "\n";
    }

    uspeshno = !ferror(potok);
    if (fclose(potok) != 0)
    {
        uspeshno = false;
    }

    return uspeshno;
}

bool zamenit_fayl(const char* imya_fayla, const char* vremennyy_fayl)
{
    if (remove(imya_fayla) != 0)
    {
        remove(vremennyy_fayl);
        return false;
    }

    if (rename(vremennyy_fayl, imya_fayla) != 0)
    {
        remove(vremennyy_fayl);
        return false;
    }

    return true;
}

bool sovpadaet_nazvanie(const Stadion& zapis, const char* iskomoe_nazvanie)
{
    return strcmp(zapis.nazvanie, iskomoe_nazvanie) == 0;
}

bool udalit_po_nazvaniyu(const char* imya_fayla, const char* iskomoe_nazvanie)
{
    const char* vremennyy_fayl = "stadiums.tmp";
    FILE* vhodnoy_potok;
    FILE* vyhodnoy_potok;
    Stadion zapis;
    bool naydeno, uspeshno;

    vhodnoy_potok = fopen(imya_fayla, "rb");
    if (vhodnoy_potok == NULL)
    {
        return false;
    }

    vyhodnoy_potok = fopen(vremennyy_fayl, "wb");
    if (vyhodnoy_potok == NULL)
    {
        fclose(vhodnoy_potok);
        return false;
    }

    naydeno = false;
    uspeshno = true;
    while (fread(&zapis, sizeof(Stadion), 1, vhodnoy_potok) == 1)
    {
        if (!naydeno && sovpadaet_nazvanie(zapis, iskomoe_nazvanie))
        {
            naydeno = true;
        }
        else if (!zapisat_blok(vyhodnoy_potok, zapis))
        {
            uspeshno = false;
            break;
        }
    }

    if (ferror(vhodnoy_potok))
    {
        uspeshno = false;
    }
    if (fclose(vhodnoy_potok) != 0)
    {
        uspeshno = false;
    }
    if (fclose(vyhodnoy_potok) != 0)
    {
        uspeshno = false;
    }

    if (!uspeshno || !naydeno)
    {
        remove(vremennyy_fayl);
        return false;
    }

    return zamenit_fayl(imya_fayla, vremennyy_fayl);
}

bool dobavit_posle_nomera(const char* imya_fayla, int nomer_pozicii,
                          const Stadion& pervaya, const Stadion& vtoraya)
{
    const char* vremennyy_fayl = "stadiums.tmp";
    FILE* vhodnoy_potok;
    FILE* vyhodnoy_potok;
    Stadion zapis;
    int tekushiy_nomer;
    bool naydeno, uspeshno;

    vhodnoy_potok = fopen(imya_fayla, "rb");
    if (vhodnoy_potok == NULL)
    {
        return false;
    }

    vyhodnoy_potok = fopen(vremennyy_fayl, "wb");
    if (vyhodnoy_potok == NULL)
    {
        fclose(vhodnoy_potok);
        return false;
    }

    tekushiy_nomer = 0;
    naydeno = false;
    uspeshno = true;
    while (fread(&zapis, sizeof(Stadion), 1, vhodnoy_potok) == 1)
    {
        if (!zapisat_blok(vyhodnoy_potok, zapis))
        {
            uspeshno = false;
            break;
        }

        tekushiy_nomer++;
        if (tekushiy_nomer == nomer_pozicii)
        {
            naydeno = true;
            if (!zapisat_blok(vyhodnoy_potok, pervaya) ||
                !zapisat_blok(vyhodnoy_potok, vtoraya))
            {
                uspeshno = false;
                break;
            }
        }
    }

    if (ferror(vhodnoy_potok))
    {
        uspeshno = false;
    }
    if (fclose(vhodnoy_potok) != 0)
    {
        uspeshno = false;
    }
    if (fclose(vyhodnoy_potok) != 0)
    {
        uspeshno = false;
    }

    if (!uspeshno || !naydeno)
    {
        remove(vremennyy_fayl);
        return false;
    }

    return zamenit_fayl(imya_fayla, vremennyy_fayl);
}

int main()
{
    const char* imya_fayla = "stadiums.dat";
    char nazvanie_dlya_udaleniya[razmer_polya];
    Stadion pervyy_novyy, vtoroy_novyy;
    int nomer_pozicii;

    if (!sozdat_fayl(imya_fayla))
    {
        cerr << "Ошибка формирования файла или ввода\n";
        return 1;
    }

    cout << "Исходный файл:\n";
    if (!pechatat_fayl(imya_fayla))
    {
        cerr << "Ошибка чтения файла\n";
        return 1;
    }

    if (!schitat_stroku("Название для удаления: ", nazvanie_dlya_udaleniya, razmer_polya))
    {
        cerr << "Ошибка ввода названия\n";
        return 1;
    }

    if (!udalit_po_nazvaniyu(imya_fayla, nazvanie_dlya_udaleniya))
    {
        cerr << "Запись не найдена или ошибка файла\n";
        return 1;
    }

    cout << "После удаления:\n";
    if (!pechatat_fayl(imya_fayla))
    {
        cerr << "Ошибка чтения файла\n";
        return 1;
    }

    cout << "Номер записи, после которой добавить две: ";
    if (!(cin >> nomer_pozicii) || nomer_pozicii < 1)
    {
        cerr << "Неверный номер записи\n";
        return 1;
    }
    cin.ignore(10000, '\n');

    memset(&pervyy_novyy, 0, sizeof(Stadion));
    memset(&vtoroy_novyy, 0, sizeof(Stadion));

    cout << "Новый стадион 1\n";
    if (!vvesti_stadion(pervyy_novyy))
    {
        cerr << "Ошибка ввода данных\n";
        return 1;
    }

    cout << "Новый стадион 2\n";
    if (!vvesti_stadion(vtoroy_novyy))
    {
        cerr << "Ошибка ввода данных\n";
        return 1;
    }

    if (!dobavit_posle_nomera(imya_fayla, nomer_pozicii, pervyy_novyy, vtoroy_novyy))
    {
        cerr << "Номер не найден или ошибка файла\n";
        return 1;
    }

    cout << "После добавления:\n";
    if (!pechatat_fayl(imya_fayla))
    {
        cerr << "Ошибка чтения файла\n";
        return 1;
    }

    return 0;
}