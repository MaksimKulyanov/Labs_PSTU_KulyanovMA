#include <iostream>
using namespace std;

int main() {
    const int n = 7;
    int a[n] = {-7, -2, 0, 3, 6, 6, 11};
    // F = true означает, что найдено нарушение строгого возрастания.
    bool F = false;
    int i = 0;
    while (i < n - 1 && F == false) {
        if (a[i] >= a[i + 1]) F = true;
        else ++i;
    }
    if (F) cout << "Not strictly increasing\n";
    else cout << "Strictly increasing\n";
}