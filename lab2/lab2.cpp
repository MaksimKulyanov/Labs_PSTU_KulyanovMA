#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double eps = 0.0001;
    int n = 1;
    double a = 1.0 / 3;
    double s = 0;

    while (fabs(a) >= eps)
    {
        s += a;
        a = a * pow((double)n / (n + 1), n);
        n++;
    }

    cout << "Сумма ряда n!/(3*n^n), точность: " << eps << endl;
    cout << "Сумма = " << s << endl;
    cout << "Количество членов: " << n - 1 << endl;
    return 0;
}
