#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float a_float, b_float;
    float kub_summy_float, kub_a_float;
    float tri_a2b_float, tri_ab2_float, kub_b_float;
    float chislitel_float, znamenatel_float, otvet_float;
    double a_double, b_double;
    double kub_summy_double, kub_a_double;
    double tri_a2b_double, tri_ab2_double, kub_b_double;
    double chislitel_double, znamenatel_double, otvet_double;
    int m, n, summa_vyrazheniya;
    bool sravnenie_1, sravnenie_2;

    a_float = 1000.0f;
    b_float = 0.0001f;
    a_double = 1000.0;
    b_double = 0.0001;

    kub_summy_float = pow(a_float + b_float, 3);
    kub_a_float = pow(a_float, 3);
    tri_a2b_float = 3 * a_float * a_float * b_float;
    tri_ab2_float = 3 * a_float * b_float * b_float;
    kub_b_float = pow(b_float, 3);
    chislitel_float = kub_summy_float - (kub_a_float + tri_a2b_float);
    znamenatel_float = tri_ab2_float + kub_b_float;
    otvet_float = chislitel_float / znamenatel_float;

    kub_summy_double = pow(a_double + b_double, 3);
    kub_a_double = pow(a_double, 3);
    tri_a2b_double = 3 * a_double * a_double * b_double;
    tri_ab2_double = 3 * a_double * b_double * b_double;
    kub_b_double = pow(b_double, 3);
    chislitel_double = kub_summy_double
                       - (kub_a_double + tri_a2b_double);
    znamenatel_double = tri_ab2_double + kub_b_double;
    otvet_double = chislitel_double / znamenatel_double;

    cout << setprecision(10);
    cout << "float:" << endl;
    cout << "Числитель = " << chislitel_float << endl;
    cout << "Знаменатель = " << znamenatel_float << endl;
    cout << "Результат = " << otvet_float << endl << endl;
    cout << "double:" << endl;
    cout << "Числитель = " << chislitel_double << endl;
    cout << "Знаменатель = " << znamenatel_double << endl;
    cout << "Результат = " << otvet_double << endl << endl;

    cout << "Введите m и n: ";
    cin >> m >> n;

    summa_vyrazheniya = m + --n;
    cout << "m + --n = " << summa_vyrazheniya;
    cout << "; m = " << m << ", n = " << n << endl;

    sravnenie_1 = m++ < ++n;
    cout << "m++ < ++n = " << sravnenie_1;
    cout << "; m = " << m << ", n = " << n << endl;

    sravnenie_2 = n-- < --m;
    cout << "n-- < --m = " << sravnenie_2;
    cout << "; m = " << m << ", n = " << n << endl;

    return 0;
}
