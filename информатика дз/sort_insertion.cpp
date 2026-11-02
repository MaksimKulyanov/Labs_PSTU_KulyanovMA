#include <iostream>
using namespace std;

int main() {
    const int n = 7;
    int a[n] = {7, 3, 9, 2, 5, 1, 8};
    for (int i = 1; i < n; ++i) {
        int y = a[i];
        int j = i - 1;
        bool F = false; // место для y пока не найдено
        while (j >= 0 && !F) {
            if (a[j] > y) { a[j + 1] = a[j]; --j; }
            else F = true;
        }
        a[j + 1] = y;
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';