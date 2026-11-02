#include <iostream>
using namespace std;

int main() {
    const int n = 7;
    int a[n] = {7, 3, 9, 2, 5, 1, 8};
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIndex]) minIndex = j;
        int temp = a[i]; a[i] = a[minIndex]; a[minIndex] = temp;
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
}