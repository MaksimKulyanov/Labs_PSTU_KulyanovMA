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

    cout << "Sum of series n!/(3*n^n) with eps = " << eps << endl;
    cout << "S = " << s << endl;
    cout << "Number of terms: " << n - 1 << endl;
    return 0;
}
