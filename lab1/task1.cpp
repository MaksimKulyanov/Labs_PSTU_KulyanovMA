#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float a = 1000, b = 0.0001f;
    float c = pow(a + b, 3);
    float d = pow(a, 3);
    float e = 3 * a * a * b;
    float f = 3 * a * b * b;
    float g = pow(b, 3);
    float numf = c - (d + e);
    float denf = f + g;
    float resf = numf / denf;

    double a2 = 1000, b2 = 0.0001;
    double c2 = pow(a2 + b2, 3);
    double d2 = pow(a2, 3);
    double e2 = 3 * a2 * a2 * b2;
    double f2 = 3 * a2 * b2 * b2;
    double g2 = pow(b2, 3);
    double numd = c2 - (d2 + e2);
    double dend = f2 + g2;
    double resd = numd / dend;

    cout << setprecision(10);
    cout << "float:" << endl;
    cout << "(a+b)^3 = " << c << endl;
    cout << "a^3 + 3a^2b = " << d + e << endl;
    cout << "numerator = " << numf << endl;
    cout << "denominator = " << denf << endl;
    cout << "result = " << resf << endl << endl;

    cout << "double:" << endl;
    cout << "(a+b)^3 = " << c2 << endl;
    cout << "a^3 + 3a^2b = " << d2 + e2 << endl;
    cout << "numerator = " << numd << endl;
    cout << "denominator = " << dend << endl;
    cout << "result = " << resd << endl;
    return 0;
}
