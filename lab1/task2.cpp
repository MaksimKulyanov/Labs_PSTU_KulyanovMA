#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    int r1 = m + --n;
    cout << "1) m+--n = " << r1 << "   m = " << m << ", n = " << n << endl;

    bool r2 = m++ < ++n;
    cout << "2) m++<++n = " << r2 << "   m = " << m << ", n = " << n << endl;

    bool r3 = n-- < --m;
    cout << "3) n--<--m = " << r3 << "   m = " << m << ", n = " << n << endl;
    return 0;
}
